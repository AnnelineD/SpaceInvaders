//
// Created by anneline on 11/27/19.
//

#include "View.h"
#include <iostream>

View::View() : window(sf::VideoMode(500, 500), "Protect your planet!"){}

View::View(int width, int height) : window(sf::VideoMode(width, height), "Protect Mars against humans!") {
    if (!texture.loadFromFile("../mars_planeet.jpg")){}
}

void View::render() {
    this->window.clear();
/*
    //Mars
    sf::CircleShape Mars(this->window.getSize().x, 100);
    Mars.setFillColor(sf::Color::Red);
    Mars.setPosition(0, (float)this->window.getSize().y/2);
    this->window.draw(Mars);
    */

    window.draw(sf::Sprite(texture));

    //player
    sf::RectangleShape player(sf::Vector2f(20, 20));
    player.setFillColor(sf::Color::Green);
    player.setPosition(this->model->player->coordx, this->model->player->coordy);

    this->window.draw(player);

    //Bullets
    sf::RectangleShape bullet(sf::Vector2f(5, 10));
    bullet.setFillColor(sf::Color::White);

    for(auto b: this->model->p_bullets){
        bullet.setPosition(b->coordx, b->coordy);
        this->window.draw(bullet);
    }

    //Enemies
    sf::RectangleShape enemy(sf::Vector2f(20, 20));
    enemy.setFillColor(sf::Color::Blue);

    for(auto e: this->model->enemies){
            enemy.setPosition(e->coordx, e->coordy);
            this->window.draw(enemy);
    }

    //enemy bullets
    for(auto b: this->model->e_bullets){
        bullet.setPosition(b->coordx, b->coordy);
        this->window.draw(bullet);
    }

    this->window.display();
}