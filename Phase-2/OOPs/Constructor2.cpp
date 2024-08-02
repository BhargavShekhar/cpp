#include<iostream>
using namespace std;

class Hero
{
    private:
    int health;

    public:
    // using getter and setter for private class element health
    int getHealth()
    {
        return health;
    }

    int setHealth(int h)
    {
        health = h;
    }

    char level;

    // cresting a constructor
    Hero()
    {
        cout << "Constructor called" << endl;
    }

    void print()
    {
        cout << "Health : " << health << endl;
        cout << "Level : " << level << endl;
    }

    // Creating our own copying constructor but it is there by defalut.
    Hero(Hero& temp)  // passing by refrence since we are creating a copy constructor so we can't acess the value of temp since it will call copy constructor resulting in infinite loop.
    {
        cout << "Copy Constructor called" << endl;
        this -> health = temp.health;
        this -> level = temp.level;
    }
};

int main()
{
    Hero suresh;
    suresh.setHealth(55);
    suresh.level = 'C';
    cout << suresh.getHealth() << endl;
    cout << suresh.level << endl;

    // Copying the constructor
    cout << "OnePuchMAn class call" << endl;
    Hero OnePunchMan(suresh);
    OnePunchMan.print();
    
    return 0;
}