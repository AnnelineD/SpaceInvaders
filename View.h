//
// Created by Anneline Daggelinckx on 11/27/19.
//

#ifndef SPACEINVADERS_VIEW_H
#define SPACEINVADERS_VIEW_H

#include <memory>
#include <list>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Observer.h"
#include "Sprite.h"
#include "Transformation.h"

namespace view {
    class PlayerSprite : public Sprite {
    public:
        PlayerSprite() : Sprite("../resources/alien.png"){};
    };

    class EnemySprite : public Sprite {
    public:
        EnemySprite() : Sprite("../resources/starship.png"){};
    };

    class BulletSprite : public Sprite {
    public:
        BulletSprite() : Sprite("../resources/bullet.png"){};
    };

    class ShieldSprite : public Sprite {
    public:
        ShieldSprite() : Sprite("../resources/shieldblock.png") {};
    };

    /**
     * Handles drawing and stores textures and fonts
     */
    class View {
    public:
        sf::RenderWindow window;
        sf::Texture background_texture;
        sf::Font font;

        std::shared_ptr<PlayerSprite> player_sprite = std::make_shared<PlayerSprite>();
        std::list<std::shared_ptr<EnemySprite>> enemy_sprites;
        std::list<std::shared_ptr<BulletSprite>> p_bullet_sprite; //player bullets
        std::list<std::shared_ptr<BulletSprite>> e_bullet_sprite; //enemy bullets
        std::list<std::shared_ptr<ShieldSprite>> shield_sprite;

        /**
         * Construct SFML window with background and font, throws if font couldn't be loaded
         * @param width of the window
         * @param height of the window
         */
        View(int width, int height);

        /**
         * Draws al the data member sprites on screen
         */
        void render();
    };
}


#endif //SPACEINVADERS_VIEW_H
