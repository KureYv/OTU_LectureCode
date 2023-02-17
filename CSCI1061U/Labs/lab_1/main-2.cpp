#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:

    Complex() : real(0), imaginary(0){ }
    Complex(double real, double imaginary): real(real), imaginary(imaginary){}


    void setReal(double real) {
        this-> real = real;
    }
    void setImaginary(double imaginary) {
        this-> imaginary = imaginary;
    }
    double getReal() {
        return real;
    }
    double getImaginary() {
        return imaginary;
    }
    Complex operator+(Complex& operand){
        return Complex(real + operand.real, imaginary + operand.imaginary);
    }
    Complex operator-(Complex& operand){
        return Complex(real - operand.real, imaginary - operand.imaginary);
    }
    Complex operator*(Complex& operand){
        return Complex(real * operand.real - imaginary * operand.imaginary,
                       real * operand.imaginary + imaginary * operand.real);

    }

    bool operator==(Complex& operand){
        if (real == operand.real && imaginary == operand.imaginary){
            return true;
        }
        return false;
    }
};

ostream& operator<<(ostream& output, Complex& complex) {
    output << "(" << complex.getReal() << " , " << complex.getImaginary() << ")";
    return output;
}


double extractReal(string str) {
    int start = str.find("(") + 1;
    int end = str.find(",");
    string realStr = str.substr(start, end - start);
    return stod(realStr);
}

double extractImaginary(string str) {
    int start = str.find(",") + 1;
    int end = str.find(")");
    string imaginaryStr = str.substr(start, end - start);
    return stod(imaginaryStr);
}

int main() {
    string str1, str2;

    cout << "Enter the first complex number in the form (a,b): ";
    cin >> str1;

    cout << "Enter the second complex number in the form (a,b): ";
    cin >> str2;


    double real1 = extractReal(str1);
    double imaginary1 = extractImaginary(str1);
    double real2 = extractReal(str2);
    double imaginary2 = extractImaginary(str2);

    Complex c1(real1, imaginary1);
    Complex c2(real2, imaginary2);


    cout << endl << "*********************************************" << endl;
    cout << "            Results of Calculations " << endl;
    cout << "*********************************************" << endl;
    cout << (c1+c2).getReal()<< endl;



}