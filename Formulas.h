#ifndef FORMULAS_H
#define FORMULAS_H

double toRadians(double degrees);
double acot(double x);
double AstronomicalSSCalculation(double a, double Longitude, double Declination);
double Dhur(double TimeZone, double Longitude, double EquationOfTime);
double Asr(double ShadowLength, double Longitude, double Declination);

#endif /* FORMULAS_H */