//
// Created by wangyu980312 on 31/03/2022.
//

#include "CpuLoop.h"

CpuLoop::CpuLoop(Calibrator &calibrator) : calibrator(calibrator) {}

CpuLoop::~CpuLoop() = default;

void CpuLoop::runTime(double duration_ms)
{
    runLoop(calibrator.nLoops(duration_ms));
}
