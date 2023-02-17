using namespace std;
#include <iostream>
#include <lecture6.hpp>

int main()
{
    Operation o;
    cout << "Adding: " << o.add(o.MAXINT,1) << endl;
    cout << "First division: " << o.divide(50,0) << endl;
    cout << "Second division: " << o.divide(50,5) << endl;
    cout << "Third division: " << o.divide(2147483647, 5) << endl;
}