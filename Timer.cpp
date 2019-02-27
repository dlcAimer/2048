//
// Created by Aliez on 2018/7/7.
//

#include "Timer.h"
#include <iostream>

using std::cout;
using std::endl;

void Timer::restart() {
    time = clock();
}

int Timer::getUsingTime() {
    clock_t now = clock();
    int usingTime = (int) (now - time) / CLOCKS_PER_SEC;
    return usingTime;
}

void Timer::print() {
    int usingTime = getUsingTime();
    cout << "use : " << usingTime / 60 << " minutes " << usingTime % 60 << " seconds " << endl;
}

