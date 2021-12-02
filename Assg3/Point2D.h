#ifndef POINT2D_H
#define POINT2D_H

#include <iomanip>
#include <iostream>

using namespace std;

class Point2D
{
    protected:
        int x;
        int y;
        double distFrOrigin;
        
        void setDistFrOrigin();
        
    public:
        Point2D();
        Point2D(int, int);
        
        int getX();
        int getY();
        double getScalarValue();
        
        void setX(int);
        void setY(int);
        
        bool operator==(const Point2D & p) { return(x == p.x && y == p.y); }
        bool operator<(const Point2D & p) const { return ( x < p.x || (x == p.x && y < p.y) ); }
        
    friend ostream & operator<<(ostream & out, const Point2D & p) 
        {
            out << "[" << setw(4) << p.x << ", " << setw(4) << p.y << "]";
            return out;
        }
};

#endif