#include<iostream>
using namespace std;

void printarr(int arr[], int n)
{
    cout << "Size is " << n << endl;
    cout << "Array is:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }   cout << endl;
}

bool linearSearch(int arr[], int size, int k)
{
    // Printing the Working of the function --->
    // printarr(arr, size);

    // base case
    if (size == 0)
    {
        return false;
    }
    
    // Recursive Relation
    if (arr[0] == k)
    {
        return true;
    }
    
    else
    {
        return linearSearch(arr + 1, size - 1, k);
    }
}

int main()
{
    int arr[] = {2, 3, 5, 1, 6};
    int key = 1;
    int size = sizeof(arr) / sizeof(int);

    if (linearSearch(arr, size, key))
    {
        cout << key << " is present in the Array" << endl;
    }

    else
    {
        cout << key << " is not present in the Array" << endl;
    }    

    return 0;
}