//
// Created by anneline on 11/27/19.
//

#include "Controller.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void Controller::update(float dt, sf::Event &event) {

    //TODO Enemys bewegen
    //TODO Enemys schieten
    //TODO player schiet

        switch (event.key.code){
            case sf::Keyboard::Left:
                view->model->player->move(-10, 0);
                break;

            case sf::Keyboard::Right:
                view->model->player->move(10, 0);
                break;
        }
}
