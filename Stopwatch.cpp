//
// Created by Anneline Daggelinckx on 12/8/19.
//

#include "Stopwatch.h"

Stopwatch* Stopwatch::instance = nullptr;

/**
 * Observer pattern -> only one instance
 * If instance doesn't exist make one, else return instance
 */
Stopwatch* Stopwatch::Instance() {
    if(!instance){
        instance = new Stopwatch;
    }
    return instance;
}

void Stopwatch::restart() {
    start_time = std::chrono::system_clock::now();
}

/**
 * check how much time is passed since restart
 * @return passed time in milli seconds
 */
double Stopwatch::elapsed() {
    //TODO check if start time is defined (exception)
    return (std::chrono::system_clock::now() - start_time).count()/(1e6); //in milli seconds
}

double Stopwatch::elapsed(std::chrono::time_point<std::chrono::system_clock> begin) {
    return (std::chrono::system_clock::now() - begin).count()/(1e6);
}

std::chrono::time_point<std::chrono::system_clock> Stopwatch::now() {
    return std::chrono::system_clock::now();
}