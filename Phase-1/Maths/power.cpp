#include<iostream>
using namespace std;

int power(int num, int n)
{
    int ans = num;
    if (n == 0)
    {
        return 1;
    }
    
    for (int i = 0; i < n - 1; i++)
    {        
        ans = ans * num;
    }
    return ans;
}

int main()
{
    int num, n;

    cout << "Enter a number" << endl;
    cin >> num;

    cout << "Enter the power of the number" << endl;
    cin >> n;

    cout << "The resul is " << power(num, n) << endl;

    return 0;
}