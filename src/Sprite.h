//
// created by Anneline Daggelinckx
//

#ifndef SPACEINVADERS_SPRITE_H
#define SPACEINVADERS_SPRITE_H


#include <SFML/Graphics.hpp>
#include "Entity.h"

namespace view {
    /**
     * the class sprite represents the view of different entities
     */
    class Sprite : public Observer {

    public:
        sf::Sprite sprite;
        sf::Texture sprite_texture; //the sprite gets a pointer to the background_texture, because it is destroyed if we don't save it
        std::shared_ptr<model::Entity> entity; //the entity that the sprite is representing
        bool to_be_deleted = false; //when the entity is dead the sprite has to be deleted

        /**
         * load texture from file
         * @param filename image file
         */
        explicit Sprite(const std::string& filename);

        static inline char player[] = "resources/spaceshipwide.png";
        static inline char enemy[] = "resources/starship.png";
        static inline char bullet[] = "resources/bullet.png";
        static inline char shieldblock[] = "resources/shieldblock.png";
        /**
         * Sets the entity of the sprite, and sets the position of the sprite in pixel coordinates
         * @param e is a shared pointer to the entity that represents the sprite
         */
        void setEntity(std::shared_ptr<model::Entity> e);

        /**
         * this method is overridden from the observer class
         * It changes the position of the sprite when the position of it's subject has changed
         */
        void update() override;
    };
}

#endif //SPACEINVADERS_SPRITE_H
