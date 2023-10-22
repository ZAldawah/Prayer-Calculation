#include <iostream>
#include <iomanip>
#include "PrayerFormulas.h"
#include "GregorianToJulian.h"
#include <chrono>
#include <cmath>

using namespace std;
using namespace chrono;

double DSEJ2000 = getCurrentJulianDate() - 2451545.0; // Days since Epoch J2000

// An angular measurement that describes the position of the sun in its elliptical orbit around the Earth.
double Sun_MeanAnomaly = fmod(toRadians(357.529) + toRadians(0.98560028) * DSEJ2000, 2.0 * PI);

// An angle that measures the average or mean position of the sun in its apparent orbit around Earth.
double Sun_MeanLongitude = fmod(toRadians(280.459) + toRadians(0.98564736) * DSEJ2000, 2.0 * PI); // 

// The mean Sun_ApparentLongitude (q) corrected for the sun's elliptical orbit's two main periodic terms. This is the position of the sun as it appears in the sky (taking into account factors like the inclination of the sun's orbit).
double Sun_ApparentLongitude = Sun_MeanLongitude + 1.915 * sin(Sun_MeanAnomaly) + 0.020 * sin(2 * Sun_MeanAnomaly);  

// This determines how far the sun is from Earth.
double SunEarthDistance = 1.00014 - 0.01671 * cos(Sun_MeanAnomaly) - 0.00014 * cos(2 * Sun_MeanAnomaly);

// The tilt of Earth's axis of rotation relative to its orbital plane. FIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIXFIX
double ObliquityOfTheEcliptic = computeObliquity(getCurrentJulianDate()); 

// One of the two angles used to specify the sun's position in the celestial sphere, the other being declination.
double Sun_RightAscension = atan2(cos(ObliquityOfTheEcliptic) * sin(Sun_ApparentLongitude), cos(Sun_ApparentLongitude)) / 15;

// An angle between the rays of the sun and the plane of the Earth's equator.
double Sun_Declination = asin(sin(ObliquityOfTheEcliptic) * sin(Sun_ApparentLongitude));

// It represents a correction factor to adjust for discrepancies between solar time (apparent solar day) and mean solar time (average solar day). It results from the eccentricity of Earth's orbit and the tilt of its axis.
double EquationOfTime = (Sun_MeanLongitude / 15) - Sun_RightAscension;

int main() 
{
    double FajrAngle = 15.0;
    double IshaAngle = 15.0;
    int ShadowLength = 1;
    int TimeZone = -5;

    //Print out Fajr time
    cout << Dhur(TimeZone, Sun_ApparentLongitude, EquationOfTime) - AstronomicalSSCalculation(FajrAngle, Sun_ApparentLongitude, Sun_Declination) << endl;

    //Print out Sunrise time
    cout << Dhur(TimeZone, Sun_ApparentLongitude, EquationOfTime) + AstronomicalSSCalculation(0.833, Sun_ApparentLongitude, Sun_Declination) << endl;

    //Print out Dhur time
    cout << Dhur(TimeZone, Sun_ApparentLongitude, EquationOfTime) << endl;

    //Print out Asr time
    cout << Dhur(TimeZone, Sun_ApparentLongitude, EquationOfTime) + Asr(ShadowLength, Sun_ApparentLongitude, Sun_Declination) << endl;

    //Print out Sunset time
    cout << Dhur(TimeZone, Sun_ApparentLongitude, EquationOfTime) - AstronomicalSSCalculation(0.833, Sun_ApparentLongitude, Sun_Declination) << endl;

    //Print out Maghrib time
    cout << Dhur(TimeZone, Sun_ApparentLongitude, EquationOfTime) + AstronomicalSSCalculation(4.0, Sun_ApparentLongitude, Sun_Declination) << endl;
    
    //Print out Isha time
    cout << Dhur(TimeZone, Sun_ApparentLongitude, EquationOfTime) + AstronomicalSSCalculation(IshaAngle, Sun_ApparentLongitude, Sun_Declination) << endl;
    
    system("pause>0");
}
