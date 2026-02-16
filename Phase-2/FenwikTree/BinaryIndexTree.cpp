#include <bits/stdc++.h>
using namespace std;

class BinaryIndexTree {
    private:
        int n;
        vector<long> arr;
    public: 
        // ctor -> init
        BinaryIndexTree(int n): n(n), arr(n+1, 0) {}

        void update(int idx, long val) {
            while (idx <= n) {
                arr[idx] += val;
                idx += (idx & -idx); // move next
            }
        }

        long query(int idx) {
            long sum = 0;
            while (idx > 0) {
                sum += arr[idx];
                idx -= (idx & -idx);
            }
            return sum;
        }

        long rangeQuery(int l, int r) {
            return query(r)-query(l-1);
        }
};

int main(){
    int n = 5;
    BinaryIndexTree bi(n);

    vector<int> arr = {0, 1, 2, 3, 4, 5}; // 1 based index

    for (int i = 1; i <= n; i++) {
        bi.update(i, arr[i]);
    }

    cout << bi.rangeQuery(2, 4);  // Output: 2+3+4 = 9

    return 0;
}