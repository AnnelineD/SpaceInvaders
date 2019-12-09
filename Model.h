//
// Created by anneline on 11/27/19.
//

#ifndef SPACEINVADERS_MODEL_H
#define SPACEINVADERS_MODEL_H

#include "Entity.h"
#include <list>
#include <vector>
#include <memory>


class Model {
public:
    Player* player;
    std::list<Bullet*> p_bullets;
    std::list<Enemy*> enemies;
    std::list<Bullet*> e_bullets;
};


#endif //SPACEINVADERS_MODEL_H
