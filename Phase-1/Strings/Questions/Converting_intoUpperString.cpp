#include<iostream>
using namespace std;

string uppercaseConvo(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            i++;
        }
        
        char ch = str[i] - 'a' + 'A';
        str[i] = ch;
    }
    return str;
}

int main()
{
    string s = "bhargav shekhar";

    cout << uppercaseConvo(s) << endl;

    return 0;
}