arm-linux-g++ -Wall -Wextra src/main_td2a.cpp -o main_td2a -lpthread
arm-linux-g++ -Wall -Wextra src/main_td2b.cpp src/timespec.cpp -o main_td2b -lrt -lpthread
arm-linux-g++ -Wall -Wextra src/main_td2c.cpp src/timespec.cpp -o main_td2c -lrt -lpthread