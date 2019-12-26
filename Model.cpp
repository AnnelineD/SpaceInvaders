//
// Created by anneline on 11/27/19.
//

#include "Model.h"


Model::Model(const std::string& filename) {
    INIReader reader(filename);

    if (reader.ParseError() != 0) {
        throw std::invalid_argument("Can't load " + filename + "\n");
    }

    this->player =  std::make_shared<Player>();
    this->player->health = (int)reader.GetInteger("player", "health", 3);

    int x_enemies = (int)reader.GetInteger("enemies", "enemiesPerRow", 6);
    if(x_enemies > 20){
        std::cerr << x_enemies << "enemies per row are too much to handle, value is set to 20";
        x_enemies = 20;
    }
    int y_enemies = (int)reader.GetInteger("enemies", "numberOfRows", 3);
    if(y_enemies > 6){
        std::cerr << y_enemies << "rows of enemies are too much to handle, value is set to the maximum rows 6";
        y_enemies = 6;
    }
    float vx = reader.GetFloat("enemies", "horizontalSpeed", 1);
    if(vx > 7){
        std::cerr << "Your enemies are going too fast, value is set to the maximum speed 7";
        vx = 7;
    }
    float vy = reader.GetFloat("enemies", "verticalSpeed", 1);
    if(vy > 5){
        std::cerr << "Your enemies are coming down too fast, value is set to the maximum speed 5";
        vy = 5;
    }
    initializeEnemies(x_enemies, y_enemies, vx, vy);

    std::string FORM = reader.Get("shields", "form", " ######## /##########/##      ##/##      ##");
    int n_shields = (int)reader.GetInteger("shields", "number", 4);
    initializeShields(n_shields, 16, parseShieldForm(FORM));
}

void Model::initializeEnemies(int x, int y, float vx, float vy) {
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            std::tuple<float, float> c = Transformation::Instance()->toLogic({i * 50, j * 50 + 50});
            this->enemies.push_back(std::make_shared<Enemy>(std::get<0>(c), std::get<1>(c)));
            this->enemies.back()->setSpeed(vx * .0002, vy * (-.00003));
        }
        this->enemies.back()->frontline = true;
    }
}

void Model::initializeShields(int n_shields, int length, std::vector<bool> form) {
    for(int n = 0; n < n_shields; n++){
        for (int i = 0; i < form.size()/length; i++) {
            for (int j = 0; j < length; j++){
                if (form[i*length + j]){
                    this->shields.push_back(std::make_shared<ShieldBlock>(-3.5 + j*0.1 + n*(length*.1 + (7 - n_shields*0.1*length)/(n_shields-1)), -1 + i*0.1));
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
