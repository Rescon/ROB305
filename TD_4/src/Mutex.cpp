//
// Created by wangyu980312 on 14/03/2022.
//

#include "Mutex.h"

Mutex::Mutex()
{
    pthread_mutexattr_t mutexAttr;
    pthread_mutexattr_init(&mutexAttr);
    pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_RECURSIVE);

    pthread_mutex_init(&posixId, &mutexAttr);
    pthread_cond_init(&posixCondId, nullptr);

    pthread_mutexattr_destroy(&mutexAttr);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&posixId);
    pthread_cond_destroy(&posixCondId);
}

void Mutex::lock()
{
    pthread_mutex_lock(&posixId);
}

bool Mutex::lock(double timeout_ms)
{
    timespec timeout_ts = timespec_from_ms(timeout_ms);
    return !(bool)pthread_mutex_timedlock(&posixId, &timeout_ts); // If successful, the function shall return zero
}


bool Mutex::trylock()
{
    return !(bool)pthread_mutex_trylock(&posixId);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&posixId);
}


Mutex::Monitor::Monitor(Mutex& mutex) : mutex(mutex) {}

void Mutex::Monitor::wait()
{
    pthread_cond_wait(&mutex.posixCondId, &mutex.posixId);
}


bool Mutex::Monitor::wait(double timeout_ms)
{
    timespec timeout_ts = timespec_from_ms(timeout_ms);
    return !(bool)pthread_cond_timedwait(&mutex.posixCondId, &mutex.posixId, &timeout_ts);
}

void Mutex::Monitor::notify()
{
    pthread_cond_signal(&mutex.posixCondId);
}

void Mutex::Monitor::notifyAll()
{
    pthread_cond_broadcast(&mutex.posixCondId);
}

const char* Mutex::Monitor::TimeoutException::launchingException() noexcept
{
    return "\nTime out Exception!\n";
}


Mutex::Lock::Lock(Mutex& mutex) : Mutex::Monitor(mutex)
{
    mutex.lock();
}

Mutex::Lock::Lock(Mutex& mutex, double timeout_ms) : Mutex::Monitor(mutex)
{

    if(!mutex.lock(timeout_ms))
    {
        throw Mutex::Monitor::TimeoutException();
    }
}

Mutex::Lock::~Lock()
{
    mutex.unlock();
}

Mutex::TryLock::TryLock(Mutex& mutex) : Mutex::Monitor(mutex)
{
    if(!mutex.trylock())
    {
        throw Mutex::Monitor::TimeoutException();
    }
}

Mutex::TryLock::~TryLock()
{
    mutex.unlock();
}