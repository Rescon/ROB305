//
// Created by wangyu980312 on 01/02/2022.
//

#include <ctime>
#include <csignal>
#include <iostream>

void myHandler(int, siginfo_t* si, void*)
{
    int* pCounter = (int*)si->si_value.sival_ptr;
    *pCounter += 1;
    std::cout << *pCounter << std::endl;
}

int main()
{
    volatile int counter = 0;

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = myHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = (void*) &counter;

    timer_t tid;

    if(timer_create(CLOCK_REALTIME, &sev, &tid))
    {
        perror("timer_create");
    }

    struct itimerspec its;
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = 5e8;
    its.it_interval = its.it_value;

    if (timer_settime(tid, 0, &its, nullptr))
    {
        perror("timer_settime");
    }

    while(counter < 15)
        continue;
    timer_delete(tid);
    return 0;
}