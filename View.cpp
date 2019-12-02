//
// Created by anneline on 11/27/19.
//

#include "View.h"
#include <iostream>

View::View() : window(sf::VideoMode(500, 500), "Protect your planet!"){}

View::View(int width, int height) : window(sf::VideoMode(width, height), "Protect Mars against humans!") {}

void View::render() {
    //player
    sf::RectangleShape player(sf::Vector2f(20, 20));

    //Mars
    sf::CircleShape Mars(this->window.getSize().x, 100);
    Mars.setFillColor(sf::Color::Red);
    Mars.setPosition(0, (float)this->window.getSize().y/2);

    //Bullets
    sf::RectangleShape bullet(sf::Vector2f(5, 10));
    bullet.setFillColor(sf::Color::White);


    player.setFillColor(sf::Color::Green);

    player.setPosition(this->model->player->coordx, this->model->player->coordy);

    this->window.clear();
    this->window.draw(Mars);
    this->window.draw(player);
    for(auto b: this->model->p_bullets){
        bullet.setPosition(b->coordx, b->coordy);
        this->window.draw(bullet);
    }

    this->window.display();
}