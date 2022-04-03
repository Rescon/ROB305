//
// Created by wangyu980312 on 17/02/2022.
//

#ifndef TD_3_CHRONO_H
#define TD_3_CHRONO_H

#include "timespec.h"

class Chrono
{
public:
    // Constructor of Chrono
    Chrono();

    // Stop the Chrono
    void stop();

    // Restart the Chrono
    void restart();

    // Get the status of Chrono
    bool isActive();

    // Get the startTime (in milliseconds) of Chrono
    double startTime();

    // Get the stopTime (in milliseconds) of Chrono
    double stopTime();

    // Get the time (in milliseconds) between the (re)start of the Chrono and the call to stop().
    double lap();

private:
    // Start time
    timespec startTime_;

    // Stop time
    timespec stopTime_;
};

#endif //TD_3_CHRONO_H
