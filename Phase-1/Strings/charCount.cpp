#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s ={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    int arr[26] = {0};

    cout << "Before creating char count in the array:" << endl;

    for (int i = 0; i < s.length(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Creating char count
    for (int i = 0; i < s.length(); i++)
    {
        arr[i] = s[i] - 'a';
    }

    cout << "After creating char count in the array:" << endl;
    
    for (int i = 0; i < s.length(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    

    return 0;
}