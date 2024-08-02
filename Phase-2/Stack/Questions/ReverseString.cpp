#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string s = "Love";

    // Creating a stack
    stack<char> st;

    // Pushing the charectors in Stack.
    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
    }

    // Poping all element and storing it in an empty string
    string ans = "";

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    cout << "Reversed String is : " << ans << endl;
    
    return 0;
}