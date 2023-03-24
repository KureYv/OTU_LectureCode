#include <iostream>
#include <string>

#pragma once

using namespace std;

class Shape {
    protected:
        string name = "shape";
    public:
        // constructor
        Shape () {};

        // deconstructor
        virtual ~Shape() {};

        /// methods

        void about() {
            cout << "I'm a " << this->name
                 << " with a perimeter of " << this->perimeter()
                 << " and an area of " << this->area()
                 << endl;
        }

        /// abstract methods

        virtual double perimeter() { return 0.00; }
        virtual double area() { return 0.00; }
};

class Circle: public Shape{
    private:
        int radius;
    public:
        double perimeter(){ return 2*3.1459*radius; }
        double area(){ return 3.1459*radius*radius; }
};

class Square: public Shape{
    private:
        int length;
    public:
        double perimeter(){ return 4*length; }
        double area(){ return length*length; }
};