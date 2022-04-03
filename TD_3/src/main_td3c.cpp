//
// Created by wangyu980312 on 30/03/2022.
//

#include "CpuLoop.h"
#include "Chrono.h"

int main()
{
    // Calculate the parameters a and b of l(t)=a*t+b
    Chrono chrono;
    Calibrator calibrator(1000, 10);
    CpuLoop cpuloop(calibrator);

    chrono.stop();
    std::cout << "Time passed for calculation : " << chrono.lap() << "ms" << std::endl;
    std::cout << std::endl;

    // Test the parameters
    std::cout << "Test the parameters of the calibration (for 5 seconds)" << std::endl;
    chrono.restart();
    double timeTest = 5000;
    cpuloop.runTime(timeTest);

    double loop = cpuloop.getSample();
    double loopCal = calibrator.nLoops(timeTest);

    std::cout << "The actual number of cycles executed: " << loop << std::endl;
    std::cout << "The calculated number of cycles executed: " << loopCal << std::endl;
    std::cout << "Accuracy : " << (1-std::abs(loop - loopCal) / loop)*100 << "%" << std::endl;

    chrono.stop();
    std::cout << "Time passed for test : " << chrono.lap() << "ms" << std::endl;
    return 0;
}