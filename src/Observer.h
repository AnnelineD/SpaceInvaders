//
// Created by Anneline Daggelinckx on 12/12/19.
//

#ifndef SPACEINVADERS_OBSERVER_H
#define SPACEINVADERS_OBSERVER_H


/**
 * abstract class observer from observer design pattern
 */
class Observer {
public:
    Observer() = default;
    virtual ~Observer() = default;

    /**
     * virtual function that gets called when the subject notifies the observer
     */
    virtual void update() = 0;
};

#endif //SPACEINVADERS_OBSERVER_H
