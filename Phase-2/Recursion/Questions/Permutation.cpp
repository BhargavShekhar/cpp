// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
// eg --> Input: nums = [1,2,3]
//        Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

#include<iostream>
#include<vector>
using namespace std;

void permutation(vector<vector<int>>& ans, vector<int> nums, int index)
{
    // base case
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++)
    {
        swap(nums[i], nums[index]);
        permutation(ans, nums, index + 1);
        swap(nums[i], nums[index]);
    }

}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    int index = 0;

    permutation(ans, nums, index);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            // cout << nums[i][j];   // print vector of vetor !!
        }
        
    }
    
    
    return 0;
}