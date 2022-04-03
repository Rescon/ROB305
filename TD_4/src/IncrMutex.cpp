//
// Created by wangyu980312 on 15/03/2022.
//

#include "IncrMutex.h"

IncrMutex::IncrMutex(Data *data, Mutex *mutex): IncrThread(data), mutex(mutex)
{
    int schedPriority = data->schedPolicy == SCHED_OTHER ? 0 : rand()%99 + 1;
    setScheduling(data->schedPolicy, schedPriority);
}

IncrMutex::~IncrMutex() = default;

void IncrMutex::run()
{
    for(loop_t iLoop=0; iLoop < data->nLoops; ++iLoop)
    {
        Mutex::Lock lock = Mutex::Lock(*mutex);
        data->counter += 1;
        lock.~Lock();
    }
}