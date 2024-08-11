#include<iostream>
#include<typeinfo>
using namespace std;

int main()
{
    int num(3);
    int arr[4];

    cout << num << endl;
    cout << typeid(num).name() << endl;

    // int num = 3;
    
    return 0;
}