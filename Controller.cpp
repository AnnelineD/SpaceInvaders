//
// Created by anneline on 11/27/19.
//

#include "Controller.h"
#include "Stopwatch.h"
#include <SFML/Graphics.hpp>
#include <random>

void Controller::handleEvent(double dt, sf::Event &event) {

    //TODO Enemys schieten
    //TODO player schiet

    //move player
        switch (event.key.code){
            case sf::Keyboard::Left:
                if (model->player->coordx -50*dt > 10) {
                    model->player->move(-50*dt, 0);
                }
                break;
            case sf::Keyboard::Right:
                //check that player doesn't go out of view before moving
                if (model->player->coordx + 50*dt < (float)view->window.getSize().x - 20){
                    model->player->move(dt);
                }
                break;
            case sf::Keyboard::Up:
            case sf::Keyboard::Space:
                // check time between shoots so that player does't have a machine gun
                if(Stopwatch::Instance()->elapsed(model->player->last_shot) > 400){
                    model->p_bullets.push_back(std::make_shared<Bullet>(model->player->coordx, model->player->coordy));
                    view->p_bullet_sprite.push_back(std::make_shared<BulletSprite>());
                    view->p_bullet_sprite.back()->entity = model->p_bullets.back();
                    model->p_bullets.back()->addObserver(view->p_bullet_sprite.back());

                    model->player->last_shot = Stopwatch::Instance()->now();
                }
                break;
        }
}

void Controller::update(double dt) {
    //player bullet render
    auto p_bullets_ = model->p_bullets;

    for (auto b:p_bullets_){
        b->move(0, -1*dt);
        //bullet is removed when it is out of the screen
        if(b->coordy < 0){
            b->setHealth(0);
            model->p_bullets.remove(b);
        }
    }

    //enemy bullet render
    auto e_bullets_ = model->e_bullets;

    for (auto b:e_bullets_){
        b->move(0, .7*dt);
        //bullet is removed when it is out of the screen
        if(b->coordy > view->window.getSize().y){
            b->setHealth(0);
            model->e_bullets.remove(b);
        }
    }

    //enemy movement
    //only do the enemy movement and shoot when there are enemies
    if(model->enemies.empty()){
        return;
    }

    //the "enemy block" changes direction when the most left of right enemies hit the side of the screen
    bool change_direction = model->enemies.back()->coordx > view->window.getSize().x || model->enemies.front()->coordx < 0;

    for (auto& e:model->enemies){
        if(change_direction){
            e->changeDirection();
        }
        e->move(dt);
    }

    //enemy shoot
    std::random_device rd;
    std::mt19937 mt(rd());
    for(auto& e : model->enemies){
        std::uniform_real_distribution<double> dist(0, 4000);
        //an enemy can't shoot twice in 0.4 seconds and has to be on the frontline
        if(dist(mt) < 1 && Stopwatch::Instance()->elapsed(e->last_shot) > 3000 && e->frontline){
                model->e_bullets.push_back(std::make_shared<Bullet>(e->coordx, e->coordy));
                view->e_bullet_sprite.push_back(std::make_shared<BulletSprite>());
                view->e_bullet_sprite.back()->entity = model->e_bullets.back();
                model->e_bullets.back()->addObserver(view->e_bullet_sprite.back());

                e->last_shot = Stopwatch::Instance()->now();
        }
    }

    //collision detection
    auto enemies_ = model->enemies;
    p_bullets_ = model->p_bullets;

    for (auto& e:enemies_){
        for (auto b : p_bullets_){
            //check whether a bullet hits an enemy
            if(e->collidesWith(*b)){
                double x = e->coordx;
                e->setHealth(0);
                model->enemies.remove(e);
                //reverse iteration
                for (auto it = model->enemies.rbegin(); it != model->enemies.rend(); ++it){
                    if((*it)->coordx == x){
                        (*it)->frontline = true;
                        break;
                    }
                }
                b->setHealth(0);
                model->p_bullets.remove(b);
            }
        }
    }

    e_bullets_ = model->e_bullets;

    for (auto& b : e_bullets_){
        if(model->player->collidesWith(*b)){
            model->player->setHealth(model->player->health - 1);
            b->setHealth(0);
            model->e_bullets.remove(b);
        }
    }
}
