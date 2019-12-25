//
// Created by anneline on 12/25/19.
//

#include "Transformation.h"

Transformation* Transformation::instance = nullptr;

/**
 * Observer pattern -> only one instance
 * If instance doesn't exist make one, else return instance
 */
Transformation* Transformation::Instance() {
    if(!instance){
        instance = new Transformation;
    }
    return instance;
}