#include <cmath>
#include "PrayerFormulas.h"



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
double AstronomicalSSCalculation(double a, double Sun_ApparentLongitude, double Sun_Declination)
{
    return ((1.0 / 15.0) * acos((-sin(a) - (sin(Sun_ApparentLongitude) * sin(Sun_Declination)) / (cos(Sun_ApparentLongitude) * cos(Sun_Declination)))));
}

//Calculate Dhur prayer time
double Dhur(int TimeZone, double Sun_ApparentLongitude, double EquationOfTime)
{
    return (12 + TimeZone - (Sun_ApparentLongitude / 15) - EquationOfTime);
}

//Calculate Asr prayer time
double Asr(int ShadowLength, double Sun_ApparentLongitude, double Sun_Declination)
{
    return ((1.0/15.0) * acos((sin(acot(ShadowLength + tan(Sun_ApparentLongitude - Sun_Declination))) - (sin(Sun_ApparentLongitude) * sin(Sun_Declination))) / (cos(Sun_ApparentLongitude) * cos(Sun_Declination))));
}