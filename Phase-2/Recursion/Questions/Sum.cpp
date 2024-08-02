#include<iostream>
using namespace std;

// return 1 + 2 + 3 + ... + (n-1) + n
int getSum(int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }

    int left_part = getSum(n - 1);
    return left_part + n;
    
}

int main()
{
    int n;
    
    cout << "Enter a number" << endl;
    cin >> n;

    cout << "Sum of the numbers till " << n << " is " << getSum(n);

    return 0;
}