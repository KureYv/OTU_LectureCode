#include<iostream>
#include<vector>
using namespace std;

class GameInventory{
    private: 
        string name;
        string brand;
        int year;
        double price;
    public:
        GameInventory(); //Constructor
        GameInventory(string name, string brand, int year, double price); //Overloaded constructor
        string getName();
        string getBrand();
        int getYear();
        double getPrice();
        void displayGame();
        bool isSimilar(const GameInventory& game);
};

GameInventory::GameInventory(){ //Default values when the constructor is called without params
    this->name = "";
    this->brand = "";
    this->year = 0;
    this->price = 0;
}

GameInventory::GameInventory(string name, string brand, int year, double price){ //Sets the values depending on the constructor params
    this->name = name;
    this->brand = brand;
    this->year = year;
    this->price = price;
}

string GameInventory::getName(){ //Gets the name
    return this->name;
}

string GameInventory::getBrand(){ //Gets the brand
    return this->brand;
}

int GameInventory::getYear(){ //Gets the year
    return this->year;
}

double GameInventory::getPrice(){ //Gets the price
    return this->price;
}

void GameInventory::displayGame(){ //Prints out the game
    cout << "Name: "<< this->name << ", " << "Brand: " << this->brand << ", " << "Year: " << this->year <<", "<< "Price " << this->price << endl; 
}

bool GameInventory::isSimilar(const GameInventory& game){ //Checks to see if the game exists already in the inventory or not, each value has to be the same for it to return true
    if(game.brand == this->brand && game.name == this->name && game.price == this->price && game.year == this->year){
        return true;
    }
    return false;
}


bool searchInventory(vector<GameInventory>& v, GameInventory& game){ //Uses the function isSimilar to see if the game exists
    for(auto gameSearched:v){
        if(game.isSimilar(gameSearched)){
            return true;
        }
    }
    return false;
}

void displayInventory(vector<GameInventory>& v){ //Displays the full inventory based on the vector
    for(auto gameSearched:v){
        gameSearched.displayGame();
    }
}

bool addNewGame(vector<GameInventory>& v, GameInventory& game){ //Adds a new game to the vector, with a try and catch block to catch errors generated if the item already exists in the vector
    try{
        if(!(searchInventory(v, game))){
            v.push_back(game);
        }
        else{
            string errorMessage = "Already Exists";
            throw errorMessage;
        }
    }
    catch(string error){
        return false;
    }
    return true;
}