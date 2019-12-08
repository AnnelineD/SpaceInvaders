#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>

#include "Entity.h"
#include "View.h"
#include "Controller.h"



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

    Player p;
    p.coordy = 560;
    p.coordx = 200;

    Model m;
    m.player = &p;

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 3; j++){
            m.enemies.push_back(new Enemy(i * 50, j * 50));
            m.enemies.back()->setSpeed(.1, .01);
        }
    }

    View v(800, 600);

    v.model = &m;

    Controller c;

    c.view = &v;

    auto delta_time = std::chrono::duration<double>(2);

    while (v.window.isOpen()) {

        auto start = std::chrono::system_clock::now();
        c.update(delta_time.count());

        v.render();

        sf::Event event;
        //handle event
        while (((start - std::chrono::system_clock::now()).count() * 1000 < 10) && v.window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                v.window.close();
            else
                c.handleEvent(delta_time.count(), event);

        }

        auto end = std::chrono::system_clock::now();
        delta_time = 1000*(end-start); //milli seconds

        //float i = 10 - delta_time.count();

        //std::cout << i << std::endl;
        //std::this_thread::sleep_for(std::chrono::milliseconds((int)i));
    }

    return 0;
}