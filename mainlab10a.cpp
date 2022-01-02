/*  
Description: using  2D arrys and functions to claculate the 
sum of a colum and rows of a file input
Input: user inputs file with set of numbers for calculation  
Output: the output is the sum of the rows and colums as well 
as the data from the file structured using parametric 
manipulators  
*/

#include<iostream> //c++ librarary 
#include<fstream> //file stream library 
#include<string> //string libraray 
#include<iomanip> //library for parametric manipulators 
using namespace std; 
static const int size = 10;
 //declaration of functions
void openFile(ifstream&, string);
void readFile(ifstream&, double[][size], int, int);
void rowSumCalculator(double[][size], int, int);
void columnSumCalculator(double[][size], int, int);

const int rCnt = 7; 
const int cCnt = 10;
int main(){
    //declaration of file stream 
    ifstream iFile; 
    string file; 
    //user propmpt statment 
    string prompt = "Enter a file name\n**";
    //declaration of array 
    double arr[rCnt][cCnt]={};  
    int row = rCnt, colum= cCnt; 
    
    //dunction to opne user input file
    openFile(iFile, prompt); 
    //reading the file inot a 2d arry for calculation 
    readFile(iFile, arr, row, colum); 
    //to calculate the sum of the rows 
    rowSumCalculator(arr, row, colum); 
    //calculates the sum of the colums 
    columnSumCalculator(arr, row, colum);
    //closes the file 
    iFile.close(); 

    return 0; 
}
//function to open the file 
void openFile(ifstream& iFile, string prompt){
    const int eMax = 100;  
    string file; 
    //do..while loop that checks for user input error 
    do{
    cout << prompt; 
    cin >> file; 
    cout << endl; 
    iFile.open (file); //file beign opened 
        //chechking for faliur of file open
        if(!iFile.is_open()){
            iFile.clear(); 
            iFile.ignore(eMax, '\n'); 
            cout << "Error: Invalid file name\n";
            continue;
        }
        break; 
    }while(true); //condition for the d0..while loop
}
 
//reading the file into a 2d array 
void readFile(ifstream& iFile, double arr[][size],int rowCount,
int colCount){
    //the row and colum of the file being initialized 
    for (int i = 0; i < rowCount; i++){
        for(int j = 0; j< colCount; j++){
            //accessing file data and storing 
            iFile >> arr[i][j];  
        }
    }
}
//caluclating the sum of the rows 
void rowSumCalculator(double arr[][size],int rowCount,int colCount){
     double sumRow  = 0; 
     cout.precision(1); //fixing to one place past decimal 
     cout << fixed << showpoint; 
     //prints out stament 
     cout << "ROW SUMS:" << endl;
     
     for (int i = 0; i < rowCount; i++){
        for(int j = 0; j< colCount-1; j++){
            //calcualtion sum 
            sumRow += arr[i][j]; 
            //ouput elemnt 
        cout << left <<setw(4) <<arr[i][j]<< setw(3) <<" + ";
        
        } 
        //out put element accounting for the last value in the row
        cout<< setw(4) <<arr[i][cCnt-1]<< setw(3)
        << " = "<< sumRow + arr[i][cCnt-1] << endl; 
        //reseting the sumRow for the second row 
        sumRow = 0; 
    }
        
}
//calculating the sum of the colums of the data set 
void columnSumCalculator(double arr[][size],int rowCount,int colCount){
    double sumCol = 0; 
    cout << endl; 
    //prints out stament
    cout << "COLUMN SUMS:" << endl;

    for (int i = 0; i < colCount; i++){
        for(int j = 0; j< rowCount -1; j++){  
            //calcualtion sum
            sumCol += arr[j][i]; 
            //ouput elemnt 
            cout <<left << setw(4) <<arr[j][i] << setw(3) << " + "; 
        }                  
        //out put element accounting for the last value in the row
        cout << setw(4) <<arr[rCnt-1][i] << setw(3) 
        << " = " << sumCol + arr[rCnt-1][i] << endl;
        sumCol = 0; 
    }
 
}

