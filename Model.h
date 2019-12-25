//
// Created by anneline on 11/27/19.
//

#ifndef SPACEINVADERS_MODEL_H
#define SPACEINVADERS_MODEL_H

#include "Subject.h"
#include "Entity.h"
#include <list>
#include <vector>
#include <memory>


class Model : public Subject {
public:
    std::shared_ptr<Player> player;
    std::list<std::shared_ptr<Bullet>> p_bullets;
    std::list<std::shared_ptr<Enemy>> enemies;
    std::list<std::shared_ptr<Bullet>> e_bullets;
    std::list<std::shared_ptr<ShieldBlock>> shields;

    ~Model() override = default;
};


#endif //SPACEINVADERS_MODEL_H
