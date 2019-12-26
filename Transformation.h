//
// Created by anneline on 12/25/19.
//

#ifndef SPACEINVADERS_TRANSFORMATION_H
#define SPACEINVADERS_TRANSFORMATION_H

#include <tuple>

class Transformation {
public:
    static Transformation* Instance();
    std::tuple<float, float> toScreen(std::tuple<float, float> gameCoordinates);
    std::tuple<float, float> toLogic(std::tuple<float, float> screenCoordinates);

private:
    Transformation() = default;
    Transformation(Transformation const&) = default;
    Transformation& operator=(Transformation const&) = default;
    static Transformation* instance;
};


#endif //SPACEINVADERS_TRANSFORMATION_H
