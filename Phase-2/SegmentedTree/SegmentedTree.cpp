// THIS IS A MAX SEGMENT TREE
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
    // Example array
    int n = 8;
    vector<int> arr = {1, 3, 2, 7, 9, 11, 3, 5};

    cout << "Initial Array:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";

    // Build Segment Tree
    SegmentTree st(n, arr);
    cout << "Segment Tree Built (Max Segment Tree)\n\n";

    // ---------------- QUERY EXAMPLES ----------------
    cout << "Range Maximum Queries:\n";

    cout << "Max in range [0, 3]: ";
    cout << st.query(0, 3) << "  (Expected: 7)\n";

    cout << "Max in range [2, 5]: ";
    cout << st.query(2, 5) << "  (Expected: 11)\n";

    cout << "Max in range [4, 7]: ";
    cout << st.query(4, 7) << "  (Expected: 11)\n";

    cout << "Max in range [6, 6]: ";
    cout << st.query(6, 6) << "  (Expected: 3)\n";

    cout << "\n";

    // ---------------- UPDATE EXAMPLES ----------------
    cout << "Point Updates:\n";

    cout << "Update index 2 to value 15\n";
    st.update(2, 15);
    arr[2] = 15;

    cout << "Update index 6 to value 20\n";
    st.update(6, 20);
    arr[6] = 20;

    cout << "\nUpdated Array:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";

    // ---------------- QUERY AFTER UPDATE ----------------
    cout << "Range Maximum Queries After Updates:\n";

    cout << "Max in range [0, 3]: ";
    cout << st.query(0, 3) << "  (Expected: 15)\n";

    cout << "Max in range [2, 6]: ";
    cout << st.query(2, 6) << "  (Expected: 20)\n";

    cout << "Max in range [5, 7]: ";
    cout << st.query(5, 7) << "  (Expected: 20)\n";

    cout << "Max in range [0, 7]: ";
    cout << st.query(0, 7) << "  (Expected: 20)\n";

    return 0;
}