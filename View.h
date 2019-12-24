//
// Created by anneline on 11/27/19.
//

#ifndef SPACEINVADERS_VIEW_H
#define SPACEINVADERS_VIEW_H

#include "Model.h"

#include <SFML/Graphics.hpp>
#include <memory>
#include <list>
#include <utility>

#include "Observer.h"

class Sprite : public Observer{
public:
    sf::Sprite sprite;
    sf::Texture sprite_texture; //the sprite gets a pointer to the background_texture, so it is destroyed if we don't save it
    std::shared_ptr<Entity> entity;
    bool to_be_deleted = false;

    //constructors
    Sprite() = default;
    explicit Sprite(std::shared_ptr<Entity> e): entity(std::move(e)){
        this->sprite.setPosition(this->entity->coordx, this->entity->coordy);
    };
    explicit Sprite(const Entity& e): entity(std::make_shared<Entity>(e)){
        this->sprite.setPosition(this->entity->coordx, this->entity->coordy);
    };

    //methods
    void setEntity(std::shared_ptr<Entity> e){
        entity = e;
        this->sprite.setPosition(this->entity->coordx, this->entity->coordy);
    };

    void update() override {
        if(this->entity->health <= 0){
            this->to_be_deleted = true;
        }
        else{
            this->sprite.setPosition(sf::Vector2f(this->entity->coordx, this->entity->coordy));
        }
    };
};

class PlayerSprite: public Sprite{
public:
    PlayerSprite(){
        if (!sprite_texture.loadFromFile("../alien.png")) {
            // TODO error...
        }
        sprite.setTexture(sprite_texture);
    }
};

class EnemySprite: public Sprite{
public:
    EnemySprite(){
        if (!sprite_texture.loadFromFile("../starship.png"))
        {
            // TODO error...
        }
        sprite.setTexture(sprite_texture);
    }
};

class BulletSprite: public Sprite{
public:
    BulletSprite(){
        if (!sprite_texture.loadFromFile("../bullet.png"))
        {
            // TODO error...
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
};




#endif //SPACEINVADERS_VIEW_H
