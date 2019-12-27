//
// Anneline Daggelinckx
//

#ifndef SPACEINVADERS_SPRITE_H
#define SPACEINVADERS_SPRITE_H


#include <SFML/Graphics.hpp>
#include "Entity.h"

class Sprite : public Observer{
public:
    sf::Sprite sprite;
    sf::Texture sprite_texture; //the sprite gets a pointer to the background_texture, because it is destroyed if we don't save it
    std::shared_ptr<Entity> entity; //the entity that the sprite is representing
    bool to_be_deleted = false; //when the entity is dead the sprite has to be deleted

    //constructors
    Sprite() = default;

    //methods
    void setEntity(std::shared_ptr<Entity> e);

    void update() override;
};


#endif //SPACEINVADERS_SPRITE_H
