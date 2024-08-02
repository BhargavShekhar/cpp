#include<iostream>
#include<typeinfo>
using namespace std;

int main()
{
    char ch = '5';

    int num = ch - '0';

    cout << num  / 2 << endl;
    cout << ch / 2 << endl;

    string a = "abc";

    a.pop_back();

    cout << a << endl;

    return 0;
}