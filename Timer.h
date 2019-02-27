//
// Created by Aliez on 2018/7/7.
//

#ifndef INC_2048_TIMER_H
#define INC_2048_TIMER_H

#include <ctime>

class Timer {
private:
    clock_t time = clock();
public:
    Timer() = default;
    ~Timer() = default;

    void restart();
    int getUsingTime();
    void print();
};


#endif //INC_2048_TIMER_H
