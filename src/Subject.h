//
// Created by Anneline Daggelinckx on 12/12/19.
//

#ifndef SPACEINVADERS_SUBJECT_H
#define SPACEINVADERS_SUBJECT_H

#include <vector>
#include <memory>
#include "Observer.h"


/**
 * class subject from observer design pattern
 */
class Subject {
    std::vector<std::shared_ptr<Observer>> m_observer_list;
public:
    Subject() = default;
    virtual ~Subject() = default;

    /**
     * adds an observer
     * @param observerPtr a shared ptr to the observer you want to add
     */
    void addObserver(const std::shared_ptr<Observer>& observerPtr);

    /**
     * calls update on all linked observers
     */
    void notify() const;
};


#endif //SPACEINVADERS_SUBJECT_H
