//
// Created by anneline on 12/8/19.
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
float Stopwatch::elapsed() {
    //TODO check if start time is defined (exception)
    return (std::chrono::system_clock::now() - start_time).count()/(10e+06); //in milli seconds
}