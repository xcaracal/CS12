//include any standard libraries needed
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   if(argc < 2){
       cout << "Usage: " << argv[0] << " InputFile" << endl;
       return 1;
   }
    string input = argv[1];
   // verify file name provided on command line
    ifstream fin(input);
   // open file and verify it opened
    if(!fin.is_open()){
        cout << "Error Opening " << argv[1] << endl;
        return 1;
    }
   // Declare an array of doubles of size ARR_CAP.
    double ARR_NUM[ARR_CAP];
    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
    int i = 0;
    double num;
    int sz = 0;
    while(fin >> num && sz < ARR_CAP){
        if(i < ARR_CAP){
        ARR_NUM[i] = num;
        ++i;
        ++sz;
        }  
    }
    fin.close();
   // Call the mean function passing it this array and output the 
   // value returned.
    cout << "Mean: " << endl;
    cout << mean(ARR_NUM, sz) << endl;
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
    int deleteNum;
    cout << "Enter index of value to be removed (0 to " << sz-1 <<  "):" << endl;
    cin >> deleteNum;
    
	
   // Call the display function to output the array.
    cout << "Before removing value: " << endl;
    display(ARR_NUM, sz);
    cout << endl;
   
   // Call the remove function to remove the value at the index
   // provided by the user.
     remove(ARR_NUM, sz, deleteNum);
    
   // Call the display function again to output the array
   // with the value removed.
    cout << "After removing value: " << endl;
    display(ARR_NUM, sz);
    cout << endl;
   
   // Call the mean function again to get the new mean
    cout << "Mean: " << endl;
    cout << mean(ARR_NUM, sz) << endl;
   
	return 0;
}
       
//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize){
    int i;
    double sum = 0.0;
    double meanO;
    for(i = 0; i < arraySize; ++i){
        sum += array[i];
    }
    double nums = arraySize + 0.0;
    meanO = sum/nums;
    return meanO;
}

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index){
    int i;
    for(i = index; i+1 < arraySize; ++i){
        array[i] = array[i+1];
        array[arraySize] = 0;
    }
    arraySize--;
}


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize){
    int i;
     for(i = 0; i+1 < arraySize; ++i){
         cout << array[i] << ", ";
    }
    cout << array[arraySize - 1];
}