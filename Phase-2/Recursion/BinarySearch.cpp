#include<iostream>
using namespace std;

bool binarySearch(int arr[], int start, int end, int key)
{
    // base case
    if (start > end)
    {
        return false;
    }

    int mid = start + (end - start) / 2;
    if (arr[mid] == key)
    {
        return true;
    }    

    // Recurcive Relation
    if (arr[mid] > key)
    {
        return binarySearch(arr, start, mid - 1, key);
    }

    else
    {
        return binarySearch(arr, mid + 1, end, key);
    }
}

int main()
{
    int arr[] = {2, 4, 6, 10, 14, 18};
    int size = sizeof(arr) / sizeof(int);
    int key = 10;

    // cout << "Element found or not --> " << binarySearch(arr, 0, size - 1, key) << endl;

    if (binarySearch(arr, 0, size - 1, key))
    {
        cout << "Element Found" << endl;
    }
    
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}