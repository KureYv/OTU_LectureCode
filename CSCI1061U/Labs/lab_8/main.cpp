#include<iostream> //imports
#include <array>
using namespace std;

bool checkRange(int x){ //function that checks if the number is in the range, takes in aan integer and returns if it's between 10 and 100 inclusive
    if(x >= 10 and x <= 100){
        return true;
    }
    return false;
}

bool checkDuplicate(int x, array<int, 10> arr){ //function that checks for duplicates, it takes in an array and an integer as parameters, loops through the array and returns true if the number is found
    for(auto i: arr){
        if(x == i){
            return true;
        }
    }
    return false;
}

int main() //main function, handles all the inputs and logic
{
    int num, counter = 0, countRuns = 0; //variables
    array<int, 10> arr{}; //creating the array for 10 inputs maximum
    while(countRuns<10){ //while loop to loop through the inputs, countRuns is a variable that increases each run if its not a duplicate number
        cout << "Enter 10 integers between 10 and 100:" << endl;
        cout << "Enter a number: ", cin >> num;
        if(checkRange(num)){ //see if number is in range
            if(!checkDuplicate(num, arr)){ //if number isnt a duplicate in the array
                arr[counter] = num; //add to array
                counter++; //increase counter, this counter is used to determine which position to add to
            }
            else{
                cout << "Duplicate number." << endl; 
                 cout << endl;
            }
            countRuns++; //increment countRuns
        }
        else{
            cout << "Invalid number. Please enter a number between 10 and 100." << endl;
            cout << endl;
        }
    }


    cout << "The nonduplicate values are:" << endl;
    for(auto a:arr){ //for loop to print array out
        if(a!=0){ //if it isnt a 0 as it is an invalid number, but can appear if nothing is inputted in that position of the array
            cout << a << " ";
        }
    }
    return 0; //end of main
}