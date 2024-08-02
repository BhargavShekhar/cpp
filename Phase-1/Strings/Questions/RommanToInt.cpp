#include<iostream>
#include<string>
using namespace std;

int main()
{
    int arr[7] = {1, 5, 10, 50, 100, 500, 1000};
    char ch[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

    int ans = 0;
    string s;

    cout << "Enter a roman value" << endl;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (s[i] == ch[j])
            {
                if (s[i] == 'I' && s[i + 1] == 'V' || s[i] == 'X' && s[i + 1] == 'L' || s[i] == 'C' && s[i + 1] == 'D')
                {
                    ans = ans + arr[j + 1] - arr[j];
                    i++;
                    break;
                }

                else if (s[i] == 'I' && s[i + 1] == 'X' || s[i] == 'X' && s[i + 1] == 'C' || s[i] == 'C' && s[i + 1] == 'M')
                {
                    ans = ans + arr[j + 2] - arr[j];
                    i++;
                    break;
                }
                
                ans += arr[j];
            }
        }
        
    }
    
    cout << "Output: " << ans << endl;

    return 0;
}