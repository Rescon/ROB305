cmake_minimum_required(VERSION 3.10)
project(TD_5)

set(CMAKE_CXX_STANDARD 11)

add_executable(main_td5 src/main_td5.cpp src/Calibrator.cpp src/Chrono.cpp src/CpuLoop.cpp src/Looper.cpp src/Mutex.cpp src/PeriodicTimer.cpp src/PosixThread.cpp src/Thread.cpp src/Timer.cpp src/timespec.cpp src/CpuLoopMutex.cpp)

find_library(LIBRT rt)
if(LIBRT)
    target_link_libraries(main_td5 ${LIBRT})
endif()

find_library(LIBPTHREAD pthread)
if(LIBPTHREAD)
    target_link_libraries(main_td5 ${LIBPTHREAD})
endif()