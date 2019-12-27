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

/**
 * Converts logic coordinates in the [-4, 4]x[-3, 3] space to pixel coordinates
 * @param gameCoordinates are the logic coordinates we want to convert
 * @return the pixel coordinates that match the given game coordinates
 */
std::tuple<float, float> Transformation::toScreen(std::tuple<float, float> gameCoordinates) {
    float x = std::get<0>(gameCoordinates)*100 + 400;
    float y = -(std::get<1>(gameCoordinates)*100 - 300);

    return std::make_tuple(x, y);
}

/**
 * Convers pixel coordinates to logic coordinates in the [-4, 4]x[-3, 3] space
 * @param screenCoordinates is a tuple of the pixel coordinates we want to convert
 * @return the logic coordinates that match the given pixel coordinates
 */
std::tuple<float, float> Transformation::toLogic(std::tuple<float, float> screenCoordinates) {
    float x = std::get<0>(screenCoordinates)/100 - 4;
    float y = -(std::get<1>(screenCoordinates)/100 - 3);

    return std::make_tuple(x, y);
}
