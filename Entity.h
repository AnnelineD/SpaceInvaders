//
// Created by ubuntu on 11/23/19.
//

#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H


class Entity {

public:
    float coordx;
    float coordy;

    unsigned int health;

    void move(float dx, float dy);
};


class Player : public Entity{
public:
    Player();

};

/*
class Enemy : private Entity{
public:
    Enemy();

    void move() override;
};
*/





#endif //SPACEINVADERS_ENTITY_H
