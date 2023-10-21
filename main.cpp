#include <iostream>
#include <iomanip>
#include <chrono>
#include "Formulas.cpp"
#include "AstronomicalValues.h"

using namespace std;
using namespace std::chrono;



int main() 
{
    const double FajrAngle = 15.0;
    const double IshaAngle = 15.0;
    const double ShadowLength = 1.0;
    const double TimeZone = -5.0;



    cout << fixed << setprecision(5);  // for a neater output with fixed number of decimal places
    //Print out Fajr time
    cout << Dhur(TimeZone, Longitude, EquationOfTime) - AstronomicalSSCalculation(15.0, Longitude, Declination) << endl;
    //Print out Sunrise time
    cout << Dhur(TimeZone, Longitude, EquationOfTime) + AstronomicalSSCalculation(0.833, Longitude, Declination) << endl;
    //Print out Dhur time
    cout << Dhur(TimeZone, Longitude, EquationOfTime) << endl;
    //Print out Asr time
    cout << Dhur(TimeZone, Longitude, EquationOfTime) + Asr(ShadowLength, Longitude, Declination) << endl;
    //Print out Sunset time
    cout << Dhur(TimeZone, Longitude, EquationOfTime) - AstronomicalSSCalculation(0.833, Longitude, Declination) << endl;
    //Print out Maghrib time
    cout << Dhur(TimeZone, Longitude, EquationOfTime) + AstronomicalSSCalculation(4.0, Longitude, Declination) << endl;
    //Print out Isha time
    cout << Dhur(TimeZone, Longitude, EquationOfTime) + AstronomicalSSCalculation(15.0, Longitude, Declination) << endl;
    return 0;
}
