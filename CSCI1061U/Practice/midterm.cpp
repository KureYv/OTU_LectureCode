#include <iostream>

using namespace std;

int main()
{
    string** array;
    int arrSizeX, arrSizeY, choice, inputRowNumber, inputColumnNumber;
    string input;
    cout << "Enter number of rows: ";
    cin >> arrSizeY;
    cout << "Enter number of columns: ";

    // allocate memory for the array
    array = new string*[arrSizeY];
    for (int i = 0; i < arrSizeY; i++) {
        array[i] = new string[arrSizeX];
    }

    while (true) {
        cout << "Menu:" << endl
             << "1. Add a string" << endl
             << "2. Remove a string" << endl
             << "3. Print the array" << endl
             << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the row number: ";
            cin >> inputRowNumber;
            cout << "Enter the column number: ";
            cin >> inputColumnNumber;
            cout << "Enter the string: ";
            cin >> input;
            array[inputRowNumber][inputColumnNumber] = input;
        } else if (choice == 2) {
            cout << "Enter the row number: ";
            cin >> inputRowNumber;
            cout << "Enter the column number: ";
            cin >> inputColumnNumber;
            array[inputRowNumber][inputColumnNumber] = "";
        } else if (choice == 3) {
            for (int i = 0; i < arrSizeY; i++) {
                for (int j = 0; j < arrSizeX; j++) {
                    if(array[i][j] == ""){
                        cout << "NULL";
                    }
                    cout << array[i][j] << " ";
                }
                cout << endl;
            }
        } else if (choice == 4) {
            // free memory and exit
            for (int i = 0; i < arrSizeY; i++) {
                delete[] array[i];
            }
            delete[] array;
            return 0;
        }
    }
    return 0;
}
