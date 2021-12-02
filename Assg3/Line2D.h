#ifndef LINE2D_H
#define LINE2D_H

#include "Point2D.h"

using namespace std;

class Line2D
{
    private:
        Point2D pt1;
        Point2D pt2;
    
    protected:
        double length;
        
        void setLength();
        
    public:
        Line2D();
        Line2D(Point2D, Point2D);
        
        Point2D getPt1();
        Point2D getPt2();
        double getScalarValue();
        
        void setPt1(Point2D);
        void setPt2(Point2D);
        
        bool operator==(const Line2D & l) { return(pt1 == l.pt1 && pt2 == l.pt2); }
        bool operator<(const Line2D & l) { return ( pt1 < l.pt1 || (pt1 == l.pt1 && pt2 < l.pt2) ); }
        
    friend ostream & operator<<(ostream & out, const Line2D & l) 
        {
            out << l.pt1 << "    " << l.pt2;
            return out;
        }
};

#endif