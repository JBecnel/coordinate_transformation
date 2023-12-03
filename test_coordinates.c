#include <stdio.h>
#include "coordinates.h"

int main() {
    // Test 1 Coordinates for Wallops Island and Puerto Rico
    printf("Test 1: Wallops Island and Puerto Rico\n");
    double wallopsIslandLat = 37.0;
    double wallopsIslandLon = -75.0;
    double puertoRicoLat = 18.0;
    double puertoRicoLon = -66.0;

    double range, bearing;
    double testLat, testLon;

    // Convert from GIS to Radar coordinates
    if (GIS2Radar(&range, &bearing, wallopsIslandLon, wallopsIslandLat, puertoRicoLon, puertoRicoLat) == 0) {
        printf("Range: %f km, Bearing: %f radians\n", range, bearing);
    } else {
        printf("Error in GIS2Radar\n");
    }

    // Convert back from Radar to GIS coordinates
    if (RtoG(range, bearing, wallopsIslandLon, wallopsIslandLat, &testLon, &testLat) == 0) {
        printf("Converted Back - Latitude: %f, Longitude: %f\n", testLat, testLon);
    } else {
        printf("Error in RtoG\n");
    }

    printf("\n");
    // Test 2 Coordinates for Hawaii and Fiji
    printf("Test 2: Hawaii and Fiji\n");
    double hawaiiLat = 21.0;
    double hawaiiLon = -157.0;
    double fijiLat = -18.0;
    double fijiLon = 178.0;

    // Convert from GIS to Radar coordinates
    if (GIS2Radar(&range, &bearing, hawaiiLon, hawaiiLat, fijiLon, fijiLat) == 0) {
        printf("Range: %f km, Bearing: %f \n", range, bearing);
    } else {
        printf("Error in GIS2Radar\n");
    }

    // Convert back from Radar to GIS coordinates
    if (RtoG(range, bearing, hawaiiLon, hawaiiLat, &testLon, &testLat) == 0) {
        printf("Converted Back - Latitude: %f, Longitude: %f\n", testLat, testLon);
    } else {
        printf("Error in RtoG\n");
    }

    printf("\n");
    // Test 3 Coordinates for Iceland and Japan
    printf("Test 3: Iceland and Japan\n");
    double icelandLat = 64.0;
    double icelandLon = -19.0;
    double japanLat = 36.0;
    double japanLon = 138.0;

    // Convert from GIS to Radar coordinates
    if (GIS2Radar(&range, &bearing, icelandLon, icelandLat, japanLon, japanLat) == 0) {
        printf("Range: %f km, Bearing: %f \n", range, bearing);
    } else {
        printf("Error in GIS2Radar\n");
    }

    // Convert back from Radar to GIS coordinates
    if (RtoG(range, bearing, icelandLon, icelandLat, &testLon, &testLat) == 0) {
        printf("Converted Back - Latitude: %f, Longitude: %f\n", testLat, testLon);
    } else {
        printf("Error in RtoG\n");
    }
    
    return 0;
}
