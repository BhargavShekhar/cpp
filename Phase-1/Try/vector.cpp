#include<iostream>
#include<vector>
using namespace std;

vector<int> printarr(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    // vector<int> v = {1, 2, 3, 0, 0, 0};
    // printarr(v);

    // int m = 3;
    
    // v.push_back(100);
    // printarr(v);

    // v.pop_back();
    // printarr(v);




    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;

    cout << nums1.size() << endl;

    for (int i = 0; i < nums1.size(); i++)
    {
        printarr(nums1);
        nums1.pop_back();
    }
    // printarr(nums1);

    vector<int> vec = {1, 2, 3, 4};

    printarr(vec);

    vec.erase(vec.begin() + 1);

    cout << "After erasing 1st element " << endl;
    printarr(vec);

    return 0;
}