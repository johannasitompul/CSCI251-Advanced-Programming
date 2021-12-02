#include <cmath>

#include "Point2D.h"

using namespace std;


// constructor
Point2D::Point2D()
{
    x = 0;
    y = 0;
    distFrOrigin = 0.0;
}

Point2D::Point2D(int ax, int ay)
{
    x = ax;
    y = ay;
    setDistFrOrigin();
}


// get methods
int Point2D::getX()
{
    return x;
}

int Point2D::getY()
{
    return y;
}

double Point2D::getScalarValue()
{
    return distFrOrigin;
}


// set methods
void Point2D::setX(int ax)
{
    x = ax;
}

void Point2D::setY(int ay)
{
    y = ay;
    setDistFrOrigin();
}

void Point2D::setDistFrOrigin()
{
    distFrOrigin = sqrt( (x*x) + (y*y) );
}

