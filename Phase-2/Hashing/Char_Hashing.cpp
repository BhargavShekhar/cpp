#include<iostream>
using namespace std;

int main()
{
    string s = "abcdabehf";

    int hash[26] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a'] += 1;
    }

    // printing the hash map
    char c = 'a';
    cout << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << c << " ";
        c++;
    }   cout << endl;
    
    for (int i = 0; i < 26; i++)
    {
        cout << hash[i] << " ";
    }   cout << endl << endl;;        

    return 0;
}