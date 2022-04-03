//
// Created by wangyu980312 on 01/02/2022.
//

#include "timespec.h"

int main()
{
    // Test timespec_now;
    std::cout << "Test timespec_now" << std::endl;
    struct timespec time_now;
    time_now = timespec_now();
    std::cout << "Seconds:" << time_now.tv_sec << ", Nanosecond: " << time_now.tv_nsec << "\n" << std::endl;

    // Test timespec_negate;
    std::cout << "Test timespec_negate" << std::endl;
    struct timespec time_neg;
    time_neg = timespec_negate(time_now);
    std::cout << "Seconds:" << time_neg.tv_sec << ", Nanosecond: " << time_neg.tv_nsec << "\n" << std::endl;

    // Test timespec_to_ms
    double time_to_ms;
    std::cout << "Test timespec_to_ms" << std::endl;
    time_to_ms = timespec_to_ms(time_now);
    std::cout << "Millisecond:" << time_to_ms << "ms" << "\n" << std::endl;

    // Test timespec_from_ms
    std::cout << "Test timespec_from_ms" << std::endl;
    struct timespec time_from_ms;
    time_from_ms = timespec_from_ms(time_to_ms);
    std::cout << "Seconds:" << time_from_ms.tv_sec << ", Nanosecond: " << time_from_ms.tv_nsec << "\n" << std::endl;

    // Test timespec_add
    std::cout << "Test timespec_add" << std::endl;
    struct timespec time_add;
    time_add = timespec_add(time_now, time_neg);
    std::cout << "Seconds:" << time_add.tv_sec << ", Nanosecond: " << time_add.tv_nsec << "\n" << std::endl;

    // Test timespec_sub
    std::cout << "Test timespec_sub" << std::endl;
    struct timespec time_sub;
    time_sub = timespec_subtract(time_now, time_from_ms);
    std::cout << "Seconds:" << time_sub.tv_sec << ", Nanosecond: " << time_sub.tv_nsec << "\n" << std::endl;

    // Test timespec_wait
    std::cout << "Test timespec_wait" << std::endl;
    struct timespec delay_ts;
    delay_ts.tv_nsec = 500000000;    // 500ms
    delay_ts.tv_sec = 0;

    struct timespec start, end, diff;
    start = timespec_now();
    timespec_wait(delay_ts);
    end = timespec_now();

    diff = timespec_subtract(end, start);
    std::cout << "Elapsed time: " << "Secondes:" << diff.tv_sec << ", Nanosec: " << diff.tv_nsec << "\n" << std::endl;

    // Test operators
    struct timespec time1, time2;
    time1.tv_nsec = 500000000;
    time1.tv_sec = 0;
    time2.tv_nsec = 0;
    time2.tv_sec = 2;

    std::cout << "Start testing operators" << std::endl;
    std::cout << "time1: " << "Secondes:" << time1.tv_sec << ", Nanosec: " << time1.tv_nsec << std::endl;
    std::cout << "time2: " << "Secondes:" << time2.tv_sec << ", Nanosec: " << time2.tv_nsec << std::endl;
    std::cout << std::endl;

    // Test operator of negation -
    std::cout << "Test operator of negation -" << std::endl;
    struct timespec time1_neg;
    time1_neg = -time1;
    std::cout << "-time1: " << "Secondes:" << time1_neg.tv_sec << ", Nanosec: " << time1_neg.tv_nsec << "\n"
              << std::endl;

    // Test operator of addition +
    std::cout << "Test operator of addition +" << std::endl;
    time_add = time1 + time2;
    std::cout << "time1 + time2: " << "Secondes:" << time_add.tv_sec << ", Nanosec: " << time_add.tv_nsec << "\n"
              << std::endl;

    // Test operator of subtraction -
    std::cout << "Test operator of subtraction -" << std::endl;
    time_sub = time1 - time2;
    std::cout << "time1 - time2: " << "Secondes:" << time_sub.tv_sec << ", Nanosec: " << time_sub.tv_nsec << "\n"
              << std::endl;

    // Test operator of addition +=
    std::cout << "Test operator of addition +=" << std::endl;
    time1 += time2;
    std::cout << "time1 += time2: " << "Secondes:" << time1.tv_sec << ", Nanosec: " << time1.tv_nsec << "\n"
              << std::endl;

    // Test operator of subtraction -=
    std::cout << "Test operator of subtraction -=" << std::endl;
    time1 -= time2;
    std::cout << "time1 -= time2: " << "Secondes:" << time1.tv_sec << ", Nanosec: " << time1.tv_nsec << "\n"
              << std::endl;

    // Test operator of equal condition ==
    std::cout << "Test operator of equal condition ==" << std::endl;
    std::cout << "time1==time1 " << (time1 == time1) << std::endl;
    std::cout << "time1==time2 " << (time1 == time2) << std::endl;
    std::cout << std::endl;

    // Test operator of notequal condition !=
    std::cout << "Test operator of notequal condition !=" << std::endl;
    std::cout << "time1!=time1 " << (time1 != time1) << std::endl;
    std::cout << "time1!=time2 " << (time1 != time2) << std::endl;
    std::cout << std::endl;

    // Test operator of smaller condition <
    std::cout << "Test operator of smaller condition <" << std::endl;
    std::cout << "time1<time2 " << (time1 < time2) << std::endl;
    std::cout << "time2<time1 " << (time2 < time1) << std::endl;
    std::cout << std::endl;

    // Test operator of bigger condition >
    std::cout << "Test operator of bigger condition >" << std::endl;
    std::cout << "time1>time2 " << (time1 > time2) << std::endl;
    std::cout << "time2>time1 " << (time2 > time1) << std::endl;
    std::cout << std::endl;

    std::cout << "End testing operators" << std::endl;
    return 0;
}
