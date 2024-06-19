/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293029
 * Submitted at:  2024-06-19 11:29:14
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    27
 * Problem Name:  Gems in the maze
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 300;

int a, b, c, n;
bool visited[MAX_N];
int dp[MAX_N];

int next_chamber(int v) {
    return (a * v * v + b * v + c) % n;
}

int dfs(int chamber) {
    if (visited[chamber]) return 0; // If already visited, no more gems can be collected from here
    visited[chamber] = true;
    int next = next_chamber(chamber);
    return 1 + dfs(next); // Collect gem in current chamber and move to next chamber
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> n;

        int max_gems = 0;
        for (int i = 0; i < n; ++i) {
            memset(visited, false, sizeof(visited)); // Reset visited array for each start chamber
            max_gems = max(max_gems, dfs(i)); // Start DFS from chamber i
        }
        cout << max_gems << endl;
    }
    return 0;
}