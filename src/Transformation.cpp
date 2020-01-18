//
// Created by Anneline Daggelinckx on 12/25/19.
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
std::tuple<float, float> Transformation::toScreen(std::tuple<float, float> gameCoordinates) const {
    auto [x, y] = gameCoordinates;
    return {x*100 + 400, -y*100 + 300};
}

/**
 * Convers pixel coordinates to logic coordinates in the [-4, 4]x[-3, 3] space
 * @param screenCoordinates is a tuple of the pixel coordinates we want to convert
 * @return the logic coordinates that match the given pixel coordinates
 */
std::tuple<float, float> Transformation::toLogic(std::tuple<float, float> screenCoordinates) const {
    auto [x, y] = screenCoordinates;
    return {x/100 - 4, y/100 - 3};
}
