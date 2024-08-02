#include<iostream>
using namespace std;

/* i/p --> 121423
   o/p --> 1 + 2 + 1 + 4 + 3
*/
int sum_digits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int last_digit = n % 10;
    int remaining = n / 10;
    cout << remaining << " " << last_digit << endl;
    return sum_digits(remaining) + last_digit;
    
}

int main()
{
    int digit = 12143;

     cout << sum_digits(digit);

    return 0;
}