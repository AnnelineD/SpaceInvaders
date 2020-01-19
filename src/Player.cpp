//
// Created by Anneline Daggelinckx
//

#include "Player.h"
#include "Stopwatch.h"

namespace model{

    Player::Player(int health, float coordx, float coordy, float xSpeed, int shoot_delay)
            : Entity(coordx, coordy, xSpeed, 0, health, .64, .32), shoot_delay(shoot_delay) {}

    bool Player::hurt() {
        health--;
        notify();
        return (health >=1);
    }

    bool Player::may_shoot() {
        return Stopwatch::Instance()->elapsed(last_shot) > shoot_delay;
    }

    bool Player::would_reach_border(float step) {
        return x - width/2 + vx*step <= -4 || x + width/2 + vx*step >= 4;
    }
}
