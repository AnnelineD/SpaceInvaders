//
// Created by Anneline Daggelinckx on 11/23/19.
//

#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H

#include <chrono>
#include "Subject.h"
#include "Transformation.h"


namespace model {
/**
 * this class represents the entities of the game (player, enemy, bullet, shieldblock)
 */
    class Entity: public Subject {
    public:
        float x{}, y{}; //position in the x and y axis
        float vx{}, vy{}; //the speed of the entity
        int health = 1;
        float width{}, height{}; //width and height of the entity
        std::chrono::time_point<std::chrono::system_clock> last_shot = std::chrono::system_clock::now(); //last time the entity shot

        /**
         * moves the entity according to it's speed and the time that passed
         * @param dt delta-time (the time that passed)
         */
        void move(float dt);

        /**
         * changes the sign of the horizontal speed
         */
        void changeDirection();

        /**
         * sets the health of the entity to 0 and notifies its observers
         */
        void kill();

        /**
         * checks whether two enemies hit each other
         * @param e
         * @return true if the enemies hit
         */
        [[nodiscard]] bool collidesWith(const Entity& e) const;

    protected:
        Entity(float coordx, float coordy, float xSpeed, float ySpeed, int health, float width, float height);
    };
}
#endif //SPACEINVADERS_ENTITY_H
