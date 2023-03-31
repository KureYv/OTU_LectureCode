    #include <iostream> //imports
    #include <string>
    #include <algorithm> 

    using namespace std;

    template <typename T> //declare template name T


    T max_numbers(T arr[], int size){ //function that returns value of template T which takes in arrays and the size of the array
        auto Largest = arr[0];
        for(int i = 0;i<size-1;i++){ //for loop to loop through the array
            Largest = max(Largest, arr[i+1]);
        }
        return Largest; //returns the largest value
    }


    int main()
    {
        int doubleSize = 4; int intSize = 6; int stringSize = 5; //declare array sizes
        double doubleArray[doubleSize] = {-3.4, 58.1, -76.4, 34.4}; 
        int intArr[intSize] = {2, 3, 81, 1, 9, 22};
        string stringArray[stringSize] = {"Ontario", "Tech", "University", "Oshawa", "Canada"};
        auto displayArr = [](auto arr[], int size){for(int i = 0; i< size;i++){cout << arr[i] << ", ";}}; //lambda function to print array out
        cout << "Array of decimals..." << endl;
        displayArr(doubleArray, doubleSize); 
        cout << endl;
        cout << "The largest double: " << max_numbers(doubleArray, doubleSize); //print largest double of the array
        cout << endl;
        cout << endl;
        cout << "Array of integers..." << endl;
        displayArr(intArr, intSize);
        cout << endl;
        cout << "The largest integer: " << max_numbers(intArr, intSize); //print largest int of array
        cout << endl;
        cout << endl;
        cout << "Array of Characters..." << endl;
        displayArr(stringArray, stringSize);
        cout << endl;
        cout << "The largest character sequence: " << max_numbers(stringArray, stringSize); //print largest string of array
        cout << endl;
        cout << endl;
        return 0;
    }