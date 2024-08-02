#include<iostream>
using namespace std;

void pattern_print(int n)
{
    if (n == 0)
    {
        return;
    }
    
    pattern_print(n-1);  // Trusting the function
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }   cout << endl;
    
}

int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;

    pattern_print(n);

    return 0;
}