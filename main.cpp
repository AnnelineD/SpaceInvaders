#include <iostream>
#include "SpaceInvadersGame.h"


int main(int argc, char* argv[]) {
    SpaceInvadersGame game;

    try{
        // arv + 1, not interested in first argument as it is the executable
        game.load(std::vector<std::string> { argv + 1, argv + argc });
    }
    catch (std::exception &e) {
        std::cerr << "Fatal error occured: " << e.what() << std::endl << "exiting...\n";
        return 1;
    }

    game.start();

    return 0;
}