//
// Created by anneline on 11/27/19.
//

#ifndef SPACEINVADERS_CONTROLLER_H
#define SPACEINVADERS_CONTROLLER_H

#include "Entity.h"
#include "Model.h"
#include "View.h"

class Controller {
public:

    void handleEvent(float dt, sf::Event &event);
    void update(float dt);

    std::shared_ptr<view::View> view;
    std::shared_ptr<model::Model> model;
};


#endif //SPACEINVADERS_CONTROLLER_H
