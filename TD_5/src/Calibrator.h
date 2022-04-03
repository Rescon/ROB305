//
// Created by wangyu980312 on 30/03/2022.
//

#ifndef TD_5_CALIBRATOR_H
#define TD_5_CALIBRATOR_H

#include <vector>
#include "PeriodicTimer.h"
#include "Looper.h"

class Calibrator : public PeriodicTimer
{
public:
    // Constructor of Calibrator
    Calibrator(double samplingPeriod_ms, unsigned int nSamples);

    // Destructor of Calibrator
    ~Calibrator();

    // Calculate the estimated number of loops
    double nLoops(double duration_ms) const;

protected:
    // Handle function
    void callback() override;

private:
    // Parameter a
    double a;

    // Parameter b
    double b;

    // Vector of samples
    std::vector<double> samples;

    // Object of Looper
    Looper looper;
};

#endif //TD_5_CALIBRATOR_H
