//
// Created by wangyu980312 on 03/03/2022.
//

#ifndef TD_5_POSIXTHREAD_H
#define TD_5_POSIXTHREAD_H

#include <pthread.h>
#include <exception>
#include "timespec.h"

class PosixThread {
public:
    // Constructor of PosixThread
    PosixThread();

    // Constructor based on the id of existing thread
    explicit PosixThread(pthread_t posixId);

    // Destructor of PosixThread
    ~PosixThread();

    // Start the thread
    void start(void*(*threadFunc)(void*), void* threadArg);

    // Terminate the thread
    void join() const;

    // Terminate the thread with a timeout
    bool join(double timeout_ms) const;

    // Set the scheduling of the thread
    bool setScheduling(int schedPolicy, int priority);

    // Get the scheduling of the thread
    bool getScheduling(int* pSchedPolicy, int* pPriority);

    // The exception must be generated if the Posix task does not exist (for the 2nd constructor)
    class Exception;

protected:
    // flag of the status (true if the task is active)
    bool isActive = false;

private:
    // Posix thread id
    pthread_t posixId;

    // Posix thread attribute
    pthread_attr_t posixAttr{};
};

class PosixThread::Exception : public std::exception
{
public:
    static const char* launchingException() noexcept;
};

#endif //TD_5_POSIXTHREAD_H
