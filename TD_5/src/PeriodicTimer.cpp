//
// Created by wangyu980312 on 18/02/2022.
//

#include "PeriodicTimer.h"

void PeriodicTimer::start(double duration_ms) {
    struct itimerspec its;
    its.it_value = timespec_from_ms(duration_ms);
    its.it_interval = its.it_value;

    if(timer_settime(tid, 0, &its, nullptr))
    {
        perror("PeriodicTimer_start : timer_settime");
    }
}
