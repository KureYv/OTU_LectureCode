#include <shape.h>
#include<iostream>
using namespace std;

int main()
{
    Shape** sh;
    sh[0] = new Square();
    sh[1] = new Circle();
    sh[2] = new Shape();

    for(int i =0;i<3;i++){
        sh[i]->about();
    }
    return 0;
}