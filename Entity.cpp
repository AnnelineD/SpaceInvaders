//
// Created by ubuntu on 11/23/19.
//

#include "Entity.h"

Player::Player() {
    this->coordx = 0;
    this->coordy = 0;
}

Bullet::Bullet() {
    this->coordx = 0;
    this->coordy = 0;
}

void Entity::move(float dx, float dy) {
    this->coordx += dx;
    this->coordy += dy;
}