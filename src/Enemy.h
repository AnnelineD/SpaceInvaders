//
// Created by Anneline Daggelinckx
//

#ifndef SPACEINVADERS_ENEMY_H
#define SPACEINVADERS_ENEMY_H

#include <list>
#include "Entity.h"
#include "Bullet.h"

namespace model{
    class Enemy : public Entity{
        bool frontline = false;
        int shoot_delay; // delay between shots in ms
    public:
        /**
         * Constructor for loading enemy waves from file.
         * @param coordx initial x coordinate of enemy, should be set to not overlap
         * @param coordy initial y coordinate of enemy, should be set to not overlap
         * @param xSpeed initial x velocity of enemy
         * @param ySpeed initial y velocity of enemy
         * @param health can be read from file in the future
         * @param shoot_delay can be read from file in the future
         */
        explicit Enemy(float coordx, float coordy,
                       float xSpeed, float ySpeed,  bool frontline,
                       int health = 1, int shoot_delay = 1800);

        /**
         * When an enemy dies, it has to pass it's frontline tag to the next in the wave
         * @param enemies in the wave
         */
        void delegate_frontline(std::list<std::shared_ptr<Enemy>> enemies);

        /**
         * Check if enemy is at the vertical borders of the logic playing field
         * @return true if the enemy touches the border
         */
        bool at_border();

        /**
         * Check if enemy may shoot again yet
         * @return true if enough time has past since last fire
         */
        bool may_shoot();
    };
}



#endif //SPACEINVADERS_ENEMY_H
