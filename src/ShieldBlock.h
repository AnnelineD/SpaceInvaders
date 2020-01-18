//
// Created by Anneline Daggelinckx
//

#ifndef SPACEINVADERS_SHIELDBLOCK_H
#define SPACEINVADERS_SHIELDBLOCK_H

#include "Entity.h"

namespace model{
    class ShieldBlock : public Entity {
    public:
        explicit ShieldBlock(float coordx = 0, float coordy = 0,
                       float xSpeed = 0, float ySpeed = 0,
                       int health = 1,
                       float width = 0.1, float height = 0.1);
    };
}



#endif //SPACEINVADERS_SHIELDBLOCK_H
