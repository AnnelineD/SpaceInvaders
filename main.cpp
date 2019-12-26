#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

#include "View.h"
#include "Controller.h"
#include "Stopwatch.h"
#include "SpaceInvadersGame.h"


int main() {
    SpaceInvadersGame game("../testLevel.ini");
    game.start();

    return 0;
}