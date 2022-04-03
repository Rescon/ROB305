cmake_minimum_required(VERSION 3.10)
project(TD_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(main_td1a src/main_td1a.cpp src/timespec.cpp)
add_executable(main_td1b src/main_td1b.cpp)
add_executable(main_td1c src/main_td1c.cpp src/timespec.cpp)
add_executable(main_td1d src/main_td1d.cpp src/timespec.cpp)
add_executable(main_td1e src/main_td1e.cpp src/timespec.cpp)
add_executable(main_pthread_test src/pthread_test.cpp)

find_library(LIBRT rt)
if(LIBRT)
    target_link_libraries(main_td1b ${LIBRT})
    target_link_libraries(main_td1d ${LIBRT})
    target_link_libraries(main_td1e ${LIBRT})
    target_link_libraries(main_pthread_test ${LIBRT})
endif()

find_library(LIBPTHREAD pthread)
if(LIBPTHREAD)
    target_link_libraries(main_pthread_test ${LIBPTHREAD})
endif()