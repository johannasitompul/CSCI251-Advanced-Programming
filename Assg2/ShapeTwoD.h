#ifndef SHAPETWOD_H
#define SHAPETWOD_H

#include <string>

using namespace std;


struct Point
{
    int x;
    int y;
    
    Point()
    {
        x = 0;
        y = 0;
    }
    
    Point(int ax, int ay)
    {
        x = ax;
        y = ay;
    }
    
    bool operator==(const Point & pt) { return(x == pt.x && y == pt.y); }
    bool operator!=(const Point & pt) { return !(*this == pt); }
    
    // to print out points easily
    friend ostream & operator<<(ostream & out, const Point & pt) 
        {
            out << "(" << pt.x << "," << pt.y << ") ";
            return out;
        }
};


class ShapeTwoD
{
	protected:
		string name;
		bool containsWarpSpace;
		double area;
		
	public:
		ShapeTwoD();
		ShapeTwoD(string, bool, double);
		
		string getName();
		bool getContainsWarpSpace();
		double getArea();
		
		void setName(string);
		void setContainsWarpSpace(bool);
		void setArea(double);
		
		// string toString();
		virtual double computeArea();
		virtual bool isPointInShape(int, int);
		virtual bool isPointOnShape(int, int);
		
		virtual void displayVertices();
		virtual Point * getVertices();
		
		virtual void displayPointsInShape();
		virtual void displayPointsOnShape();
};

#endif
