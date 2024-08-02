/*
Arrays are in assending order
*/


#include<iostream>
#include<vector>
using namespace std;

void intersection(int arr1[], int arr2[], int n, int m)
{
    int i, j;
    i = 0;
    j = 0;
    vector<int> ans;
	while(i < n && j < m)
    {
        if(arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
       // Printing Vectors
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
    
}

int main()
{
    int arr1[] = {1, 2, 2, 2, 3, 4};  //Array is in increasing order
    int arr2[] = {2, 2, 3, 3};

    int n, m;
    n = sizeof(arr1)/sizeof(int);
    m = sizeof(arr2)/sizeof(int);

    intersection(arr1, arr2, n, m);

    return 0;
}