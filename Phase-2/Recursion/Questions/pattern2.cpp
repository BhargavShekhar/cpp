#include<iostream>
using namespace std;

void patter_print(int n)
{
    if (n == 0)
    {
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }   cout << endl;
    patter_print(n -1);
    
}

int main()
{
    patter_print(5);
    
    return 0;
}