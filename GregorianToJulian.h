#ifndef GREGORIANTOJULIAN_H
#define GREGORIANTOJULIAN_H

double toJulian(int year, int month, int day, int hour, int minute, int second);
double getCurrentJulianDate();
double computeObliquity(double JD);

#endif /* GREGORIANTOJULIAN_H */