//
// Created by ubuntu on 11/23/19.
//

#include "Entity.h"

Entity::Entity(float x, float y): coordx(x), coordy(y) {}

Player::Player(): Entity(0, 0) {
    width = 32;
    height = 32;
    this->health = 1;
}

Bullet::Bullet(float x, float y): Entity(x, y) {
    width = 5;
    height = 10;
}

Enemy::Enemy(float x, float y): Entity(x, y) {
    width = 16;
    height = 32;
}

void Entity::move(float dx, float dy) {
    this->coordx += dx;
    this->coordy += dy;
    notify();
}

void Entity::move(float dt){
    this->coordx += dt*this->x_speed;
    this->coordy += dt*this->y_speed;
    notify();
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

bool Entity::setHealth(int i) {
    this->health = i;
    notify();
    return (health >=1);
}

ShieldBlock::ShieldBlock(float x, float y): Entity(x, y) {
    this->width = 10;
    this->height = 10;
}