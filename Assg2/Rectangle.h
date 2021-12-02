#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>

#include "ShapeTwoD.h"

using namespace std;

class Rectangle : public ShapeTwoD
{
    private:
        Point vertices[4];
        int minX, maxX;
        int minY, maxY;
        
    public:
        Rectangle();
        Rectangle(Point newVertices[4]);
        Rectangle& operator=(const Rectangle& pt);
        
        void setVertices();
        Point * getVertices();
        
        void setMinMax();

        double computeArea();
        bool isPointInShape(int, int);
		bool isPointOnShape(int, int);
		
        void displayVertices();
        void displayPointsInShape();
        void displayPointsOnShape();
};

#endif