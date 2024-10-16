#include<iostream>
using namespace std;

void bubbleSort(int *arr, int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return ;
    }
    
    // solve for one case
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i] , arr[i + 1]);
        }
        
    }
    bubbleSort(arr, n - 1);
}

int main()
{
    int arr[] = {2, 5, 1, 6, 9};

    bubbleSort(arr, 5);

    // printing the array
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }   cout << endl;
    
    return 0;
}