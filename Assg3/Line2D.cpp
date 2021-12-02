#include <cmath>

#include "Point2D.h"
#include "Line2D.h"

using namespace std;


// constructor
Line2D::Line2D()
{
    pt1 = Point2D(0,0);
    pt2 = Point2D(0,0);
    length = 0.0;
}

Line2D::Line2D(Point2D p1, Point2D p2)
{
    pt1 = p1;
    pt2 = p2;
    setLength();
}


// get methods
Point2D Line2D::getPt1()
{
    return pt1;
}

Point2D Line2D::getPt2()
{
    return pt2;
}

double Line2D::getScalarValue()
{
    return length;
}


// set methods
void Line2D::setPt1(Point2D p1)
{
    pt1 = p1;
}

void Line2D::setPt2(Point2D p2)
{
    pt2 = p2;
}

void Line2D::setLength()
{
    length = sqrt( pow((pt1.getX() - pt2.getX()), 2) + pow((pt1.getY() - pt2.getY()), 2) );
}