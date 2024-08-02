#include<iostream>
#include<vector>
using namespace std;

vector<int> printarr(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
       
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    printarr(nums);

    int  i = 0;

    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != 0)
        {
            swap(nums[j], nums[i]);
            i++;
        }
        
    }

    printarr(nums);

    return 0;
}