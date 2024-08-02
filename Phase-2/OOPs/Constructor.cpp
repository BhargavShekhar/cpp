#include<iostream>
using namespace std;

class Hero
{
    public:
    int health;
    char level;

    // creating a constructor
    Hero()
    {
        cout << "Constructor called" << endl;
    }
};

// Class for learning parametric constructor and this keyword
class learning
{
    public:
    int study_level;

    // creating a parametric constructor
    learning(int study_level)
    {
        // object level       // variable which came through the function
        this -> study_level = study_level;

        cout << study_level << endl;

    }

};

int main()
{
    // object creation statically
    Hero ramesh;

    // oblect creation dinamically
    Hero *rajesh = new Hero;

    // parametric class call
    learning para(10);

    // dinamical call
    learning *parametric = new learning(12);
    
    return 0;
}