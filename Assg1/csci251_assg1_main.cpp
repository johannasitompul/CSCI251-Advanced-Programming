#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include <algorithm>

#include "grid.h"

using namespace std;

// 2D array
grid ** mainArray;

// function prototype list
vector<string> tokenizeString (string, string);

void getConfigFile();
void getCloudValue(string);
void getPressureValue(string);
void getCityLocation(string);
void initCityIDlist();
void insertData();

int getNoOfLines(string);
int getX(string);
int getY(string);
int getRange(string);
int getMinVal(string);
int getMaxVal(string);

void initMainArray();
void displayCityMap();
void displayCloudIdxMap();
void displayCloudLvlMap();
void displayPressIdxMap();
void displayPressLvlMap();
void deallocateMainArray();

void displayX();

string getLMH(double);
double getAveCloudVal(int);
double getAvePressVal(int);
int getRainProb(string, string);
void displayRainProb(int);
string getCityName(int);
void displaySummary();

int getArea(int);

// student details
void myDetails()
{
    cout << endl;
    cout << "Student ID   : 7020041" << endl;
    cout << "Student Name : Johanna Then Lasmauli Sitompul" << endl;
    cout << "=============================================" << endl;
    
    cout << "Welcome to Weather Information Processing System!" << endl << endl;
}


// menu
void menu()
{
    myDetails();
    
    cout << "1) Read in and process a configration file" << endl;
    cout << "2) Display city map" << endl;
    cout << "3) Display cloud coverage map (cloudiness index)" << endl;
    cout << "4) Display cloud coverage map (LMH symbol)" << endl;
    cout << "5) Display atmospheric pressure map (pressure index)" << endl;
    cout << "6) Display atmospheric pressure map (LMH symbol)" << endl;
    cout << "7) Show weather forecast summary report" << endl;
    cout << "8) Quit" << endl << endl;
}


