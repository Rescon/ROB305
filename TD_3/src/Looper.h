//
// Created by wangyu980312 on 30/03/2022.
//

#ifndef TD_3_LOOPER_H
#define TD_3_LOOPER_H

#include <cfloat>

class Looper
{
public:
    // Constructor of Looper
    Looper();

    // Destructor of Looper
    ~Looper();

    // Run a loop for a given number of iterations
    double runLoop(double nLoops = DBL_MAX);

    // Get the number of loops that have been executed so far (get iLoop)
    double getSample() const;

    // Stop the looper and return the number of loops that have been executed
    double stopLoop();

private:
    // The flag to stop looper
    bool doStop;

    // The number of loops that have been executed
    double iLoop;
};

#endif //TD_3_LOOPER_H
