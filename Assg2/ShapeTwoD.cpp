#include <string>
#include <iostream>

#include "ShapeTwoD.h"

using namespace std;


// constructors
ShapeTwoD::ShapeTwoD()
{
	name = "";
	containsWarpSpace = false;
	area = 0.0;
}

ShapeTwoD::ShapeTwoD(string sName, bool isWarp, double sArea)
{
    name = sName;
    containsWarpSpace = isWarp;
    area = sArea;
}


// get methods
string ShapeTwoD::getName()
{
	return name;
}

bool ShapeTwoD::getContainsWarpSpace()
{
	return containsWarpSpace;
}

double ShapeTwoD::getArea()
{
    return area;
}


// set methods
void ShapeTwoD::setName(string strName)
{
	name = strName;
}

void ShapeTwoD::setContainsWarpSpace(bool isWarp)
{
	containsWarpSpace = isWarp;
}

void ShapeTwoD::setArea(double sArea)
{
    area = sArea;
}


// other methods
double ShapeTwoD::computeArea()
{
}

bool ShapeTwoD::isPointInShape(int, int)
{
}

bool ShapeTwoD::isPointOnShape(int, int)
{
}

void ShapeTwoD::displayVertices()
{
}

Point * ShapeTwoD::getVertices()
{
}

void ShapeTwoD::displayPointsInShape()
{
}

void ShapeTwoD::displayPointsOnShape()
{
}