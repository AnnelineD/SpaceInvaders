//
// Created by Anneline Daggelinckx on 12/26/19.
//

#include "Sprite.h"


namespace view{

    Sprite::Sprite(const std::string& filename) {
        if (!sprite_texture.loadFromFile(filename)) {
            throw std::invalid_argument("Couldn't load image : " + filename);
        }
        sprite.setTexture(sprite_texture);
    }

    void Sprite::setEntity(std::shared_ptr <model::Entity> e) {
        entity = std::move(e);
        auto [x, y] = Transformation::Instance()->toScreen({entity->x - entity->width/2, entity->y});
        sprite.setPosition(x, y);
    }

    void Sprite::update() {
        //when the entity is dead the sprite has to be deleted
        if(entity->health <= 0){
            to_be_deleted = true;
        } else{
            auto [x, y] = Transformation::Instance()->toScreen({entity->x - entity->width/2, entity->y});
            sprite.setPosition(x, y);
        }
    }
}