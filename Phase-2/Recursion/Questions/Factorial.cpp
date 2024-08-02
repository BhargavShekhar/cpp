#include<iostream>
using namespace std;

int factorial(int fact)
{
    // base case 
    if (fact <= 1)
    {
        return 1;
    }

    int ans = fact * factorial(fact - 1);
    return ans;
    
}

int main()
{
    int fact;

    cout << "Enter a number to find it's factorial" << endl;
    cin >> fact;

    cout << factorial(fact);

    return 0;
}