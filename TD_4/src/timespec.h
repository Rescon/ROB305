//
// Created by wangyu980312 on 01/02/2022.
//

#ifndef TD_4_TIMESPEC_H
#define TD_4_TIMESPEC_H

#include <iostream>
#include <ctime>
#include <cerrno>

// Transform from timespec to seconds
double timespec_to_ms(const timespec &time_ts);

// Transform from ms to timespec
timespec timespec_from_ms(double time_ms);

// Get the current time
timespec timespec_now();

// Negate the timespec
timespec timespec_negate(const timespec &time_ts);

// Add two timespec
timespec timespec_add(const timespec &time1_ts, const timespec &time2_ts);

// Subtract two timespec
timespec timespec_subtract(const timespec &time1_ts, const timespec &time2_ts);

// Wait for a timespec
timespec timespec_wait(const timespec &delay_ts);

// The operator of negation -
timespec operator-(const timespec &time_ts);

// The operator of addition +
timespec operator+(const timespec &time1_ts, const timespec &time2_ts);

// The operator of subtraction -
timespec operator-(const timespec &time1_ts, const timespec &time2_ts);

// The operator of addition +=
timespec &operator+=(timespec &time_ts, const timespec &delay_ts);

// The operator of subtraction -=
timespec &operator-=(timespec &time_ts, const timespec &delay_ts);

// The operator of equal condition ==
bool operator==(const timespec &time1_ts, const timespec &time2_ts);

// The operator of notequal condition !=
bool operator!=(const timespec &time1_ts, const timespec &time2_ts);

// The operator of smaller condition <
bool operator<(const timespec &time1_ts, const timespec &time2_ts);

// The operator of bigger condition >
bool operator>(const timespec &time1_ts, const timespec &time2_ts);

#endif //TD_4_TIMESPEC_H
