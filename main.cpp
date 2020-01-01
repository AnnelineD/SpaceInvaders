#include <iostream>
#include "SpaceInvadersGame.h"


int main() {

    SpaceInvadersGame game;

    try{
        game.load("../testLevel2.ini");
    }
    catch (std::exception &e) {
        std::cerr << "Fatal error occured: " << e.what() << std::endl << "exiting...";
        return -1;
    }

    game.start();

    return 0;
}