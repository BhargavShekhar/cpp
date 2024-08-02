#include<iostream>
#include<vector>
using namespace std;

vector<int> printarr(vector<int> nums1)
{
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }

    cout << endl;

}

vector<int> merge(vector<int> nums1, vector<int> nums2, int m, int n)
{
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        ans.push_back(nums1[i]);      // Merging both vectors.
    }

    for (int i = 0; i < n; i++)
    {
        ans.push_back(nums2[i]);
    }

    printarr(ans);

    // Sorting

    int start, end;

    for (int i = 0; i < ans.size() - 1; i++)
    {
        for (int j = i + 1; j < ans.size(); j++)
        {
            if (ans[i] > ans[j])
            {
                swap(ans[i], ans[j]);
            }
            
        }
        
    }

    cout << "After Sortng: " << endl;
    printarr(ans);

}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m, n;

    m = 3;
    n = 3;

    merge(nums1, nums2, m, n);

    return 0;
}