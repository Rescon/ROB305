//
// Created by wangyu980312 on 14/03/2022.
//

#ifndef TD_5_MUTEX_H
#define TD_5_MUTEX_H

#include <pthread.h>
#include <exception>
#include "timespec.h"

class Mutex
{
public :
    // Class that locks a mutex
    class Lock;

    // Class that tries to lock a mutex
    class TryLock;

    // Class that monitors a mutex
    class Monitor;

    // Constructor of Mutex
    Mutex();

    // Constructor of Mutex with a boolean parameter for inversion-safe case
    Mutex(bool isInversionSafe);

    // Destructor of Mutex
    ~Mutex();

private :
    // Posix mutex id
    pthread_mutex_t posixId{};

    // Posix condition attribute of the mutex
    pthread_cond_t posixCondId{};

    // Lock the mutex
    void lock();

    // Lock the mutex with a timeout
    bool lock(double timeout_ms);

    // Try to lock the mutex
    bool trylock();

    // Unlock the mutex
    void unlock();
};

class Mutex::Monitor
{
public :
    // Throws an exception when Lock does not work.
    class TimeoutException;

    // Wait for the posix condition of the mutex
    void wait();

    // Wait for the posix condition of the mutex or the end of a duration
    bool wait(double timeout_ms);

    // Unlock a thread that is in blocked in a waiting condition
    void notify();

    // Unlock all the threads that are blocked in a waiting condition
    void notifyAll();

    // Reference to a Mutex object
    Mutex& mutex;

protected :
    // Constructor of Mutex::Monitor
    explicit Monitor(Mutex& mutex);
};

class Mutex::Monitor::TimeoutException : public std::exception
{
public:
    static const char* launchingException() noexcept;
};

class Mutex::Lock : public Mutex::Monitor
{
public :
    // Constructor of Mutex::Lock
    explicit Lock(Mutex& mutex);

    // Constructor of Mutex::Lock with a timeout
    Lock(Mutex& m, double timeout_ms);

    // Destructor of Mutex::Lock
    ~Lock();
};

class Mutex::TryLock : public Mutex::Monitor
{
public :
    // Constructor of Mutex::TryLock
    explicit TryLock(Mutex& mutex);

    //Destructor of Mutex::TryLock
    ~TryLock();
};

#endif //TD_5_MUTEX_H
