#include<iostream>
#include <string.h>
using namespace std;

class Hero
{
    public:
    char *name;
    int health;
    char level;

    // creating a constructor
    Hero()
    {
        cout << "Constructor Called" << endl;
        name = new char[20];
    }

    void setName(char name[20])
    {
        strcpy(this -> name, name);
    }

    string getName()
    {
        return this -> name;
    }

    void setHealth(int h)
    {
        health = h;
    }

    int getHealth()
    {
        return health;
    }

    void setLevel(char level)
    {
        this -> level = level;
    }

    char getLevel()
    {
        return level;
    }

    void print()
    {
        cout << "Name: " << this -> name << endl;
        cout << "Health: " << this -> health << endl;
        cout << "Level: " << this -> level << endl;
    }

    // DESTRUCTOR
    ~Hero()
    {
        cout << "Destructor Called" << endl;
    }

};

int main()
{
    // static Object creation
    Hero a;

    // Dynamic Object creation
    Hero *b = new Hero();
    delete b;   // Manually calling destructor for dynamic allocated Object.
    
    return 0;
}