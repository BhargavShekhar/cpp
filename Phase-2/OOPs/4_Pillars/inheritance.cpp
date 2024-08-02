#include<iostream>
using namespace std;

class Human
{
    public:
        int height;
        int weight;
        int age;

    public:
        int getAge()
        {
            return age;
        }
        
        int setWeight(int weight)
        {
            this -> weight = weight;
        }

};

class Male: public Human
{
    public:
        string color;

    void sleep()
    {
        cout << "Male is sleeping" << endl;
    }

};

int main()
{
    Male object1;
    
    cout << "Age: " << object1.age << endl;
    object1.setWeight(74);
    cout << "Weight: " << object1.weight << endl;
    cout << "Height: " << object1.height << endl;
    cout << "Colour: " << object1.color << endl;
    object1.sleep();
    
    return 0;
}