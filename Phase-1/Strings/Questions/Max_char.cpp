#include<iostream>
#include<string>
using namespace std;

char maxOccuringChar(string s)
{
    int arr[26] = {0};

    // Creating an array of count
    for (int i = 0; i < s.length(); i++)
    {
        int number = 0;

        // for Lower Case
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            number = s[i] - 'a';  // converting to respective num betw 0 to 25
        }

        // for Upper Case
        else
        {
            number = s[i] - 'A';
        }
        
        arr[number]++;
    }

    int maxi = -1;  // putting any value since we have to change it.
    int ans = 0;  // putting any value since we have to change it.

    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
        
    }
    
    char finalAns = 'a' + ans;  // converting back the assigned num to its respective char.
    return finalAns;
}

int main()
{
    string s;
    cout << "Write a word:" << endl;

    cin >> s;

    cout << maxOccuringChar(s) << endl;

    return 0;
}