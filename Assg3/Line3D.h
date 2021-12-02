#ifndef LINE3D_H
#define LINE3D_H

#include "Point3D.h"
#include "Line2D.h"

using namespace std;

class Line3D : public Line2D
{
    private:
        Point3D pt1;
        Point3D pt2;
        
    protected:
        void setLength();
        
    public:
        Line3D();
        Line3D(Point3D, Point3D);
        
        Point3D getPt1();
        Point3D getPt2();
        
        void setPt1(Point3D);
        void setPt2(Point3D);
        
        bool operator==(const Line3D & l) { return(pt1 == l.pt1 && pt2 == l.pt2); }
        bool operator<(const Line3D & l) { return ( pt1 < l.pt1 || (pt1 == l.pt1 && pt2 < l.pt2) ); }
        
    friend ostream & operator<<(ostream & out, const Line3D & l) 
        {
            out << l.pt1 << "    " << l.pt2;
            return out;
        }    
};

#endif