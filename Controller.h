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

    void update(float dt, sf::Event &event);

    View* view;
};


#endif //SPACEINVADERS_CONTROLLER_H
