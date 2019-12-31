//
// Created by Anneline Daggelinckx on 11/23/19.
//

#include "Entity.h"

namespace model{
    Entity::Entity(float x, float y): x(x), y(y) {}

    Entity::Entity(float coordx, float coordy, float xSpeed, float ySpeed, int health, float width, float height) : x(
            coordx), y(coordy), vx(xSpeed), vy(ySpeed), health(health), width(width), height(height) {}

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
}