int main()
{
    myDetails();
    
    insertData();
    
    int userInput;
    
    while (userInput != 8)
    {
        menu();
        cout << "Please enter your choice : "; 
        cin >> userInput;
        
        if (userInput == 1)
        {
            insertData();
        }

        if (userInput == 2)
        {
            displayCityMap();
        }
    
        if (userInput == 3)
        {
            displayCloudIdxMap();
        }
    
        if (userInput == 4)
        {
            displayCloudLvlMap();
        }
    
        if (userInput == 5)
        {
            displayPressIdxMap();
        }
    
        if (userInput == 6)
        {
            displayPressLvlMap();
        }
    
        if (userInput == 7)
        {
            displaySummary();
        }
    
        if (userInput > 8)
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
    
    // displayX();
    
    delete [] cityIDtemp;
    delete [] cityIDlist;
    deallocateMainArray();
    
    return 0;
}


// ==================== FUNCTIONS ====================

// cher's function
vector<string> tokenizeString (string input, string delimiter)
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


// my functions 
void getConfigFile()
{
    string configFileName;
    cout << "Please enter config filename : ";
    cin >> configFileName;

    ifstream instream(configFileName);
    
    string line, rangeXLine, rangeYLine, fileNames[3];
    
    if (instream.good())
    {
    	// search for needed lines, ignore the rest
    	int i=0;
    	while (getline(instream, line))
    	{
    	    size_t pos1 = line.find("GridX_IdxRange");
    	    if (pos1 != string::npos)
    	        rangeXLine = line;
                
    	    size_t pos2 = line.find("GridY_IdxRange");
    	    if (pos2 != string::npos)
    	        rangeYLine = line;
    	            
    	    size_t pos3 = line.find(".txt");
    	    if (pos3 != string::npos)
    	    {
    	        fileNames[i] = line;
    	        i++;
    	    }
    	}
    
    	locFileName = fileNames[0];
    	ccFileName = fileNames[1];
    	presFileName = fileNames[2];
    	
    	// highest & lowest value of x & size of x (no of columns)
    	rangeX_min = getMinVal(rangeXLine);
    	rangeX_max = getMaxVal(rangeXLine);
    	x_size = getRange(rangeXLine);
    	
    	// highest & lowest value of y & size of y (no of rows)
    	rangeY_min = getMinVal(rangeYLine);
    	rangeY_max = getMaxVal(rangeYLine);
    	y_size = getRange(rangeYLine);
    	
    	cout << endl;
    	cout << "Range of X : " << rangeXLine << endl;
    	cout << "Range of Y : " << rangeYLine << endl;
    	cout << "City location data file name        : " << locFileName << endl;
    	cout << "Cloud coverage data file name       : " << ccFileName << endl;
    	cout << "Atmospheric pressure data file name : " << presFileName << endl;
    	cout << endl << endl;
    	cout << "Reading " << configFileName << " successful!" << endl << endl;
    }
    
    else
    {
    	cout << endl << "Error encountered. Please check your input and re-run the program!" << endl << endl;
    }		
}	


// get number of lines in a file
int getNoOfLines(string filename)
{
    int result;
    int noOfLines = 0;
    string line;
    ifstream openFile;
    openFile.open(filename);
    
    while (getline(openFile, line))
        ++noOfLines;
        
    result = noOfLines-1;
    return result;
}


// get the x coordinates from a line
int getX(string strcoordinates)
{
    string str;
    
    str = strcoordinates.erase(0, 1);
    str.pop_back();
    
    vector<string> tokenVector = tokenizeString(str, ", ");
    int result = stoi(tokenVector[0]);
    
    return result;
}


// get the y coordinates from a line
int getY(string strcoordinates)
{
    string str;
    
    str = strcoordinates.erase(0, 1);
    str.pop_back();
    
    vector<string> tokenVector = tokenizeString(str, ", ");
    int result = stoi(tokenVector[1]);
    
    return result;
}


// get range of x or y
int getRange(string str)
{
    int result;
    vector<string> tokenStringVector = tokenizeString(str, "=");
    string a = tokenStringVector[1];
    
    tokenStringVector.clear();
    tokenStringVector = tokenizeString (a, "-");
    
    int minVal = stoi(tokenStringVector[0]);
    int maxVal = stoi(tokenStringVector[1]);
    result = maxVal - minVal + 1; 
    
    return result;
}


// get min value from the Grid_IdxRange=... line
int getMinVal(string str)
{
    vector<string> tokenStringVector = tokenizeString(str, "=");
    string a = tokenStringVector[1];
    
    tokenStringVector.clear();
    tokenStringVector = tokenizeString (a, "-");
    
    int minVal = stoi(tokenStringVector[0]);
    
    return minVal;
}


// get max value from the Grid_IdxRange=... line
int getMaxVal(string str)
{
    vector<string> tokenStringVector = tokenizeString(str, "=");
    string a = tokenStringVector[1];
    
    tokenStringVector.clear();
    tokenStringVector = tokenizeString (a, "-");
    
    int maxVal = stoi(tokenStringVector[1]);
    
    return maxVal;
}


// initialising mainArray
void initMainArray()
{
    mainArray = new grid * [x_size];
    
    for (int i=0; i<x_size; i++)
    {
        mainArray[i] = new grid [y_size];
    }
}


// get values of cloud coverage
void getCloudValue(string filename)
{
    ifstream instream(filename);
    string line;
    
    for (int i=0; i<getNoOfLines(filename); i++)
    {
        getline(instream, line);
        vector<string> tokenStringVector = tokenizeString(line, "-");
        
        int x = getX(tokenStringVector[0]);
        int y = getY(tokenStringVector[0]);
        int cVal = stoi(tokenStringVector[1]);
        mainArray[x][y].cloudValue = cVal;
        mainArray[x][y].cloudIdx = cVal/10;
        
        if ( 0 <= cVal && cVal < 35)
            mainArray[x][y].cloudLvl = "L";
            
        else if ( 35 <= cVal && cVal < 65)
            mainArray[x][y].cloudLvl = "M";
        
        else if ( 65 <= cVal && cVal < 100)
            mainArray[x][y].cloudLvl = "H";
    }
}


// get values of atmos pressure
void getPressureValue(string filename)
{
    ifstream instream(filename);
    string line;
    
    for (int i=0; i<getNoOfLines(filename); i++)
    {
        getline(instream, line);
        vector<string> tokenStringVector = tokenizeString(line, "-");
        
        int x = getX(tokenStringVector[0]);
        int y = getY(tokenStringVector[0]);
        int pVal = stoi(tokenStringVector[1]);
        mainArray[x][y].pressValue = pVal;
        mainArray[x][y].pressIdx = pVal/10;
        
        if ( 0 <= pVal && pVal < 35)
            mainArray[x][y].pressLvl = "L";
            
        else if ( 35 <= pVal && pVal < 65)
            mainArray[x][y].pressLvl = "M";
        
        else if ( 65 <= pVal && pVal < 100)
            mainArray[x][y].pressLvl = "H";
    }
}


// get city location data
void getCityLocation(string filename)
{
    ifstream instream(filename);
    string line;
    int n = getNoOfLines(filename);
    cityIDtemp = new int[n];
    
    for (int i=0; i<n; i++)
    {
        getline(instream,line);
        vector<string> tokenStringVector = tokenizeString(line, "-");
        int _x = getX(tokenStringVector[0]);
        int _y = getY(tokenStringVector[0]);
        int _id = stoi(tokenStringVector[1]);
        string str = tokenStringVector[2];
        
        mainArray[_x][_y].x = _x;
        mainArray[_x][_y].y = _y;
        mainArray[_x][_y].ID = _id;
        mainArray[_x][_y].name = str;
        
        cityIDtemp[i] = _id;
        cityIDtemp_size++;
    }
    
    // get number of cities by finding unique elements in the array cityIDtemp
    for (int i=1; i<n; i++)
    {
        int j = 0;
        
        for (j=0; j<i; j++)
        {
            
            if (cityIDtemp[i] == cityIDtemp[j])
            {
                break;
            }
        }
        
        if (i == j)
            noOfCities++;
    }
    
}


// insert the unique city id into a separate array (no repeats!)
void initCityIDlist()
{
    cityIDlist = new int[noOfCities];
    int k = 0;
    
    for (int i=0; i<cityIDtemp_size; i++)
    {
        int j;
        for (j=0; j<i; j++)
        {
            if (cityIDtemp[i] == cityIDtemp[j])
            {
                break;
            }
        }
        if (i == j)
        {
            cityIDlist[k] = cityIDtemp[i];
            // cout << cityIDlist[k] << endl;
            k++;
        }
    }
}


// assignment of values into the data structure
void insertData()
{
    getConfigFile();
    
    initMainArray();
    
    getCloudValue(ccFileName);
    
    getPressureValue(presFileName);
    
    getCityLocation(locFileName);
    
    initCityIDlist();
}


// display location of city by city id
void displayCityMap()
{
    int width = 4;
    
    cout << endl;
    
    // top fence
    cout << "   " << string((x_size*width)+4, '=') << endl;
    
    // main loop to print out the values from mainArray[][]
    for (int i=y_size-1; i>=0; i--)
    {
        cout << setw(2) << i << " |";
        
        for (int j=0; j<x_size; j++)
        {
            // city id was initialised to 888
            if (mainArray[j][i].ID > 0)
                cout << setw(4) << mainArray[j][i].ID;
            else
                cout << "    ";
        }
        
        cout << "  |" << endl;
    }
    
    // bottom fence
    cout << "   " << string((x_size*width)+4, '=') << endl;

    cout << "    ";
    for (int k=0; k<x_size; k++)
    {
        cout << setw(4) << k;
    }
    cout << endl;
}


// same concept as displayCityMap()
void displayCloudIdxMap()
{
    int width = 4;
    
    cout << endl;
    cout << "   " << string((x_size*width)+4, '=') << endl;
    
    for (int i=y_size-1; i>=0; i--)
    {
        cout << setw(2) << i << " |";
        
        for (int j=0; j<x_size; j++)
        {
            cout << setw(4) << mainArray[j][i].cloudIdx;
        }
        
        cout << "  |" << endl;
    }
    
    cout << "   " << string((x_size*width)+4, '=') << endl;

    cout << "    ";
    for (int k=0; k<x_size; k++)
    {
        cout << setw(4) << k;
    }
    cout << endl;
}


// same concept as displayCityMap()
void displayCloudLvlMap()
{
    int width = 4;
    
    cout << endl;
    cout << "   " << string((x_size*width)+4, '=') << endl;
    
    for (int i=y_size-1; i>=0; i--)
    {
        cout << setw(2) << i << " |";
        
        for (int j=0; j<x_size; j++)
        {
            cout << right << setfill(' ') << setw(4) << mainArray[j][i].cloudLvl;
        }
        
        cout << "  |" << endl;
    }
    
    cout << "   " << string((x_size*width)+4, '=') << endl;

    cout << "    ";
    for (int k=0; k<x_size; k++)
    {
        cout << setw(4) << k;
    }
    cout << endl;
}


// same concept as displayCityMap()
void displayPressIdxMap()
{
    int width = 4;
    
    cout << endl;
    cout << "   " << string((x_size*width)+4, '=') << endl;
    
    for (int i=y_size-1; i>=0; i--)
    {
        cout << setw(2) << i << " |";
        
        for (int j=0; j<x_size; j++)
        {
            cout << setw(4) << mainArray[j][i].pressIdx;
        }
        
        cout << "  |" << endl;
    }
    
    cout << "   " << string((x_size*width)+4, '=') << endl;

    cout << "    ";
    for (int k=0; k<x_size; k++)
    {
        cout << setw(4) << k;
    }
    cout << endl;
}


// same concept as displayCityMap()
void displayPressLvlMap()
{
    int width = 4;
    
    cout << endl;
    cout << "   " << string((x_size*width)+4, '=') << endl;
    
    for (int i=y_size-1; i>=0; i--)
    {
        cout << setw(2) << i << " |";
        
        for (int j=0; j<x_size; j++)
        {
            cout << right << setfill(' ') << setw(4) << mainArray[j][i].pressLvl;
        }
        
        cout << "  |" << endl;
    }
    
    cout << "   " << string((x_size*width)+4, '=') << endl;

    cout << "    ";
    for (int k=0; k<x_size; k++)
    {
        cout << setw(4) << k;
    }
    cout << endl;
}


// delete mainArray[][]
void deallocateMainArray()
{
    if (mainArray != nullptr)
    {
        for (int i=0; i<x_size; i++)
        {
            delete [] mainArray[i];
        }
        delete mainArray;
    }
}


// for the average values in the summary
string getLMH(double value)
{
    string str;
    
    if ( 0 <= value && value < 35)
        str = "L";
            
    else if ( 35 <= value && value < 65)
        str = "M";
        
    else if ( 65 <= value && value < 100)
        str = "H";
        
    return str;
}


// get average by city id
double getAveCloudVal(int cityID)
{
    double aveCloudVal;
    int sumOfCloudVal = 0;
    int counter = 0;
    
    // assumption!
    int min_X = 100;
    int max_X = 0;
    int min_Y = 100;
    int max_Y = 0;
    
    // get min and max values of both x and y for each city (perimeter)
    for (int i=0; i<y_size; i++)
    {
        for (int j=0; j<x_size; j++)
        {
            if (mainArray[j][i].ID == cityID) 
            {
                if (mainArray[j][i].x < min_X)
                    min_X = mainArray[j][i].x;
                    
                if (mainArray[j][i].x > max_X)
                    max_X = mainArray[j][i].x;
                    
                if (mainArray[j][i].y < min_Y)
                    min_Y = mainArray[j][i].y;
                    
                if (mainArray[j][i].y > max_Y)
                    max_Y = mainArray[j][i].y;
            }
        }
    }
    
    // add or minus 1 to get include the area surrounding the city
    min_X = min_X - 1;
    max_X = max_X + 1;
    min_Y = min_Y - 1;
    max_Y = max_Y + 1;
    
    // set limit according to the overall range
    if (min_X < rangeX_min)
        min_X = rangeX_min;
        
    if (max_X > rangeX_max)
        max_X = rangeX_max;
        
    if (min_Y < rangeY_min)
        min_Y = rangeY_min;
        
    if (max_Y > rangeY_max)
        max_Y = rangeY_max;
    
    // loop using the min and max of x and y values
    for (int y=min_Y; y<=max_Y; y++)
    {
        for (int x=min_X; x<=max_X; x++)
        {
            sumOfCloudVal = sumOfCloudVal + mainArray[x][y].cloudValue;
            counter++;
        }
    }
    
    aveCloudVal = static_cast<double>(sumOfCloudVal) / counter;
    
    return aveCloudVal;
}


// same concept as getAveCloudVal()
double getAvePressVal(int cityID)
{
    double avePressVal;
    int sumOfPressVal = 0;
    int counter = 0;
    
    int min_X = 100;
    int max_X = 0;
    int min_Y = 100;
    int max_Y = 0;
    
    for (int i=0; i<y_size; i++)
    {
        for (int j=0; j<x_size; j++)
        {
            if (mainArray[j][i].ID == cityID) 
            {
                if (mainArray[j][i].x < min_X)
                    min_X = mainArray[j][i].x;
                    
                if (mainArray[j][i].x > max_X)
                    max_X = mainArray[j][i].x;
                    
                if (mainArray[j][i].y < min_Y)
                    min_Y = mainArray[j][i].y;
                    
                if (mainArray[j][i].y > max_Y)
                    max_Y = mainArray[j][i].y;
            }
        }
    }
    
    min_X = min_X - 1;
    max_X = max_X + 1;
    min_Y = min_Y - 1;
    max_Y = max_Y + 1;
    
    if (min_X < rangeX_min)
        min_X = rangeX_min;
        
    if (max_X > rangeX_max)
        max_X = rangeX_max;
        
    if (min_Y < rangeY_min)
        min_Y = rangeY_min;
        
    if (max_Y > rangeY_max)
        max_Y = rangeY_max;
    
    for (int y=min_Y; y<=max_Y; y++)
    {
        for (int x=min_X; x<=max_X; x++)
        {
            sumOfPressVal = sumOfPressVal + mainArray[x][y].pressValue;
            counter++;
        }
    }
    
    avePressVal = static_cast<double>(sumOfPressVal) / counter;
    
    return avePressVal;
}


// extra function to check other values when writing code
void displayX ()
{
    int width = 4;
    
    cout << endl;
    cout << "   " << string((x_size*width)+4, '=') << endl;
    
    for (int i=y_size-1; i>=0; i--)
    {
        cout << setw(2) << i << " |";
        
        for (int j=0; j<x_size; j++)
        {
            cout << setw(4) << mainArray[j][i].x;
        }
        
        cout << "  |" << endl;
    }
    
    cout << "   " << string((x_size*width)+4, '=') << endl;

    cout << "    ";
    for (int k=0; k<x_size; k++)
    {
        cout << setw(4) << k;
    }
    
    cout << endl;
}


// using compare function
int getRainProb(string cloud, string pressure)
{
    int rainProb;
    
    if (cloud.compare("L") == 0)
    {
        if (pressure.compare("L") == 0)
            rainProb = 70;
        if (pressure.compare("M") == 0)
            rainProb = 40;
        if (pressure.compare("H") == 0)
            rainProb = 10;
    }
    
    if (cloud.compare("M") == 0)
    {
        if (pressure.compare("L") == 0)
            rainProb = 80;
        if (pressure.compare("M") == 0)
            rainProb = 50;
        if (pressure.compare("H") == 0)
            rainProb = 20;
    }
    
    if (cloud.compare("H") == 0)
    {
        if (pressure.compare("L") == 0)
            rainProb = 90;
        if (pressure.compare("M") == 0)
            rainProb = 60;
        if (pressure.compare("H") == 0)
            rainProb = 30;
    }
    
    return rainProb;
}


// rain rain go away
void displayRainProb(int rainProb)
{
    if (rainProb == 10)
    {
      cout << endl;
      cout << "~" << endl;
      cout << "~~" << endl;
      cout << endl;
    }
    
    if (rainProb == 20)
    {
      cout << endl;
      cout << "~~" << endl;
      cout << "~~~" << endl;
      cout << endl;
    }
    
    if (rainProb == 30)
    {
      cout << endl;
      cout << "~~~" << endl;
      cout << "~~~~" << endl;
      cout << endl;
    }
    
    if (rainProb == 40)
    {
      cout << endl;
      cout << "~~~~" << endl;
      cout << "~~~~~" << endl;
      cout << endl;
    }
    
    if (rainProb == 50)
    {
      cout << endl;
      cout << "~~~~" << endl;
      cout << "~~~~~" << endl;
      cout << "    \\" << endl;
      cout << endl;
    }
    
    if (rainProb == 60)
    {
      cout << endl;
      cout << "~~~~" << endl;
      cout << "~~~~~" << endl;
      cout << "    \\\\" << endl;
      cout << endl;
    }
    
    if (rainProb == 70)
    {
      cout << endl;
      cout << "~~~~" << endl;
      cout << "~~~~~" << endl;
      cout << "    \\\\\\" << endl;
      cout << endl;
    }
    
    if (rainProb == 80)
    {
      cout << endl;
      cout << "~~~~" << endl;
      cout << "~~~~~" << endl;
      cout << "    \\\\\\\\" << endl;
      cout << endl;
    }
    
    if (rainProb == 90)
    {
      cout << endl;
      cout << "~~~~" << endl;
      cout << "~~~~~" << endl;
      cout << "    \\\\\\\\\\" << endl;
      cout << endl;
    }
}


// using the cityIDlist[] to get name from mainArray[][]
string getCityName(int cityID)
{
    string str;
    
    for (int i=0; i<y_size; i++)
    {
        for (int j=0; j<x_size; j++)
        {
            if (mainArray[j][i].ID == cityID) 
            {
                str = mainArray[j][i].name;
                break;
            }
        }
    }
    
    return str;
}


// using cityIDlist[] to get values from mainArray[][]
void displaySummary()
{
    int city_id;
    cout << endl;
    cout << "Weather Forecast Summary Report" << endl;
    cout << "-------------------------------" << endl;
    
    for (int i=0; i<noOfCities; i++)
    {
        city_id = cityIDlist[i];
        cout << "City Name : " << getCityName(city_id) << endl;
        cout << "City ID   : " << city_id << endl;
        cout << "City Size : " << getArea(city_id) << " unit(s) " << endl;
        
        // (input) --to-get--> (output)
        // city id -> average cloud value
        // average cloud value -> LMH 
        // 2 LMH values -> rain probability
        // rain probability -> rain symbols
        cout << "Ave. Cloud Cover (ACC)  : " << fixed << setprecision(2) << getAveCloudVal(city_id);
        cout << " ( " << getLMH(getAveCloudVal(city_id)) << " ) " << endl;
        
        cout << "Ave. Pressure (AP)      : " << fixed << setprecision(2) << getAvePressVal(city_id);
        cout << " ( " << getLMH(getAvePressVal(city_id)) << " ) " << endl;
        
        cout << "Probability of Rain (%) : " << getRainProb( getLMH(getAveCloudVal(city_id)), getLMH(getAvePressVal(city_id)) );
        displayRainProb( getRainProb( getLMH(getAveCloudVal(city_id)), getLMH(getAvePressVal(city_id)) ) );
    }
}


// get area of city by city id
int getArea(int cityID)
{
	int area = 0;
	
	for (int i=0; i<y_size; i++)
    {
        for (int j=0; j<x_size; j++)
        {
            if (mainArray[j][i].ID == cityID) 
            {
            	area++;
            }
        }
    }
    
    return area;
}
    	
