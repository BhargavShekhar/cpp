#include<iostream>
using namespace std;
// Given series -> 1!/1 + 2!/2 + 3!/3 + 4!/5 + 5!/5 ....
int fact(int n)
{
    // base case
    if (n == 1)
    {
        return 1;
    }

    return n * fact(n - 1);
    
}

int series(int n)
{
    // base case
    if (n == 1)
    {
        return 1;
    }

    // recursive relation
    int sum = fact(n)/n + series(n - 1);
    return sum;
    
}

int main()
{
    int ans = series(5);    // ans = 34

    cout << ans << endl;
    
    return 0;
}