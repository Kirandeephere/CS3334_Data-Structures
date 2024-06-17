/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293024
 * Submitted at:  2024-06-17 11:11:15
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    141
 * Problem Name:  Ubiquitous Religions (UVa 10583)
 */

#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int n, m;
    int caseNum = 1;

    while (cin >> n >> m, n != 0 || m != 0) {
        UnionFind uf(n);
        
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            uf.unite(a, b);
        }

        // Find the number of distinct sets
        int distinctReligions = 0;
        for (int i = 1; i <= n; ++i) {
            if (uf.find(i) == i) {
                distinctReligions++;
            }
        }

        cout << "Case " << caseNum++ << ": " << distinctReligions << endl;
    }

    return 0;
}