//
// Created by anneline on 11/27/19.
//

#include "Controller.h"
#include "Stopwatch.h"
#include <SFML/Graphics.hpp>

void Controller::handleEvent(double dt, sf::Event &event) {

    //TODO Enemys schieten
    //TODO player schiet

    //move player
        switch (event.key.code){
            case sf::Keyboard::Left:
                if (view->model->player->coordx > 10) {
                    view->model->player->move(-50*dt, 0);
                }
                break;
            case sf::Keyboard::Right:
                //check that player doesn't go out of view before moving
                if (view->model->player->coordx < (float)view->window.getSize().x - 20){
                    view->model->player->move(50*dt, 0);
                }
                break;
            case sf::Keyboard::Up:
            case sf::Keyboard::Space:
                //TODO check time between shoots so that player does't have a machine gun
                if(Stopwatch::Instance()->elapsed(view->model->player->last_shot) > 600){
                    view->model->p_bullets.push_back(new Bullet(view->model->player->coordx, view->model->player->coordy));
                    view->model->player->last_shot = Stopwatch::Instance()->now();
                }
                break;
        }
}

void Controller::update(double dt) {

    //bullet update
    auto p_bullets_ = view->model->p_bullets;

    for (Bullet* b:p_bullets_){
        b->move(0, -1*dt);
        if(b->coordy < 0){
            view->model->p_bullets.remove(b);
        }
    }

    //enemy movement
    if(view->model->enemies.empty()){
        return;
    }
    bool change_direction = view->model->enemies.back()->coordx > view->window.getSize().x || view->model->enemies.front()->coordx < 0;

    for (auto e:view->model->enemies){
        if(change_direction){
            e -> changeDirection();
        }
        e -> move(dt);
    }

    auto enemies_ = view->model->enemies;
    p_bullets_ = view->model->p_bullets;

    //collision detection
    for (auto e:enemies_){
        for (auto b : p_bullets_){
            if(e->collidesWith(*b)){
                view->model->enemies.remove(e);
                view->model->p_bullets.remove(b);
            }
        }
    }
}
