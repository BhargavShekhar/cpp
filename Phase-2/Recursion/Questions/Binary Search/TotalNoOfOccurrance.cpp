#include<iostream>
using namespace std;

int firstOccurance(int arr[], int k, int start, int end, int ans = -1)
{
    // base case
    if (start > end)
    {
        return ans;
    }
    
    // Recursive Relation
    int mid = start + (end - start) / 2;
    if (arr[mid] == k)
    {
        ans = mid;
        return firstOccurance(arr, k, start, mid - 1, ans);
    }

    else if (arr[mid] > k)
    {
        return firstOccurance(arr, k, start, mid - 1, ans);
    }
    
    else
    {
        return firstOccurance(arr, k, mid + 1, end, ans);
    }
}

int lastOccurance(int arr[], int k, int start, int end, int ans = -1)
{
    // base case
    if (start > end)
    {
        return ans;
    }
    
    // Recursive Relation
    int mid = start + (end - start) / 2;
    if (arr[mid] == k)
    {
        ans = mid;
        return lastOccurance(arr, k, mid + 1, end, ans);
    }

    else if (arr[mid] > k)
    {
        return lastOccurance(arr, k, start, mid - 1, ans);
    }
    
    else
    {
        return lastOccurance(arr, k, mid + 1, end, ans);
    }
}

int main()
{
    int arr[] = {3, 4, 4, 4, 4, 5, 5, 5, 6};
    int k = 5;
    int n = sizeof(arr) / sizeof(int);

    int ans = lastOccurance(arr, k, 0, n - 1) - firstOccurance(arr, k, 0, n - 1) + 1;
    cout << "Total no of occurance of the given key is " << ans << endl;

    return 0;
}