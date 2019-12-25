//
// Created by anneline on 11/27/19.
//

#include "Model.h"

#include <utility>

Model::Model(const std::string& filename) {
    INIReader reader(filename);

    if (reader.ParseError() != 0) {
        std::cout << "Can't load 'test.ini'\n";
        //TODO exception
    }

    this->player =  std::make_shared<Player>();
    this->player->health = (int)reader.GetInteger("player", "health", 3);
}
