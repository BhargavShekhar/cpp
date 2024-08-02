// generating wrong ans ie, ans = ans - 1;

#include<iostream>
using namespace std;

int merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copying elements
    int mainArrayIndex = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merging
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;
    int invCount = 0;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        
        else
        {
            // i < j && arr[i], arr[i + 1], arr[i + 2] > arr[j]  --> since its a sorted array
            invCount += len1 - index1;
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first, delete []second;
    return invCount;  
}

int mergeSort(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    int invCount = 0;
    // base case
    if (start >= end)
    {
        return invCount;
    }
    // for left side
    invCount += mergeSort(arr, start, mid);
    
    // for right side
    invCount += mergeSort(arr, mid + 1, end);

    // merge
    invCount += merge(arr, start, end);
}

int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    int ans = mergeSort(arr, 0, n - 1);

    cout << ans << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }   cout << endl;

    return 0;
}