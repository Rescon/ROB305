//
// Created by wangyu980312 on 14/03/2022.
//

#include "Thread.h"

Thread::Thread() = default;

Thread::~Thread() = default;

bool Thread::start()
{
    if(!isActive)
    {
        startTime = timespec_now();
        PosixThread::start(call_run, (void*) this);
    }
    return isActive;
}

void Thread::sleep_ms(double delay_ms)
{
    timespec_wait(timespec_from_ms(delay_ms));
}

double Thread::startTime_ms()
{
    return timespec_to_ms(startTime);
}

double Thread::stopTime_ms()
{
    return timespec_to_ms(stopTime);
}

double Thread::execTime_ms()
{
    stopTime = timespec_now();
    return timespec_to_ms(stopTime - startTime);
}

void *Thread::call_run(void *v_thread)
{
    auto* thread = (Thread*) v_thread;
    thread->run();
    return (void*) thread;
}
