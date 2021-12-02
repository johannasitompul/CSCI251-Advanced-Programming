#include <string>
#include <iostream>

#include "ShapeTwoD.h"
#include "Rectangle.h"

using namespace std;


// overloading operator
Rectangle& Rectangle::operator=(const Rectangle& pt)
{
    if (this != &pt)
    {
        for (int i=0; i<4; i++)
        {
            vertices[i] = pt.vertices[i];
        }
    }
    return *this;
}


// constructor
Rectangle::Rectangle()
{
    for (int i=0; i<4; i++)
    {
        vertices[i] = Point(0,0);
    }
}


Rectangle::Rectangle(Point newVertices[4])
{
    for (int i=0; i<4; i++)
    {
        vertices[i] = newVertices[i];
    }
}


// set method
void Rectangle::setVertices()
{
    int ax;
    int ay;
    for (int i=0; i<4; i++)
    {
        cout << "Enter x-coordinate of pt." << i+1 << " : ";
        cin >> ax;
        cout << "Enter y-coordinate of pt." << i+1 << " : ";
        cin >> ay;
        vertices[i] = Point(ax, ay);
    }
}


// get method
Point * Rectangle::getVertices()
{
    return vertices;
}


// other methods
double Rectangle::computeArea()
{
    int result;
    int xLen, yLen;
    
    xLen = maxX - minX;
    yLen = maxY - minY;
    
    result = xLen * yLen;
    return result;
}


void Rectangle::setMinMax()
{
    int min_x = vertices[0].x;
    int max_x = vertices[0].y;
    int min_y = vertices[0].x;
    int max_y = vertices[0].y;
    
    for (int i=1; i<4; i++)
    {
        if (vertices[i].x < min_x)
            min_x = vertices[i].x;
        if (vertices[i].x > max_x)
            max_x = vertices[i].x;
        if (vertices[i].y < min_y)
            min_y = vertices[i].y;
        if (vertices[i].y > max_y)
            max_y = vertices[i].y;
    }
    
    minX = min_x;
    maxX = max_x;
    minY = min_y;
    maxY = max_y;
}


bool Rectangle::isPointInShape(int ax, int ay)
{
    bool result;
    
    if (minX < ax && ax < maxX)
    {
        if (minY < ay && ay < maxY)
            result = true;
        else
            result = false;
    }
    
    else
        result = false;
    
    return result;
}


bool Rectangle::isPointOnShape(int ax, int ay)
{
    bool result;
    
    if (minX < ax && ax < maxX)
    {
        if (ay == minY || ay == maxY)
            result = true;
        else
            result = false;
    }
    
    else if (minY < ay && ay < maxY)
    {
        if (ax == minX || ax == maxX)
            result = true;
        else
            result = false;
    }
    
    else
        result = false;
    
    return result;
}


void Rectangle::displayVertices()
{
    for (int i=0; i<4; i++)
    {
        cout << vertices[i];
    }
    cout << endl;
}


void Rectangle::displayPointsInShape()
{
    for (int i=minX; i<=maxX; i++)
    {
        for (int j=minY; j<=maxY; j++)
        {
            if (isPointInShape(i,j) == true)
                cout << "(" << i << "," << j << ") ";
        }
    }
}


void Rectangle::displayPointsOnShape()
{
    for (int i=minX; i<=maxX; i++)
    {
        for (int j=minY; j<=maxY; j++)
        {
            if (isPointOnShape(i,j) == true)
                cout << "(" << i << "," << j << ") ";
        }
    }
}