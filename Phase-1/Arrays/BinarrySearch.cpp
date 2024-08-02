#include<iostream>
using namespace std;

int binarysearch(int arr[], int key, int n)
{
    int start, mid, end;
    start = 0;
    end = n-1;
    mid = start + (end-start)/2;

    while (start <= end)
    {
        if (arr[mid] > key)
        {
            end = mid - 1;
        }

        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        
        else
        {
            return mid;
        }
        
        mid = start + (end-start)/2;
    } 
    return -1;

}

int main()
{
    int arr[] = {3, 5, 9, 13, 27, 50}; // Array should be monotonusly increasing.
    int key = 13;
    int n = sizeof(arr)/sizeof(int);

    cout << binarysearch(arr, key, n);

    return 0;
}