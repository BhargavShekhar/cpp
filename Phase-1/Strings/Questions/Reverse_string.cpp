#include<iostream>
#include<string>
using namespace std;

void printstr(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i];
    }
    cout << endl;    
}

string reverse_str(string str)
{
    string rstr;

    int count = 0;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] != ' ')
        {
            // count = i;
            // while (str[count] != ' ')
            // {
            //     rstr.push_back(str[count]);
            //     count++;
            // }
            
            rstr.push_back(str[i]);
        }
        
        else
        {
            rstr.push_back(' ');
        }
    }
    
    printstr(rstr);
}

int main()
{
    string str = "The sky is blue";  // o/p --> should be blue is sky The

    reverse_str(str);

    // cout << str.length();
    
    return 0;
}