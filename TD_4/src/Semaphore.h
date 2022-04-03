//
// Created by wangyu980312 on 15/03/2022.
//

#ifndef TD_4_SEMAPHORE_H
#define TD_4_SEMAPHORE_H

#include <climits>
#include "Mutex.h"

class Semaphore
{
public :
    // Constructor of Semaphore
    explicit Semaphore(unsigned int counter = 0, unsigned int maxCount = UINT_MAX);

    // Destructor of Semaphore
    ~Semaphore();

    // Add a token
    void give();

    // Remove a token
    void take();

    // Remove a token with waiting for a certain time if the Semaphore is empty
    bool take(double timeout_ms);

private :
    // Number of tokens
    unsigned int counter;

    // Maximal number of tokens that can be stored
    unsigned int maxCount;

    // Mutex object
    Mutex mutex;
};

#endif //TD_4_SEMAPHORE_H
