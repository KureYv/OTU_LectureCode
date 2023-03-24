#include <iostream>   
using namespace std;

int main()
{
    int size = 8;
    string one = "1 ", zero = "0 ";

    for (int i = 0; i < size; i++)
    {
        for (int j = size; j > 0; j--)
        {
            if ((i + j) % 2 != 0)
            {
                cout << zero << " ";
            }
            else
            {
                cout << one << " ";
            }
            
        }
        cout << endl;
    }
    return 0;
}