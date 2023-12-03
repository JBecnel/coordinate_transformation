#ifndef COORDINATES_H
#define COORDINATES_H

int GIS2Radar(double *range, double *bearing, double glonInit, double glatInit, double glonFinal, double glatFinal);
int RtoG(double range, double bearing, double glonInit, double glatInit, double *glonFinal, double *glatFinal);

#endif // COORDINATES_H
