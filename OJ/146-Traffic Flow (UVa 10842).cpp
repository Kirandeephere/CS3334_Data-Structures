/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293057
 * Submitted at:  2024-06-24 15:23:58
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    146
 * Problem Name:  Traffic Flow (UVa 10842)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 105;
const int MAXM = 10005;

int n, m;
vector<pair<int, int>> graph[MAXN]; // adjacency list for the graph
bool visited[MAXN]; // to mark visited nodes during connectivity check

// Function to perform DFS to check connectivity with a minimum capacity constraint
void dfs(int node, int min_capacity) {
    visited[node] = true;
    for (auto neighbor : graph[node]) {
        int next_node = neighbor.first;
        int capacity = neighbor.second;
        if (!visited[next_node] && capacity >= min_capacity) {
            dfs(next_node, min_capacity);
        }
    }
}

// Function to check if the graph is connected with a minimum capacity
bool is_connected_with_min_capacity(int min_capacity) {
    memset(visited, false, sizeof(visited));
    dfs(0, min_capacity);
    // Check if all nodes from 0 to n-1 are visited
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

// Binary search function to find maximum minimum capacity
int find_max_min_capacity() {
    int lo = 1, hi = 1000; // capacity range from 1 to 1000
    int best = 0;
    
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (is_connected_with_min_capacity(mid)) {
            best = mid;
            lo = mid + 1; // try for a higher minimum capacity
        } else {
            hi = mid - 1; // reduce the minimum capacity
        }
    }
    
    return best;
}

int main() {
    int N;
    cin >> N;
    
    for (int t = 1; t <= N; ++t) {
        cin >> n >> m;
        
        // Clear previous graph
        for (int i = 0; i < n; ++i)
            graph[i].clear();
        
        // Read the roads
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            graph[u].push_back({v, c});
            graph[v].push_back({u, c});
        }
        
        // Find maximum minimum capacity
        int max_min_capacity = find_max_min_capacity();
        
        // Output the result for the current test case
        cout << "Case #" << t << ": " << max_min_capacity << endl;
    }
    
    return 0;
}