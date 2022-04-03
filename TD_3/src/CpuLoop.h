//
// Created by wangyu980312 on 31/03/2022.
//

#ifndef TD_3_CPULOOP_H
#define TD_3_CPULOOP_H

#include "Calibrator.h"

class CpuLoop : public Looper
{
public:
    // Constructor of CpuLoop
    explicit CpuLoop(Calibrator& calibrator);

    // Destructor of Calibrator
    ~CpuLoop();

    // Run the Looper objet with a given time
    void runTime(double duration_ms);

private:
    // Reference for a calibrator object
    Calibrator& calibrator;
};

#endif //TD_3_CPULOOP_H
