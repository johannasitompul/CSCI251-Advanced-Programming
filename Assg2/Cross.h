#ifndef CROSS_H
#define CROSS_H

#include "ShapeTwoD.h"

using namespace std;

class Cross : public ShapeTwoD
{
    private:
        Point vertices[12];
        Point sq_min, sq_max;
        Point left_bot, left_top;
        Point top_left, top_right;
        Point right_top, right_bot;
        Point bot_right, bot_left;
        Point innerTopLeft, innerTopRight;
        Point innerBotLeft, innerBotRight;
        vector<Point> ptsOnShape;
        vector<Point> ptsNotInShape;
        vector<Point> allPoints;
        
    public:
        Cross();
        Cross(Point newVertices[12]);
        
        void setVertices();
        void setPoints();
        void setMinMax();
        void setLeftPoints();
        void setRightPoints();
        void setTopPoints();
        void setBotPoints();
        void setInnerPoints();
    
        double computeArea();
    
        void displayVertices();
        
        void findPointsInBetween(Point low, Point high);
        void setPointsOnShape();
        void displayPointsOnShape();
        
        void findPointsNotInShape(Point min, Point max);
        void setPointsNotInShape();
        void displayPointsInShape();
        
};

#endif