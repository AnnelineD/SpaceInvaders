//
// Created by ubuntu on 11/23/19.
//

#include "Entity.h"

namespace model{
    Entity::Entity(float x, float y): x(x), y(y) {}

    Entity::Entity(float coordx, float coordy, float width, float height, int health, float xSpeed, float ySpeed) : x(
            coordx), y(coordy), width(width), height(height), health(health), vx(xSpeed), vy(ySpeed) {}


    Player::Player(float coordx, float coordy, float width, float height, int health, float xSpeed, float ySpeed) : Entity(
            coordx, coordy, width, height, health, xSpeed, ySpeed) {}

    Bullet::Bullet(float x, float y): Entity(x, y) {
        width = .05;
        height = .10;
    }

    Enemy::Enemy(float coordx, float coordy, float width, float height, int health, float xSpeed, float ySpeed) : Entity(
            coordx, coordy, width, height, health, xSpeed, ySpeed) {}


    void Entity::move(float dt){
        this->x += dt * this->vx;
        this->y += dt * this->vy;
        notify();
    }

    void Entity::setSpeed(float vx, float vy) {
        this->vx = vx;
        this->vy = vy;
    }

    void Entity::changeDirection() {
        this->vx = -this->vx;
    }

    bool Entity::collidesWith(const Entity &e) const {
        return (this->x < e.x + e.width &&
                this->x + this->width > e.x &&
                this->y < e.y + e.height &&
                this->y + this->height > e.y);
    }

    bool Entity::setHealth(int i) {
        this->health = i;
        notify();
        return (health >=1);
    }

    ShieldBlock::ShieldBlock(float x, float y): Entity(x, y) {
        this->width = .1;
        this->height = .1;
    }
}