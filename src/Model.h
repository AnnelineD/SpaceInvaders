//
// Created by Anneline Daggelinckx on 11/27/19.
//

#ifndef SPACEINVADERS_MODEL_H
#define SPACEINVADERS_MODEL_H

#include <list>
#include <memory>
#include <iostream>
#include "../extern/INIReader.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "ShieldBlock.h"

namespace model{
    /**
     * class that holds all game state
     */
    class Model {
    public:
        std::shared_ptr<Player> player;
        std::list<std::shared_ptr<Bullet>> p_bullets;
        std::list<std::shared_ptr<Enemy>> enemies;
        std::list<std::shared_ptr<Bullet>> e_bullets;
        std::list<std::shared_ptr<ShieldBlock>> shields;

        /**
         * load world state from specification file
         * @param filename ini file
         */
        explicit Model(const std::string& filename);

    private:
        void initializeEnemies(int x, int y, float vx, float vy);
        void initializeShields(int n, int length, const std::vector<bool>& form);
        [[nodiscard]] std::tuple<std::vector<bool>, int> parseShieldForm(const std::string& spec) const;
    };
}


#endif //SPACEINVADERS_MODEL_H
