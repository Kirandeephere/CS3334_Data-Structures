/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293083
 * Submitted at:  2024-07-06 21:31:19
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    535
 * Problem Name:  Ahoy, Pirates! (UVa 11402)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SegmentTree {
private:
    vector<int> tree, lazy;
    vector<bool> to_set, to_clear, to_invert;
    int n;

    void build(const string &pirates, int node, int start, int end) {
        if (start == end) {
            tree[node] = pirates[start] - '0';
        } else {
            int mid = (start + end) / 2;
            build(pirates, 2 * node, start, mid);
            build(pirates, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void apply_lazy(int node, int start, int end) {
        if (to_set[node] || to_clear[node] || to_invert[node]) {
            if (to_set[node]) {
                tree[node] = (end - start + 1);
                if (start != end) {
                    to_set[2 * node] = to_set[2 * node + 1] = true;
                    to_clear[2 * node] = to_clear[2 * node + 1] = false;
                    to_invert[2 * node] = to_invert[2 * node + 1] = false;
                }
                to_set[node] = false;
            }
            if (to_clear[node]) {
                tree[node] = 0;
                if (start != end) {
                    to_clear[2 * node] = to_clear[2 * node + 1] = true;
                    to_set[2 * node] = to_set[2 * node + 1] = false;
                    to_invert[2 * node] = to_invert[2 * node + 1] = false;
                }
                to_clear[node] = false;
            }
            if (to_invert[node]) {
                tree[node] = (end - start + 1) - tree[node];
                if (start != end) {
                    if (to_invert[2 * node]) to_invert[2 * node] = false; else to_invert[2 * node] = true;
                    if (to_invert[2 * node + 1]) to_invert[2 * node + 1] = false; else to_invert[2 * node + 1] = true;
                }
                to_invert[node] = false;
            }
        }
    }

    void update_range(int node, int start, int end, int l, int r, int type) {
        apply_lazy(node, start, end);
        if (start > r || end < l) return;
        if (start >= l && end <= r) {
            if (type == 1) {
                tree[node] = (end - start + 1);
                if (start != end) {
                    to_set[2 * node] = to_set[2 * node + 1] = true;
                    to_clear[2 * node] = to_clear[2 * node + 1] = false;
                    to_invert[2 * node] = to_invert[2 * node + 1] = false;
                }
            } else if (type == 2) {
                tree[node] = 0;
                if (start != end) {
                    to_clear[2 * node] = to_clear[2 * node + 1] = true;
                    to_set[2 * node] = to_set[2 * node + 1] = false;
                    to_invert[2 * node] = to_invert[2 * node + 1] = false;
                }
            } else if (type == 3) {
                tree[node] = (end - start + 1) - tree[node];
                if (start != end) {
                    if (to_invert[2 * node]) to_invert[2 * node] = false; else to_invert[2 * node] = true;
                    if (to_invert[2 * node + 1]) to_invert[2 * node + 1] = false; else to_invert[2 * node + 1] = true;
                }
            }
            return;
        }
        int mid = (start + end) / 2;
        update_range(2 * node, start, mid, l, r, type);
        update_range(2 * node + 1, mid + 1, end, l, r, type);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query_range(int node, int start, int end, int l, int r) {
        apply_lazy(node, start, end);
        if (start > r || end < l) return 0;
        if (start >= l && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int left = query_range(2 * node, start, mid, l, r);
        int right = query_range(2 * node + 1, mid + 1, end, l, r);
        return left + right;
    }

public:
    SegmentTree(const string &pirates) {
        n = pirates.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        to_set.resize(4 * n, false);
        to_clear.resize(4 * n, false);
        to_invert.resize(4 * n, false);
        build(pirates, 1, 0, n - 1);
    }

    void update(int l, int r, int type) {
        update_range(1, 0, n - 1, l, r, type);
    }

    int query(int l, int r) {
        return query_range(1, 0, n - 1, l, r);
    }
};

int main() {
    int test_cases;
    cin >> test_cases;
    for (int t = 1; t <= test_cases; t++) {
        int m;
        cin >> m;
        string pirates = "";
        for (int i = 0; i < m; i++) {
            int T;
            string part;
            cin >> T >> part;
            for (int j = 0; j < T; j++) {
                pirates += part;
            }
        }
        SegmentTree st(pirates);
        int q;
        cin >> q;
        cout << "Case " << t << ":\n";
        int query_count = 1;
        for (int i = 0; i < q; i++) {
            char type;
            int a, b;
            cin >> type >> a >> b;
            if (type == 'F') {
                st.update(a, b, 1);
            } else if (type == 'E') {
                st.update(a, b, 2);
            } else if (type == 'I') {
                st.update(a, b, 3);
            } else if (type == 'S') {
                int result = st.query(a, b);
                cout << "Q" << query_count << ": " << result << "\n";
                query_count++;
            }
        }
    }
    return 0;
}