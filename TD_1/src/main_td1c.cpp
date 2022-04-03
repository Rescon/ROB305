//
// Created by wangyu980312 on 03/02/2022.
//

#include "timespec.h"
#include <sstream>

using loop_t = unsigned long int;
void incr(loop_t nLoops, double* pCounter)
{
    for (loop_t iLoop = 0; iLoop < nLoops; ++iLoop)
    {
        *pCounter += 1.0;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: number of arguments. 1 expected : <nLoops>" << std::endl;
        exit(-1);
    }

    std::istringstream iss(argv[1]);
    loop_t nLoops = 0;
    iss >> nLoops;

    double counter = 0.0;
    struct timespec timeBegin, timeEnd;

    timeBegin = timespec_now();
    incr(nLoops, &counter);
    timeEnd = timespec_now();

    std::cout << "Counter value: " << counter << std::endl;
    std::cout << "Time passed: " << (timespec_to_ms(timeEnd - timeBegin)/1000) << "s" << std::endl;
    return 0;
}
