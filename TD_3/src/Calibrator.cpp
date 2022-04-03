//
// Created by wangyu980312 on 30/03/2022.
//

#include <iostream>
#include "Calibrator.h"

Calibrator::Calibrator(double samplingPeriod_ms, unsigned int nSamples)
{
    samples.reserve(nSamples);

    std::cout << "Calculate the parameters of the calibration (for " << samplingPeriod_ms/1000 << " seconds)" << std::endl;
    start(samplingPeriod_ms);
    looper.runLoop();
    stop();

    double sum_x = 0, sum_xx = 0, sum_y = 0, sum_xy = 0;
    for (int i = 0; i<nSamples; ++i)
    {
        sum_x += (i+1)*samplingPeriod_ms;
        sum_y += samples[i];
        sum_xx += (i+1)*samplingPeriod_ms * (i+1)*samplingPeriod_ms;
        sum_xy += (i+1)*samplingPeriod_ms * samples[i];
    }

    a = (nSamples * sum_xy - sum_x * sum_y) / (nSamples * sum_xx - sum_x * sum_x);
    b = (sum_y - a * sum_x) / nSamples;

    std::cout << "Results : a = " << a << ", b = " << b << std::endl;
    std::cout << "Loops used for calculation : " << nLoops(samplingPeriod_ms) << std::endl;
}

Calibrator::~Calibrator() = default;

double Calibrator::nLoops(double duration_ms) const
{
    return a*duration_ms + b;
}

void Calibrator::callback()
{
    samples.push_back(looper.getSample());
    if (samples.size() == samples.capacity())
    {
        looper.stopLoop();
    }
}
