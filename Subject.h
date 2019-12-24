//
// Created by anneline on 12/12/19.
//

#ifndef SPACEINVADERS_SUBJECT_H
#define SPACEINVADERS_SUBJECT_H

#include <vector>
#include <memory>
#include "Observer.h"


//abstract class
class Subject {
    std::vector<std::shared_ptr<Observer>> m_observer_list;
public:
    Subject() = default;
    virtual ~Subject() = default;
    void addObserver(std::shared_ptr<Observer> observerPtr);
    //void removeObserver(std::shared_ptr<Observer>  observerPtr);
    void notify(){
        for(const auto& m_obs: m_observer_list){
            m_obs->update();
        }
    };
};


#endif //SPACEINVADERS_SUBJECT_H
