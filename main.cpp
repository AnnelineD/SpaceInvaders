#include <iostream>
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "View.h"
#include "Controller.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    Player p;
    p.coordy = 10;
    p.coordx = 200;

    Model m;
    m.player = &p;

    View v(400, 400);

    v.model = &m;

    Controller c;

    c.view = &v;




    while (v.window.isOpen()) {
        sf::Event event;
        while (v.window.pollEvent(event))
        {
            c.update(10, event);

            if (event.type == sf::Event::Closed)
                v.window.close();

            else{

                v.render();
            }
        }
    }





    return 0;
}