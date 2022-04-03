//
// Created by wangyu980312 on 03/03/2022.
//

#include "PosixThread.h"

PosixThread::PosixThread()
{
    posixId = 0;

    pthread_attr_init(&posixAttr);
    pthread_attr_setinheritsched(&posixAttr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&posixAttr, SCHED_OTHER);

    sched_param schedParams;
    schedParams.sched_priority = 0;
    pthread_attr_setschedparam(&posixAttr, &schedParams);
}

PosixThread::PosixThread(pthread_t posixId) : posixId(posixId)
{
    pthread_attr_init(&posixAttr);
    pthread_attr_setinheritsched(&posixAttr, PTHREAD_EXPLICIT_SCHED);

    sched_param schedParams;
    int policy;
    if(pthread_getschedparam(this -> posixId, &policy, &schedParams))
    {
        throw PosixThread::Exception();
    }
    else
    {
        isActive = true;
        pthread_attr_setschedpolicy(&posixAttr, policy);
        pthread_attr_setschedparam(&posixAttr, &schedParams);
    }
}

PosixThread::~PosixThread()
{
    pthread_attr_destroy(&posixAttr);
}

void PosixThread::start(void *(*threadFunc)(void *), void *threadArg)
{
    pthread_create(&posixId, &posixAttr, threadFunc, threadArg);
    isActive = true;
}

void PosixThread::join() const
{
    pthread_join(posixId, nullptr);
}

bool PosixThread::join(double timeout_ms) const
{
    timespec timeout(timespec_from_ms(timeout_ms));
    return pthread_timedjoin_np(posixId, nullptr, &timeout);
}

bool PosixThread::setScheduling(int schedPolicy, int priority)
{
    sched_param schedParam;
    schedParam.sched_priority = priority;

    pthread_attr_setschedpolicy(&posixAttr, schedPolicy);
    pthread_attr_setschedparam(&posixAttr, &schedParam);

    if(isActive)
    {
        pthread_setschedparam(posixId, schedPolicy, &schedParam);
    }
    return isActive;
}

bool PosixThread::getScheduling(int *pSchedPolicy, int *pPriority)
{
    sched_param schedParam;
    *pPriority = schedParam.sched_priority;
    if(isActive)
    {
        pthread_getschedparam(posixId, pSchedPolicy, &schedParam);
    }
    else
    {
        pthread_attr_getschedpolicy(&posixAttr, pSchedPolicy);
        pthread_attr_getschedparam(&posixAttr, &schedParam);
    }
    return isActive;
}

const char *PosixThread::Exception::launchingException() noexcept
{
    return "The Posix task does not exist!";
}
