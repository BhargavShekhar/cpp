#include<iostream>
using namespace std;

int power(int a, int b)
{
    // base case
    if (b == 0)
    {
        return 1;
    }

    if (b == 1)
    {
        return a;
    }
    
    // recursive relation
    int ans = power(a, b / 2);

    if (b % 2 == 0)
    {
        ans = ans * ans;
    }

    else
    {
        ans = a * ans * ans;
    }
    
}

int main()
{
    int a, b;
    cout << "Enter Base Number" << endl;
    cin >> a;
    cout << "Enter the power of the base number" << endl;
    cin >> b;

    int ans = power(a, b);
    
    cout << "Calculated value is " << ans << endl;

    return 0;
}