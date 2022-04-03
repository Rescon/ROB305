//
// Created by wangyu980312 on 17/02/2022.
//

#include "Chrono.h"
#include <unistd.h>

int main()
{
    struct timespec timeBegin;
    struct timespec timeEnd;

    std::cout << "Start testing the class Chrono." << std::endl;

    Chrono chrono;
    timeBegin = timespec_now();

    std::cout << "The chrono is created." << std::endl;
    std::cout << "Now the status of the chrono is: " << chrono.isActive() << std::endl;
    std::cout << std::endl;

    std::cout << "Sleeping for 5000 ms" << std::endl;
    sleep(5);

    std::cout << "Time measured by Chrono :" << chrono.lap() << " ms" << std::endl;

    std::cout << "Sleeping for another 5000 ms" << std::endl;
    sleep(5);

    chrono.stop();
    timeEnd = timespec_now();
    std::cout << std::endl;
    std::cout << "Thr Chrono is stopped" << std::endl;
    std::cout << "Now the status of the chrono is: " << chrono.isActive() << std::endl;

    std::cout << std::endl;
    std::cout << "Time measured by TimeSpec :" << (timespec_to_ms(timeEnd-timeBegin)) << "ms" << std::endl;
    std::cout << "Time measured by Chrono :" << chrono.lap() << " ms" << std::endl;

    std::cout << "End testing the class Chrono." << std::endl;
    return 0;
}
