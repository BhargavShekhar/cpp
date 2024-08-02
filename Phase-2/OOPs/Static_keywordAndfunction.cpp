#include<iostream>
using namespace std;

class Hero
{
    public:
    char *name;
    int health;
    char level;
    // static member
    static int timeToComplete;

    // static member
    static int random()
    {
        return timeToComplete;
    }

    // Constructor
    Hero()
    {
        cout << "Constructor Called" << endl;
        name = new char[20];
    }
};

int Hero :: timeToComplete = 5;

int main()
{
    cout << "Time to complete: " << Hero::timeToComplete << endl;
    cout << "Time to complete: " << Hero::random() << endl;

    Hero a;
    // Not recomended since the static member belongs to class not the object
    cout << "Time to Complete: " << a.timeToComplete << endl;
    
    return 0;
}