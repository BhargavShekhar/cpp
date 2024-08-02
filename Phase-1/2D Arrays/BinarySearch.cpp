#include<iostream>
using namespace std;

int binarySearch(int arr[3][4], int row, int col, int key)
{
    int start = 0;
    int end = row * col;
    int mid = start + (end - start)/2;

    while (start < end)
    {
        int element = arr[mid / col][mid % col];

        if (element == key)
        {
            return 1;
        }

        else if (element > key)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
        
        mid = start + (end - start)/2;
    }
    
    return 0;
}

int main()
{
    int arr[3][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int row = 3;
    int col = 4;
    int key = 40;

    if (binarySearch(arr, row, col, key))
    {
        cout << "Element is present" << endl;
    }
    
    else
    {
        cout << "Element not present" << endl;
    }

    return 0;
}