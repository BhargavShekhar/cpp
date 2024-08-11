#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // all elements before the chosen element are sorted in selection sort 
    // just like in the deck of card we move after the next element to its correct position in the before sorted elements

    vector<int> arr = {5, 4, 3, 2, 1};

    for(int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    for(const auto elem : arr) {
        cout << elem << " ";
    }   cout << endl;

    return 0;
}