#include <string>
#include <iostream>

#include "ShapeTwoD.h"
#include "Square.h"

using namespace std;


// overloading operator =
Square & Square::operator=(const Square & pt)
{
    if (this != & pt)
    {
        for (int i=0; i<4; i++)
        {
            vertices[i] = pt.vertices[i];
        }
    }
    return *this;
}


// construtor
Square::Square()
{
    for (int i=0; i<4; i++)
    {
        vertices[i] = Point(0,0);
    }
}


Square::Square(Point newVertices[4])
{
    for (int i=0; i<4; i++)
    {
        vertices[i] = newVertices[i];
    }
}


// set method
void Square::setVertices()
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
Point * Square::getVertices()
{
    return vertices;
}


// other methods
double Square::computeArea()
{
    int result;
    int sLen;
    
    if (vertices[0].x != vertices[1].x)
    {
        sLen = vertices[0].x - vertices[1].x;
    }
    
    else if (vertices[0].x == vertices[1].x)
    {
        sLen = vertices[0].y - vertices[1].y;
    }
    
    sLen = abs(sLen);
    
    result = sLen * sLen;
    return result;
}


void Square::setMinMax()
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


bool Square::isPointInShape(int ax, int ay)
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


bool Square::isPointOnShape(int ax, int ay)
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


void Square::displayVertices()
{
    for (int i=0; i<4; i++)
    {
        cout << vertices[i];
    }
    cout << endl;
}


void Square::displayPointsInShape()
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


void Square::displayPointsOnShape()
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