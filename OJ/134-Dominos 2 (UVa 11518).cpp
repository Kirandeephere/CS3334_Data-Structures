/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293049
 * Submitted at:  2024-06-24 14:41:32
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    134
 * Problem Name:  Dominos 2 (UVa 11518)
 */

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

void dfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    stack<int> s;
    s.push(start);
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        if (!visited[current]) {
            visited[current] = true;
            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        int n, m, l;
        cin >> n >> m >> l;
        vector<vector<int>> graph(n + 1);
        vector<bool> visited(n + 1, false);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
        }
        for (int i = 0; i < l; ++i) {
            int z;
            cin >> z;
            if (!visited[z]) {
                dfs(z, graph, visited);
            }
        }
        int fallen_dominos = 0;
        for (int i = 1; i <= n; ++i) {
            if (visited[i]) {
                ++fallen_dominos;
            }
        }
        cout << fallen_dominos << endl;
    }
    return 0;
}