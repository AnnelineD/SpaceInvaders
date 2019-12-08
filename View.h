//
// Created by anneline on 11/27/19.
//

#ifndef SPACEINVADERS_VIEW_H
#define SPACEINVADERS_VIEW_H

#include <SFML/Graphics.hpp>
#include "Model.h"
#include <memory>


class View {
public:
    View();
    View(int width, int height);
    void render();

    sf::RenderWindow window;
    sf::Texture texture;

    Model* model;
};


#endif //SPACEINVADERS_VIEW_H
