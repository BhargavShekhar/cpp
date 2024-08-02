#include<iostream>
#include<map>
using namespace std;

int main()
{
    int arr[5] = {1, 3, 2, 1, 3};

    map<int, int> mpp;
    for (int i = 0; i < 5; i++)
    {
        mpp[arr[i]]++;
    }

    // printing the values
    for (auto i : mpp)
    {
        cout << "Key: " << i.first << "    Value: " << i.second << endl;
    }

    return 0;
}