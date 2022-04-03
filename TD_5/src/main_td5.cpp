#include <iostream>
#include "Chrono.h"
#include "Mutex.h"
#include "Calibrator.h"
#include "CpuLoop.h"
#include "CpuLoopMutex.h"

int main() {
    // CPU setting
    cpu_set_t  cpuSetting;
    CPU_ZERO(&cpuSetting);
    CPU_SET(0, &cpuSetting);
    sched_setaffinity(0, sizeof(cpu_set_t), &cpuSetting);

    Chrono chrono;
    Mutex mutex(false);
    Calibrator calibrator(1000, 10);

    CpuLoop cpuLoop_A(calibrator);
    CpuLoop cpuLoop_B(calibrator);
    CpuLoop cpuLoop_C(calibrator);

    // Set policy and priority
    int policy = SCHED_RR;
    int priority_A = 90;
    int priority_B = 80;
    int priority_C = 70;

    // Create threads with mutex
    CpuLoopMutex cpuLoopMutex_A(mutex, cpuLoop_A, 40, 10, 10);
    cpuLoopMutex_A.setScheduling(policy, priority_A);

    CpuLoopMutex cpuLoopMutex_B(mutex, cpuLoop_B, 10, -1, -1);
    cpuLoopMutex_B.setScheduling(policy, priority_B);

    CpuLoopMutex cpuLoopMutex_C(mutex, cpuLoop_C, 50, 20, 20);
    cpuLoopMutex_C.setScheduling(policy, priority_C);

    // Start threads
    std::cout << std::endl;
    std::cout << "Start of Thread C (priority 70)" << std::endl;
    cpuLoopMutex_C.start();
    timespec_wait(timespec_from_ms(3000));

    std::cout << "Start of Thread A (priority 90) and B (priority 80)\n" << std::endl;
    cpuLoopMutex_A.start();
    cpuLoopMutex_B.start();

    // Join threads
    cpuLoopMutex_A.join();
    cpuLoopMutex_B.join();
    cpuLoopMutex_C.join();

    chrono.stop();

    std::cout << "Time taken by A : " << cpuLoopMutex_A.execTime_ms() << " ms" << std::endl;
    std::cout << "Time taken by B : " << cpuLoopMutex_B.execTime_ms() << " ms" << std::endl;
    std::cout << "Time taken by C : " << cpuLoopMutex_C.execTime_ms() << " ms" << std::endl;

    std::cout << "Execution Time: " << chrono.lap() << " ms"<< std::endl;
}
