//
// Created by Anneline Daggelinckx on 11/27/19.
//

#include "View.h"
#include "Stopwatch.h"
#include <iostream>

namespace view {
    View::View(unsigned int width, unsigned int height) : window(sf::VideoMode(width, height), "Protect Mars against humans!") {
        if (!background_texture.loadFromFile("resources/mars_planeet.jpg"))
            std::cerr << "Continuing with black background\n";

        if (!lives_texture.loadFromFile("resources/alien.png"))
            std::cerr << "Continuing with numeric lives counter\n";

        if (!font.loadFromFile("resources/ScifiAdventure.otf"))
            throw std::invalid_argument("Couldn't load font");
    }

    void View::render() {
        window.clear();

        window.draw(sf::Sprite(background_texture));

        drawContainer(shieldblock_sprites);
        drawContainer(player_bullet_sprites);
        drawContainer(enemy_bullet_sprites);
        drawContainer(enemy_sprites);

        if (player_sprite->entity->health > 0)
            window.draw(player_sprite->sprite);

        drawLives();
        drawText();

        window.display();
    }

    void View::drawContainer(std::list<std::shared_ptr<view::Sprite>>& container) {
        //can't iterate over a list while deleting elements of that list
        auto container_ = container;
        for (const auto &e: container_) {
            if (e->to_be_deleted)
                container.remove(e);
            else
                window.draw(e->sprite);
        }
    }

    void View::drawLives() {
        // if texture could not load, x is 0, and we fall back on numeric display
        static float lives_texture_width = lives_texture.getSize().x;
        if ((int)lives_texture_width) {
            auto lives_spite = sf::Sprite(lives_texture);
            lives_spite.scale(25.f/lives_texture_width, 25.f/lives_texture_width);

            for (int live = 0; live < player_sprite->entity->health; live++) {
                lives_spite.setPosition((float)(30 + live*45), 30);
                window.draw(lives_spite);
            }
        } else {
            sf::Text text;
            text.setFont(font);
            text.setString(std::to_string(player_sprite->entity->health));
            text.setCharacterSize(25);
            text.setFillColor(sf::Color(255, 255, 255));
            text.setPosition(30, 30);
            window.draw(text);
        }

    }

    void View::drawText() {
        double elapsed_ratio = Stopwatch::Instance()->elapsed(text_first_draw)/5500;
        if (elapsed_ratio > 1)
            return;

        sf::Text text;
        text.setFont(font);
        text.setString(main_text);
        text.setCharacterSize((unsigned int) (30*650/text.getLocalBounds().width));
        text.setFillColor(sf::Color(255, 255, 255, 255 - 150*elapsed_ratio));
        text.setPosition(100, (float) .5*window.getSize().y);
        window.draw(text);

        sf::Text instruction;
        instruction.setFont(font);
        instruction.setString(side_text);
        instruction.setCharacterSize((unsigned int) (30*650/instruction.getLocalBounds().width));
        instruction.setFillColor(sf::Color(255, 255, 255, 255 - 150*elapsed_ratio));
        instruction.setPosition(100, (float) .8*window.getSize().y);
        window.draw(instruction);
    }


    void View::display(const std::string& text, const std::string& instruction = "") {
        main_text = text;
        side_text = instruction;
        text_first_draw = Stopwatch::Instance()->now();
    }
}
