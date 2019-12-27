//
// Created by ubuntu on 11/23/19.
//

#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H

#include <chrono>
#include "Subject.h"
#include "Transformation.h"


class Entity: public Subject {
public:
    Entity() = default;
    Entity(float x, float y);
    Entity(float coordx, float coordy, float width, float height, int health, float xSpeed, float ySpeed);

    float coordx, coordy;
    float width, height;
    std::chrono::time_point<std::chrono::system_clock> last_shot = std::chrono::system_clock::now();
    int health = 1;

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
    /*
    Player();
     */
    Player(float coordx = 0, float coordy = -2.5,
            float width = .32,
            float height = .32,
            int health = 3, float xSpeed = .1, float ySpeed = 0);
};

class Bullet : public Entity{
public:
    Bullet(float x, float y);
};

class Enemy : public Entity{
public:
    //Enemy(float x, float y);
    explicit Enemy(float coordx = 0, float coordy = 0,
                   float width = 0.16,
                   float height = 0.32,
                   int health = 1, float xSpeed = .002, float ySpeed = .0001);
    bool frontline = false;
};

class ShieldBlock : public Entity{
public:
    ShieldBlock(float x, float y);
};

#endif //SPACEINVADERS_ENTITY_H
