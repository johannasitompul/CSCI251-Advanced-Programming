#ifndef GRID_H
#define GRID_H

#include <string>

using namespace std;

// global variables
string locFileName;
string ccFileName;
string presFileName;
int x_size, y_size;
int rangeX_min, rangeX_max;
int rangeY_min, rangeY_max;
int noOfCities = 1;
int * cityIDtemp;
int cityIDtemp_size = 0;
int * cityIDlist;

// data structure used
struct grid
{
    int x = 888;
    int y = 888;
    int cloudValue, cloudIdx;
    int pressValue, pressIdx;
    string cloudLvl, pressLvl;
    int ID = 0;
    string name = " ";
};

#endif
