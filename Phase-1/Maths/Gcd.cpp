// Finding GCD using Euclids Algorithum
// GCD ---> HCF   (Written is copy see the algorithum) !!
#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }

    else if (b == 0)
    {
        return a;
    }
    
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }

        else
        {
            b -= a;
        }
    }
    
    return a;    
}

int main()
{
    int a, b;
    cout << "Enter two Numbers:" << endl;
    cin >> a >> b;

    int ans = gcd(a, b);

    cout << "GCD of " << a << " and " << b << " is " << ans << endl;

    return 0;
}