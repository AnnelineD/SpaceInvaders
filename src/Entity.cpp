//
// Created by Anneline Daggelinckx on 11/23/19.
//

#include "Entity.h"

namespace model{

    Entity::Entity(float coordx, float coordy, float xSpeed, float ySpeed, int health, float width, float height) : x(
            coordx), y(coordy), vx(xSpeed), vy(ySpeed), health(health), width(width), height(height) {}

    void Entity::move(float dt){
        x += dt * vx;
        y += dt * vy;
        notify();
    }

    void Entity::changeDirection() {
        vx = -vx;
    }

    bool Entity::collidesWith(const Entity &e) const {
        return (x - width/2 < e.x + e.width/2 &&
                x + width/2 > e.x - e.width/2 &&
                y < e.y + e.height &&
                y + height > e.y);
    }

    void Entity::kill() {
        health = 0;
        notify();
    }
}