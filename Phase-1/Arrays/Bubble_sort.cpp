#include<iostream>
using namespace std;

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printarr(arr, n);
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
            
        }
        
    }
    
}

int main()
{
    int arr[] = {6, 2, 8, 4, 10};
    int n = sizeof(arr)/sizeof(n);

    bubbleSort(arr, n);
    // printarr(arr, n);

    return 0;
}