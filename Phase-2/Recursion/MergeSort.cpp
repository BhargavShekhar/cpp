#include<iostream>
using namespace std;

void merger(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;        // length of the Left side
    int len2 = end - mid;              // length of the Right side

    int *first = new int[len1];
    int *second = new int[len2];

    // copying elements in first and second

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
    
    // merging and sorting

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        
        else
        {
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
}

void mergeSort(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    // base case
    if (start >= end)
    {
        return ;
    }

    // for Left Side
    mergeSort(arr, start, mid);

    // for Right Side
    mergeSort(arr, mid + 1, end);

    // merging
    merger(arr, start, end);
}

int main()
{
    int arr[] = {2, 3, 14, 15, 12, 12, 12, 45};
    int size = 8;

    mergeSort(arr, 0, size - 1);

    // printing the result
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }   cout << endl;    

    return 0;
}