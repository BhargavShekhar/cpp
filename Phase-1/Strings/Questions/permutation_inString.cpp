// if permutaion of s1 is present in s2 return true.

#include<iostream>
#include<string>
using namespace std;

bool permutation(string s1, string s2)
{
    // creating char count for s1

    int count[26] = {0};

    for (int i = 0; i < s2.length(); i++)
    {
        int index = s2[i] - 'a';
        count[index]++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        cout << count[i] << " ";  // verifying ?
    }
    cout << endl;
    
}

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";

    permutation(s1, s2);

    return 0;
}