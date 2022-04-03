//
// Created by wangyu980312 on 15/03/2022.
//

#include "SemsphoreProd.h"

SemaphoreProd::SemaphoreProd(Semaphore *semaphore, unsigned int maxCount) : Thread(), semaphore(semaphore), counter(0), maxCount(maxCount) {}

SemaphoreProd::~SemaphoreProd() = default;

void SemaphoreProd::run() {
    for (unsigned int i = 0; i < maxCount; ++i)
    {
        semaphore->give();
        ++counter;
    }
}

unsigned int SemaphoreProd::getCounter() const {
    return counter;
}


