//
// Created by Anneline Daggelinckx
//

#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H

#include "Entity.h"

namespace model{
    class Bullet : public Entity {
    public:
        /**
         * Bullets are always spawned from another entity: a player or an enemy
         * with a certain signed speed
         * @param who_fires
         * @param ySpeed
         */
        explicit Bullet(const std::shared_ptr<Entity>& who_fires, float ySpeed);

        /**
         * Check if bullet is currently at top/bottom border (and should be destroyed)
         * @return true if bullet at logic playing field border
         */
        bool at_border();
    };
}



#endif //SPACEINVADERS_BULLET_H
