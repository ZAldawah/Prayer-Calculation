#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>


using namespace std;

//Define PI
double PI = 3.14159265359;

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
double AstronomicalSSCalculation(double a, double Latitude, double Declination)
{
    return ((1.0 / 15.0) * acos((-sin(a) - (sin(Latitude) * sin(Declination)) / (cos(Latitude) * cos(Declination)))));
}

//Calculate Dhur prayer time
double Dhur(double TimeZone, double Longitude, double EqT)
{
    return (12 + TimeZone - (Longitude / 15) - EqT);
}

//Calculate Asr prayer time
double Asr(double Latitude, double Declination, double ShadowLength)
{
    return ((1.0/15.0) * acos((sin(acot(ShadowLength + tan(Latitude - Declination))) - (sin(Latitude) * sin(Declination))) / (cos(Latitude) * cos(Declination))));
}

int main() 
{
    const double FajrAngle = 15.0;
    const double IshaAngle = 15.0;
    const double ShadowLength = 1.0;
    const double TimeZone = -5.0;



    cout << fixed << setprecision(5);  // for a neater output with fixed number of decimal places
    //Print out Fajr time
    cout << Dhur(-5, -95.7006392, 0.12310) - ASS_Calculation(15.0, L, D) << endl;
    //Print out Sunrise time
    cout << Dhur(-5, -95.7006392, 0.12310) + ASS_Calculation(0.833, L, D) << endl;
    //Print out Dhur time
    cout << Dhur(-5, -95.7006392, 0.12310) << endl;
    //Print out Asr time
    cout << Dhur(-5, -95.7006392, 0.12310) + Asr(L, D, ShadowLength) << endl;
    //Print out Sunset time
    cout << Dhur(-5, -95.7006392, 0.12310) - ASS_Calculation(0.833, L, D) << endl;
    //Print out Maghrib time
    cout << Dhur(-5, -95.7006392, 0.12310) + ASS_Calculation(4.0, L, D) << endl;
    //Print out Isha time
    cout << Dhur(-5, -95.7006392, 0.12310) + ASS_Calculation(15.0, L, D) << endl;
    return 0;
}
