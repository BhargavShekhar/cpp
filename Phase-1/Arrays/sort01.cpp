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

void sortone(int arr[], int n)
{
    //Pointers method
    int i, j;
    i = 0;
    j = n-1;

    while (i < j)
    {
        if (arr[i] == 0)
        {
            i++;
        }

        if (arr[j] == 1)
        {
            j--;
        }

        if (arr[i] == 1 && arr[j] == 0)
        {
            swap(arr[i], arr[j]);
        }
        
    }
    
}

int main()
{
    int arr[] = {1, 1, 0, 0, 0, 0, 1, 0};
    int n = sizeof(arr)/sizeof(int);

    cout << "Before: " << endl;
    printarr(arr, n);
    cout << "After: " << endl;
    sortone(arr, n);
    printarr(arr, n);

    return 0;
}