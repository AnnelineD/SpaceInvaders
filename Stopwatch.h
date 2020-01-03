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
    [[nodiscard]] double elapsed() const; //in milli seconds
    [[nodiscard]] double elapsed(std::chrono::time_point<std::chrono::system_clock> begin) const;
    [[nodiscard]] std::chrono::time_point<std::chrono::system_clock> now() const;

private:
    Stopwatch() = default;
    Stopwatch(Stopwatch const&) = default;
    Stopwatch& operator=(Stopwatch const&) = default;
    static Stopwatch* instance;
    std::chrono::time_point<std::chrono::system_clock> start_time;
};


#endif //SPACEINVADERS_STOPWATCH_H
