//
// Created by ubuntu on 11/23/19.
//

#include "Entity.h"

Entity::Entity(float x, float y): coordx(x), coordy(y) {}

Player::Player(): Entity(0, 0) {}

Bullet::Bullet(float x, float y): Entity(x, y) {
    width = 5;
    height = 10;
}

Enemy::Enemy(float x, float y): Entity(x, y) {
    width = 20;
    height = 20;
}

void Entity::move(float dx, float dy) {
    this->coordx += dx;
    this->coordy += dy;
}

void Entity::move(float dt){
    this->coordx += dt*this->x_speed;
    this->coordy += dt*this->y_speed;
}

void Entity::setSpeed(float vx, float vy) {
    this->x_speed = vx;
    this->y_speed = vy;
}

void Entity::changeDirection() {
    this->x_speed = -this->x_speed;
}

bool Entity::collidesWith(const Entity &e) const {
    return (this->coordx < e.coordx + e.width &&
       this->coordx + this->width > e.coordx &&
       this->coordy < e.coordy + e.height &&
       this->coordy + this->height > e.coordy);
}