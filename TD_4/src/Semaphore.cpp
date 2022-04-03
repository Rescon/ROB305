//
// Created by wangyu980312 on 15/03/2022.
//

#include "Semaphore.h"

Semaphore::Semaphore(unsigned int counter, unsigned int maxCount) : counter(counter), maxCount(maxCount), mutex() {}

Semaphore::~Semaphore() = default;

void Semaphore::give()
{
    Mutex::Lock lock(mutex);
    if (counter < maxCount)
    {
        ++counter;
    }
    lock.notifyAll();
    lock.~Lock();
}

void Semaphore::take()
{
    Mutex::Lock lock(mutex);
    if (counter == 0)
    {
        lock.wait();
    }
    else
    {
        --counter;
    }
    lock.notifyAll();
    lock.~Lock();
}

bool Semaphore::take(double timeout_ms) {
    Mutex::Lock lock(mutex);
    if (counter == 0)
    {
        lock.wait(timeout_ms);
        lock.notifyAll();
        lock.~Lock();
        return false;
    }
    else
    {
        --counter;
        lock.notifyAll();
        lock.~Lock();
        return true;
    }
}
