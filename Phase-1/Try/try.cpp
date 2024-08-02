#include<iostream>
using namespace std;

int main()
{
   int x[3][5] = {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15}
   };

   int *n = &x[0][0];

   cout << x << endl;

   cout << *(*(x+2) + 1) << endl;

   int (*p)[3][5] = &x;
   int *y = &x[0][0];
    
    return 0;
}