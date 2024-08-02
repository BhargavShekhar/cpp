#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s = "abcd";
    string t = "abcde";

    // creating a char count for string s
    int arrS[26] = {0};
    int sIndex;
    for (int i = 0; i < s.size(); i++)
    {
        sIndex = s[i] - 'a';
        arrS[sIndex]++;
    }

    // creating a char count for string t
    int arrT[26] = {0};
    int tIndex;
    for (int i = 0; i < t.size(); i++)
    {
        tIndex = t[i] - 'a';
        arrT[tIndex]++;
    }

    // Comparing the resultant arrays
    int index = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arrT[i] != arrS[i])
        {
            index = i;
        }
    }

    char ans = index + 'a';
    cout << ans << endl;

    return 0;
}