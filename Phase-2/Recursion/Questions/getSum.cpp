#include<iostream>
using namespace std;

int getSum(int *arr, int size)
{
    // base case
    if (size == 0)
    {
        return 0;
    }

    // Recursive Relation
    return arr[size - 1] + getSum(arr, size - 1);
}

int main()
{
    int arr[] = {2, 3, 5, 1, 6};
    int size = sizeof(arr) / sizeof(int);
    int sum = 0;

    cout << getSum(arr, size) << endl;

    return 0;
}