#include<iostream>
using namespace std;

int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reverse(char name[])
{
    int start = 0;
    int end = getLength(name) - 1;

    while (start <= end)
    {
        swap(name[start++], name[end--]);
    }
    
    cout << "Reverse of the name is ";

    // printing the resut of the array
    for (int i = 0; name[i] != '\0'; i++)
    {
        cout << name[i];
    }
    cout << endl;
}

int main()
{
    char name[20];   // '\0' is null charector which is stored in the last element of the array to signify its ending
    cout << "Enter your name: " << endl;

    cin >> name;

    // using null charactor
    name[1] = '\0';

    cout << "Your name starts with " << name << endl;

    // printing lenght of char array
    char length[20] = {'b', 'h', 'a', 'r', 'g', 'a', 'v'};
    cout << "Length of the name is " << getLength(length) << endl;


    // Reversing the char array
    reverse(length);
    
    return 0;
}