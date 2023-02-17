// #include<iostream>
// using namespace std;

// int add(int num1, int num2){
//     return num1 + num2;
// }

// int multiply(int num1, int num2){
//     return num1 * num2;
// }

// int subtract(int num1, int num2){
//     return num1 - num2;
// }

// int divide(int num1, int num2){
//     try{
//         if(num2 == 0){
//             string errorMessage = "Divide by zero error";
//             throw errorMessage;
//         }
//     }
//     catch(string e){
//         cout << e << endl;
//         return -1;


//     }
    
// }

// int main()
// {
//     cout << divide(5,0) << endl;

//     // try{
//     //     if(a == 5){
//     //         throw 20;
//     //     }
//     //     // cout << "No Exception" << endl;
//     //     string errorMessage = "Exception happened";
//     //     throw errorMessage;

//     // }
//     // catch(int e){
//     //     cout << "An Exception 1 occured. "<< e << "\n";
//     // }
//     // catch(string e){
//     //     cout<< "An Exception 2 occured. " << e << "\n";
//     // }
    
//     return 0;


#include<iostream>
using namespace std;

class Operation{
    public:
        int num1;
        int num2;
        const int MAXINT = 2147483467;
        int add(int num1, int num2);
        int subtract(int num1, int num2);
        int multiply(int num1, int num2);
        int divide(int num1, int num2);
};

int Operation::divide(int num1, int num2){
    try{
        if(num1 > MAXINT/2){
            throw 0;
        }
        if(num2 == 0){
            string errorMessage = "Divide by zero error";
            throw errorMessage;
        }
        return num1/num2;
    }
    catch(string e){
        cout << e << endl;
        return -1;
    }
    catch(...){
        cout << "Num1 is too big" << endl;
        return 0;
    }
    
}

int Operation::add(int num1, int num2){
    try{
        if(num1> MAXINT/2 || num2 > MAXINT/2){
            string error = "Too big! Can't add these.";
            throw error;
        }
        return num1 + num2;
    }
    catch (string s){
        cout << s << endl;
        return 0;
    }
    
}


int Operation::multiply(int num1, int num2){
    try{
        if(num1> MAXINT/2 || num2 > MAXINT/2){
            string error = "Too big! Can't multiply these.";
            throw error;
        }
        return num1 * num2;
    }
    catch (string s){
        cout << s << endl;
        return 0;
    }
    
}

int Operation::subtract(int num1, int num2){
    try{
        if(num1> MAXINT/2 || num2 > MAXINT/2){
            string error = "Too big! Can't subtract these.";
            throw error;
        }
        return num1 - num2;
    }
    catch (string s){
        cout << s << endl;
        return 0;
    }
    
}


