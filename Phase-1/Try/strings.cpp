#include<iostream>
#include<typeinfo>
using namespace std;

int main()
{
    // Learning Strings

    string str[] = {"Hello ", "my ", "name is ", "Bhargav "};

    cout << str[3] << endl;
    cout << typeid(str).name() << endl;

    for (int i = 0; i < 4; i++)  // "/0" is the last charector of the string.
    {
        cout << str[i];
    }

    cout << endl;

    // Adding Two strings.
    string app("Appending two strings ");
    string done("Done, use gft for refference. ");
    
    app.append(done);

    cout << app << endl;

    return 0;
}