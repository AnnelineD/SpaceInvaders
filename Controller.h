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

    void handleEvent(double dt, sf::Event &event);
    void update(double dt);

    std::shared_ptr<View> view;
    std::shared_ptr<Model> model;
};


#endif //SPACEINVADERS_CONTROLLER_H
