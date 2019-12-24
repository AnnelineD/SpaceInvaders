//
// Created by anneline on 11/27/19.
//

#include "View.h"
#include <iostream>

View::View(int width, int height) : window(sf::VideoMode(width, height), "Protect Mars against humans!") {
    if (!background_texture.loadFromFile("../mars_planeet.jpg")){}
    if (!font.loadFromFile("../ScifiAdventure.otf")){}
}

void View::render() {
    this->window.clear();

    window.draw(sf::Sprite(background_texture));

    auto p_bullet_sprite_ = this->p_bullet_sprite;
    for(const auto& b: p_bullet_sprite_) {
        if (b->to_be_deleted) {
            this->p_bullet_sprite.remove(b);
        }
        this->window.draw(b->sprite);
    }


    auto e_bullet_sprite_ = this->e_bullet_sprite;
    for(const auto& b: e_bullet_sprite_){
        if(b->to_be_deleted){
            this->e_bullet_sprite.remove(b);
        }
        this->window.draw(b->sprite);
    }

    std::list<std::shared_ptr<EnemySprite>> enemy_sprites_ = this->enemy_sprites;
    for(const auto& e: enemy_sprites_){
        if(e->to_be_deleted){
            this->enemy_sprites.remove(e);
        }
        else{
            this->window.draw(e->sprite);
        }
    }

    if (this->player_sprite->entity->health > 0) {
        this->window.draw(this->player_sprite->sprite);

    } else {
        sf::Text text;
        text.setFont(font);
        text.setString("GAME OVER");

        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Magenta);
        text.setPosition(100, (float)this->window.getSize().y/2);
        this->window.draw(text);
    }


    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(this->player_sprite->entity->health));

    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Magenta);
    text.setPosition(20, 20);
    this->window.draw(text);

    this->window.display();
}
