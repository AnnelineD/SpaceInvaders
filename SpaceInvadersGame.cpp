//
// Created by Anneline Daggelinckx on 11/23/19.
//

#include <SFML/Audio.hpp>
#include "SpaceInvadersGame.h"
#include "Stopwatch.h"

void SpaceInvadersGame::load(const std::string& filename) {
    this->view = std::make_shared<view::View>(800, 600);

    this->model = std::make_shared<model::Model>(filename);

    this->model->player->addObserver(this->view->player_sprite);
    this->view->player_sprite->setEntity(this->model->player);


    for (auto& i : this->model->enemies){
        this->view->enemy_sprites.push_back(std::make_shared<view::EnemySprite>());
        this->view->enemy_sprites.back()->entity = i;
        i->addObserver(this->view->enemy_sprites.back());
    }

    for(auto& s : this->model->shields){
        this->view->shield_sprite.push_back(std::make_shared<view::ShieldSprite>());
        this->view->shield_sprite.back()->setEntity(s);
        s->addObserver(this->view->shield_sprite.back());
    }

    this->controller = controller::Controller(this->model, this->view);
}

void SpaceInvadersGame::start() {

    //play music
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("../resources/david-bowie-life-on-mars.wav"))
        std::cout << "Couldn't load sound" << std::endl;

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(100);
    sound.play();

    double delta_time = 2;

    while (view->window.isOpen()) {
        //restart stopwatch to see how much time has passed when the loop ends
        Stopwatch::Instance()->restart();

        controller.update((float)delta_time);
        view->render();

        sf::Event event;
        //handle event
        while (Stopwatch::Instance()->elapsed() < 10){
            if (view->window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    view->window.close();
                else
                    controller.handleEvent((float) delta_time, event);
            }
        }
        delta_time = (Stopwatch::Instance()->elapsed()); //milli seconds
    }
}
