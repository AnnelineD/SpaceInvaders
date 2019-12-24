//
// Created by ubuntu on 11/23/19.
//

#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H

#include <chrono>
#include "Subject.h"


class Entity: public Subject {
public:
    Entity() = default;
    Entity(float x, float y);

    float coordx, coordy;
    float width, height;
    std::chrono::time_point<std::chrono::system_clock> last_shot = std::chrono::system_clock::now();
    int health = 1;

    //TODO delete this function
    void move(float dx, float dy);

    void move(float dt);
    void setSpeed(float vx, float vy);
    void changeDirection();
    bool setHealth(int i);

    [[nodiscard]] bool collidesWith(const Entity& e) const;

private:
    float x_speed, y_speed;
};


class Player : public Entity{
public:
    Player();
};

class Bullet : public Entity{
public:
    Bullet(float x, float y);
};

class Enemy : public Entity{
public:
    Enemy(float x, float y);
    bool frontline = false;
};


#endif //SPACEINVADERS_ENTITY_H
