//
// Created by wangyu980312 on 10/02/2022.
//


#include <csignal>
#include <climits>
#include <vector>
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

    return iLoop;
}

struct parameters{
    double a;
    double b;
};

struct parameters calibratorRegression(int num)
{
    std::vector<double> x(num), y(num);
    for (int i = 0; i<num; ++i)
    {
        std::cout << "Calibrator task : " << i+1 << std::endl;
        x[i] = i+1;
        y[i] = (double)measure(i+1, 0);
    }

    double sum_x = 0, sum_xx = 0, sum_y = 0, sum_xy = 0;
    for (int i = 0; i<num; ++i)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xx += x[i]*x[i];
        sum_xy += x[i]*y[i];
    }

    struct parameters para;
    para.a = (num * sum_xy - sum_x * sum_y) / (num * sum_xx - sum_x * sum_x);
    para.b = (sum_y - para.a * sum_x) / num;
    return para;
}

int main(int argc, char* argv[])
{
    int num = 5;
    if (argc == 2)
    {
        num = std::stoi(argv[1]);
    }

    std::cout << "Calculate the parameters of the calibration" << std::endl;
    struct parameters para = calibratorRegression(num);
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

