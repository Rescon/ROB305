//
// Created by wangyu980312 on 30/03/2022.
//

#ifndef TD_4_FIFOCONS_H
#define TD_4_FIFOCONS_H

#include "Thread.h"
#include "Fifo.hpp"

class FifoCons : public Thread
{
public :
    // Constructor of FifoCons
    explicit FifoCons(Fifo<int> *fifo);

    // Destructor of FifoCons
    ~FifoCons();

    // Handle function
    void run() override;

    // Get tne number of tokens already consumed
    unsigned int getCounter() const;

private :
    // Pointer to Fifo
    Fifo<int> *fifo;

    // Number of tokens that have been consumed
    unsigned int counter;
};

#endif //TD_4_FIFOCONS_H
