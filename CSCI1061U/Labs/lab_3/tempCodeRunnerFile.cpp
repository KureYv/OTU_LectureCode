#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Bits{
    private:
        string sequence;
        string packet;
    public: 
        string getSequence();
        string getPacket();
        void setSequence(string sequence);
        void setPacket(string packet);
        void toString();
        bool isEmpty();

};

string Bits::getSequence(){
    return this->sequence;
}

string Bits::getPacket(){
    return this->packet;
}

void Bits::setSequence(string sequence){
    this->sequence = sequence;
}

void Bits::setPacket(string packet){
    this->packet = packet;
}

void Bits::toString(){
    cout << this->packet << ": " << this->sequence << endl;
}

bool Bits::isEmpty(){
    if(this->sequence == "" && this->packet == ""){
        return true;
    }
    return false;
}


Bits getBitsObject(string word, string user_sequence){
    Bits object;
    if(word.find(user_sequence)){
        object.setPacket(word.substr(0,3));
        object.setSequence(word.substr(5,36));
    }
    return object;
}

Bits* resize(Bits* arr, int* size){
    Bits* newArr = new Bits[*size+1];
    for(int i=0; i<*size; i++){
        newArr[i] = arr[i];
    }
    delete[] arr;
    return newArr;
}

void display(Bits *arr, int size){
    cout << "********** Bit Sequences Found **********"<< endl;
    for(int i = 0; i <size;i++){
        if (!(arr[i].isEmpty())){
            arr[i].toString();
        }
    }

}



int main()
{
    ifstream file(("bits.txt"));
    string input, sentence, choice;
    bool cont = true;
    Bits* arr = new Bits[10];
    int count = 0;
    while(cont){
        cout << "Enter a bit sequence: ";
        cin >> input;        
        while(getline(file, sentence)){
            if(sentence.find(input) != string::npos){
                arr = resize(arr, &count);
                arr[count] = getBitsObject(sentence, input);
                count++; 
            }
        }
        display(arr, count);
        cout << "Total occurrences: " << count << endl;
        cout << "Continue? (y/n):";
        cin >> choice;
        if(choice == "n"){
            cont = false;
        }
    }
    
    
    delete[] arr;
    return 0;
}