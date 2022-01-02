/*  
Description: using file-stream and arrays to take a list, 
account for errors, and calculate the stats of it. such as 
MIN, MAX, Average and sum of the data.   
Input: user in prompted to input file.  
Output:The output has the files data organized both forward 
and backwards, as well as calculates the MIN, MAX, Ave, and sum.   
*/
#include<iostream>
#include<fstream> //file stream library 
#include<string> // strings library 
using namespace std; 

int main(){
    //declaring my variables 
    ifstream inData; 
    string data; 
    const int size = 100; //static size 
    double array[size]; //array with stattic size 
    int value1 =0;  
    double average, MAX = -100, MIN =100;  
    double sum = 0.0;  
    const int eMax = 100; 
    
   
    do{ //prompting for file input 
    cout << "Enter a file name\n" << "**";
    cin >> data; 
    cout << endl; 
    inData.open (data); //file beign opened 
        //chechking for faliur of file open
        if(!inData.is_open()){
            inData.clear(); 
            inData.ignore(eMax, '\n'); 
            cout << "Error: Invalid file name\n";
            continue; 
        } 
        //reads up to only the end of line 
        while (!inData.eof())
        {   //data being read into a single dimension array
            inData >> array[value1];
            //chechking for faliures within data 
            if (!inData){
                //making sure unused lines in data are seen as errors
                if (!inData.eof()){
                    inData.clear();
                    inData.ignore(eMax, '\n');
                    cout << "Error: Invalid input in file.\n";
                }
                continue; 
        }  
        value1++; //count of data 
        }
        inData.close(); //closing the file 
        cout << endl; 
        //printing count of data 
        cout << "Amount of Elements Read In: " << value1 << endl;  
        cout.precision(2); 
        cout << fixed << showpoint; 
        //printing the data forwards 
        cout << "Forwards: ";
        for (int i = 0; i < value1; i++){
            //adding up all the data 
            sum+= array[i]; 
            //clac the average of the data 
            average = sum/value1;
             //printing out the last line so no coma 
            if(i == value1 -1){
                cout << array[i]; 
            }
            else {//every number except the last one  
                cout << array[i] << ", ";
            }
            //to figure out the MAX and MIN 
            if(array[i] > MAX){
                MAX = array[i]; 
            }
            if(array[i] <= MIN){
                MIN = array[i];
            }
        }
        cout << endl;  
        //to print out the data being read backwards 
        cout << "Backwards: ";
        for (int i = value1-1; i > 0; i--){
            //prints out all the data except the first one
            cout << array[i] << ", "; 
        }
           //prints the first one and no coma 
            cout << array[0]; 
        cout << endl;  
        //prinitng results from the calc done above 
        cout << "Minimum: " << MIN << '\n';
        cout << "Maximum: " << MAX << '\n'; 
        cout << "Sum: " << sum << '\n'; 
        cout << "Average: " << average << '\n';  

        break; //breaking the do..while loop 
    }while(true);
    
    return 0; 
}


