#ifndef SQUARE_H
#define SQUARE_H

#include <string>

#include "ShapeTwoD.h"

using namespace std;

class Square : public ShapeTwoD
{
    private:
        Point vertices[4];
        int minX, maxX;
        int minY, maxY;
        
    public:
        Square();
        Square(Point newVertices[4]);
        Square & operator=(const Square & pt);
        
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