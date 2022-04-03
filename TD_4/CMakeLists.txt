cmake_minimum_required(VERSION 3.10)
project(TD_4)

set(CMAKE_CXX_STANDARD 11)

add_executable(main_td4a src/main_td4a.cpp src/timespec.cpp src/PosixThread.cpp src/Thread.cpp src/IncrThread.cpp)
add_executable(main_td4b src/main_td4b.cpp src/timespec.cpp src/PosixThread.cpp src/Thread.cpp src/IncrThread.cpp src/Mutex.cpp src/IncrMutex.cpp)
add_executable(main_td4c src/main_td4c.cpp src/timespec.cpp src/PosixThread.cpp src/Thread.cpp src/Mutex.cpp src/Semaphore.cpp src/SemsphoreCons.cpp src/SemsphoreProd.cpp)
add_executable(main_td4d src/main_td4d.cpp src/timespec.cpp src/PosixThread.cpp src/Thread.cpp src/Mutex.cpp src/Fifo.hpp src/FifoCons.cpp src/FifoProd.cpp)

find_library(LIBPTHREAD pthread)
if(LIBPTHREAD)
    target_link_libraries(main_td4a ${LIBPTHREAD})
    target_link_libraries(main_td4b ${LIBPTHREAD})
    target_link_libraries(main_td4c ${LIBPTHREAD})
    target_link_libraries(main_td4d ${LIBPTHREAD})
endif()