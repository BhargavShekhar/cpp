#include<iostream>
using namespace std;

// Given a number m, Reverse the array after that index.

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    
}

void revese(int arr[], int n, int m)
{
    int start, end;
    start = m + 1;
    end = n - 1;

    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    

}

int main()
{
    int arr[] = {1, 4, 5, 6, 6, 7, 7};
    int n = sizeof(arr)/sizeof(int);
    int m = 3;

    revese(arr, n, m);
    cout << "Reversed after " << m << "th element: " << endl;
    printarr(arr, n);

    return 0;
}