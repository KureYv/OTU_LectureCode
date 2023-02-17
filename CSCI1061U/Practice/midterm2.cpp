#include<iostream>
#include<vector>
using namespace std;

class Vector{
    private:
        int x, y, z;
    public:
        Vector(int x, int y, int z);
        int operator+(vector<int> v);
};

Vector::Vector(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}

int main()
{
    
    return 0;
}