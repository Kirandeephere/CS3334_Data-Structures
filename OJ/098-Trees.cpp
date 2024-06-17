/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293023
 * Submitted at:  2024-06-17 11:03:37
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    98
 * Problem Name:  Trees
 */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 500;
vector<int> adj[MAXN + 1];
bool visited[MAXN + 1];
bool hasCycle;
int vertices, edges;

void dfs(int v, int parent) {
    visited[v] = true;
    vertices++;
    for (int u : adj[v]) {
        if (!visited[u]) {
            edges++;
            dfs(u, v);
        } else if (u != parent) {
            hasCycle = true;
        }
    }
}

int main() {
    int n, m, caseNum = 1;
    while (cin >> n >> m, n || m) {
        // Reset graph structure
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
        }
        memset(visited, false, sizeof(visited));

        // Read edges
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int treeCount = 0;

        // Process each connected component
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                vertices = edges = 0;
                hasCycle = false;
                dfs(i, -1);

                if (!hasCycle && edges == vertices - 1) {
                    treeCount++;
                }
            }
        }

        // Output result for the current case
        if (treeCount == 0) {
            cout << "Case " << caseNum << ": No trees." << endl;
        } else if (treeCount == 1) {
            cout << "Case " << caseNum << ": There is one tree." << endl;
        } else {
            cout << "Case " << caseNum << ": A forest of " << treeCount << " trees." << endl;
        }

        caseNum++;
    }

    return 0;
}