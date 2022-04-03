//
// Created by wangyu980312 on 10/02/2022.
//

#include <iostream>
#include <pthread.h>
#include <vector>

using loop_t = unsigned long int;
struct Data {
    loop_t nLoops;
    double counter;
};

void incr(loop_t nLoops, double* pCounter)
{
    for (loop_t iLoop=0; iLoop<nLoops; ++iLoop)
    {
        *pCounter += 1.0;
    }
}

void* call_incr(void* v_data)
{
    Data* p_data = (Data*) v_data;
    incr(p_data -> nLoops, &p_data -> counter);
    return v_data;
}


int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Error: number of arguments. 2 expected : <nLoops> <nTasks>" << std::endl;
        exit(-1);
    }

    loop_t nLoops = std::stoi(argv[1]);
    unsigned int nTasks = std::stoi(argv[2]);
    std::cout << "nLoops : " << nLoops << std::endl;
    std::cout << "nTasks : " << nTasks << std::endl;

    Data data = {nLoops, 0.0};

    // Create nTasks threads
    std::vector<pthread_t> incrementThread(nTasks);
    for (unsigned int i=0; i<nTasks; ++i)
    {
        pthread_create(&incrementThread[i], NULL, call_incr, (void*)&data);
    }

    // Join nTasks threads
    for (unsigned int i=0; i<nTasks; ++i) {
        pthread_join(incrementThread[i], NULL);
    }

    std::cout << "Counter : " <<  data.counter << std::endl;
    return 0;
}