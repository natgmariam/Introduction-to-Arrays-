/* 
Description: using  2D arrys and functions to claculate the
avergae temps of a file input
Input: user inputs file with set of numbers for calculation
Output: the output is the average, MIN, and MAX of input file
as the data from the file is ouptut
*/
#include <iostream> //c++ librarary
#include <fstream>  //file stream library
#include <string>   //string libraray
#include <iomanip>  //library for parametric manipulators
using namespace std;

static const int size = 2;
void openFile(ifstream &, string);
void readFile(ifstream &, double[][size], int, int);
float lowestTemp(double arr[][size], int rowCnt, int colCnt);
float highestTemp(double arr[][size], int rowCnt, int colCnt);
float averageLowTemp(double arr[][size], int rowCnt, int colCnt);
float averageHighTemp(double arr[][size], int rowCnt, int colCnt);
//globabl variables 
const int rCnt = 12;
const int cCnt = 2;
int main()
{

    string place = "";
    double year;
    // declaration of file stream
    ifstream iFile;
    string file;
    // user propmpt statment
    string prompt = "Enter file name\n**";
    // declaration of array
    // declaration of array
    double arr[rCnt][cCnt] = {};
    int row = rCnt, count = cCnt;

    // dunction to opne user input file
    openFile(iFile, prompt);
    iFile >> place >> year;
    // reading the file inot a 2d arry for calculation
    readFile(iFile, arr, row, count);
    cout << place << " " << year << endl;
    //calling temp lowest function 
    lowestTemp(arr, row, count);
    cout << "Lowest temperature of the year was " 
    << lowestTemp(arr, row, count)<<"°"<<" F." << endl;
    //calling highest temp function 
    highestTemp(arr, row, count);
    cout << "Highest temperature of the year was " 
    << highestTemp(arr, row, count)<<"°"<<" F." << endl;
    //calling average of low temp 
    averageLowTemp(arr, row, count);
    cout << "Average low temperature of the year was "
    << averageLowTemp(arr, row, count)<<"°"<<" F." << endl;
    //calling highest ave temp
    averageHighTemp(arr, row, count); 
    cout<< "Average high temperature of the year was "
    << averageHighTemp(arr, row, count)<<"°"<<" F."<< endl; 
    iFile.close(); 
    
    return 0;
}
void openFile(ifstream &iFile, string prompt)
{
    const int eMax = 100;
    string file;
    // do..while loop that checks for user input error
    do
    {
        cout << prompt;
        cin >> file;
        cout << endl;
        iFile.open(file); // file beign opened
        // chechking for faliur of file open
        if (!iFile.is_open())
        {
            iFile.clear();
            iFile.ignore(eMax, '\n');
            cout << "Error: Invalid file name\n";
            continue;
        }
        break;
    } while (!iFile.is_open()); // condition for the d0..while loop
}
void readFile(ifstream &iFile, double arr[][size], int rowCnt, 
int colCnt)
{
    // the row and colum of the file being initialized

    for (int i = 0; i < rowCnt; i++)
    {
        for (int j = 0; j < colCnt; j++)
        {
            // accessing file data and storing
            iFile >> arr[i][j];
        }
    }
}
float lowestTemp(double arr[][size], int rowCnt, int colCnt)
{
    //float MAX = arr[0][1];
    double MIN = 1000; 
    cout.precision(2); //fixing to one place past decimal 
    cout << fixed << showpoint;
    for (int i = 0; i < rowCnt; i++)
    {
        for(int j = 0; j <colCnt; j++){
            // accessing file data and storing/ checking for the min 
            if (arr[i][0] <= MIN)
            {
                //assigning min 
                MIN = arr[i][0];
            }
        }
    }
    return MIN;
}
float highestTemp(double arr[][size], int rowCnt, int colCnt)
{
    float MAX = arr[0][1];
    //double MIN = 100;
    cout.precision(2); //fixing to one place past decimal 
    cout << fixed << showpoint;
    for (int i = 0; i < rowCnt; i++)
    {
        for (int j = 0; j < colCnt; j++)
        {
            // accessing file data and storing/chechking for max 
            //chechking through conditions 
            if (arr[i][j] > MAX)
            {
                MAX = arr[i][j];
            }
            // if (arr[i][j] <= MIN)
            // {
            //     MIN = arr[i][j];
            // }
        }
    }
    return MAX;
}
float averageLowTemp(double arr[][size], int rowCnt, int colCnt){
    float average=0; 
    float sumLow= 0; 
    double MIN = 1000;
    const int divide = 12; 

    for (int i = 0; i < rowCnt; i++)
    {
        //calculating the sum and average 
        sumLow += arr[i][0];
        average = (sumLow/divide);
        // accessing file data and storing/ checking for the min 
        if (arr[i][0] <= MIN)
        {
            MIN = arr[i][0];
        }

    }
    return average;   
}
float averageHighTemp(double arr[][size], int rowCnt, int colCnt){
    double sumHigh = 0;
    float averageHigh = 0; 
    const int divide = 12;
    cout.precision(2); //fixing to one place past decimal 
    cout << fixed << showpoint;
    for (int i = 0; i < rowCnt; i++)
    {
            //calcualting the sum and average 
            sumHigh += arr[i][1]; 
            averageHigh = (sumHigh/divide); 
            //NewAve = averageHigh*1.66;
            //accessing file data and storing/chechking for max 
        
    }
    return averageHigh; 
}
