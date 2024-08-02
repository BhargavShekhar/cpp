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

void sortarr(int arr[], int n)
{
    int left, mid, right;
    left = 0;
    right = n-1;

    int check = 0;

    while(check <= 5)
    {
        mid = left + (right-left)/2;

        cout << "Left: " << left << " Right: " << right << " Mid: " << mid << endl;
        printarr(arr, n);

        while (arr[right] == 2)
        {
            right--;
        }

        while (arr[left] == 0)
        {
            left++;
        }
        
        if (arr[left] >= arr[mid])
        {
            swap(arr[mid], arr[left]);
            // left++;
            
        }
        
        if (arr[right] <= arr[mid])
        {
            swap(arr[mid], arr[right]);
            // right--;
        }
        
        // printarr(arr, n);
        check++;
    }
}

int main()
{
    int arr1[] = {0, 1, 2, 1, 2, 1, 2}; // Not working
    int arr2[] = {0, 2, 2, 1, 0, 1, 1, 0, 2};
    int arr3[] = {0, 1, 2, 2, 1, 0};
    int n = sizeof(arr2)/sizeof(int);

    sortarr(arr2, n);

    return 0;
}