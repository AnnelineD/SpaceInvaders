//
// Created by anneline on 12/25/19.
//

#ifndef SPACEINVADERS_TRANSFORMATION_H
#define SPACEINVADERS_TRANSFORMATION_H


class Transformation {
public:
    static Transformation* Instance();

private:
    Transformation() = default;
    Transformation(Transformation const&) = default;
    Transformation& operator=(Transformation const&) = default;
    static Transformation* instance;
    // TODO implement transformations to and from screen coordinates like: 
    // auto [x, y] = Transformation().toScreen(x, y)
};


#endif //SPACEINVADERS_TRANSFORMATION_H
