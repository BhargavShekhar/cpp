#include<iostream>
#include<cctype>
using namespace std;

char Lower_case(char ch[])
{
    for (int i = 0; ch[i] != '\0'; i++)
    {
        if (ch[i] >= 'A' && ch[i] <= 'Z')
        {
            ch[i] = ch[i] - 'A' + 'a';
        }
        
    }
    
}

int length(char ch[])
{
    int count = 0;

    for (int i = 0; ch[i] != '\0'; i++)
    {
        count++;
    }
    
    return count;
}

int palindrom(char ch[])
{
    int start = 0;
    int end = length(ch) - 1;

    // cout << end  << endl;

    while (start < end)
    {
        while (isalnum(ch[start]) == 0 && start < end)
        {
            start++;
        }
        
        while (isalnum(ch[end]) == 0 && start < end)
        {
            end--;
        }
        
        if (ch[start] == ch[end])
        {
            start++;
            end--;
        }
        
        else
        {
            return 0;
        }
        
    }

    return 1;
}

int main()
{
    char ch[] = {'A', '@', ' ', 'b', 'C', 'B', '@', '#', 'a', '\0'};

    // Converting all charectors to Lower case first
    Lower_case(ch);

    // Printing the charector after lower case func call
    cout << "After ignoring all special charectors and converting to lower case:" << endl;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        if (ch[i] >= 'a' && ch[i] <= 'z')
        {
            cout << ch[i] << " ";
        }
    }
    cout << endl;

    cout << "Length is: " << length(ch) << endl;
    
    cout << "Char array is Palindromic: " << palindrom(ch);

    return 0;
}