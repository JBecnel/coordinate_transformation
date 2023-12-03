#include "coordinates.h"
// code based off discussion at https://www.movable-type.co.uk/scripts/latlong.html

#define _USE_MATH_DEFINES
#include <math.h>

#define RADIUS_EARTH_KM 6371.0

// Convert degrees to radians
static double toRadians(double degree) {
    return degree * M_PI / 180.0;
}

static double radiansToBearing(double radians) {
    double degrees =  radians * 180.0 / M_PI;
    if (degrees < 0)  
        degrees = degrees + 360.0;
    return degrees;
}

static double toLatLongDegrees(double radians) {
    double degrees = radians * 180/M_PI; // convert back to degrees
    if (degrees < -180)
        degrees = degrees + 360;
    else if (degrees > 180)
        degrees = degrees - 360;
    return degrees;
}

// Calculate the great-circle distance using the Haversine formula
static double haversineDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = toRadians(lat2 - lat1);
    double dLon = toRadians(lon2 - lon1);

    lat1 = toRadians(lat1);
    lat2 = toRadians(lat2);

    double a = sin(dLat/2) * sin(dLat/2) + sin(dLon/2) * sin(dLon/2) * cos(lat1) * cos(lat2); 
    double c = 2 * atan2(sqrt(a), sqrt(1-a)); 
    return RADIUS_EARTH_KM * c;
}

// Calculate bearing (returns an angle in degrees between 0 and 360)
static double calculateBearing(double lat1, double lon1, double lat2, double lon2) {
    lat1 = toRadians(lat1);
    lat2 = toRadians(lat2);
    double dLon = toRadians(lon2 - lon1);

    double y = sin(dLon) * cos(lat2);
    double x = cos(lat1) * sin(lat2) -   sin(lat1) * cos(lat2) * cos(dLon);
    double angle = atan2(y, x);
    return radiansToBearing(angle);
}

// Calculate final latitude and longitude from initial point, range and bearing
int RtoG(double range, double bearing, double glonInit, double glatInit, double *glonFinal, double *glatFinal) {
    if (!glonFinal || !glatFinal) return -1; // Error handling

    double lat1 = toRadians(glatInit);
    double lon1 = toRadians(glonInit);
    bearing = toRadians(bearing);

    double dR = range / RADIUS_EARTH_KM; // Convert range to angular distance in radians

    double lat2 = asin(sin(lat1) * cos(dR) + cos(lat1) * sin(dR) * cos(bearing));
    double lon2 = lon1 + atan2(sin(bearing) * sin(dR) * cos(lat1), cos(dR) - sin(lat1) * sin(lat2));

    *glatFinal = toLatLongDegrees(lat2); // Convert back to degrees
    *glonFinal = toLatLongDegrees(lon2); // Convert back to degrees

    return 0; // Success
}


int GIS2Radar(double *range, double *bearing, double glonInit, double glatInit, double glonFinal, double glatFinal) {
    if (!range || !bearing) return -1; // Error handling

    *range = haversineDistance(glatInit, glonInit, glatFinal, glonFinal);
    *bearing = calculateBearing(glatInit, glonInit, glatFinal, glonFinal);

    return 0; // Success
}