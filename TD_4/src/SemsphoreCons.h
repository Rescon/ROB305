//
// Created by wangyu980312 on 15/03/2022.
//

#ifndef TD_4_SEMSPHORECONS_H
#define TD_4_SEMSPHORECONS_H

#include "Thread.h"
#include "Semaphore.h"

class SemaphoreCons : public Thread
{
public :
    // Constructor of SemaphoreCons
    explicit SemaphoreCons(Semaphore* semaphore);

    // Destructor of SemaphoreCons
    ~SemaphoreCons();

    // Handle function
    void run() override;

    // Get tne number of tokens already consumed
    unsigned int getCounter() const;

private :
    // Pointer to the object semaphore
    Semaphore *semaphore;

    // Number of tokens that have been consumed
    unsigned int counter;
};

#endif //TD_4_SEMSPHORECONS_H
