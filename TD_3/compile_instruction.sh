arm-linux-g++ -Wall -Wextra main_td3a.cpp timespec.cpp Chrono.cpp -o main_td3a -lrt
arm-linux-g++ -Wall -Wextra main_td3b.cpp timespec.cpp Chrono.cpp Timer.cpp PeriodicTimer.cpp CountDown.cpp -o main_td3b -lrt
arm-linux-g++ -Wall -Wextra main_td3c.cpp timespec.cpp Chrono.cpp Timer.cpp PeriodicTimer.cpp Looper.cpp Calibrator.cpp CpuLoop.cpp -o main_td3c -lrt -Wno-psabi