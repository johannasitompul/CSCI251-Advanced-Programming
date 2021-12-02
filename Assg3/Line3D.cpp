#include <cmath>

#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

using namespace std;


// constructor
Line3D::Line3D()
{
    pt1 = Point3D(0,0,0);
    pt2 = Point3D(0,0,0);
}

Line3D::Line3D(Point3D p1, Point3D p2)
{
    pt1 = p1;
    pt2 = p2;
    setLength();
}


// get methods
Point3D Line3D::getPt1()
{
    return pt1;
}

Point3D Line3D::getPt2()
{
    return pt2;
}


// set methods
void Line3D::setPt1(Point3D p1)
{
    pt1 = p1;
}

void Line3D::setPt2(Point3D p2)
{
    pt2 = p2;
}

void Line3D::setLength()
{
    length = sqrt( pow((pt1.getX() - pt2.getX()), 2) + pow((pt1.getY() - pt2.getY()), 2) + pow((pt1.getZ() - pt2.getZ()), 2) );
}