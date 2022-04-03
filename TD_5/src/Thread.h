//
// Created by wangyu980312 on 14/03/2022.
//

#ifndef TD_5_THREAD_H
#define TD_5_THREAD_H

#include "PosixThread.h"

class Thread : public PosixThread {
public:
    // Constructor of Thread
    Thread();

    // Destructor of Thread
    ~Thread();

    // Start the thread
    bool start();

    // Make the thread sleep for a given time
    static void sleep_ms(double delay_ms);

    // Get the start time of the thread
    double startTime_ms();

    // Get the stop time of the thread
    double stopTime_ms();

    // Get the execution time of the thread
    double execTime_ms();

protected:
    // Handle function (must be implemented by the derived class)
    virtual void run() = 0;

private:
    // Call the handle function
    static void* call_run(void* v_thread);

    // The start time of the thread
    timespec startTime{};

    // The stop time of the thread
    timespec stopTime{};
};

#endif //TD_5_THREAD_H
