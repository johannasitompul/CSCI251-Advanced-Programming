#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "MyTemplates.h"

using namespace std;


// global variables
string filterCriteria = "Point2D";
string sortCriteria = "X-ordinate";
string sortOrder = "ASC";

vector<Point2D> p2dVector;
vector<Point3D> p3dVector;
vector<Line2D> l2dVector;
vector<Line3D> l3dVector;


// function prototype
vector<string> tokenizeString(string, string);

int getNoOfRecs(string);

void initVectors();
void storeData();
void displaySummary();


// student details
void myDetails()
{
    cout << endl;
    cout << "Student ID   : 7020041" << endl;
    cout << "Student Name : Johanna Then Lasmauli Sitompul" << endl;
    cout << "=============================================" << endl;
    
    cout << "Welcome to Assignment 3 Program!" << endl << endl;
}


// menu
void mainMenu()
{
    myDetails();
    
    cout << "1) Read in data" << endl;
    cout << "2) Specify filtering criteria ( current : " << filterCriteria << " )" << endl;
    cout << "3) Specify sorting criteria ( current : " << sortCriteria << " )" << endl;
    cout << "4) Specify sorting order ( current : " << sortOrder << " )" << endl;
    cout << "5) View data" << endl;
    cout << "6) Store data" << endl;
    cout << "7) Quit" << endl << endl;
}

void filterMenu()
{
    cout << "[ Specifying filtering criteria ( current : " << filterCriteria << " ) ]" << endl;
    cout << endl;
    cout << "a) Point2D records" << endl;
    cout << "b) Point3D records" << endl;
    cout << "c) Line2D records" << endl;
    cout << "d) Line3D records" << endl << endl;
}

void sortMenuP2D()
{
    cout << "[ Specifying sorting criteria ( current : " << sortCriteria << " ) ]" << endl;
    cout << endl;
    cout << "a) X-ordinate value" << endl;
    cout << "b) Y-ordinate value" << endl;
    cout << "c) Dist. Fr Origin value" << endl << endl;
}

void sortMenuP3D()
{
    cout << "[ Specifying sorting criteria ( current : " << sortCriteria << " ) ]" << endl;
    cout << endl;
    cout << "a) X-ordinate value" << endl;
    cout << "b) Y-ordinate value" << endl;
    cout << "c) Z-ordinate value" << endl;
    cout << "d) Dist. Fr Origin value" << endl << endl;
}

void sortMenuLine()
{
    cout << "[ Specifying sorting criteria ( current : " << sortCriteria << " ) ]" << endl;
    cout << endl;
    cout << "a) Pt.1 value" << endl;
    cout << "b) Pt.2 value" << endl;
    cout << "c) Length value" << endl << endl;
}

void sortOrderMenu()
{
    cout << "[ Specifying sorting order ( current : " << sortOrder << " ) ]" << endl;
    cout << endl;
    cout << "a) Ascending" << endl;
    cout << "b) Descending" << endl << endl;
}


