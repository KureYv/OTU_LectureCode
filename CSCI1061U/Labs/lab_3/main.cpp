#include<iostream>
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
        bool isEmpty(string sequenceOrPacket);
        Bits getBitsObject(string word, string user_sequence);
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
    cout << this->sequence << ":" << this->packet;
}

bool Bits::isEmpty(string sequenceOrPacket){
    if(sequenceOrPacket == ""){
        return true;
    }
    return false;
}

Bits Bits::getBitsObject(string word, string user_sequence){
    
}



int main()
{
    
    return 0;
}