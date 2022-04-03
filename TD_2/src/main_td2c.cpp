//
// Created by wangyu980312 on 17/02/2022.
//

#include <iostream>
#include <pthread.h>
#include <vector>
#include "timespec.h"

using loop_t = unsigned long int;
struct Data {
    loop_t nLoops;
    double counter;
    bool protect;
    pthread_mutex_t mutex;
};

void incr(loop_t nLoops, double* pCounter)
{
    for (loop_t iLoop = 0; iLoop < nLoops; ++iLoop)
    {
        *pCounter += 1.0;
    }
}

void* call_incr(void* v_data)
{
    Data* p_data = (Data*) v_data;
    if (p_data->protect) {
        pthread_mutex_lock(&p_data->mutex);
        incr(p_data -> nLoops, &p_data -> counter);
        pthread_mutex_unlock(&p_data->mutex);
    } else {
        incr(p_data -> nLoops, &p_data -> counter);
    }

    return v_data;
}


int main(int argc, char* argv[])
{
    if (argc != 4 and argc != 5)
    {
        std::cerr << "Error: number of arguments. 3 or 4 expected : <nLoops> <nTasks> <schedPolicy> <protect>" << std::endl;
        exit(-1);
    }

    loop_t nLoops = std::stoi(argv[1]);
    unsigned int nTasks = std::stoi(argv[2]);
    bool protect = (argc == 5 && std::stoi(argv[4]));

    int schedPolicy;
    if (std::string(argv[3]) == "SCHED_RR")
    {
        schedPolicy = SCHED_RR;
    }
    else if (std::string(argv[3]) == "SCHED_FIFO")
    {
        schedPolicy = SCHED_FIFO;
    }
    else
    {
        schedPolicy = SCHED_OTHER;
    }

    std::cout << "nLoops : " << nLoops << std::endl;
    std::cout << "nTasks : " << nTasks << std::endl;
    std::cout << "schedPolicy : " << schedPolicy << std::endl;
    std::cout << "protect : " << protect << std::endl;

    // Main priority
    struct sched_param schedParam;
    schedParam.sched_priority = sched_get_priority_max(schedPolicy);
    pthread_setschedparam(pthread_self(), schedPolicy, &schedParam);

    // Thread priority
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr, schedPolicy);

    sched_param schedParams;
    int priority = rand()%99 + 1;
    schedParams.sched_priority = (schedPolicy == SCHED_OTHER) ? 0 : priority;
    pthread_attr_setschedparam(&attr, &schedParams);

    // Set mutex
    pthread_mutex_t mutex;
    Data data = {nLoops, 0.0, protect, mutex};
    if (protect) pthread_mutex_init(&data.mutex, nullptr);

    struct timespec timeBegin, timeEnd;
    timeBegin = timespec_now();

    // Create nTasks pthreads
    std::vector<pthread_t> incrementThread(nTasks);
    for (unsigned int i=0; i<nTasks; ++i)
    {
        pthread_create(&incrementThread[i], &attr, call_incr, (void*)&data);
    }
    pthread_attr_destroy(&attr);

    // Join nTasks threads
    for (unsigned int i=0; i<nTasks; ++i)
    {
        pthread_join(incrementThread[i], nullptr);
    }
    pthread_mutex_destroy(&data.mutex);

    timeEnd = timespec_now();

    std::cout << "Duration : " << timespec_to_ms(timeEnd - timeBegin)  << " ms" << std::endl;
    std::cout << "Counter : " <<  data.counter << std::endl;

    return 0;
}
