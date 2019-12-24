//
// Created by anneline on 12/12/19.
//

#include "Subject.h"

void Subject::addObserver(std::shared_ptr<Observer> observerPtr) {
    m_observer_list.push_back(observerPtr);
}

