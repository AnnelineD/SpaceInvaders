//
// Created by ubuntu on 11/23/19.
//

#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H


class Entity {
public:
    Entity(float x, float y);

    float coordx;
    float coordy;

    unsigned int health;

    void move(float dx, float dy);
};


class Player : public Entity{
public:
    Player();
};

class Bullet : public Entity{
public:
    Bullet(float x, float y);
};

/*
class Enemy : private Entity{
public:
    Enemy();

    void move() override;
};
*/





#endif //SPACEINVADERS_ENTITY_H
