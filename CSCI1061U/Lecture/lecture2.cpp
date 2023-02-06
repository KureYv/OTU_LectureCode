#include <iostream>
using namespace std;
class Animal{
    private:
        string taxonomic;
        double weight;
    public:
        int size;
        string name;
        string colloquial;
        Animal();
        Animal(int x, double y, string tax, string collo);    
        void toString();
        void setTaxonomicName(string s){
            taxonomic = s;
        }

        void getTaxonomicName(){
            cout << taxonomic << endl;
        }        
        void eat();

};

class Habitat{
    private:
        Animal owner;
    public:
        string name;
        void setOwner(Animal a){owner=a;}
        Animal getOwner(){return owner;}
        Habitat(){owner = Animal();}
};

Animal::Animal(int x, double y, string tax, string collo){
    size = x;
    taxonomic = tax;
    colloquial = collo;
    weight = y;
}
Animal::Animal(){
    this->size = 2;
}

void Animal::toString(){
    cout << colloquial << endl;
    cout << taxonomic << endl;
}

void Animal::eat(){
    size++;
}

int main(){
    Animal lion(9,20, "lion", "mane");
    Animal Pig(3,15, "pig", "pork");
    Animal* cat = new Animal();
    cat->colloquial = "cat";
    cat->setTaxonomicName("Felis Catus");
    cat->size = 66;
    cat->toString();
    cat->getTaxonomicName();
    cat->name = "cat";
    cout<< cat->size << endl;
    lion.eat();
    cout << lion.size << endl;
    lion.toString();

    Habitat h = Habitat();
    h.setOwner(*cat);
    h.name = "my couch";
    cout << h.getOwner().name<<" lives on "<< h.name;
    return 0;
}