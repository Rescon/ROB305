cmake_minimum_required(VERSION 3.10)
project(TD_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(main_td2a src/main_td2a.cpp)
add_executable(main_td2b src/main_td2b.cpp src/timespec.cpp)
add_executable(main_td2c src/main_td2c.cpp src/timespec.cpp)

find_library(LIBRT rt)
if(LIBRT)
    target_link_libraries(main_td2b ${LIBRT})
    target_link_libraries(main_td2c ${LIBRT})
endif()

find_library(LIBPTHREAD pthread)
if(LIBPTHREAD)
    target_link_libraries(main_td2a ${LIBPTHREAD})
    target_link_libraries(main_td2b ${LIBPTHREAD})
    target_link_libraries(main_td2c ${LIBPTHREAD})
endif()