arm-linux-g++ -Wall -Wextra main_td2a.cpp -o main_td2a -lpthread
arm-linux-g++ -Wall -Wextra main_td2b.cpp timespec.cpp -o main_td2b -lrt -lpthread
arm-linux-g++ -Wall -Wextra main_td2c.cpp timespec.cpp -o main_td2c -lrt -lpthread