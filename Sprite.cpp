//
// Created by anneline on 12/26/19.
//

#include "Sprite.h"


namespace view{

    void Sprite::setEntity(std::shared_ptr <model::Entity> e) {
        entity = std::move(e);
        std::tuple<float, float> position = Transformation::Instance()->toScreen(std::make_tuple(this->entity->x, this->entity->y));
        this->sprite.setPosition(std::get<0>(position), std::get<1>(position));
    }

    void Sprite::update() {
        //when the entity is dead the sprite has to be deleted
        if(this->entity->health <= 0){
            this->to_be_deleted = true;
        }
        else{
            std::tuple<float, float> position = Transformation::Instance()->toScreen(std::make_tuple(this->entity->x, this->entity->y));
            this->sprite.setPosition(std::get<0>(position), std::get<1>(position));
        }
    }
}