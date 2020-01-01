//
// Created by anneline on 11/27/19.
//

#include "Model.h"

namespace model {
    Model::Model(const std::string &filename) {
        INIReader reader(filename);

        if (reader.ParseError() != 0) {
            throw std::invalid_argument("Can't load " + filename + "\n");
        }

        this->player = std::make_shared<Entity>(0, -2.5, .1, 0, 3, .32, .32);
        this->player->health = (int) reader.GetInteger("player", "health", 3);

        int x_enemies = (int) reader.GetInteger("enemies", "enemiesPerRow", 6);
        if (x_enemies > 20) {
            std::cerr << x_enemies << " enemies per row are too much to handle, value is set to 20\n";
            x_enemies = 20;
        }
        int y_enemies = (int) reader.GetInteger("enemies", "numberOfRows", 3);
        if (y_enemies > 6 || y_enemies < 1) {
            std::cerr << "number of enemy rows " << y_enemies << " has to be between 0 and 6, value is set to 3\n";
            y_enemies = 3;
        }
        float vx = reader.GetFloat("enemies", "horizontalSpeed", 1);
        if (vx > 7 || vx <= 0) {
            std::cerr << "invalid horizontal enemy speed (has to be between 0 and 7, value is set to the 1\n";
            vx = 1;
        }
        float vy = reader.GetFloat("enemies", "verticalSpeed", 1);
        if (vy > 5 || vy <= 0) {
            std::cerr << "invalid vertical enemy speed (has to be between 0 and 5, value is set to the 1\n";
            vy = 1;
        }
        initializeEnemies(x_enemies, y_enemies, vx, vy);

        std::string FORM = reader.Get("shields", "form", "_########_/##########/##______##/##______##");
        int n_shields = (int) reader.GetInteger("shields", "number", 4);

        std::tuple<std::vector<bool>, int> p;

        try{
            p = parseShieldForm(FORM);
        }
        catch (std::exception &e){
            std::cerr << e.what() << ", default shield form is used" << std::endl;
            p = parseShieldForm("_########_/##########/##______##/##______##");
        }

        auto [form, length] = p;

        if(length * n_shields > 60){
            std::cerr << "too many or too big shields, default shields are used\n";
            p = parseShieldForm("_########_/##########/##______##/##______##");
            form = std::get<0>(p);
            length = std::get<1>(p);

            n_shields = 4;
        }

        initializeShields(n_shields, length, form);
    }

    void Model::initializeEnemies(int x, int y, float vx, float vy) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                std::tuple<float, float> c = Transformation::Instance()->toLogic({i * 50, j * 50 + 50});
                this->enemies.push_back(std::make_shared<Entity>(std::get<0>(c), std::get<1>(c), vx * .0002, vy * (-.00003), 1, .16, .32));
            }
            this->enemies.back()->frontline = true;
        }
    }

    void Model::initializeShields(int n_shields, int length, std::vector<bool> form) {
        for (int n = 0; n < n_shields; n++) {
            for (int i = 0; (long)i < form.size() / length; i++) {
                for (int j = 0; j < length; j++) {
                    if (form[i * length + j]) {
                        this->shields.push_back(std::make_shared<Entity>(
                                -3.5 + j * 0.1 + n * (length * .1 + (7 - n_shields * 0.1 * length) / (n_shields - 1)),
                                -1 + i * -0.1, 0, 0, 1, .1, .1));
                    }
                }
            }
        }
    }

    std::tuple<std::vector<bool>, int> Model::parseShieldForm(const std::string& spec) {
        std::vector<bool> form;
        int length = -1;
        int l = 0;

        for (auto c: spec) {
            switch (c) {
                case '_':
                    form.push_back(false);
                    break;
                case 'X':
                case '#':
                    form.push_back(true);
                    break;
                case '/':

                    if(length != -1 && l != length){
                        throw std::invalid_argument("invalid shield form");
                    }
                    length = l;
                    l = 0;
                    continue;
                default: //TODO exception
                    continue;
            }

            l ++;
        }

        return {form, length};
    }
}
