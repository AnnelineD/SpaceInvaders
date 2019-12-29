//
// Created by ubuntu on 11/23/19.
//

#ifndef SPACEINVADERS_SPACEINVADERSGAME_H
#define SPACEINVADERS_SPACEINVADERSGAME_H

#include <memory>
#include <string>
#include "Model.h"
#include "View.h"
#include "Controller.h"


class SpaceInvadersGame {
    std::shared_ptr<model::Model> model;
    std::shared_ptr<view::View> view;
    Controller controller;

public:
    explicit SpaceInvadersGame(const std::string& filename);
    void start();
};


#endif //SPACEINVADERS_SPACEINVADERSGAME_H
