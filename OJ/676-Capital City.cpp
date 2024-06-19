/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293030
 * Submitted at:  2024-06-19 11:41:24
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    676
 * Problem Name:  Capital City
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MAXN = 100;
const int INF = INT_MAX;

int main() {
    int n, m;
    
    while (cin >> n >> m) {
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
        
        for (int i = 1; i <= n; i++) {
            dist[i][i] = 0;
        }
        
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            dist[u][v] = w;
            dist[v][u] = w;
        }
        
        // Floyd-Warshall algorithm
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        int bestCity = 1;
        int minTotalDist = INF;
        
        for (int i = 1; i <= n; i++) {
            int totalDist = 0;
            for (int j = 1; j <= n; j++) {
                totalDist += dist[i][j];
            }
            if (totalDist < minTotalDist) {
                minTotalDist = totalDist;
                bestCity = i;
            }
        }
        
        cout << bestCity << endl;
    }
    
    return 0;
}