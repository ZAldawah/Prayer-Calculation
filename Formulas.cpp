#include <cmath>
#include "Formulas.h"



//Define PI
double PI = 3.14159265358979323846264338327950288419716939937510;

//Convert degrees to radians
double toRadians(double degrees) 
{
    return degrees * (PI / 180.0);
}

//Define the arcCotangent function
double acot(double x)
{
    return atan(1/x);
}

//Calculation for Sunrise/Sunset 
double AstronomicalSSCalculation(double a, double Longitude, double Declination)
{
    return ((1.0 / 15.0) * acos((-sin(a) - (sin(Longitude) * sin(Declination)) / (cos(Longitude) * cos(Declination)))));
}

//Calculate Dhur prayer time
double Dhur(double TimeZone, double Longitude, double EquationOfTime)
{
    return (12 + TimeZone - (Longitude / 15) - EquationOfTime);
}

//Calculate Asr prayer time
double Asr(double ShadowLength, double Longitude, double Declination)
{
    return ((1.0/15.0) * acos((sin(acot(ShadowLength + tan(Longitude - Declination))) - (sin(Longitude) * sin(Declination))) / (cos(Longitude) * cos(Declination))));
}