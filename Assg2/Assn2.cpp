#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Assn2.h"
#include "ShapeTwoD.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Cross.h"

using namespace std;


// student details
void Assn2::myDetails()
{
    cout << endl;
    cout << "Student ID   : 7020041" << endl;
    cout << "Student Name : Johanna Then Lasmauli Sitompul" << endl;
    cout << "=============================================" << endl;
    
    cout << "Welcome to Assignment 2 Program!" << endl << endl;
}


// main menu
void Assn2::mainMenu()
{
    myDetails();
    
    cout << "1) Input sensor data" << endl;
    cout << "2) Compute area ( for all records )" << endl;
    cout << "3) Print shapes report" << endl;
    cout << "4) Sort shape data" << endl;
    cout << "5) Quit" << endl << endl;
}


// sort menu
void Assn2::sortMenu()
{
    cout << endl;
	cout << "a) Sort by area (ascending)" << endl;
	cout << "b) Sort by area (descending)" << endl;
	cout << "c) Sort by special type and area" << endl;
	cout << "d) Sort by shape" << endl;
	cout << "e) Go back to main menu" << endl << endl;
}


// to print out vector
void Assn2::printVector(vector<ShapeTwoD*> const &vectorName)
{
	string temp;

	for (int i=0; i<vectorName.size(); i++)
	{
	    if (vectorName[i]->getContainsWarpSpace() == true)
        {
        	temp = "WS";
        }
        else if (vectorName[i]->getContainsWarpSpace() == false)
        {
	        temp = "NS";
        }
		        
        cout << endl;
        cout << "Shape [" << i+1 << "]" << endl;
        cout << "Name         : " << vectorName[i]->getName() << endl;
        cout << "Special Type : " << temp << endl;
        cout << "Area         : " << vectorName[i]->getArea() << " unit(s) square" << endl;
        cout << "Vertices     : "; vectorName[i]->displayVertices();
        cout << "Points on perimeter : "; vectorName[i]->displayPointsOnShape(); cout << endl;
        cout << "Points in shape     : "; vectorName[i]->displayPointsInShape();
		cout << endl;
    }
}


