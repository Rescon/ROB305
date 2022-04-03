//
// Created by wangyu980312 on 30/03/2022.
//

#include <vector>
#include "IncrMutex.h"

int main(int argc, char* argv[]) {
    if (argc != 4)
    {
        std::cerr << "Error: number of arguments. 3 expected : <nLoops> <nTasks> <schedPolicy>" << std::endl;
        exit(-1);
    }

    loop_t nLoops = std::stoi(argv[1]);
    unsigned int nTasks = std::stoi(argv[2]);

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

    Data data = {nLoops, 0.0, schedPolicy};
    Mutex mutex;
    double ThreadTime = 0;

    // Start nTasks threads
    std::vector<IncrMutex*> incrementMutexThread(nTasks);
    for (unsigned int i=0; i<nTasks; ++i)
    {
        incrementMutexThread[i] = new IncrMutex(&data, &mutex);
        incrementMutexThread[i]->start();
    }

    // Join nTasks threads
    for (unsigned int i=0; i<nTasks; ++i)
    {
        incrementMutexThread[i]->join();
        ThreadTime += incrementMutexThread[i]->execTime_ms();
    }

    std::cout << "Counter : " <<  (incrementMutexThread[0]->data)->counter << std::endl;
    std::cout << "Time passed by all the threads : " << ThreadTime << " ms" << std::endl;

    return 0;
}
