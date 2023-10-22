#ifndef PRAYERFORMULAS_H
#define PRAYERFORMULAS_H

extern double PI;
double toRadians(double degrees);
double acot(double x);
double AstronomicalSSCalculation(double a, double Sun_ApparentLongitude, double Sun_Declination);
double Dhur(int TimeZone, double Sun_ApparentLongitude, double EquationOfTime);
double Asr(int ShadowLength, double Sun_ApparentLongitude, double Sun_Declination);

#endif /* PRAYERFORMULAS_H */