/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293064
 * Submitted at:  2024-06-24 16:28:15
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    161
 * Problem Name:  Knight Moves (UVa 439)
 */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

// Directions for the knight's moves (8 possible moves)
const int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Validity check for chessboard coordinates
bool isValid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// BFS function to find shortest path
int bfs(string start, string end) {
    // Convert chess notation to coordinates
    int startX = start[0] - 'a';
    int startY = start[1] - '1';
    int endX = end[0] - 'a';
    int endY = end[1] - '1';

    // Queue for BFS, initially push the start position
    queue<pair<int, int>> q;
    q.push({ startX, startY });

    // Distance map and visited set
    unordered_map<int, unordered_map<int, int>> dist;
    unordered_set<int> visited;
    dist[startX][startY] = 0;
    visited.insert(startX * 10 + startY);

    // BFS loop
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        // If reached the destination
        if (x == endX && y == endY) {
            return dist[x][y];
        }

        // Explore all 8 possible knight moves
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny) && visited.find(nx * 10 + ny) == visited.end()) {
                visited.insert(nx * 10 + ny);
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }

    // If no path found (though problem guarantees there will always be one)
    return -1;
}

int main() {
    string from, to;

    while (cin >> from >> to) {
        int moves = bfs(from, to);
        cout << "To get from " << from << " to " << to << " takes " << moves << " knight moves." << endl;
    }

    return 0;
}