// function template
template <typename T>
void remove_duplicates(vector<T> & vec)
{
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

template <typename T>
void printVector(vector<T> & vec)
{
    for (int i=0; i<vec.size(); i++)
    {
        cout << vec[i] << "    " << vec[i].getScalarValue() << endl;
    }
}

// ========== MAIN ==========

int main()
{
    int userInput;
    
    while (userInput != 7)
    {
        mainMenu();
        
        cout << "Please enter your choice : ";
        cin >> userInput;
        
        if (userInput == 1)
        {
            initVectors();
        }
        
        if (userInput == 2)
        {
            string filterInput;
            
            filterMenu();
            
            cout << "Please enter your choice : ";
            cin >> filterInput;
            
            while (filterInput != "a" && filterInput != "b" && filterInput != "c" && filterInput != "d")
            {
                cout << "Invalid input. Please re-enter your choice : ";
                cin >> filterInput;
            }
            
            if (filterInput == "a")
            {
                filterCriteria = "Point2D";
            }
            
            if (filterInput == "b")
            {
                filterCriteria = "Point3D";
            }
            
            if (filterInput == "c")
            {
                filterCriteria = "Line2D";
                sortCriteria = "Pt.1";
            }
            
            if (filterInput == "d")
            {
                filterCriteria = "Line3D";
                sortCriteria = "Pt.1";
            }
        }
        
        if (userInput == 3)
        {
            string sortInput;
            
            if (filterCriteria == "Point2D")
            {
                sortMenuP2D();
                cout << "Please enter your choice : ";
                cin >> sortInput;
                
                while (sortInput != "a" && sortInput != "b" && sortInput != "c")
                {
                    cout << "Invalid input. Please re-enter your choice : ";
                    cin >> sortInput;
                }
                
                if (sortInput == "a")
                {
                    sortCriteria = "X-ordinate";
                }
                
                if (sortInput == "b")
                {
                    sortCriteria = "Y-ordinate";
                }
                
                if (sortInput == "c")
                {
                    sortCriteria = "Dist. Fr Origin";
                }
            }
            
            if (filterCriteria == "Point3D")
            {
                sortMenuP3D();
                cout << "Please enter your choice : ";
                cin >> sortInput;
                
                while (sortInput != "a" && sortInput != "b" && sortInput != "c" && sortInput != "d")
                {
                    cout << "Invalid input. Please re-enter your choice : ";
                    cin >> sortInput;
                }
                
                if (sortInput == "a")
                {
                    sortCriteria = "X-ordinate";
                }
                
                if (sortInput == "b")
                {
                    sortCriteria = "Y-ordinate";
                }
                
                if (sortInput == "c")
                {
                    sortCriteria = "Z-ordinate";
                }
                
                if (sortInput == "d")
                {
                    sortCriteria = "Dist. Fr Origin";
                }
            }
            
            if (filterCriteria == "Line2D" || filterCriteria == "Line3D")
            {
                sortMenuLine();
                cout << "Please enter your choice : ";
                cin >> sortInput;
                
                while (sortInput != "a" && sortInput != "b" && sortInput != "c")
                {
                    cout << "Invalid input. Please re-enter your choice : ";
                    cin >> sortInput;
                }
                
                if (sortInput == "a")
                {
                    sortCriteria = "Pt.1";
                }
                
                if (sortInput == "b")
                {
                    sortCriteria = "Pt.2";
                }
                
                if (sortInput == "c")
                {
                    sortCriteria = "Length";
                }
            }
        }
        
        if (userInput == 4)
        {
            string orderInput;
            
            sortOrderMenu();
            
            cout << "Please enter your choice : ";
            cin >> orderInput;
            
            while (orderInput != "a" && orderInput != "b")
            {
                cout << "Invalid input. Please re-enter your choice : ";
                cin >> orderInput;
            }
            
            if (orderInput == "a")
            {
                sortOrder = "ASC";
            }
            
            if (orderInput == "b")
            {
                sortOrder = "DES";
            }
        }
        
        // view data
        if (userInput == 5)
        {
            // =========================================================================================== point2d
            if (filterCriteria == "Point2D")
            {
                if (sortCriteria == "X-ordinate")
                {
                    if (sortOrder == "ASC")
                    {
                        sort( p2dVector.begin(), p2dVector.end(), compareX<Point2D> );
                        displaySummary();
                        cout << "    X     Y     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - -" << endl;
                        printVector(p2dVector);
                    }
                    
                    if (sortOrder == "DES")
                    {
                        sort( p2dVector.rbegin(), p2dVector.rend(), compareX<Point2D> );
                        displaySummary();
                        cout << "    X     Y     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - -" << endl;
                        printVector(p2dVector);
                    }
                }
                
                if (sortCriteria == "Y-ordinate")
                {
                    if (sortOrder == "ASC")
                    {
                        sort( p2dVector.begin(), p2dVector.end(), compareY<Point2D> );
                        displaySummary();
                        cout << "    X     Y     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - -" << endl;
                        printVector(p2dVector);
                    }
                    
                    if (sortOrder == "DES")
                    {
                        sort( p2dVector.rbegin(), p2dVector.rend(), compareY<Point2D> );
                        displaySummary();
                        cout << "    X     Y     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - -" << endl;
                        printVector(p2dVector);
                    }
                }
                
                if (sortCriteria == "Dist. Fr Origin")
                {
                    if (sortOrder == "ASC")
                    {
                        sort( p2dVector.begin(), p2dVector.end(), compareDistLength<Point2D> );
                        displaySummary();
                        cout << "    X     Y     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - -" << endl;
                        printVector(p2dVector);
                    }
                    
                    if (sortOrder == "DES")
                    {
                        sort( p2dVector.rbegin(), p2dVector.rend(), compareDistLength<Point2D> );
                        displaySummary();
                        cout << "    X     Y     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - -" << endl;
                        printVector(p2dVector);
                    }
                }
            }
            
            // =========================================================================================== point3d 
            if (filterCriteria == "Point3D")
            {
                if (sortCriteria == "X-ordinate")
                {
                    if (sortOrder == "ASC")
                    {
                        sort( p3dVector.begin(), p3dVector.end(), compareX<Point3D> );
                        displaySummary();
                        cout << "    X     Y     Z     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(p3dVector);
                    }
                    
                    if (sortOrder == "DES")
                    {
                        sort( p3dVector.rbegin(), p3dVector.rend(), compareX<Point3D> );
                        displaySummary();
                        cout << "    X     Y     Z     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(p3dVector);
                    }
                }
                
                if (sortCriteria == "Y-ordinate")
                {
                    if (sortOrder == "ASC")
                    {
                        sort( p3dVector.begin(), p3dVector.end(), compareY<Point3D> );
                        displaySummary();
                        cout << "    X     Y     Z     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(p3dVector);
                    }
                    
                    if (sortOrder == "DES")
                    {
                        sort( p3dVector.rbegin(), p3dVector.rend(), compareY<Point3D> );
                        displaySummary();
                        cout << "    X     Y     Z     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(p3dVector);
                    }
                }
                
                if (sortCriteria == "Z-ordinate")
                {
                    if (sortOrder == "ASC")
                    {
                        sort( p3dVector.begin(), p3dVector.end(), compareZ<Point3D> );
                        displaySummary();
                        cout << "    X     Y     Z     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(p3dVector);
                    }
                    
                    if (sortOrder == "DES")
                    {
                        sort( p3dVector.rbegin(), p3dVector.rend(), compareZ<Point3D> );
                        displaySummary();
                        cout << "    X     Y     Z     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(p3dVector);
                    }
                }
                
                if (sortCriteria == "Dist. Fr Origin")
                {
                    if (sortOrder == "ASC")
                    {
                        sort( p3dVector.begin(), p3dVector.end(), compareDistLength<Point3D> );
                        displaySummary();
                        cout << "    X     Y     Z     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(p3dVector);
                    }
                    
                    if (sortOrder == "DES")
                    {
                        sort( p3dVector.rbegin(), p3dVector.rend(), compareDistLength<Point3D> );
                        displaySummary();
                        cout << "    X     Y     Z     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(p3dVector);
                    }
                }
            }
            
            // =========================================================================================== line2d 
            if (filterCriteria == "Line2D")
            {
                if (sortCriteria == "Pt.1")
                {
                    if (sortOrder == "ASC")
                    {
                        sort( l2dVector.begin(), l2dVector.end(), comparePt1<Line2D> );
                        displaySummary();
                        cout << " P1-X  P1-Y      P2-X  P2-Y     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(l2dVector);
                    }
                    
                    if (sortOrder == "DES")
                    {
                        sort( l2dVector.rbegin(), l2dVector.rend(), comparePt1<Line2D> );
                        displaySummary();
                        cout << " P1-X  P1-Y      P2-X  P2-Y     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(l2dVector);
                    }
                }
                
                if (sortCriteria == "Pt.2")
                {
                    if (sortOrder == "ASC")
                    {
                        sort( l2dVector.begin(), l2dVector.end(), comparePt2<Line2D> );
                        displaySummary();
                        cout << " P1-X  P1-Y      P2-X  P2-Y     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(l2dVector);
                    }
                    
                    if (sortOrder == "DES")
                    {
                        sort( l2dVector.rbegin(), l2dVector.rend(), comparePt2<Line2D> );
                        displaySummary();
                        cout << " P1-X  P1-Y      P2-X  P2-Y     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(l2dVector);
                    }
                }
                
                if (sortCriteria == "Length")
                {
                    if (sortOrder == "ASC")
                    {
                        sort( l2dVector.begin(), l2dVector.end(), compareDistLength<Line2D> );
                        displaySummary();
                        cout << " P1-X  P1-Y      P2-X  P2-Y     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(l2dVector);
                    }
                    
                    if (sortOrder == "DES")
                    {
                        sort( l2dVector.rbegin(), l2dVector.rend(), compareDistLength<Line2D> );
                        displaySummary();
                        cout << " P1-X  P1-Y      P2-X  P2-Y     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(l2dVector);
                    }
                }
            }
            
            // =========================================================================================== line3d
            if (filterCriteria == "Line3D")
            {
                if (sortCriteria == "Pt.1")
                {
                    if (sortOrder == "ASC")
                    {
                        sort( l3dVector.begin(), l3dVector.end(), comparePt1<Line3D> );
                        displaySummary();
                        cout << " P1-X  P1-Y  P1-Z      P2-X  P2-Y  P2-Z     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(l3dVector);
                    }
                    
                    if (sortOrder == "DES")
                    {
                        sort( l3dVector.rbegin(), l3dVector.rend(), comparePt1<Line3D> );
                        displaySummary();
                        cout << " P1-X  P1-Y  P1-Z      P2-X  P2-Y  P2-Z     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(l3dVector);
                    }
                }
                
                if (sortCriteria == "Pt.2")
                {
                    if (sortOrder == "ASC")
                    {
                        sort( l3dVector.begin(), l3dVector.end(), comparePt2<Line3D> );
                        displaySummary();
                        cout << " P1-X  P1-Y  P1-Z      P2-X  P2-Y  P2-Z     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(l3dVector);
                    }
                    
                    if (sortOrder == "DES")
                    {
                        sort( l3dVector.rbegin(), l3dVector.rend(), comparePt2<Line3D> );
                        displaySummary();
                        cout << " P1-X  P1-Y  P1-Z      P2-X  P2-Y  P2-Z     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(l3dVector);
                    }
                }
                
                if (sortCriteria == "Length")
                {
                    if (sortOrder == "ASC")
                    {
                        sort( l3dVector.begin(), l3dVector.end(), compareDistLength<Line3D> );
                        displaySummary();
                        cout << " P1-X  P1-Y  P1-Z      P2-X  P2-Y  P2-Z     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(l3dVector);
                    }
                    
                    if (sortOrder == "DES")
                    {
                        sort( l3dVector.rbegin(), l3dVector.rend(), compareDistLength<Line3D> );
                        displaySummary();
                        cout << " P1-X  P1-Y  P1-Z      P2-X  P2-Y  P2-Z     Dist. Fr Origin" << endl;
                        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
                        printVector(l3dVector);
                    }
                }
            }
        }
        
        if (userInput == 6)
        {
            storeData();
        }
        
        if (userInput > 7)
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


// ========== FUNCTIONS ==========

// display summary of the various criteria
void displaySummary()
{
    cout << endl << "[ View data... ]" << endl;
    cout << "Filtering criteria : " << filterCriteria << endl;
    cout << "Sorting criteria   : " << sortCriteria << endl;
    cout << "Sorting order      : " << sortOrder << endl << endl;
}


// storing data to an output .txt file
void storeData()
{
    string outputFilename;
    cout << "Please enter filename : ";
    cin >> outputFilename;
    
    ofstream outstream;
    outstream.open(outputFilename);
    
    if (filterCriteria == "Point2D")
    {
        outstream << "    X     Y     Dist. Fr Origin" << endl;
        outstream << "- - - - - - - - - - - - - - - -" << endl;
    
        for (int i=0; i<p2dVector.size(); i++)
        {
            outstream << p2dVector[i] << "    " << p2dVector[i].getScalarValue() << endl;
        }
        
        outstream.close();
        cout << endl << p2dVector.size() << " records output successfully!" << endl;
    }
    
    if (filterCriteria == "Point3D")
    {
        outstream << "    X     Y     Z     Dist. Fr Origin" << endl;
        outstream << "- - - - - - - - - - - - - - - - - - -" << endl;
    
        for (int i=0; i<p3dVector.size(); i++)
        {
            outstream << p3dVector[i] << "    " << p3dVector[i].getScalarValue() << endl;
        }
        
        outstream.close();
        cout << endl << p3dVector.size() << " records output successfully!" << endl;
    }
    
    if (filterCriteria == "Line2D")
    {
        outstream << " P1-X  P1-Y      P2-X  P2-Y     Length" << endl;
        outstream << "- - - - - - - - - - - - - - - - - - - -" << endl;
    
        for (int i=0; i<l2dVector.size(); i++)
        {
            outstream << l2dVector[i] << "    " << l2dVector[i].getScalarValue() << endl;
        }
        
        outstream.close();
        cout << endl << l2dVector.size() << " records output successfully!" << endl;
    }
    
    if (filterCriteria == "Line3D")
    {
        outstream << " P1-X  P1-Y  P1-Z      P2-X  P2-Y  P2-Z     Length" << endl;
        outstream << "- - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    
        for (int i=0; i<l3dVector.size(); i++)
        {
            outstream << l3dVector[i] << "    " << l3dVector[i].getScalarValue() << endl;
        }
        
        outstream.close();
        cout << endl << l3dVector.size() << " records output successfully!" << endl;
    }
}


// to get values from specific locations
vector<string> tokenizeString(string input, string delimiter)
{
	size_t pos = 0;
	string token;
	vector<string> result;

	while ((pos = input.find(delimiter)) != string::npos) 
	{
    	token = input.substr(0, pos);
    	result.push_back (token);
		input.erase(0, pos + delimiter.length());
	}

	result.push_back (input);

	return (result);
}


// to initialise vectors and remove duplicates
void initVectors()
{
    string filename;
    cout << "Please enter filename : ";
    cin >> filename;
    
    ifstream instream;
    instream.open(filename);
    string line;
    
    while ( getline(instream, line) )
    {
        // point2D
        size_t pos1 = line.find("Point2D");
        if (pos1 != string::npos)
        {
            Point2D p2d;
            string str;
            
            str = line.erase(0,10);
            vector<string> token = tokenizeString(str, ",");
            
            int ax = stoi(token[0]);        // X value
            int ay = stoi(token[1]);        // Y value
            
            p2d = Point2D(ax,ay);
            
            p2dVector.push_back(p2d);
        }
        
        // point3D
        size_t pos2 = line.find("Point3D");
        if (pos2 != string::npos)
        {
            Point3D p3d;
            string str;
            
            str = line.erase(0,10);
            vector<string> token = tokenizeString(str, ",");
            
            int ax = stoi(token[0]);
            int ay = stoi(token[1]);
            int az = stoi(token[2]);        // Z value
            
            p3d = Point3D(ax,ay,az);
            
            p3dVector.push_back(p3d);
        }
        
        // line2D 
        size_t pos3 = line.find("Line2D");
        if (pos3 != string::npos)
        {
            Line2D l2d;
            string str;
            
            str = line.erase(0,9);
            str.erase( remove(str.begin(), str.end(), '['), str.end() );        // so that the string basically contains only "," and integers
            vector<string> token = tokenizeString(str, ",");
            
            int ax = stoi(token[0]);
            int ay = stoi(token[1]);
            
            int bx = stoi(token[2]);
            int by = stoi(token[3]);
            
            l2d = Line2D( Point2D(ax,ay), Point2D(bx,by) );
            
            l2dVector.push_back(l2d);
        }
        
        // line3D 
        size_t pos4 = line.find("Line3D");
        if (pos4 != string::npos)
        {
            Line3D l3d;
            string str;
            
            str = line.erase(0,9);
            str.erase( remove(str.begin(), str.end(), '['), str.end() );
            vector<string> token = tokenizeString(str, ",");
            
            int ax = stoi(token[0]);
            int ay = stoi(token[1]);
            int az = stoi(token[2]);
            
            int bx = stoi(token[3]);
            int by = stoi(token[4]);
            int bz = stoi(token[5]);
            
            l3d = Line3D( Point3D(ax,ay,az), Point3D(bx,by,bz) );
            
            l3dVector.push_back(l3d);
        }
    }
    
    remove_duplicates(p2dVector);
    remove_duplicates(p3dVector);
    remove_duplicates(l2dVector);
    remove_duplicates(l3dVector);
    
    cout << endl << getNoOfRecs(filename) << " records read in successfully!" << endl;
}


// get number of lines in a file
int getNoOfRecs(string filename)
{
    int result;
    int noOfLines = 0;
    string line;
    ifstream openFile;
    openFile.open(filename);
    
    while (getline(openFile, line))
        ++noOfLines;
        
    result = noOfLines;
    return result;
}