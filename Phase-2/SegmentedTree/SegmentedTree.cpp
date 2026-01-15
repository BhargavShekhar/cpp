#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
    int n;
    vector<int> seg;

    public:
        // ctor
        SegmentTree(int n, vector<int>& arr): n(n), seg(4*n, -1) {
            build(arr, 0, n-1, 0);
        }

        int query(int l, int r) {
            return queryHelper(0, n-1, l, r, 0);
        }

        void update(int idx, int val) {
            updateHelper(0, n-1, val, idx, 0);
        }
    
    private:
        int build(vector<int>& arr, int l, int r, int idx) {
            // base case
            if (l == r) {
                return seg[idx] = arr[l];
            }

            int mid = (l+r)/2;

            int left = build(arr, l, mid, 2*idx+1);
            int right = build(arr, mid+1, r, 2*idx+2);

            int val = max(left, right);
            return seg[idx] = val;
        }

        /*
            There are three posiblity of this query
            1. the range completly overlaps -> we will return the node value
            2. the range is outside -> we will return INT_MIN 
            3. there is partial overlap of range -> we will traverse in both direction
        */
       // NOTE THIS IS A MAX SEGMENT TREE
       // l, r -> query range, segLeft, segRight -> segment range (curr node)
        int queryHelper(int segLeft, int segRight, int l, int r, int idx) {
            // complete overlap if the segment is fully inside the query
            if (l <= segLeft && r >= segRight) {
                return seg[idx];
            }

            // the range is outside
            if (r < segLeft || l > segRight) {
                return INT_MIN;
            }

            // partial overlap
            int mid = (segLeft+segRight)/2;
            int left = queryHelper(segLeft, mid, l, r, 2*idx+1);
            int right = queryHelper(mid+1, segRight, l, r, 2*idx+2);

            return max(left, right);
        }

        void updateHelper(int segLeft, int segRight, int val, int idx, int currIdx) {
            // base case
            if (segLeft == segRight) {
                seg[currIdx] = val;
                return;
            }
            
            int mid = (segLeft+segRight)/2;
            if (mid >= idx) {
                updateHelper(segLeft, mid, val, idx, 2*currIdx+1);
            }
            else {
                updateHelper(mid+1, segRight, val, idx, 2*currIdx+2);
            }

            // update val while backtracking
            seg[currIdx] = max(seg[2*currIdx+1], seg[2*currIdx+2]);
        }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


}