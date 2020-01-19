//
// Created by Anneline Daggelinckx on 11/27/19.
//

#include "Controller.h"
#include "Stopwatch.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <utility>

namespace controller {
    Controller::Controller(std::shared_ptr<model::Model> model, std::shared_ptr<view::View> view) : view(std::move(view)), model(std::move(model)) {}


    void Controller::handleEvent(float dt, const sf::Event &event) {
        //move player
        switch (event.key.code) {
            case sf::Keyboard::Left:
                if (!model->player->would_reach_border(-dt))
                    model->player->move(-dt);
                break;
            case sf::Keyboard::Right:
                //check that player doesn't go out of view before moving
                if (!model->player->would_reach_border(dt))
                    model->player->move(dt);
                break;
            case sf::Keyboard::Up:
            case sf::Keyboard::Space:
                // check time between shoots so that player does't have a machine gun
                if (model->player->may_shoot()) {
                    model->p_bullets.push_back(std::make_shared<model::Bullet>(model->player, 0.007));
                    view->player_bullet_sprites.push_back(std::make_shared<view::Sprite>(view::Sprite::bullet));
                    view->player_bullet_sprites.back()->setEntity(model->p_bullets.back());
                    model->p_bullets.back()->addObserver(view->player_bullet_sprites.back());

                    model->player->last_shot = Stopwatch::Instance()->now();
                }
                break;
            case sf::Keyboard::Escape:
                view->window.close();
                break;
            default:
                break;
        }
    }

    std::tuple<bool, bool> Controller::continueState() const {
        //   proceed, win

        if (model->enemies.empty())
            return {false, true};

        if (model->enemies.back()->y <= -3)
            return {false, false};

        if (model->player->health <= 0)
            return {false, false};

        return {true, false};
    }

    void Controller::update(float dt) {
        //player bullet render
        auto p_bullets_ = model->p_bullets;

        for (const auto &b:p_bullets_) {
            b->move(dt);
            //bullet is removed when it is out of the screen
            if (b->at_border()) {
                b->kill();
                model->p_bullets.remove(b);
            }
        }

        //enemy bullet render
        auto e_bullets_ = model->e_bullets;
        for (const auto &b:e_bullets_) {
            b->move(dt);
            //bullet is removed when it is out of the screen
            if (b->at_border()) {
                b->kill();
                model->e_bullets.remove(b);
            }
        }

        //enemy movement
        //only do the enemy movement and shoot when there are enemies
        if (model->enemies.empty()) {
            return;
        }

        //the "enemy block" changes direction when the most left of right enemies hit the side of the screen
        bool change_direction = model->enemies.back()->at_border() || model->enemies.front()->at_border();

        for (auto &e:model->enemies) {
            if (change_direction) {
                e->changeDirection();
            }
            e->move(dt);
        }

        //enemy shoot
        std::random_device rd;
        std::mt19937 mt(rd());
        for (auto &e : model->enemies) {
            std::uniform_real_distribution<double> dist(0, 1000);
            //an enemy can't shoot twice in 2 seconds and has to be on the frontline to shoot
            if (dist(mt) < 1 && e->may_shoot()) {
                model->e_bullets.push_back(std::make_shared<model::Bullet>(e, -0.003));
                view->enemy_bullet_sprites.push_back(std::make_shared<view::Sprite>(view::Sprite::bullet));
                view->enemy_bullet_sprites.back()->entity = model->e_bullets.back();
                model->e_bullets.back()->addObserver(view->enemy_bullet_sprites.back());

                e->last_shot = Stopwatch::Instance()->now();
            }
        }

        //collision detection

        //enemies-playerbullets-shields
        auto enemies_ = model->enemies;
        p_bullets_ = model->p_bullets;
        auto shields_ = model->shields;

        for (const auto &b : p_bullets_) {
            for (auto &e:enemies_) {
                //check whether a bullet hits an enemy
                if (e->collidesWith(*b)) {
                    e->kill();
                    model->enemies.remove(e);

                    e->delegate_frontline(model->enemies);
                    b->kill();
                    model->p_bullets.remove(b);
                }
            }
            for (auto &s:shields_) {
                if (s->collidesWith(*b)) {
                    //remove shield block
                    s->kill();
                    model->shields.remove(s);

                    //remove bullet
                    b->kill();
                    model->p_bullets.remove(b);
                }
            }
        }

        //bullets-player
        e_bullets_ = model->e_bullets;
        shields_ = model->shields;

        for (auto &b : e_bullets_) {
            if (model->player->collidesWith(*b)) {
                model->player->hurt();

                b->kill();
                model->e_bullets.remove(b);
            }
            for (auto &s:shields_) {
                if (s->collidesWith(*b)) {
                    //remove shield block
                    s->kill();
                    model->shields.remove(s);

                    //remove bullet
                    b->kill();
                    model->e_bullets.remove(b);
                }
            }
        }
    }
}
