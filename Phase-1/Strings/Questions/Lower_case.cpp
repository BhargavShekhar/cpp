#include<iostream>
using namespace std;

char LowerCase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }

    else
    {
        ch = ch - 'A' + 'a';
    }   
    
    return ch;
}

char UpperCase(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch;
    }

    else
    {
        ch = ch - 'a' + 'A';
    }
    
}

int main()
{
    char ch;
    cout << "Enter a charector: " << endl;
    cin >> ch;

    cout << "Lower case of the charector is " << LowerCase(ch) << endl;
    cout << "Upper case of the charector is " << UpperCase(ch) << endl;
    
    return 0;
}