#include<iostream>
using namespace std;

void printarr(int arr[], int n);

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
            
        }
        
        swap(arr[minIndex], arr[i]);
    }
}

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    int arr[] = {4, 1, 9, 2, 3, 6};
    int n = sizeof(arr)/sizeof(int);

    selectionSort(arr, n);
    printarr(arr, n);

    return 0;
}