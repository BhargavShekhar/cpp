#include<iostream>
using namespace std;

int getLength(char c[])
{
    int count = 0;
    for (int i = 0; c[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

bool getCheck(char c[])
{
    int start = 0;
    int end = getLength(c) - 1;

    bool check = false;

    while (start < end)
    {
        if (c[start] == c[end])
        {
            check = true;
        }
        start++;
        end--;
    }
    return check;
}

int main()
{
    char c[] = {'a', 'b', 'c', 'd', 'c', 'b', 'a', '\0'};   // \0 is nessecery to give the end of 1d char array.

    getLength(c);

    if (getCheck(c))
    {
        cout << "String is Palindromic" << endl;
    }

    else
    {
        cout << "String is not Palindromic" << endl;
    }

    return 0;
}