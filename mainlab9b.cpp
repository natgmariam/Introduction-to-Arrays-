/*  
Description: using arrys and functions to claculate grades 
with parallele arrays 
Input: user inpurs file and name selection 
Output: the output is the name is order, grades, and 
the calclulated grade average 
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std; 

void readFile(ifstream&, string[], double[], int&); 
void print(double[], int);
void print(string[], int);
void printReverse(double[], int); 
void printReverse(string[], int); 
double averageScore(string, string[], double[], int); 

int main(){
    //declaring variables 
    static const int size = 100;
    double scores[size]={}; 
    int count = 0; 
    //declaring file stream 
    ifstream iFile; 
    string file; 
    string findnames= ""; 
    string names[size]={};
    //int size = sizeof(names)/sizeof(names[0]);
    int eMax= 100; 
    
    do
    {
    cout << "Enter a file name\n" << "**";
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
        
        readFile(iFile, names, scores, count); 
    //prompt for user name 
    cout << "Enter a student's name to \n find the average score of\n"; 
    cout << "**";
    cin >> findnames; 
    cout << endl;
        
        //close file 
        iFile.close(); 
            cout << "Names Forward: ";
        print(names, count);
            //print 
            cout << "Scores Forward: "; 
        print(scores, count); 
           //print 
            cout << "Names Reverse: "; 
        printReverse(names, count);
           //print stamtnet 
            cout << "Scores Reverse: ";
        printReverse(scores, count);  
        //prints out average with decimals 
        
        cout.precision(6); 
        cout << fixed << showpoint; 
        double ave= averageScore(findnames, names, scores, count); 
            if(ave <= 0){
                cout << "Error: error is not a student in the list\n";
                // cout << "Average score for " << findnames << ": " 
                // << setprecision(6) << fixed<< showpoint<< ave << '\n';  
            }
            else
            {
                cout << "Average score for " << findnames << ": " << ave << '\n';  
                
            }
        break; 
    }while(true);


    return 0; 
}
void readFile(ifstream& iFile, string names[], double scores[], int& count){     
    //the file tansfter into out values 
    while (iFile >> names[count] >> scores[count]){ 
        count++; //count of data 
        }
        
        
} 

void print(double scores[], int size){
    //this is to print the forawrd 
    for (int i = 0; i < size; i++){

        if(i == size-1){
            cout << scores[i] << endl; 
        }
        else {//every number except the last one  
            cout << scores[i] << ", "; 
        }
    }
}

void print(string names[], int size){
    //printss the names 
    for (int i = 0; i < size; i++){
            
        if(i == size -1){
            cout << names[i] << endl; 
        }
        else {//every number except the last one  
            cout << names[i] << ", "; 
        }
    } 
}

void printReverse(double scores[], int size){
    //prints the scores back wards 
    for (int i = size-1; i > 0; --i){
        cout << scores[i] << ", ";      
    }
    cout << scores[0] << endl; 
 
} 

void printReverse(string names[], int size){
    //prints the names backwards 
    for (int i = size-1; i > 0; --i){
         cout << names[i] << ", "; 
    }
        cout << names[0] << endl;      
         
}
double averageScore(string toFind, string names[], double scores[], int size){
    //prints the average 
    int sum = 0; 
    double average = 0; 
    double people =0; 
    for (int i = 0; i < size; i++){
        if (toFind == names[i]){  
            sum+=scores[i];  
            people++; 
            average = sum/people;
        }
        if (size == 0)
            return -1; 
    }
    return average; 
} 
