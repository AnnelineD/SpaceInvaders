//
// Created by anneline on 12/12/19.
// observer from observer design pattern

#ifndef SPACEINVADERS_OBSERVER_H
#define SPACEINVADERS_OBSERVER_H


//abstract class
class Observer {
public:
    Observer() = default;
    virtual ~Observer() = default;
    virtual void update() = 0;
};

#endif //SPACEINVADERS_OBSERVER_H
