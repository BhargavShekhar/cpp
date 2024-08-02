#include<iostream>
#include<vector>
using namespace std;

void subSet(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans)
{
    // base case
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // excluding elements of the index position
    subSet(nums, output, index + 1, ans);

    // including the elements of the index position
    output.push_back(nums[index]);
    subSet(nums, output, index + 1, ans);
    
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<int> output;
    vector<vector<int>> ans;
    int index = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }   cout << endl;
    

    subSet(nums, output, index, ans);

    // printing the output
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j != ans[i].size() - 1)
            {
                cout << ",";
            }

        }
        cout << "} ";
    }
    
    return 0;
}