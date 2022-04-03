//
// Created by wangyu980312 on 18/02/2022.
//

#ifndef TD_3_TIMER_H
#define TD_3_TIMER_H

#include "timespec.h"
#include <csignal>

class Timer
{
public:
    // Constructor of Timer
    Timer();

    // Destructor of Timer
    ~Timer();

    // Start the Timer
    virtual void start(double duration_ms);

    // Stop the Timer
    void stop();

protected:
    // Timer id
    timer_t tid;

    // Handle function (must be implemented by the derived class)
    virtual void callback() = 0;

private:
    // Call the handle function
    static void call_callback(int, siginfo_t* si, void*);
};

#endif //TD_3_TIMER_H
