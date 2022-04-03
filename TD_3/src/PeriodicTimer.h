//
// Created by wangyu980312 on 18/02/2022.
//

#ifndef TD_3_PERIODICTIMER_H
#define TD_3_PERIODICTIMER_H

#include "Timer.h"

class PeriodicTimer : public Timer
{
public:
    // Start the Periodic Timer
    void start(double duration_ms) override;
};

#endif //TD_3_PERIODICTIMER_H
