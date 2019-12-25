#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>
#include <memory>

#include "Entity.h"
#include "View.h"
#include "Controller.h"
#include "Stopwatch.h"



int main() {


    std::cout << "Hello, World!" << std::endl;

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("../david-bowie-life-on-mars.wav"))
        std::cout << "Sound doesn't work" << std::endl;
    //TODO make a real exception

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(50);
    //sound.play();

    /*
    Player p;
    p.setSpeed(50, 0);
    p.coordy = 560;
    p.coordx = 200;

    Model m;
    m.player = &p;

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 3; j++){
            m.enemies.push_back(new Enemy(i * 50, j * 50));
            m.enemies.back()->setSpeed(.1, .01);
        }
        m.enemies.back()->frontline = true;
    }

    View v(800, 600);

    //std::shared_ptr<View> m_v = std::make_shared<View>(800, 600);
    //m.addObserver(m_v);

    v.model = &m;

    Controller c;

    c.view = &v;

    double delta_time = 2;

    while (v.window.isOpen()) {

        Stopwatch::Instance()->restart();

        //c.render(delta_time.count());
        c.update(delta_time);

        v.render();

        sf::Event event;
        //handle event
        while ((Stopwatch::Instance()->elapsed() < 10) && v.window.pollEvent(event)){

            if (event.type == sf::Event::Closed)
                v.window.close();
            else
                c.handleEvent(delta_time, event);
        }
        delta_time = (Stopwatch::Instance()->elapsed()); //milli seconds
    }
     */

    auto v = std::make_shared<View>(800, 600);

    auto m = std::make_shared<Model>("../testLevel.ini");

    m->player->addObserver(v->player_sprite);
    v->player_sprite->setEntity(m->player);

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 3; j++){
            m->enemies.push_back(std::make_shared<Enemy>(i * 50, j * 50 + 50));
            m->enemies.back()->setSpeed(.06, .003);
            v->enemy_sprites.push_back(std::make_shared<EnemySprite>());
            v->enemy_sprites.back()->entity = m->enemies.back();
            m->enemies.back()->addObserver(v->enemy_sprites.back());
        }
        m->enemies.back()->frontline = true;
    }

    std::vector<std::string> FORM = {
            " ######## ",
            "##########",
            "##      ##",
            "##      ##"};

    for(int n = 0; n < 4; n++){
        for (int i = 0; i < FORM.size(); i++) {
            for (int j = 0; j < FORM[0].length(); j++){
                if (FORM[i][j] == '#'){
                    m->shields.push_back(std::make_shared<ShieldBlock>(50 + j*10 + n*200, 350 + i*10));
                    v->shield_sprite.push_back(std::make_shared<ShieldSprite>());
                    v->shield_sprite.back()->setEntity(m->shields.back());
                    m->shields.back()->addObserver(v->shield_sprite.back());
                }
            }
        }
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