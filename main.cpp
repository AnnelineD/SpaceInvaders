#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

#include "View.h"
#include "Controller.h"
#include "Stopwatch.h"



int main() {


    std::cout << "Hello, World!" << std::endl;

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("../resources/david-bowie-life-on-mars.wav"))
        std::cout << "Couldn't load sound" << std::endl;

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(100);
    //sound.play();

    auto v = std::make_shared<View>(800, 600);

    std::shared_ptr<Model> m;
    try{
        m = std::make_shared<Model>("../testLevel.ini");
    }
    catch (std::exception &e) {
        std::cerr << e.what();
        return 1;
    }

    m->player->addObserver(v->player_sprite);
    v->player_sprite->setEntity(m->player);


    //TODO zet volgende 2 loops in view
    for (auto& i : m->enemies){
            v->enemy_sprites.push_back(std::make_shared<EnemySprite>());
            v->enemy_sprites.back()->entity = i;
            i->addObserver(v->enemy_sprites.back());
    }

    for(auto& s : m->shields){
        v->shield_sprite.push_back(std::make_shared<ShieldSprite>());
        v->shield_sprite.back()->setEntity(s);
        s->addObserver(v->shield_sprite.back());
    }


    Controller c;

    c.view = v;
    c.model = m;

    double delta_time = 2;

    while (v->window.isOpen()) {
        Stopwatch::Instance()->restart();

        c.update(delta_time);
        v->render();

        sf::Event event;
        //handle event
        while ((Stopwatch::Instance()->elapsed() < 10) && v->window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                v->window.close();
            else
                c.handleEvent(delta_time, event);
        }
        delta_time = (Stopwatch::Instance()->elapsed()); //milli seconds
    }

    return 0;
}