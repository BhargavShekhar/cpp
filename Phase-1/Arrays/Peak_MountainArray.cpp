#include<iostream>
using namespace std;

int binarysearch(int arr[], int n)
{
    int start, mid, end;
    start = 0;
    end = n-1;
    mid = start + (end - start)/2;

    while (start < end)
    {

        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }

        else if (arr[mid] > arr[mid + 1])
        {
            end = mid;
        }

        mid = start + (end - start)/2;
    }
    return arr[start];

}

int main()
{
    int arr[] = {0, 2, 1, 0};
    int n = sizeof(arr)/sizeof(int);

    cout << binarysearch(arr, n);

    return 0;
}