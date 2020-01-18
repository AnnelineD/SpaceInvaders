//
// Created by Anneline Daggelinckx
//

#ifndef SPACEINVADERS_PLAYER_H
#define SPACEINVADERS_PLAYER_H

#include "Entity.h"

namespace model {
    class Player : public Entity {
    public:
        explicit Player(float coordx = 0, float coordy = -2.5,
                        float xSpeed = .01, float ySpeed = 0,
                        int health = 3,
                        float width = .64,
                        float height = .32);
    };
}


#endif //SPACEINVADERS_PLAYER_H
