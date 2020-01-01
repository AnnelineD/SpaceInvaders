//
// Created by anneline on 11/27/19.
//

#ifndef SPACEINVADERS_MODEL_H
#define SPACEINVADERS_MODEL_H

#include "Entity.h"
#include <list>
#include <memory>
#include <iostream>
#include "INIReader.h"

namespace model{
    class Model {
    public:
        std::shared_ptr<Entity> player;
        std::list<std::shared_ptr<Entity>> p_bullets;
        std::list<std::shared_ptr<Entity>> enemies;
        std::list<std::shared_ptr<Entity>> e_bullets;
        std::list<std::shared_ptr<Entity>> shields;

        //constructor
        explicit Model(const std::string& filename);

    private:
        void initializeEnemies(int x, int y, float vx, float vy);
        void initializeShields(int n, int length, std::vector<bool> form);
        std::tuple<std::vector<bool>, int> parseShieldForm(const std::string& spec);
    };
}


#endif //SPACEINVADERS_MODEL_H
