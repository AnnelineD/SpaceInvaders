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
        float vx{}, vy{}; //the speed of the entity

    public:
        float x{}, y{}; //position in the x and y axis
        float width{}, height{}; //width and height of the entity
        std::chrono::time_point<std::chrono::system_clock> last_shot = std::chrono::system_clock::now(); //last time the entity shot
        int health = 1;
        bool frontline = false;

        Entity() = default;
        Entity(float x, float y);
        Entity(float coordx, float coordy, float xSpeed, float ySpeed, int health, float width, float height);

        /**
         * moves the entity according to it's speed and the time that passed
         * @param dt delta-time (the time that passed)
         */
        void move(float dt);

        /**
         * sets the speed of the entity and notifies its observers
         * @param vx horizontal speed
         * @param vy vertical speed
         */
        void setSpeed(float vx, float vy);

        /**
         * changes the sign of the horizontal speed
         */
        void changeDirection();

        /**
         * changes the health of the entity and notifies its observers
         * @param i the health you want the observer to have
         * @return whether the health is 0 (the entity is dead)
         */
        bool setHealth(int i);

        /**
         * checks whether two enemies hit each other
         * @param e
         * @return true if the enemies hit
         */
        [[nodiscard]] bool collidesWith(const Entity& e) const;

    };

}
#endif //SPACEINVADERS_ENTITY_H
