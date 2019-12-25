//
// Created by ubuntu on 11/23/19.
//

#include "Entity.h"

Entity::Entity(float x, float y): coordx(x), coordy(y) {}

Entity::Entity(float coordx, float coordy, float width, float height, int health, float xSpeed, float ySpeed) : coordx(
        coordx), coordy(coordy), width(width), height(height), health(health), x_speed(xSpeed), y_speed(ySpeed) {}


/*
Player::Player(): Entity(0, 0) {
    width = 32;
    height = 32;
    this->health = 3;
}
 */

Player::Player(float coordx, float coordy, float width, float height, int health, float xSpeed, float ySpeed) : Entity(
        coordx, coordy, width, height, health, xSpeed, ySpeed) {}

Bullet::Bullet(float x, float y): Entity(x, y) {
    width = 5;
    height = 10;
}

Enemy::Enemy(float coordx, float coordy, float width, float height, int health, float xSpeed, float ySpeed) : Entity(
        coordx, coordy, width, height, health, xSpeed, ySpeed) {}

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