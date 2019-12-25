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

    int x_enemies = (int)reader.GetInteger("enemies", "enemiesPerRow", 6);
    int y_enemies = (int)reader.GetInteger("enemies", "numberOfRows", 6);
    float vx = reader.GetFloat("enemies", "horizontalSpeed", 1);
    float vy = reader.GetFloat("enemies", "verticalSpeed", 1);

    initializeEnemies(x_enemies, y_enemies, vx, vy);

    std::string FORM = reader.Get("shields", "form", "######## /##########/##      ##/##      ##");


    std::vector<bool> test = parseShieldForm(FORM);

    int n_shields = (int)reader.GetInteger("shields", "number", 4);

    initializeShields(n_shields, 16, test);
}

void Model::initializeEnemies(int x, int y, float vx, float vy) {
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            this->enemies.push_back(std::make_shared<Enemy>(i * 50, j * 50 + 50));
            this->enemies.back()->setSpeed(vx * .06, vy * .003);
        }
        this->enemies.back()->frontline = true;
    }
}

void Model::initializeShields(int n_shields, int length, std::vector<bool> form) {
    for(int n = 0; n < n_shields; n++){
        for (int i = 0; i < form.size()/length; i++) {
            for (int j = 0; j < length; j++){
                if (form[i*length + j]){
                    this->shields.push_back(std::make_shared<ShieldBlock>(50 + j*10 + n*200, 350 + i*10));
                }
            }
        }
    }
}

std::vector<bool> Model::parseShieldForm(std::string spec) {
    std::vector<bool> form;
    for(auto c: spec){
        switch (c){
            case ' ': form.push_back(false);
                break;
            case 'X':
            case '#':
                form.push_back(true);
                break;
            case '/':
                break;
            default: //TODO exception
                break;
        }
    }

    return form;
}
