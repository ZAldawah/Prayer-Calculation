#include "GregorianToJulian.h"
#include <chrono>
#include <cmath>

using namespace std::chrono;

// The number of days since the epoch J2000.0
double toJulian(int year, int month, int day, int hour, int minute, int second)
{
    if (month < 3)
    {
        month += 12;
        year -= 1;
    }
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    double JD = day + ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32045 + ((hour - 12) / 24.0) + (minute / 1440.0) + (second / 86400.0);
    return JD;
}

double getCurrentJulianDate() {
    auto now = system_clock::now();
    time_t now_c = system_clock::to_time_t(now);
    
    tm dateInfo;
    localtime_s(&dateInfo, &now_c);  // Use localtime_s instead

    int currentYear = dateInfo.tm_year + 1900;
    int currentMonth = dateInfo.tm_mon + 1;
    int currentDay = dateInfo.tm_mday;
    int currentHour = dateInfo.tm_hour;
    int currentMinute = dateInfo.tm_min;
    int currentSecond = dateInfo.tm_sec;
    return toJulian(currentYear, currentMonth, currentDay, currentHour, currentMinute, currentSecond);
}

double computeObliquity(double JD) {
    double t = (JD - 2451545.0) / 36525.0;
    double epsilon = 23.439292 - 0.000013 * t;
    return epsilon;
}
