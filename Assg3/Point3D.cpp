#include <cmath>

#include "Point2D.h"
#include "Point3D.h"

using namespace std;


// constructor
Point3D::Point3D() : Point2D()
{
    z = 0;
}

Point3D::Point3D(int ax, int ay, int az) : Point2D(ax, ay)
{
    z = az;
    setDistFrOrigin();
}


// get methods
int Point3D::getZ()
{
    return z;
}


// set methods
void Point3D::setZ(int az)
{
    z = az;
    setDistFrOrigin();
}

void Point3D::setDistFrOrigin()
{
    distFrOrigin = sqrt( (x*x) + (y*y) + (z*z) );
}