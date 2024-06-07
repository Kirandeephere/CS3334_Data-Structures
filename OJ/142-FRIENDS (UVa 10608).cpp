/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293000
 * Submitted at:  2024-06-07 23:11:08
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    142
 * Problem Name:  FRIENDS (UVa 10608)
 */

#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent, size;

public:
    UnionFind(int n) {
        parent.assign(n, 0);
        size.assign(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int v) {
        return parent[v] == v ? v : parent[v] = find(parent[v]);
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            if (size[rootA] < size[rootB])
                swap(rootA, rootB);
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }

    int getSize(int v) {
        return size[find(v)];
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        UnionFind uf(n);

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            uf.unite(a - 1, b - 1);
        }

        int maxSize = 0;
        for (int i = 0; i < n; ++i)
            maxSize = max(maxSize, uf.getSize(i));

        cout << maxSize << endl;
    }

    return 0;
}