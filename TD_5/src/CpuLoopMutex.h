//
// Created by wangyu980312 on 02/04/2022.
//

#ifndef TD_5_CPULOOPMUTEX_H
#define TD_5_CPULOOPMUTEX_H

#include "Thread.h"
#include "CpuLoop.h"
#include "Mutex.h"

class CpuLoopMutex : public Thread
{
public:
    // Constructor of CpuLoopMutex
    CpuLoopMutex(Mutex &mutex, CpuLoop &cpuLoop, double timeBeginMutex, double durationMutex, double timeExecution);

    // Destructor of CpuLoopMutex
    ~CpuLoopMutex();

    // Handle function
    void run() override;

private:
    // Pointer to the mutex
    Mutex &mutex;

    // Pointer to the cpuloop
    CpuLoop &cpuLoop;

    // Time that the mutex needs to begin
    double timeBeginMutex;

    // Duration time of the lock of the mutex
    double durationMutex;

    // Time of the lock of the thread
    double timeExecution;
};

#endif //TD_5_CPULOOPMUTEX_H
