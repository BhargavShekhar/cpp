#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

void printstr(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i];
    }
    
    cout << endl;
}

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

    string s;

    // geting a string input from getline.
    cout << "Enter a string:" << endl;
    getline(cin, s);

    // printing the input 
    cout << "You enter the following string:" << endl;
    cout << "\t";
    printstr(s);
    

    return 0;
}