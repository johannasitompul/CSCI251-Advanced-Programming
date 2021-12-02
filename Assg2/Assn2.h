#ifndef ASSN2_H
#define ASSN2_H

#include "ShapeTwoD.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Cross.h"

using namespace std;

class Assn2
{
    private:
        vector<ShapeTwoD*> shapeVector;
        vector<ShapeTwoD*> WSvector;
        vector<ShapeTwoD*> NSvector;
        
    public:
        void myDetails();
        void mainMenu();
        void sortMenu();
        
        // sorting function
        static bool compareAreasAsc(ShapeTwoD* a, ShapeTwoD* b) { return a->computeArea() < b->computeArea(); }
        static bool compareAreasDes(ShapeTwoD* a, ShapeTwoD* b) { return a->computeArea() > b->computeArea(); }
        static bool sortByName(ShapeTwoD* a, ShapeTwoD* b) { return a->getName() < b->getName(); }
        
        void printVector(vector<ShapeTwoD*> const &vectorName);
        
        int main();
};

#endif