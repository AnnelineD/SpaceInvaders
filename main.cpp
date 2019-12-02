#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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
    sound.play();


    Player p;
    p.coordy = 560;
    p.coordx = 200;

    Model m;
    m.player = &p;

    View v(800, 600);

    v.model = &m;

    Controller c;

    c.view = &v;

    auto delta_time = std::chrono::duration<double>(2);

    while (v.window.isOpen()) {
        sf::Event event;

        while (v.window.pollEvent(event))
        {
            auto start = std::chrono::system_clock::now();
            c.update(delta_time.count(), event);

            if (event.type == sf::Event::Closed)
                v.window.close();

            else{
                v.render();
            }
            auto end = std::chrono::system_clock::now();
            delta_time = 1000*(end-start); //milli seconds
        }
    }

    return 0;
}