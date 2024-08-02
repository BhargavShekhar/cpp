#include<iostream>
#include<vector>
using namespace std;

// NOT WORKING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

vector<int> printarr(vector<int> ans)
{
    for (int i : ans)
    {
        cout << ans[i] << " ";
    }
    cout << endl;    
}

vector<int> reverse(vector<int> ans)
{
    int start = 0;
    int end = ans.size() - 1;

    while (start <= end)
    {
        swap(ans[start++], ans[end--]);
    }
    
    return ans;
}

vector<int> sum(vector<int> arr1, vector<int> arr2)
{
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;
    int carry = 0;
    vector<int> ans;

    while (i >= 0 && j >= 0)
    {
        int val1 = arr1[i];
        int val2 = arr2[j];

        int sum = val1 + val2 + carry;

        carry = sum / 10;
        sum = sum % 10;

        ans.push_back(sum);
        i--;
        j--;
    }

    while (i >= 0)
    {
        int val1 = arr1[i];
        int sum = val1 + carry;

        carry = sum / 10;
        sum = sum % 10;

        ans.push_back(sum);
        i--;
    }

    while (j >= 0)
    {
        int val2 = arr2[j];
        int sum = val2 + carry;

        carry = sum / 10;
        sum = sum % 10;

        ans.push_back(sum);
        j--;
    }

    while (carry != 0)
    {
        int sum = carry;
        int val1 = arr1[i];
        int val2 = arr2[j];

        sum = carry + val1 + val2;

        carry = sum / 10;
        sum = sum / 10;

        ans.push_back(sum);
    }
    
    printarr(ans);
    
    reverse(ans);
    cout << "After reverse function " << endl;
    printarr(ans);

    return ans;
    
}

int main()
{
    vector<int> arr1 =  {1, 2, 3};
    vector<int> arr2 =  {99};

    // vector<int> ans = sum(arr1, arr2);

    // sum(arr1, arr2);
    cout << "Main function " << endl;
    printarr(sum(arr1, arr2));

    // printng the result
    // for (int i : ans)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    return 0;
}