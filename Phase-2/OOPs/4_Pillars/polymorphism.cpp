// COMPILE TIME POLYMORPHISM
#include<iostream>
using namespace std;

// Function overload
class A
{
    public:
        void sayHello()
        {
            cout << "Hello Sir !! " << endl;
        }

        void sayHello(string name)  // changed the function signature (added string as a argument) so its not throwing a error dispite having same name.
        {
            cout << "Hello sir !! " << endl;   // if we not do this thenn the function will bw over loaded.
        }
};

// Operator overload
class B
{
    public:
        int a;
        int b;

        int add()
        {
            return a + b;
        }

        // overloadung + operator
        void operator+ (B &obj)
        {
            int value1 = this -> a;
            int value2 = obj.a;
            cout << "output: " << value2 - value1 << endl;
        }

        // overloading brackets ()
        void operator() ()
        {
            cout << "Brackets are used " << this -> a << endl;
        }

};

int main()
{
    A obj;
    obj.sayHello();

    

    B obj1, obj2;

    obj1.a = 4;
    obj2.a = 7;

    // using add operator
    obj1 + obj2;

    // calling bracket
    obj1();
    
    return 0;
}