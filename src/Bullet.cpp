//
// Created by Anneline Daggelinckx
//

#include "Bullet.h"

namespace model {
    Bullet::Bullet(const std::shared_ptr<Entity>& who_fires, float ySpeed)
            : Entity(who_fires->x, who_fires->y, 0, ySpeed, 1, 0.05, 0.1) {}

    bool Bullet::at_border() {
        return y + height/2 >= 3 || y - height/2 <= -3;
    }
}