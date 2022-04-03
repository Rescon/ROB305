//
// Created by wangyu980312 on 15/03/2022.
//

#ifndef TD_4_SEMSPHOREPROD_H
#define TD_4_SEMSPHOREPROD_H

#include "Thread.h"
#include "Semaphore.h"

class SemaphoreProd : public Thread
{
public :
    // Constructor
    explicit SemaphoreProd(Semaphore* semaphore, unsigned int maxCount);

    // Destructor
    ~SemaphoreProd();

    // Handling function
    void run() override;

    // Get tne number of tokens already produced
    unsigned int getCounter() const;

private :
    // Pointer to the object semaphore
    Semaphore *semaphore;

    // Number of tokens that have been produced
    unsigned int counter;

    // Number of tokens wanted
    unsigned int maxCount;
};

#endif //TD_4_SEMSPHOREPROD_H
