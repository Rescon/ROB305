//
// Created by wangyu980312 on 30/03/2022.
//

#include "FifoProd.h"

FifoProd::FifoProd(Fifo<int> *fifo, unsigned int maxCount) : Thread(), fifo(fifo), counter(0), maxCount(maxCount) {}

FifoProd::~FifoProd() = default;

void FifoProd::run()
{
    for (unsigned int i = 0; i < maxCount; ++i)
    {
        fifo->push(i);
        ++counter;
    }
}

unsigned int FifoProd::getCounter() const
{
    return counter;
}
