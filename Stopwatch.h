//
// Created by Anneline Daggelinckx on 12/8/19.
//

#ifndef SPACEINVADERS_STOPWATCH_H
#define SPACEINVADERS_STOPWATCH_H

#include <chrono>


class Stopwatch {
public:
    static Stopwatch* Instance();

    void restart();
    double elapsed(); //in milli seconds
    double elapsed(std::chrono::time_point<std::chrono::system_clock> begin);
    std::chrono::time_point<std::chrono::system_clock> now();
    std::chrono::time_point<std::chrono::system_clock> start_time;

private:
    Stopwatch() = default;
    Stopwatch(Stopwatch const&) = default;
    Stopwatch& operator=(Stopwatch const&) = default;
    static Stopwatch* instance;
};


#endif //SPACEINVADERS_STOPWATCH_H
