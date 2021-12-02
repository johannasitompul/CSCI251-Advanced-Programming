#include <iostream>

#include "ShapeTwoD.h"
#include "Circle.h"

using namespace std;


// constructor
Circle::Circle()
{
    centre = Point(0,0);
    radius = 0;
}


Circle::Circle(Point cCentre, int cRad)
{
    centre = cCentre;
    radius = cRad;
}


// set method
void Circle::setCentreRadius()
{
    int ax, ay;
    int cRad;
    
    cout << "Enter x-coordinate of centre : ";
    cin >> ax;
    cout << "Enter y-coordinate of centre : ";
    cin >> ay;
    
    centre = Point(ax,ay);
    
    cout << "Enter radius (units) : ";
    cin >> cRad;
    
    radius = cRad;
}


// other methods
double Circle::computeArea()
{
    double result;
    double pi = 3.142;
    result = pi * radius * radius;
    
    return result;
}


void Circle::displayVertices()
{
    cout << centre << endl;
}


void Circle::displayPointsInShape()
{
    // no points in shape when radius is less than or equal to 1
    if (radius < 2)
    {
        cout << "none!";
    }
    
    else
    {
        // find min and max points of the square within the circle
        int minX = centre.x - radius + 1;
        int maxX = centre.x + radius - 1;
        int minY = centre.y - radius + 1;
        int maxY = centre.y + radius - 1;
        
        int sz = ((radius * 2) - 1) * ((radius * 2) - 1);
        int itor = 0;
        
        // store all points within the square in an array
        Point tempArray[sz];
        
        for (int i=minX; i<=maxX; i++)
        {
            for (int j=minY; j<=maxY; j++)
            {
                tempArray[itor] = Point(i,j);
                itor++;
            }
        }
        
        // cout all point except for the centre of circle
        for (int i=0; i<sz; i ++)
        {
            if (tempArray[i] != centre)
                cout << tempArray[i];
        }
    }
}


void Circle::displayPointsOnShape()
{
    // use centre point and radius to get points on circle perimeter
    cout << "(" << centre.x - radius << "," << centre.y << ") ";
    cout << "(" << centre.x << "," << centre.y - radius << ") ";
    cout << "(" << centre.x << "," << centre.y + radius << ") ";
    cout << "(" << centre.x + radius << "," << centre.y << ") ";
}
