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

std::tuple<float, float> Transformation::toScreen(std::tuple<float, float> gameCoordinates) {
    float x = std::get<0>(gameCoordinates)*100 + 400;
    float y = -(std::get<1>(gameCoordinates)*100 - 300);

    return std::make_tuple(x, y);
}

std::tuple<float, float> Transformation::toLogic(std::tuple<float, float> screenCoordinates) {
    float x = std::get<0>(screenCoordinates)/100 - 4;
    float y = -(std::get<1>(screenCoordinates)/100 - 3);

    return std::make_tuple(x, y);
}
