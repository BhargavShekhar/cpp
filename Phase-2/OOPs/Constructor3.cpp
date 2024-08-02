#include<iostream>
#include<string.h>
using namespace std;

class Hero
{
    public:
    char *name;
    int health;
    char level;

    Hero()
    {
        cout << "Constructor called" << endl;
        name = new char[100];  // good practice !! initialize when object is created
    }

    void setName(char name[20])
    {
        strcpy(this -> name, name);
    }

    string getName()
    {
        return name;
    }

    void setHealth(int h)
    {
        health = h;
    }

    int getHealth()
    {
        return health;
    }

    void setLevel(char ch)
    {
        level = ch;
    }

    char getLevel()
    {
        return level;
    }

    void print()
    {
        cout << "Name: " << this -> name << endl;
        cout << "health: " << this -> health << endl;
        cout << "level: " << this -> level << endl;
    }

    // Copy Constructor
    Hero(Hero &temp)
    {
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this -> name = ch;

        cout << "copy constroctor called" << endl;

        this -> health = temp.health;
        this -> level = temp.level;
    }
};

int main()
{
    // creating a object --> Hero1
    Hero hero1;

    // setting up the values
    hero1.setHealth(97);
    hero1.setLevel('A');
    char name[8] = "Bhargav";
    hero1.setName(name);

    // printing the values
    hero1.print();



    // using defaul copy contructor --> we have to comment out our own copy constructor
    Hero hero2(hero1);

    hero1.name[0] = 'A';
    cout << "Printing Hero1" << endl;
    hero1.print();
    cout << "Printing Hero2 " << endl;
    hero2.print();
    
    return 0;
}