// write all possible combination of charectors we can write through the numbers
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
#include<iostream>
#include<vector>
using namespace std;

void solution(vector<string>& ans, string output, string digit, int index, string mapping[])
{
    // base case
    if (index >= digit.length())
    {
        ans.push_back(output);

        for (int i = 0; i < ans.size(); i++)  // printing
        {
            cout << ans[i] << " ";
        }   cout << endl;
        
        return;  // last output is the correct solution
    }
    
    // convert the strings into number's
    int number = digit[index] - '0';
    string value = mapping[number];

    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solution(ans, output, digit, index + 1, mapping);
        output.pop_back();
    }
    
}


int main()
{
    string digit = "23";

    vector<string> ans;
    string output;
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    int number = digit[index] - '0';
    string value = mapping[number];

    cout << number << endl;
    cout << value << endl;

    // solution(ans, output, digit, index, mapping);

    return 0;
}