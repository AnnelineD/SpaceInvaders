//
// Created by anneline on 11/27/19.
//

#include "Controller.h"
#include <SFML/Graphics.hpp>

void Controller::handleEvent(float dt, sf::Event &event) {

    //TODO Enemys bewegen
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
                if (view->model->player->coordx < (float)view->window.getSize().x - 20){
                    view->model->player->move(50*dt, 0);
                }
                break;
            case sf::Keyboard::Up:
            case sf::Keyboard::Space:
                view->model->p_bullets.push_back(new Bullet(view->model->player->coordx, view->model->player->coordy));
                break;
        }


}

void Controller::update(float dt) {

    //bullet update
    auto p_bullets_ = view->model->p_bullets;

    for (Bullet* b:p_bullets_){
        b->move(0, -1*dt);
        if(b->coordy < 0){
            view->model->p_bullets.remove(b);
        }
    }

}
