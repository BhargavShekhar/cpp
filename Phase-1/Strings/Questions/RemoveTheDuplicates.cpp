#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s = "bcabc";
    string ans;
    cout << "Before code string is " << s << endl;
    cout << "Size of string s is " << s.size() << endl;

    int count1, count2, index;  // will use for char count
    int size = s.size();

    // comparing using count with for loop
    for (int i = 0; i < size; i++)
    {
        count1 = s[i] - 'a';
        cout << "count1 is " << count1 << " and x-index is " << i << endl;
        for (int j = i + 1; j < size; j++)
        {
            count2 = s[j] - 'a';
            cout << "  count2 is " << count2 << " and j-index is " << j << endl;
            if (count1 == count2)
            {
                break;
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
    }

    cout << "After code string is " << ans << endl;

    return 0;
}