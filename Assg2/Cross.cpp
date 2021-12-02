#include <iostream>
#include <vector>

#include "ShapeTwoD.h"
#include "Cross.h"

using namespace std;


// constructor
Cross::Cross()
{
    for (int i=0; i<12; i++)
    {
        vertices[i] = Point(0,0);
    }
    
    sq_min = Point(0,0);
    sq_max = Point(0,0);
    left_bot = Point(0,0);
    left_top = Point(0,0);
    top_left = Point(0,0);
    top_right = Point(0,0);
    right_top = Point(0,0);
    right_bot = Point(0,0);
    bot_right = Point(0,0);
    bot_left = Point(0,0);
    innerTopLeft = Point(0,0);
    innerTopRight = Point(0,0);
    innerBotLeft = Point(0,0);
    innerBotRight = Point(0,0);
}


Cross::Cross(Point newVertices[12])
{
    for (int i=0; i<12; i++)
    {
        vertices[i] = newVertices[i];
    }
}


// set method
void Cross::setVertices()
{
    int ax;
    int ay;
    for (int i=0; i<12; i++)
    {
        cout << "Enter x-coordinate of pt." << i+1 << " : ";
        cin >> ax;
        cout << "Enter y-coordinate of pt." << i+1 << " : ";
        cin >> ay;
        vertices[i] = Point(ax, ay);
    }
}


// find outer square min and max points
void Cross::setMinMax()
{
    int min_x = vertices[0].x;
    int max_x = vertices[0].y;
    int min_y = vertices[0].x;
    int max_y = vertices[0].y;
    
    for (int i=1; i<12; i++)
    {
        if (vertices[i].x < min_x)
            min_x = vertices[i].x;
        if (vertices[i].x > max_x)
            max_x = vertices[i].x;
        if (vertices[i].y < min_y)
            min_y = vertices[i].y;
        if (vertices[i].y > max_y)
            max_y = vertices[i].y;
    }
    
    sq_min.x = min_x;
    left_top.x = sq_min.x;
    left_bot.x = sq_min.x;
    
    sq_max.x = max_x;
    right_top.x = sq_max.x;
    right_bot.x = sq_max.x;
    
    sq_min.y = min_y;
    bot_left.y = sq_min.y;
    bot_right.y = sq_min.y;
    
    sq_max.y = max_y;
    top_left.y = sq_max.y;
    top_right.y = sq_max.y;
}


// find left_top left_bot points
void Cross::setLeftPoints()
{
    int findY[2];
    int j=0;
    
    for (int i=0; i<12; i++)
    {
        if (vertices[i].x == sq_min.x)
        {
            findY[j] = vertices[i].y;
            j++;
        }
    }
    
    if (findY[0] > findY[1])
    {
        left_top.y = findY[0];
        left_bot.y = findY[1];
    }
    
    if (findY[0] < findY[1])
    {
        left_top.y = findY[1];
        left_bot.y = findY[0];
    }
}


// find right_top right_bot points
void Cross::setRightPoints()
{
    int findY[2];
    int j=0;
    
    for (int i=0; i<12; i++)
    {
        if (vertices[i].x == sq_max.x)
        {
            findY[j] = vertices[i].y;
            j++;
        }
    }
    
    if (findY[0] > findY[1])
    {
        right_top.y = findY[0];
        right_bot.y = findY[1];
    }
    
    if (findY[0] < findY[1])
    {
        right_top.y = findY[1];
        right_bot.y = findY[0];
    }
}


// find top_right top_left points
void Cross::setTopPoints()
{
    int findX[2];
    int j=0;
    
    for (int i=0; i<12; i++)
    {
        if (vertices[i].y == sq_max.y)
        {
            findX[j] = vertices[i].x;
            j++;
        }
    }
    
    if (findX[0] > findX[1])
    {
        top_right.x = findX[0];
        top_left.x = findX[1];
    }
    
    if (findX[0] < findX[1])
    {
        top_right.x = findX[1];
        top_left.x = findX[0];
    }
}


// find bot_right bot_left points
void Cross::setBotPoints()
{
    int findX[2];
    int j=0;
    
    for (int i=0; i<12; i++)
    {
        if (vertices[i].y == sq_min.y)
        {
            findX[j] = vertices[i].x;
            j++;
        }
    }
    
    if (findX[0] > findX[1])
    {
        bot_right.x = findX[0];
        bot_left.x = findX[1];
    }
    
    if (findX[0] < findX[1])
    {
        bot_right.x = findX[1];
        bot_left.x = findX[0];
    }
}


