//
// Created by Anneline Daggelinckx
//

#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H

#include "Entity.h"

namespace model{
    class Bullet : public Entity {
    public:
        explicit Bullet(float coordx = 0, float coordy = 0,
                        float xSpeed = 0, float ySpeed = -0.003,
                        int health = 1,
                        float width = 0.05, float height = 0.1);
    };
}



#endif //SPACEINVADERS_BULLET_H
