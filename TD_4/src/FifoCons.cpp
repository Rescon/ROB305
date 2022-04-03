//
// Created by wangyu980312 on 30/03/2022.
//

#include "FifoCons.h"

FifoCons::FifoCons(Fifo<int> *fifo) : Thread(), fifo(fifo), counter(0) {}

FifoCons::~FifoCons() = default;

void FifoCons::run()
{
    while(isActive)
    {
        try
        {
            fifo->pop(10);
            ++counter;
        }
        catch(const Fifo<int>::EmptyException& e)
        {
            isActive = false;
        }
    }
}

unsigned int FifoCons::getCounter() const
{
    return counter;
}
