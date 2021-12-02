#ifndef POINT3D_H
#define POINT3D_H

#include "Point2D.h"

using namespace std;

class Point3D : public Point2D
{
    protected:
        int z;
        
        void setDistFrOrigin();
        
    public:
        Point3D();
        Point3D(int, int, int);
        
        int getZ();
        
        void setZ(int);
        
        bool operator==(const Point3D & p) { return(x == p.x && y == p.y && z == p.z); }
        bool operator<(const Point3D & p) const { return ( x < p.x || (x == p.x && y < p.y) || (x == p.x && y == p.y && z < p.z) ); }
        
    friend ostream & operator<<(ostream & out, const Point3D & p) 
        {
            out << "[" << setw(4) << p.x << ", " << setw(4) << p.y << ", " << setw(4) << p.z << "]";
            return out;
        }
};

#endif