#include<iostream>
using namespace std;

class Hero
{
    public:
    // properties
    int health;
    char level;
    };


int main()
{
    // creating a object
    // Hero h1;

    // cout << "size : " << sizeof(h1) << endl;


    // creating a object
    Hero IronMan;

    IronMan.health = 72;
    IronMan.level = 'A';

    cout << "Health of Iron Man is : " << IronMan.health << endl;
    cout << "Level of Iron Man is : " << IronMan.level << endl;
    
    return 0;
}