#include<iostream>
using namespace std;

int firstoccurance(int arr[], int n, int key)
{
    int start, mid, end;
    start = 0;
    end = n-1;
    mid = start + (end-start)/2;

    int ans = -1;

    while (start <= end)
    {
        // cout << "Start: " << start << endl;
        // cout << "End: " << end << endl;
        // cout << "Mid: " << mid << endl;

        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }

        else if (arr[mid] < key)
        {
            start = mid +1;
        }

        else
        {
            end = mid -1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int lastoccurance(int arr[], int n, int key)
{
    int start, mid, end;
    start = 0;
    end = n-1;
    mid = start + (end-start)/2;

    int ans = -1;

    while (start <= end)
    {
        // cout << "Start: " << start << endl;
        // cout << "End: " << end << endl;
        // cout << "Mid: " << mid << endl;

        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }

        else if (arr[mid] < key)
        {
            start = mid +1;
        }

        else
        {
            end = mid -1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int main()
{
    int arr[] = {0, 0, 1, 1, 2, 2 ,2 ,2};
    int n = sizeof(arr)/sizeof(int);
    int key = 2;

    cout << firstoccurance(arr, n, key);
    cout << endl;
    cout << lastoccurance(arr, n, key);

    return 0;
}