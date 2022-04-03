//
// Created by wangyu980312 on 30/03/2022.
//

#ifndef TD_4_FIFOPROD_H
#define TD_4_FIFOPROD_H

#include "Thread.h"
#include "Fifo.hpp"

class FifoProd : public Thread
{
public :
    // Constructor of FifoProd
    explicit FifoProd(Fifo<int>* fifo, unsigned int maxCount);

    // Destructor of FifoProd
    ~FifoProd();

    // Handle function
    void run() override;

    // Get tne number of tokens already produced
    unsigned int getCounter() const;

private :
    // Pointer to Fifo
    Fifo<int> *fifo;

    // Number of tokens that have been produced
    unsigned int counter;

    // Number of tokens wanted
    unsigned int maxCount;
};

#endif //TD_4_FIFOPROD_H
