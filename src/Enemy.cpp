//
// Created by Anneline Daggelinckx
//

#include "Enemy.h"

namespace model {
    Enemy::Enemy(float coordx, float coordy, float xSpeed, float ySpeed, int health, float width, float height)
            : Entity(coordx, coordy, xSpeed, ySpeed, health, width, height) {}
}
