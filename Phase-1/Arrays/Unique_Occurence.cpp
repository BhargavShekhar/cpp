// not Running

#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;

void uniqe(int arr[], int n)
{
    srand(time(0));  // For different output in every run
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        for (int j = i+1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                ans += 1;
                arr[j] = rand();
            }
        }
        v.push_back(ans);
    }
    
    // Printing the vector
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}


int main()
{
    int arr[] = {1, 2, 2, 1, 1, 3};
    int n = sizeof(arr)/sizeof(int);

    uniqe(arr, n); // will have to print if chaneged uniqe function
    
    return 0;
}