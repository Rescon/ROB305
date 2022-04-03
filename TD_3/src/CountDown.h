//
// Created by wangyu980312 on 18/02/2022.
//

#ifndef TD_3_COUNTDOWN_H
#define TD_3_COUNTDOWN_H

#include "PeriodicTimer.h"

class CountDown : public PeriodicTimer
{
public:
    // Constructor of CountDown
    explicit CountDown(int counter);

    // Destructor of CountDown
    ~CountDown();

    // Get the value of counter
    int getCounter() const ;

protected:
    // handle function
    void callback() override;

private:
    // The value of counter
    int counter;
};

#endif //TD_3_COUNTDOWN_H
