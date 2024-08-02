#include<iostream>
using namespace std;

int search(int arr[], int start, int end)
{
    // Base Case
    int mid = start + (end - start) / 2;
    if (arr[mid] > arr[start] && arr[mid] > arr[end])
    {
        return mid;
    }
    
    // Recursive Relation
    if (arr[mid] > arr[start])
    {
        return search(arr, mid + 1, end);
    }
    else
    {
        return search(arr, start, mid);
    }
}

int main()
{
    int arr[] = {7, 9, 12, 1, 2, 3};
    int size = sizeof(arr) / sizeof(int);

    cout << "Index of pivot element is " << search(arr, 0, size - 1);

    return 0;
}