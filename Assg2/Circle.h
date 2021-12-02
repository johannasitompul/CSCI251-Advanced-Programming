#ifndef CIRCLE_H
#define CIRCLE_H

#include "ShapeTwoD.h"

using namespace std;

class Circle : public ShapeTwoD
{
    private:
        Point centre;
        int radius;
        
    public:
        Circle();
        Circle(Point, int);
        
        void setCentreRadius();
        
        double computeArea();
        //bool isPointInShape(int, int);
		//bool isPointOnShape(int, int);
		
        void displayVertices();
        void displayPointsInShape();
        void displayPointsOnShape();
};

#endif