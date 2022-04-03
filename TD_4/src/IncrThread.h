//
// Created by wangyu980312 on 14/03/2022.
//

#ifndef TD_4_INCRTHREAD_H
#define TD_4_INCRTHREAD_H

#include "Thread.h"

using loop_t = unsigned long int;
struct Data {
    volatile loop_t nLoops;
    volatile double counter;
    int schedPolicy;
};

class IncrThread : public Thread
{
public :
    // Constructor of IncrThread
    explicit IncrThread(Data* data);

    // Destructor of IncrThread
    ~IncrThread();

    // Handle function
    void run() override;

    // Pointer to the struct Data (Counter)
    Data* data;
};

#endif //TD_4_INCRTHREAD_H
