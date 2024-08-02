#include<iostream>
using namespace std;

int firstDigit(int n)
{
    // Applying Binary Search
    int start = 0;
    int end = n -1;
    int mid = start + (end - start) / 2;

    int ans = -1;
    while (start <= end)
    {
        int check = mid * mid;
        if (check == n)
        {
            return mid;
        }
        else if (check > n)
        {
            end = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

double lastDigits(int n, int precission, int firstDigit)
{
    double ans = firstDigit;
    double factor = 1;
    for (int i = 0; i < precission; i++)
    {
        factor = factor / 10;

        for (double j = ans; j * j < n ; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter a number to find its square root" << endl;
    cin >> n;

    int ans = firstDigit(n);
    cout << "Your ans with zero precission is " << ans << endl;
    cout << "Enter precission value (recommended is 3) " << endl;

    int precission;
    cin >> precission;
    cout << "With precission the ans is " << lastDigits(n, precission, ans);

    return 0;
}