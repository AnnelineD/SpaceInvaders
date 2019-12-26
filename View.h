//
// Created by anneline on 11/27/19.
//

#ifndef SPACEINVADERS_VIEW_H
#define SPACEINVADERS_VIEW_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <list>
#include "Entity.h"
#include "Observer.h"
#include "Sprite.h"
#include "Transformation.h"


class PlayerSprite: public Sprite{
public:
    PlayerSprite(){
        std::string filename = "../resources/alien.png";
        if (!sprite_texture.loadFromFile(filename)) {
            throw std::invalid_argument("Couldn't load image for player : " + filename);
        }
        sprite.setTexture(sprite_texture);
    }
};

class EnemySprite: public Sprite{
public:
    EnemySprite(){
        std::string filename = "../resources/starship.png";
        if (!sprite_texture.loadFromFile(filename)){
            throw std::invalid_argument("Couldn't load image for enemies : " + filename);
        }
        sprite.setTexture(sprite_texture);
    }
};

class BulletSprite: public Sprite{
public:
    BulletSprite(){
        std::string filename = "../resources/bullet.png";
        if (!sprite_texture.loadFromFile(filename)){
            throw std::invalid_argument("Couldn't load image for bullets : " + filename);
        }
        sprite.setTexture(sprite_texture);
    }
};

class ShieldSprite: public Sprite {
public:
    ShieldSprite(){
        std::string filename = "../resources/shieldblock.png";
        if (!sprite_texture.loadFromFile(filename)){
            throw std::invalid_argument("Couldn't load image for shields : " + filename);
        }
    sprite.setTexture(sprite_texture);
    }
};

class View{
public:
    View(int width, int height);
    void render();

    sf::RenderWindow window;
    sf::Texture background_texture;
    sf::Font font;

    std::shared_ptr<PlayerSprite> player_sprite = std::make_shared<PlayerSprite>();
    std::list<std::shared_ptr<EnemySprite>> enemy_sprites;
    std::list<std::shared_ptr<BulletSprite>> p_bullet_sprite; //player bullets
    std::list<std::shared_ptr<BulletSprite>> e_bullet_sprite; //enemy bullets
    std::list<std::shared_ptr<ShieldSprite>> shield_sprite;
};


#endif //SPACEINVADERS_VIEW_H
