#include<iostream>
#include<vector>
using namespace std;

class GameInventory{ //Header file declarations
    private:
        string name;
        string brand;
        int year;
        double price;
    public:
        GameInventory();
        GameInventory(string name, string brand, int year, double price);
        string getName();
        string getBrand();
        int getYear();
        double getPrice();
        void displayGame();
        bool isSimilar(const GameInventory& game);
};

bool searchInventory(vector<GameInventory>& v, GameInventory& game);
void displayInventory(vector<GameInventory>& v);
bool addNewGame(vector<GameInventory>& v, GameInventory& game);

