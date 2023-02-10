#include<iostream>
#include<string>
using namespace std;

class Complex{
    private:
        double real, imaginary;
    public:
        double getReal();
        double getImaginary();
        void setReal(double real);
        void setImaginary(double imaginary);
        Complex(double real, double imaginary);
        

        Complex operator+(Complex& operand); //Override operator functions here, takes in a complex class

        Complex operator-(Complex& operand);

        Complex operator*(Complex& operand);

        bool operator==(Complex& operand);

        friend ostream& operator<<(ostream& output, Complex& complex); //Override output operator

};

Complex::Complex(double real, double imaginary){ //Default constructor, takes in a real and imaginary number
    this->real = real;
    this->imaginary = imaginary;
}

Complex Complex::operator+(Complex& operand){ //Overload the + operator to add complex and imaginary numbers by adding them seperately
    return Complex(this->real+operand.getReal(), this->imaginary+operand.getImaginary());
}

Complex Complex::operator-(Complex& operand){ //Overload the - operator to add complex and imaginary numbers by subtracting them seperately
    return Complex(this->real-operand.getReal(), this->imaginary-operand.getImaginary());
}

Complex Complex::operator*(Complex& operand){ 
//Overload the * operator, to get the real number the first real number gets multiplied to other real number which gets subtracted by the first imaginary number multiplied to the second imaginary number. For the imaginary number
//the second imaginary number is multiplied to the first real number which gets added to the first imaginary number multiplied by the second real number, this is because i^2 = -1
    return Complex(this->real*operand.getReal() - this->imaginary*operand.getImaginary(), this->real * operand.getImaginary() + this->imaginary * operand.getReal());
}

bool Complex::operator==(Complex& operand){ //Overloads the == operator to do comparisons for Complex
    if(this->real == operand.getReal() && this->imaginary == operand.getImaginary()){
        return true;
    }
    return false;
}

ostream& operator<<(ostream& output, Complex& complex){ //Overloads the << operator to output Complex
    output <<   "(" << complex.getReal() << " , " << complex.getImaginary() << ")";
    return output;
}


double Complex::getReal(){return this->real;} //Getters

double Complex::getImaginary(){return this->imaginary;}

void Complex::setReal(double realNumber){this->real = real;} //Setters

void Complex::setImaginary(double imaginaryNumber){this->imaginary = imaginary;}

double extractReal(string str){ //Extract real function, takes in a string to return the real number in double form
    string real;
    real = str.substr(1, str.find(","));
    return stod(real);
}

double extractImaginary(string str){ //Extract double function, takes in a string to return the imaginary number in double form
    string imaginary;
    imaginary = str.substr(str.find(",")+1, str.size() - str.find(",") -2);
    return stod(imaginary);
}



void displayAll(double realNumber1, double imaginaryNumber1, double realNumber2, double imaginaryNumber2){ //Displayall function, takes in the real numbers and imaginary numbers and prints it out
    Complex a(realNumber1, imaginaryNumber1);
    Complex b(realNumber2, imaginaryNumber2);
    cout << endl << "*********************************************"<< endl << "Results of Calculations " << endl << "*********************************************"<< endl;
    cout << a << " + " << b << " = (" << (a+b).getReal()<< " , " << (a+b).getImaginary() << ")" << endl;
    cout << a << " - " << b <<" = (" << (a-b).getReal()<< " , " << (a-b).getImaginary() << ")" << endl;
    cout << a << " * " << b << " = (" << (a*b).getReal()<< " , " << (a*b).getImaginary() << ")" << endl;
    if(a == b){
        cout << a << " == "  << b << endl;
    }
    else{
        cout << a << " != "  << b << endl;
    }
}



int main() //Main function
{
    string input1, input2;
    cout << "Enter the first complex number in the form (a,b): "; //Take in input here
    cin >> input1;
    cout << "Enter the second complex number in the form (a,b): ";
    cin >> input2;
    displayAll(extractReal(input1), extractImaginary(input1), extractReal(input2), extractImaginary(input2)); //Gives all the info the Displayall the process
    
    return 0;
}