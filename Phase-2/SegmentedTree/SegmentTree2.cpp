// THIS IS SUM SEGMENT TREE
#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
    int n;
    vector<int> seg;

    public:
        // ctor
        SegmentTree(int n, vector<int>& arr): n(n), seg(4*n, 0) {
            build(arr, 0, n-1, 0);
        };

        int query(int l, int r) {
            return queryHelper(0, n-1, l, r, 0);
        }

        void update(int val, int idx) {
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

            return seg[idx] = left+right;
        }

        // segLeft, segRight -> curr node, l, r -> range
        int queryHelper(int segLeft, int segRight, int l, int r, int idx) {
            // complete overlap
            if (segLeft >= l && segRight <= r) {
                return seg[idx];
            }

            // no overlap
            if (segRight < l || segLeft > r) {
                return 0;
            }

            // partial overlap
            int mid = (segLeft+segRight)/2;
            int left = queryHelper(segLeft, mid, l, r, 2*idx+1);
            int right = queryHelper(mid+1, segRight, l, r, 2*idx+2);
            return left+right;
        }

        void updateHelper(int segLeft, int segRight, int val, int idx, int currIdx) {
            // base case
            if (segLeft == segRight) {
                seg[currIdx] = val;
                return;
            }

            int mid = (segLeft+segRight)/2;
            if (idx <= mid) { // traverse left
                updateHelper(segLeft, mid, val, idx, 2*currIdx+1);
            }
            else {
                updateHelper(mid+1, segRight, val, idx, 2*currIdx+2);
            }

            // update while backtracking
            seg[currIdx] = seg[2*currIdx+1]+seg[2*currIdx+2];
        }
};


int main() {
    int n = 8;
    vector<int> arr = {1, 3, 2, 7, 9, 11, 3, 5};

    cout << "Initial Array:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";

    // Build SUM Segment Tree
    SegmentTree st(n, arr);
    cout << "Segment Tree Built (SUM Segment Tree)\n\n";

    // ---------------- QUERY EXAMPLES ----------------
    cout << "Range Sum Queries:\n";

    cout << "Sum in range [0, 3]: ";
    cout << st.query(0, 3) << "  (Expected: 13)\n";   // 1+3+2+7

    cout << "Sum in range [2, 5]: ";
    cout << st.query(2, 5) << "  (Expected: 29)\n";   // 2+7+9+11

    cout << "Sum in range [4, 7]: ";
    cout << st.query(4, 7) << "  (Expected: 28)\n";   // 9+11+3+5

    cout << "Sum in range [6, 6]: ";
    cout << st.query(6, 6) << "  (Expected: 3)\n";

    cout << "\n";

    // ---------------- UPDATE EXAMPLES ----------------
    cout << "Point Updates:\n";

    cout << "Update index 2 to value 15\n";
    st.update(15, 2);
    arr[2] = 15;

    cout << "Update index 6 to value 20\n";
    st.update(20, 6);
    arr[6] = 20;

    cout << "\nUpdated Array:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";

    // ---------------- QUERY AFTER UPDATE ----------------
    cout << "Range Sum Queries After Updates:\n";

    cout << "Sum in range [0, 3]: ";
    cout << st.query(0, 3) << "  (Expected: 26)\n";   // 1+3+15+7

    cout << "Sum in range [2, 6]: ";
    cout << st.query(2, 6) << "  (Expected: 62)\n";   // 15+7+9+11+20

    cout << "Sum in range [5, 7]: ";
    cout << st.query(5, 7) << "  (Expected: 36)\n";   // 11+20+5

    cout << "Sum in range [0, 7]: ";
    cout << st.query(0, 7) << "  (Expected: 63)\n";

    return 0;
}