//
// Created by Anneline Daggelinckx on 11/23/19.
//

#include <SFML/Audio.hpp>
#include "SpaceInvadersGame.h"
#include "Stopwatch.h"

void SpaceInvadersGame::load(const std::vector<std::string>& filenames) {
    if (filenames.empty()) {
        throw std::invalid_argument("Need at least one ini file to load!");
    }

    view = std::make_shared<view::View>(800, 600);

    for (auto& filename : filenames)
        levels.push_back(std::make_shared<model::Model>(filename));

    loadNextLevel();
}

void SpaceInvadersGame::loadNextLevel() {
    model = levels.front();
    levels.pop_front();

    model->player->addObserver(view->player_sprite);
    view->player_sprite->setEntity(model->player);

    view->enemy_bullet_sprites.clear();
    view->player_bullet_sprites.clear();

    view->enemy_sprites.clear();
    for (auto& i : model->enemies){
        view->enemy_sprites.push_back(std::make_shared<view::EnemySprite>());
        view->enemy_sprites.back()->entity = i;
        i->addObserver(view->enemy_sprites.back());
    }

    view->shieldblock_sprites.clear();
    for(auto& s : model->shields){
        view->shieldblock_sprites.push_back(std::make_shared<view::ShieldSprite>());
        view->shieldblock_sprites.back()->setEntity(s);
        s->addObserver(view->shieldblock_sprites.back());
    }

    controller = controller::Controller(model, view);
}

void SpaceInvadersGame::start() {

    //play music
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("../resources/david-bowie-life-on-mars.wav"))
        std::cout << "Couldn't load sound" << std::endl;

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(60);
    sound.play();

    float delta_time = 2;

    view->display("A wave of Starships arrive!", "prepare yourself");
    while (view->window.isOpen()) {
        auto [proceed, win_level] = controller.continueState();
        if (!proceed) {
            if (win_level && !levels.empty()) {
                loadNextLevel();
                view->display("Next wave of Starships arrive!", "prepare yourself");
            } else if (win_level && levels.empty()) {
                view->display("You successfully defended Mars!", "Press Esc to quit");
            } else {
                view->display("Humans will conquer Mars and ruin it!", "Press Esc to quit");
            }
        }

        //restart stopwatch to see how much time has passed when the loop ends
        Stopwatch::Instance()->restart();

        controller.update(delta_time);
        view->render();

        sf::Event event{};
        //handle event
        while (Stopwatch::Instance()->elapsed() < 10){
            if (view->window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    view->window.close();
                else
                    controller.handleEvent(delta_time, event);
            }
        }
        delta_time = (float)Stopwatch::Instance()->elapsed(); //milli seconds
    }
}
