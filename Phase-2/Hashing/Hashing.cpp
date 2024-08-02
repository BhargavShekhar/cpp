#include<iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }   cout << endl;
    
}

int main()
{
    int arr[5] = {1, 3, 2, 1, 3};

    // precompute
    int hash[5] = {0};
    for (int i = 0; i < 5; i++)
    {
        hash[arr[i]] += 1;
    }

    print(arr, 5);
    print(hash, 5);
    
    return 0;
}