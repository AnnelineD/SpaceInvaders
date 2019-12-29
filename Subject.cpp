//
// Created by Anneline Daggelinckx on 12/12/19.
//

#include "Subject.h"

void Subject::addObserver(const std::shared_ptr<Observer>& observerPtr) {
    m_observer_list.push_back(observerPtr);
}

void Subject::notify() {
    for(const auto& m_obs: m_observer_list){
        m_obs->update();
    }
}
