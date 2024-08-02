#include<iostream>
using namespace std;

int search(int arr[], int start, int end)
{
    // base case
    int mid = start + (end - start) / 2;
    if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
    {
        return mid;
    }

    // recursive relation
    if (arr[mid + 1] > arr[mid])
    {
        return search(arr, mid + 1, end);
    }
    
    if (arr[mid] > arr[mid + 1])
    {
        return search(arr, start, mid);
    }
}

int main()
{
    int arr[] = {0, 3, 10, 5, 2};
    int size = sizeof(arr) / sizeof(int);

    cout << "Peak in mountain array is at index " << search(arr, 0, size - 1);

    return 0;
}