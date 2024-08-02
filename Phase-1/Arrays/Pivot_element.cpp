#include<iostream>
using namespace std;

int pivot(int arr[], int n)
{
    int start, mid, end;
    start = 0;
    end = n - 1;
    mid = start + (end - start)/2;

    while (start < end)
    {
        if (arr[mid] > arr[0])
        {
            start = mid + 1;
        }

        else
        {
            end = mid;
        }
        mid = start + (end - start)/2;

    }
    return arr[start];

}

int main()
{
    int arr[] = {7, 9, 1, 2, 3};
    int n = sizeof(arr)/sizeof(int);

    cout << pivot(arr, n);

    return 0;
}