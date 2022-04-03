//
// Created by wangyu980312 on 15/03/2022.
//

#ifndef TD_4_INCRMUTEX_H
#define TD_4_INCRMUTEX_H

#include "IncrThread.h"
#include "Mutex.h"

class IncrMutex : public IncrThread
{
public :
    // Constructor of IncrMutex
    IncrMutex(Data* data, Mutex* mutex);

    // Destructor of IncrMutex
    ~IncrMutex();


protected :
    // Pointer to the mutex
    Mutex* mutex;

    // Handle function
    void run() override;
};

#endif //TD_4_INCRMUTEX_H
