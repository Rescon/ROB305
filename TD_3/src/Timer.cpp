//
// Created by wangyu980312 on 18/02/2022.
//

#include "Timer.h"

Timer::Timer()
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = call_callback;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = this;

    if(timer_create(CLOCK_REALTIME, &sev, &tid))
    {
        perror("Timer : timer_create");
    }
}

Timer::~Timer()
{
    timer_delete(tid);
}

void Timer::start(double duration_ms)
{
    struct itimerspec its;
    its.it_value = timespec_from_ms(duration_ms);
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0;

    if (timer_settime(tid, 0, &its, nullptr))
    {
        perror("Timer_start : timer_settime");
    }
}

void Timer::stop()
{
    struct itimerspec its;
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = 0;
    its.it_interval = its.it_value;

    if (timer_settime(tid, 0, &its, nullptr))
    {
        perror("Timer_stop : timer_settime");
    }
}

void Timer::call_callback(int, siginfo_t* si, void *)
{
    auto* timer = (Timer*) si->si_value.sival_ptr;
    timer->callback();
}
