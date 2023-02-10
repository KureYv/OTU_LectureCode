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
        

        Complex operator+(Complex& operand){
            return Complex(this->real+operand.getReal(), this->imaginary+operand.getImaginary());
        }

        Complex operator-(Complex& operand){
            return Complex(this->real-operand.getReal(), this->imaginary-operand.getImaginary());
        }
        Complex operator*(Complex& operand){
            return Complex(this->real*operand.getReal() - this->imaginary*operand.getImaginary(), this->real * operand.getImaginary() + this->imaginary * operand.getReal());
        }
        bool operator==(Complex& operand){
            if(this->real == operand.getReal() && this->imaginary == operand.getImaginary()){
                return true;
            }
            return false;
        }   

};

Complex::Complex(double real, double imaginary){
    this->real = real;
    this->imaginary = imaginary;
}

double Complex::getReal(){return this->real;}

double Complex::getImaginary(){return this->imaginary;}

void Complex::setReal(double realNumber){this->real = real;}

void Complex::setImaginary(double imaginaryNumber){this->imaginary = imaginary;}

double extractReal(string str){
    string real;
    real = str.substr(1, str.find(","));
    return stod(real);
}

double extractImaginary(string str){
    string imaginary;
    imaginary = str.substr(str.find(",")+1, str.size() - str.find(",") -2);
    return stod(imaginary);
}


void displayAll(double realNumber1, double imaginaryNumber1, double realNumber2, double imaginaryNumber2){
    Complex a(realNumber1, imaginaryNumber1);
    Complex b(realNumber2, imaginaryNumber2);
    cout << endl << "*********************************************"<< endl << "Results of Calculations " << endl << "*********************************************"<< endl;
    cout << "(" << realNumber1 << " , " << imaginaryNumber1 << ") + (" << realNumber2 << " , " << imaginaryNumber2 << ") = (" << (a+b).getReal()<< " , " << (a+b).getImaginary() << ")" << endl;
    cout << "(" << realNumber1 << " , " << imaginaryNumber1 << ") - (" << realNumber2 << " , " << imaginaryNumber2 << ") = (" << (a-b).getReal()<< " , " << (a-b).getImaginary() << ")" << endl;
    cout << "(" << realNumber1 << " , " << imaginaryNumber1 << ") * (" << realNumber2 << " , " << imaginaryNumber2 << ") = (" << (a*b).getReal()<< " , " << (a*b).getImaginary() << ")" << endl;
    if(a == b){
        cout << "(" << realNumber1 << " , " << imaginaryNumber1 << ") == (" << realNumber2 << " , " << imaginaryNumber2 << ")" << endl;
    }
    else{
        cout << "(" << realNumber1 << " , " << imaginaryNumber1 << ") != (" << realNumber2 << " , " << imaginaryNumber2 << ")" << endl;
    }
}



int main()
{
    string input1, input2;
    cout << "Enter the first complex number in the form (a,b): ";
    cin >> input1;
    cout << "Enter the second complex number in the form (a,b): ";
    cin >> input2;
    displayAll(extractReal(input1), extractImaginary(input1), extractReal(input2), extractImaginary(input2));
    
    return 0;
}