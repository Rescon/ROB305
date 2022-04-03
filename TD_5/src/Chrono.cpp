//
// Created by wangyu980312 on 17/02/2022.
//

#include "Chrono.h"

Chrono::Chrono()
{
    startTime_ = timespec_now();
    stopTime_ = startTime_;
}

void Chrono::stop()
{
    stopTime_ = timespec_now();
}

void Chrono::restart()
{
    startTime_ = timespec_now();
    stopTime_ = startTime_;
}

bool Chrono::isActive()
{
    return startTime_ == stopTime_;
}

double Chrono::startTime()
{
    return timespec_to_ms(startTime_);
}

double Chrono::stopTime()
{
    return timespec_to_ms(stopTime_);
}

double Chrono::lap()
{
    if (isActive())
    {
        return timespec_to_ms(timespec_now()) - startTime();
    }
    else
    {
        return stopTime() - startTime();
    }
}