#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;

//Define PI
float PI = 3.14159265359;



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



//Calculate Dhur prayer time
double Dhur(double TimeZone, double Longitude, double EqT)
{
    return (12 + TimeZone - (Longitude / 15) - EqT);
}



//Calculate Asr prayer time
double Asr(double Latitude, double Declination, int ShadowLength)
{
    return ((1.0/15.0) * acos((sin(acot(ShadowLength + tan(Latitude - Declination))) - (sin(Latitude) * sin(Declination))) / (cos(Latitude) * cos(Declination))));
}



int main() 
{
    const double ShadowLength = 1;
    const double TimeZone = -5;
    double d = 8692.168495;

    // Note: You must convert all your degrees to radians when using trigonometric functions.
    double g = fmod((toRadians(357.529) + toRadians(0.98560028) * d), 2.0 * PI);
    double q = fmod((toRadians(280.459) + toRadians(0.98564736) * d), 2.0 * PI);
    double L = fmod((q + 1.915 * sin(g) + 0.020 * sin(2 * g)), 2.0 * PI);
    double R = 1.00014 - 0.01671 * cos(g) - 0.00014 * cos(2 * g);
    double e = toRadians(23.439 - 0.00000036 * d);
    double RA = atan2(cos(e) * sin(L), cos(L)) / 15;  // using atan2, also removed redundancy
    double D = asin(sin(e) * sin(L));
    double EqT = q / 15 - RA;

    // Convert RA from radians to some unit that fits the division by 15 in EqT's calculation, if necessary.

    cout << fixed << setprecision(5);  // for a neater output with fixed number of decimal places
    

    //Print out Dhur time
    cout << Dhur(-5, -95.7006392, 0.12310) << endl;
    //Print out Asr time
    cout << Dhur(-5, -95.7006392, 0.12310) + Asr(L, D, ShadowLength) << endl;
    return 0;
}
