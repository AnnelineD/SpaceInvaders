//
// Created by Anneline Daggelinckx
//

#include "Bullet.h"

namespace model {
    Bullet::Bullet(float coordx, float coordy, float xSpeed, float ySpeed, int health, float width, float height)
            : Entity(coordx, coordy, xSpeed, ySpeed, health, width, height) {}
}