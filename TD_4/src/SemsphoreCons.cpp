//
// Created by wangyu980312 on 15/03/2022.
//

#include "SemsphoreCons.h"

SemaphoreCons::SemaphoreCons(Semaphore* semaphore) : Thread(), semaphore(semaphore), counter(0) {}

SemaphoreCons::~SemaphoreCons() = default;

void SemaphoreCons::run()
{
    while(semaphore->take(10))
    {
        ++counter;
    }
}

unsigned int SemaphoreCons::getCounter() const
{
    return counter;
}
