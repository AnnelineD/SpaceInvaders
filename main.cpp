#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>

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
        m.enemies.back()->frontline = true;
    }

    View v(800, 600);

    v.model = &m;

    Controller c;

    c.view = &v;

    double delta_time = 2;

    while (v.window.isOpen()) {

        Stopwatch::Instance()->restart();

        //c.update(delta_time.count());
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

    return 0;
}