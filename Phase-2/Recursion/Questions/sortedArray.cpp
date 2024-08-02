#include<iostream>
using namespace std;

bool check(int arr[], int size, int num)
{
    // base condition
    if (num >= size)
    {
        return 1;
    }
    if (arr[num] > arr[num + 1])
    {
        return 0;
    }
    
    // Recursive Relation
    return check(arr, size, num + 1);
}

int main()
{
    int arr[] = {2, 4, 6, 9, 11, 13};
    int n = sizeof(arr) / sizeof(int);

    if (check(arr, n - 1, 0))
    {
        cout << "Array is sorted" << endl;
    }

    else
    {
        cout << "Array is not sorted" << endl;
    }    

    return 0;
}