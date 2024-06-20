/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293032
 * Submitted at:  2024-06-20 20:02:20
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    451
 * Problem Name:  Frequent values
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct SegmentTreeNode {
    int leftValue, leftFreq;
    int rightValue, rightFreq;
    int maxFreq;
};

class SegmentTree {
private:
    vector<SegmentTreeNode> tree;
    vector<int> arr;
    int n;

    SegmentTreeNode combine(SegmentTreeNode left, SegmentTreeNode right) {
        SegmentTreeNode result;
        result.leftValue = left.leftValue;
        result.leftFreq = left.leftFreq;
        if (left.leftValue == right.leftValue) {
            result.leftFreq += right.leftFreq;
        }
        
        result.rightValue = right.rightValue;
        result.rightFreq = right.rightFreq;
        if (right.rightValue == left.rightValue) {
            result.rightFreq += left.rightFreq;
        }

        result.maxFreq = max(left.maxFreq, right.maxFreq);
        if (left.rightValue == right.leftValue) {
            result.maxFreq = max(result.maxFreq, left.rightFreq + right.leftFreq);
        }

        return result;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {arr[start], 1, arr[start], 1, 1};
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    SegmentTreeNode query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return {-1, 0, -1, 0, 0}; // Outside the range, return invalid node
        }
        if (l <= start && end <= r) {
            return tree[node]; // Completely inside the range
        }
        int mid = (start + end) / 2;
        SegmentTreeNode left = query(2 * node, start, mid, l, r);
        SegmentTreeNode right = query(2 * node + 1, mid + 1, end, l, r);
        if (left.leftValue == -1) return right;
        if (right.leftValue == -1) return left;
        return combine(left, right);
    }

public:
    SegmentTree(const vector<int>& array) {
        arr = array;
        n = array.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    int getMostFrequentInRange(int l, int r) {
        SegmentTreeNode result = query(1, 0, n - 1, l, r);
        return result.maxFreq;
    }
};

int main() {
    while (true) {
        int n, q;
        cin >> n;
        if (n == 0) break;
        cin >> q;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        SegmentTree segTree(arr);

        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            // Convert 1-based index to 0-based index
            l--; r--;
            cout << segTree.getMostFrequentInRange(l, r) << endl;
        }
    }
    return 0;
}