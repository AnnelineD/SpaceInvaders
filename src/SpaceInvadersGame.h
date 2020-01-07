//
// Created by Anneline Daggelinckx on 11/23/19.
//

#ifndef SPACEINVADERS_SPACEINVADERSGAME_H
#define SPACEINVADERS_SPACEINVADERSGAME_H

#include <memory>
#include <string>
#include "Model.h"
#include "View.h"
#include "Controller.h"

/**
 * represents the game and contains MVC
 */
class SpaceInvadersGame {
    std::shared_ptr<model::Model> model;
    std::shared_ptr<view::View> view;
    controller::Controller controller;
    std::list<std::shared_ptr<model::Model>> levels;
    /**
     * Replaces model and controller for new level, cleans up view sprites
     */
    void loadNextLevel();
public:
    SpaceInvadersGame() = default;
    /**
     * load a level file to play the game with
     * @param filename an ini file
     */
    void load(const std::vector<std::string>& filenames);

    /**
     * holds the gameloop
     */
    void start();
};


#endif //SPACEINVADERS_SPACEINVADERSGAME_H
