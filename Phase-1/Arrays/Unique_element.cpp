#include<iostream>
using namespace std;

int unique(int arr[], int n)
{
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans ^= arr[i];  // Zor ing all elements witj itself
    }
    
    return ans;
}

int main()
{
    int arr[] = {2, 3, 1, 6, 3, 6, 100, 2, 1};
    int n = sizeof(arr)/sizeof(int);

    cout << unique(arr, n) << endl;

    return 0;
}