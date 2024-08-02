#include<iostream>
#include<vector>
using namespace std;

// Moving elements k times.

vector<int> rotate(vector<int> nums, int k)
{
    vector<int> temp(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        temp[(i + k) % nums.size()] = nums[i];   // Formula from lec 21. Will rotate array after last element to first 'k' times.
    }
    
    // Printing the vector
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;    

}

int main()
{
    vector<int> nums = {1, 7, 9, 11};
    int k = 2;

    cout << "Moving nums " << k <<" times" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;    

    rotate(nums, k);

    return 0;
}