//
// Created by wangyu980312 on 30/03/2022.
//

#include <vector>
#include "IncrThread.h"

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
    double threadTime = 0;

    // Start nTasks threads
    std::vector<IncrThread*> incrementThread(nTasks);
    for (unsigned int i=0; i<nTasks; ++i)
    {
        incrementThread[i] = new IncrThread(&data);
        incrementThread[i]->start();
    }

    // Join nTasks threads
    for (unsigned int i=0; i<nTasks; ++i)
    {
        incrementThread[i]->join();
        threadTime += incrementThread[i]->execTime_ms();
    }

    std::cout << "Counter : " <<  (incrementThread[0]->data)->counter << std::endl;
    std::cout << "Time passed by all the threads : " << threadTime << " ms" << std::endl;

    return 0;
}
