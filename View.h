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
        PlayerSprite() : Sprite("../resources/spaceshipwide.png"){};
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
        sf::Texture background_texture;
        sf::Texture lives_texture;
        sf::Font font;
        std::string main_text, side_text;
        std::chrono::time_point<std::chrono::system_clock> text_first_draw = std::chrono::system_clock::now();

        /**
         * draws main_text and side_text on window
         */
        void drawText();

        /**
         * Draws a live texture for each live if the texture is loaded, else just the number of lives
         */
        void drawLives();

        /**
         * Draw sprites contained except if they are to be deleted, than delete them
         * @param container The sprite container to be drawn, gets modified
         */
        void drawContainer(std::list<std::shared_ptr<view::Sprite>> &container);
    public:
        sf::RenderWindow window;

        std::shared_ptr<Sprite> player_sprite = std::make_shared<PlayerSprite>();
        std::list<std::shared_ptr<Sprite>> enemy_sprites;
        std::list<std::shared_ptr<Sprite>> player_bullet_sprites;
        std::list<std::shared_ptr<Sprite>> enemy_bullet_sprites; //enemy bullets
        std::list<std::shared_ptr<Sprite>> shieldblock_sprites;

        /**
         * Construct SFML window with background and font, throws if font couldn't be loaded
         * @param width of the window
         * @param height of the window
         */
        View(int width, int height);

        /**
         * Draws all sprites on screen
         */
        void render();

        /**
         * Set text to be displayed for the following seconds
         * @param text to come center
         * @param instruction to come below text
         */
        void display(const std::string& text, const std::string& instruction);
    };
}


#endif //SPACEINVADERS_VIEW_H
