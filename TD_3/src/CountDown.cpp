//
// Created by wangyu980312 on 18/02/2022.
//

#include "CountDown.h"

CountDown::CountDown(int counter) : counter(counter) {}

CountDown::~CountDown() = default;

int CountDown::getCounter() const
{
    return counter;
}

void CountDown::callback()
{
    std::cout << "Counter value : " << counter << std::endl;
    if (counter > 0)
    {
        --counter;
    }
    else
    {
        CountDown::stop();
        std::cout << "CountDown Timer stopped." << std::endl;
        --counter;
    }
}