// find inner points of cross 
void Cross::setInnerPoints()
{
    innerTopLeft = Point(top_left.x, left_top.y);
    innerTopRight = Point(top_right.x, right_top.y);
    innerBotLeft = Point(bot_left.x, left_bot.y);
    innerBotRight = Point(bot_right.x, right_bot.y);
}


void Cross::setPoints()
{
    setMinMax();
    setLeftPoints();
    setRightPoints();
    setTopPoints();
    setBotPoints();
    setInnerPoints();
    setPointsOnShape();
    setPointsNotInShape();
}


double Cross::computeArea()
{
    double result;
    int bigSq;
    int sq1, sq2, sq3, sq4;
    
    // use points to get 5 different rectangles
    bigSq = (sq_max.y - sq_min.y) * (sq_max.x - sq_min.x);
    sq1 = (top_left.x - sq_min.x) * (sq_max.y - left_top.y);
    sq2 = (sq_max.x - top_right.x) * (sq_max.y - right_top.y);
    sq3 = (left_bot.y - sq_min.y) * (bot_left.x - sq_min.x);
    sq4 = (right_bot.y - sq_min.y) * (sq_max.x - bot_right.x);
    
    result = bigSq - sq1 - sq2 - sq3 - sq4;
    
    return result;
}


void Cross::displayVertices()
{
    for (int i=0; i<12; i++)
    {
        cout << "(" << vertices[i].x << "," << vertices[i].y << ") ";
    }
    cout << endl;
}


// find points in between 2 points
void Cross::findPointsInBetween(Point low, Point high)
{
    if (low.x == high.x)
    {
        for (int i=low.y + 1; i<high.y; i++)
        {
            ptsOnShape.push_back(Point(low.x,i));
        }
    }
    
    if (low.y == high.y)
    {
        for (int i=low.x + 1; i<high.x; i++)
        {
            ptsOnShape.push_back(Point(i,low.y));
        }
    }
}


// using findPointsInBetween() on the 12 sides of cross to find points on shape
void Cross::setPointsOnShape()
{
    findPointsInBetween(left_top, innerTopLeft);
    findPointsInBetween(innerTopLeft, top_left);
    findPointsInBetween(top_left, top_right);
    findPointsInBetween(innerTopRight, top_right);
    findPointsInBetween(innerTopRight, right_top);
    findPointsInBetween(right_bot, right_top);
    findPointsInBetween(innerBotRight, right_bot);
    findPointsInBetween(bot_right, innerBotRight);
    findPointsInBetween(bot_left, bot_right);
    findPointsInBetween(bot_left, innerBotLeft);
    findPointsInBetween(left_bot, innerBotLeft);
    findPointsInBetween(left_bot, left_top);
}


void Cross::displayPointsOnShape()
{
    for (int i=0; i<ptsOnShape.size(); i++)
	{
	    cout << ptsOnShape[i];
	}
}


// finding points in a rectangular area within min and max points
void Cross::findPointsNotInShape(Point min, Point max)
{
    for (int i=min.x; i<=max.x; i++)
    {
        for (int j=min.y; j<=max.y; j++)
        {
            ptsNotInShape.push_back(Point(i,j));
        }
    }
}


void Cross::setPointsNotInShape()
{
    // find all points of the rectangle surrounding the cross
    for (int i=sq_min.x; i<=sq_max.x; i++)
    {
        for (int j=sq_min.y; j<=sq_max.y; j++)
        {
            allPoints.push_back(Point(i,j));
        }
    }
    
    // find points in rectangle but not in cross, store in vector ptsNotInShape
    findPointsNotInShape(left_top, top_left);
    findPointsNotInShape(innerTopRight, sq_max);
    findPointsNotInShape(sq_min, innerBotLeft);
    findPointsNotInShape(bot_right, right_bot);
    
    // insert ptsOnShape into ptsNotInShape
    ptsNotInShape.insert(ptsNotInShape.end(), ptsOnShape.begin(), ptsOnShape.end());
}


void Cross::displayPointsInShape()
{
    // display points present in allPoints but not ptsNotInShape
    for (int i=0; i<allPoints.size(); i++) 
    { 
        int j; 
        for (j=0; j<ptsNotInShape.size(); j++) 
            if (allPoints[i] == ptsNotInShape[j]) 
                break; 
  
        if (j == ptsNotInShape.size()) 
            cout << allPoints[i];
    }
}