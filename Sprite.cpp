//
// Created by anneline on 12/26/19.
//

#include "Sprite.h"

/**
 * Sets the entity of the sprite, and sets the position of the sprite in pixel coordinates
 * @param e is a shared pointer to the entity that represents the sprite
 */
void Sprite::setEntity(std::shared_ptr <Entity> e) {
    entity = std::move(e);
    std::tuple<float, float> position = Transformation::Instance()->toScreen(std::make_tuple(this->entity->coordx, this->entity->coordy));
    this->sprite.setPosition(std::get<0>(position), std::get<1>(position));
}

/**
 * this method is overridden from the observer class
 * It changes the position of the sprite when the position of it's subject has changed
 */
void Sprite::update() {
    //when the entity is dead the sprite has to be deleted
    if(this->entity->health <= 0){
        this->to_be_deleted = true;
    }
    else{
        std::tuple<float, float> position = Transformation::Instance()->toScreen(std::make_tuple(this->entity->coordx, this->entity->coordy));
        this->sprite.setPosition(std::get<0>(position), std::get<1>(position));
    }
}
