#include<iostream>
using namespace std;

void patter_print(int n)
{
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    
    for (int i = 1; i <=  n; i++)
    {
        cout << i << " ";
    }   cout << endl;

    patter_print(n - 1);    

    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }   cout << endl;
    
}

int main()
{
    patter_print(4);
    
    return 0;
}