//
// Created by ubuntu on 11/23/19.
//

#include "Entity.h"

Entity::Entity(float x, float y): coordx(x), coordy(y) {}

Player::Player(): Entity(0, 0) {}

Bullet::Bullet(float x, float y): Entity(x, y) {}

void Entity::move(float dx, float dy) {
    this->coordx += dx;
    this->coordy += dy;
}