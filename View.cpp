//
// Created by anneline on 11/27/19.
//

#include "View.h"
#include <iostream>

View::View() : window(sf::VideoMode(500, 500), "Protect your planet!"){}

View::View(int width, int height) : window(sf::VideoMode(width, height), "Protect your planet!") {}

void View::render() {
    sf::RectangleShape shape(sf::Vector2f(20, 20));
    shape.setFillColor(sf::Color::Green);

        shape.setPosition(this->model->player->coordx, this->model->player->coordy);

        this->window.clear();
        this->window.draw(shape);
        this->window.display();

}