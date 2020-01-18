//
// Created by Anneline Daggelinckx
//

#ifndef SPACEINVADERS_ENEMY_H
#define SPACEINVADERS_ENEMY_H


#include "Entity.h"

namespace model{
    class Enemy : public Entity{
    public:
        explicit Enemy(float coordx = 0, float coordy = 0,
                       float xSpeed = .002, float ySpeed = .0001,
                       int health = 1,
                       float width = 0.16, float height = 0.32);
        bool frontline = false;
    };
}



#endif //SPACEINVADERS_ENEMY_H
