arm-linux-g++ -Wall -Wextra src/main_td1a.cpp src/timespec.cpp -o main_td1a
arm-linux-g++ -Wall -Wextra src/main_td1b.cpp -o main_td1b -lrt
arm-linux-g++ -Wall -Wextra src/main_td1c.cpp src/timespec.cpp -o main_td1c -lrt
arm-linux-g++ -Wall -Wextra src/main_td1d.cpp src/timespec.cpp -o main_td1d -lrt
arm-linux-g++ -Wall -Wextra src/main_td1e.cpp src/timespec.cpp -o main_td1e -lrt
arm-linux-g++ -Wall -Wextra src/pthread_test.cpp src/timespec.cpp -o pthread_test -lrt -lpthread