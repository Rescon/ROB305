//
// Created by wangyu980312 on 02/04/2022.
//

#include "CpuLoopMutex.h"

CpuLoopMutex::CpuLoopMutex(Mutex &mutex, CpuLoop &cpuLoop, double timeBeginMutex, double durationMutex,
                           double timeExecution) : mutex(mutex), cpuLoop(cpuLoop), timeBeginMutex(timeBeginMutex),
                           durationMutex(durationMutex), timeExecution(timeExecution) {}

CpuLoopMutex::~CpuLoopMutex() = default;

double tick_to_ms(double tick)
{
    return tick / CLOCKS_PER_SEC * 1e3;
}

void CpuLoopMutex::run()
{
    if(timeBeginMutex != -1) // with mutex
    {
        cpuLoop.runTime(tick_to_ms(timeBeginMutex));

        Mutex::Lock lock(mutex, 1000);
        cpuLoop.runTime(tick_to_ms(durationMutex));
        lock.~Lock();

        cpuLoop.runTime(tick_to_ms(timeExecution - (timeBeginMutex + durationMutex)));
    }
    else // without mutex
    {
        cpuLoop.runTime(tick_to_ms(timeExecution));
    }
}
