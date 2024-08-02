/*DOES NOT WORK ON ALL TEST CASE EG,
int arr1[] = {1, 2, 3, 4};
int arr2[] = {4, 3, 2, 1};

// Expected Output: 1 2 3 4
// Your Code's Output: 2 3
*/

#include<iostream>
#include<vector>
using namespace std;

void intersection(int arr1[], int arr2[], int n, int m)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                if (arr2[j] == arr2[j+1] || arr1[i] == arr1[i+1])
                {
                    continue;
                }
                
                ans.push_back(arr1[i]);
            }

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
    int arr1[] = {1, 2, 2, 2, 3, 4};
    int arr2[] = {2, 2, 3, 3};

    int n, m;
    n = sizeof(arr1)/sizeof(int);
    m = sizeof(arr2)/sizeof(int);

    intersection(arr1, arr2, n, m);

    return 0;
}
