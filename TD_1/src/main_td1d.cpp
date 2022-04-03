//
// Created by wangyu980312 on 03/02/2022.
//

#include <csignal>
#include <climits>
#include "timespec.h"

using loop_t = unsigned long int;
loop_t incr(loop_t nLoops, double* pCounter, const bool* pStop)
{
    loop_t iLoop;
    for(iLoop = 0; iLoop < nLoops; ++iLoop)
    {
        if (*pStop) break;
        *pCounter += 1.0;
    }
    return iLoop;
}

void myHandler(int, siginfo_t* si, void*)
{
    bool* pStop = (bool*)si->si_value.sival_ptr;
    *pStop = true;
}

loop_t measure(time_t sec, long nsec)
{
    bool stop = false;

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = myHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = (void*) &stop;

    timer_t tid;

    if(timer_create(CLOCK_REALTIME, &sev, &tid))
    {
        perror("timer_create");
    }

    struct itimerspec its;
    its.it_value.tv_sec = sec;
    its.it_value.tv_nsec = nsec;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0;

    if(timer_settime(tid, 0, &its, nullptr))
    {
        perror("timer_settime");
    }

    double counter = 0.0;
    loop_t nLoops = UINT_MAX;
    struct timespec timeBegin, timeEnd;

    timeBegin = timespec_now();
    loop_t iLoop = incr(nLoops, &counter, &stop);
    timeEnd = timespec_now();

    timer_delete(tid);

//    std::cout << "Counter value: " << counter << std::endl;
//    std::cout << "Time passed: " << timespec_to_ms(timeEnd - timeBegin) << "ms" << std::endl;
//    std::cout << "iLoop: " << iLoop << std::endl;

    return iLoop;
}

struct parameters{
    double a;
    double b;
};

struct parameters calibrator()
{
    auto I4 = (double)measure(4, 0);
    auto I6 = (double)measure(6, 0);

    struct parameters para;
    para.a = (I6 - I4)/(6.0 - 4.0);
    para.b = I4 - para.a * 4.0;
    return para;
}

int main()
{
    std::cout << "Calculate the parameters of the calibration" << std::endl;
    struct parameters para = calibrator();
    std::cout << "Results : a = " << para.a << ", b = " << para.b << std::endl;
    std::cout << std::endl;

    std::cout << "Test the parameters of the calibration (for 10 seconds):"  << std::endl;
    auto loop = (double)measure(10, 0);
    auto loopCal = para.a*10 + para.b;
    std::cout << "The actual number of cycles executed: " << loop << std::endl;
    std::cout << "The calculated number of cycles executed: " << loopCal << std::endl;
    std::cout << "Accuracy : " << (1-std::abs(loop - loopCal) / loop)*100 << "%" << std::endl;
    return 0;
}
