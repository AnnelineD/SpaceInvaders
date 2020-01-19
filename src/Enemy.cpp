//
// Created by Anneline Daggelinckx
//

#include "Enemy.h"
#include "Stopwatch.h"

namespace model {
    Enemy::Enemy(float coordx, float coordy, float xSpeed, float ySpeed, bool frontline, int health, int shoot_delay)
            : Entity(coordx, coordy, xSpeed, ySpeed, health, 0.16, 0.32), frontline(frontline), shoot_delay(shoot_delay) {}

    void Enemy::delegate_frontline(std::list<std::shared_ptr<Enemy>> enemies) {
        //reverse iteration to select first candidate
        for (auto it = enemies.rbegin(); it != enemies.rend(); ++it) {
            if ((*it)->x == x) {
                (*it)->frontline = true;
                break;
            }
        }
    }

    bool Enemy::at_border() {
        return x + width/2 >= 4 || x - width/2 <= -4;
    }

    bool Enemy::may_shoot() {
        return frontline && Stopwatch::Instance()->elapsed(last_shot) > shoot_delay;
    }
}
