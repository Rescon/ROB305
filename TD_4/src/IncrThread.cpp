//
// Created by wangyu980312 on 14/03/2022.
//

#include "IncrThread.h"

IncrThread::IncrThread(Data* data) : Thread(), data(data)
{
    int schedPriority = data->schedPolicy == SCHED_OTHER ? 0 : rand()%99 + 1;
    setScheduling(data->schedPolicy, schedPriority);
}

IncrThread::~IncrThread() = default;

void IncrThread::run()
{
    for(loop_t iLoop=0; iLoop < data->nLoops; ++iLoop)
    {
        data -> counter += 1;
    }
}
