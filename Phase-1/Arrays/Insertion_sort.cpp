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

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // printarr(arr, n);
        int temp = arr[i];
        int j = i - 1;

        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                // Shift
                arr[j + 1] = arr[j];
            }

            else
            {
                break;
            }

        }
        arr[j + 1] = temp;
    }
    
}

int main()
{
    int arr[] = {8, 4, 1, 5, 9, 2};
    int n = sizeof(arr)/sizeof(int);

    cout << "Before Insertion Sort" << endl;
    printarr(arr, n);
    
    InsertionSort(arr, n);

    cout << "After Insertion Sort" << endl;
    printarr(arr, n);

    return 0;
}