int Assn2::main()
{
    int userInput;
    
    while (userInput != 5)
    {
        mainMenu();
        cout << "Please enter your choice : ";
        cin >> userInput;
        
        
        // input shape
        if (userInput == 1)
        {
            string shapeName;
            string typeName;
            
            cout << endl << "[ Input sensor data ]" << endl;
            
            cout << "Enter name of shape : ";
            cin >> shapeName;
            
            while (shapeName != "Square" && shapeName != "square" && shapeName != "Rectangle" && shapeName != "rectangle" && shapeName != "Circle" && shapeName != "circle" && shapeName != "Cross" && shapeName != "cross")
            {
                cout << "Invalid input. Please re-enter name of shape : ";
                cin >> shapeName;
            }
            
            cout << "Please enter special type [NS/WS] : ";
            cin >> typeName;
            
            while (typeName != "WS" && typeName != "ws" && typeName != "NS" && typeName != "ns")
            {
                cout << "Invalid input. Please re-enter special type [NS/WS] : ";
                cin >> typeName;
            }
            
            if (shapeName == "Square" || shapeName == "square")
            {
                Square * newSquare;
                newSquare = new Square();
                
                newSquare->setVertices();
                newSquare->setMinMax();
                
                newSquare->setName("Square");
                
                if (typeName == "WS" || typeName == "ws")
                {
                    newSquare->setContainsWarpSpace(true);
                    WSvector.push_back(newSquare);
                }
                    
                if (typeName == "NS" || typeName == "ns")
                    NSvector.push_back(newSquare);
                
                shapeVector.push_back(newSquare);
            }
            
            if (shapeName == "Rectangle" || shapeName == "rectangle")
            {
                Rectangle * newRectangle;
                newRectangle = new Rectangle();
                
                newRectangle->setVertices();
                newRectangle->setMinMax();
                
                newRectangle->setName("Rectangle");
                
                if (typeName == "WS" || typeName == "ws")
                {
                    newRectangle->setContainsWarpSpace(true);
                    WSvector.push_back(newRectangle);
                }
                    
                if (typeName == "NS" || typeName == "ns")
                    NSvector.push_back(newRectangle);
                
                shapeVector.push_back(newRectangle);
            }
            
            if (shapeName == "Circle" || shapeName == "circle")
            {
                Circle * newCircle;
                newCircle = new Circle();
                
                newCircle->setCentreRadius();
                
                newCircle->setName("Circle");
                
                if (typeName == "WS" || typeName == "ws")
                {
                    newCircle->setContainsWarpSpace(true);
                    WSvector.push_back(newCircle);
                }
                    
                if (typeName == "NS" || typeName == "ns")
                    NSvector.push_back(newCircle);
                
                shapeVector.push_back(newCircle);
            }
            
            if (shapeName == "Cross" || shapeName == "cross")
            {
                Cross * newCross;
                newCross = new Cross();
                
                newCross->setVertices();
                newCross->setPoints();
                
                newCross->setName("Cross");
                
                if (typeName == "WS" || typeName == "ws")
                {
                    newCross->setContainsWarpSpace(true);
                    WSvector.push_back(newCross);
                }
                    
                if (typeName == "NS" || typeName == "ns")
                    NSvector.push_back(newCross);
                
                shapeVector.push_back(newCross);
            }
            
            cout << endl << "Record successfully stored. Going back to main menu..." << endl;
        }
        
        
        // compute area of all records
        if (userInput == 2)
        {
            double newArea;
            int counter = 0;
            
            for (int i=0; i<shapeVector.size(); i++)
	        {
		        newArea = shapeVector[i]->computeArea();
		        shapeVector[i]->setArea(newArea);
		        counter++;
	        }
	        
	        for (int i=0; i<WSvector.size(); i++)
	        {
		        newArea = WSvector[i]->computeArea();
		        WSvector[i]->setArea(newArea);
	        }
	        
	        for (int i=0; i<NSvector.size(); i++)
	        {
		        newArea = NSvector[i]->computeArea();
		        NSvector[i]->setArea(newArea);
	        }
	        
	        cout << endl << "Computation completed! ( " << counter << " records were updated )" << endl;
        }
        
        
        // display report
        if (userInput == 3)
        {
            cout << endl << "Total no. of records available = " << shapeVector.size() << endl;
            printVector(shapeVector);
        }
        
        
        // sort display
        if (userInput == 4)
        {
            string sortInput;
            
            while (sortInput != "e")
            {
                sortMenu();
                cout << "Please enter your choice : ";
                cin >> sortInput;
                
                if (sortInput == "a")
                {
                    cout << endl << "Sort by area ( smallest to largest )..." << endl;
                    sort(shapeVector.begin(), shapeVector.end(), compareAreasAsc);
                    printVector(shapeVector);
                }
                
                if (sortInput == "b")
                {
                    cout << endl << "Sort by area ( largest to smallest )..." << endl;
                    sort(shapeVector.begin(), shapeVector.end(), compareAreasDes);
                    printVector(shapeVector);
                }
                
                if (sortInput == "c")
                {
                    cout << endl << "Sort by special type and area..." << endl;
                    sort(WSvector.begin(), WSvector.end(), compareAreasDes);
                    printVector(WSvector);
                    sort(NSvector.begin(), NSvector.end(), compareAreasDes);
                    printVector(NSvector);
                }
                
                if (sortInput == "d")
                {
                    string sortAreaInput;
                    cout << "Sort area ascending or descending [ASC/DES] ? ";
                    cin >> sortAreaInput;
                    
                    while (sortAreaInput != "ASC" && sortAreaInput != "asc" && sortAreaInput != "DES" && sortAreaInput != "des")
                    {
                        cout << "Invalid input. Please re-enter [ASC/DES] : ";
                        cin >> sortAreaInput;
                    }
                    
                    if (sortAreaInput == "ASC" || sortAreaInput == "asc")
                    {
                        sort(shapeVector.begin(), shapeVector.end(), compareAreasAsc);
                        sort(shapeVector.begin(), shapeVector.end(), sortByName);
                        printVector(shapeVector);
                    }
                    
                    if (sortAreaInput == "DES" || sortAreaInput == "des")
                    {
                        sort(shapeVector.begin(), shapeVector.end(), compareAreasDes);
                        sort(shapeVector.begin(), shapeVector.end(), sortByName);
                        printVector(shapeVector);
                    }
                }
                
                if (sortInput > "e")
                {
                    cout << endl << "Invalid input. Please try again!" << endl;
                }
            }    
        }
        
        if (userInput > 5)
        {
            cout << endl << "Invalid input. Please try again!" << endl;
        }
        
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << endl << "Invalid input. Please try again!" << endl;
        }
    }
    
	return 0;
}
