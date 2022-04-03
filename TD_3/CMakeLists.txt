cmake_minimum_required(VERSION 3.10)
project(TD_3)

set(CMAKE_CXX_STANDARD 11)

add_executable(main_td3a src/main_td3a.cpp src/timespec.cpp src/Chrono.cpp)
add_executable(main_td3b src/main_td3b.cpp src/timespec.cpp src/Chrono.cpp src/Timer.cpp src/PeriodicTimer.cpp src/CountDown.cpp)
add_executable(main_td3c src/main_td3c.cpp src/timespec.cpp src/Chrono.cpp src/Timer.cpp src/PeriodicTimer.cpp src/Looper.cpp src/Calibrator.cpp src/CpuLoop.cpp)

find_library(LIBRT rt)
if(LIBRT)
    target_link_libraries(main_td3b ${LIBRT})
    target_link_libraries(main_td3c ${LIBRT})
endif()