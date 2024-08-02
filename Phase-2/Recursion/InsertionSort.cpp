#include<iostream>
using namespace std;

void printarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }   cout << endl;
}

void insertionSort(int *arr, int n)
{
    // printarr(arr, n);
    // base case
    if (n == 1)
    {
        return ;
    }
    // recursion call
    for (int i = 1; i < n; i++)
    {
        if (arr[0] > arr[i])
        {
            swap(arr[0], arr[i]);
        }
        
    }
    // cout << "value of n is " << n << endl;
    insertionSort(arr + 1, n - 1);
}

int main()
{
    int arr[] = {2, 4, 1, 8, 6};
    int n = sizeof(arr) / sizeof(int);

    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }   cout << endl;   
    
    return 0;
}