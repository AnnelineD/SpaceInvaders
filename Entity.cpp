//
// Created by Anneline Daggelinckx on 11/23/19.
//

#include "Entity.h"

namespace model{
    Entity::Entity(float x, float y): x(x), y(y) {}

    Entity::Entity(float coordx, float coordy, float xSpeed, float ySpeed, int health, float width, float height) : x(
            coordx), y(coordy), vx(xSpeed), vy(ySpeed), health(health), width(width), height(height) {}

    void Entity::move(float dt){
        x += dt * vx;
        y += dt * vy;
        notify();
    }

    void Entity::setSpeed(float vx, float vy) {
        vx = vx;
        vy = vy;
    }

    void Entity::changeDirection() {
        vx = -vx;
    }

    bool Entity::collidesWith(const Entity &e) const {
        return (x < e.x + e.width &&
                x + width > e.x &&
                y < e.y + e.height &&
                y + height > e.y);
    }

    bool Entity::setHealth(int i) {
        health = i;
        notify();
        return (health >=1);
    }
}