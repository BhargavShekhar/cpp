// Last oqestion of lecture 61
// Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.

#include<iostream>
#include<queue>
using namespace std;

int solve(int *arr, int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);

    // pushing first element in queue
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi[i]] <= arr[i])
        {
            cout << "Deleted: " << maxi.back() << endl;
            maxi.pop_back();
        }

        while (!mini.empty() && arr[mini[i]] >= arr[i])
        {
            mini.pop_back();
        }

        cout << maxi.back() << endl;
        cout << maxi.front() << endl;
        
        maxi.push_back(i);
        mini.push_back(i);
    }

    // finding the sum
    int ans = 0;
    for (int i = k; i < 7; i++)
    {
        ans += arr[maxi.front()] + arr[mini.front()];
    }
    
    return ans;
}

int main()
{
    int arr[7] = {2, -5, -1, 7, -3, -1, -2};
    int k = 4;

    cout << solve(arr, k) << endl;

    return 0;
}