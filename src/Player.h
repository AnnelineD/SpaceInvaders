//
// Created by Anneline Daggelinckx
//

#ifndef SPACEINVADERS_PLAYER_H
#define SPACEINVADERS_PLAYER_H

#include "Entity.h"
#include "Bullet.h"

namespace model {
    class Player : public Entity {
        int shoot_delay; // delay between shots in ms
    public:
        /**
         * Constructor for loading from file
         * @param health amount of lives
         * @param coordx allows to read in starting position from file in the future
         * @param coordy allows to read in starting position from file in the future
         * @param xSpeed allows to read in horizontal speed from file in the future
         * @param xSpeed allows to read in delay between shots from file in the future
         */
        explicit Player(int health = 3, float coordx = 0, float coordy = -2.5f,
                        float xSpeed = .01, int shoot_delay = 1000);

        /**
         * Decreases the health of the player and notifies its observers
         * @return whether the health is 0 (the player is dead)
         */
        bool hurt();

        /**
         * Check if the player may fire another bullet
         * @return true if enough time has passed
         */
        bool may_shoot();

        /**
         * Check if the player would reach a border given step
         * @param step signed timestep to predict in the future
         * @return true if player would reach a border
         */
        bool would_reach_border(float step);
    };
}


#endif //SPACEINVADERS_PLAYER_H
