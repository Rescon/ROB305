//
// Created by wangyu980312 on 18/02/2022.
//

#include "CountDown.h"
#include "Chrono.h"

int main()
{
    CountDown countDown(10);
    Chrono chrono;

    countDown.start(1000);
    while (countDown.getCounter() >= 0) {}

    chrono.stop();
    std::cout << "Time passed: " << chrono.lap() << "ms." << std::endl;

    return 0;
}