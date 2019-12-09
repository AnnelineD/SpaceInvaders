//
// Created by ubuntu on 11/23/19.
//

#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H

#include <chrono>


class Entity {
public:
    Entity(float x, float y);

    float coordx, coordy;
    unsigned int health;
    float width, height;
    std::chrono::time_point<std::chrono::system_clock> last_shot = std::chrono::system_clock::now();

    void move(float dx, float dy);
    void move(float dt);
    void setSpeed(float vx, float vy);
    void changeDirection();

    bool collidesWith(const Entity& e) const;

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
};



#endif //SPACEINVADERS_ENTITY_H
