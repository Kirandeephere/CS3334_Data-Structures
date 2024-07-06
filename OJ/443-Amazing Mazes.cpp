/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293076
 * Submitted at:  2024-07-06 12:05:07
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    443
 * Problem Name:  Amazing Mazes
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

// Directions: right, down, left, up
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// Function to check if a position is within the maze bounds
bool isValid(int x, int y, int w, int h) {
    return x >= 0 && x < w && y >= 0 && y < h;
}

int bfs(int w, int h, const vector<vector<int>>& horWalls, const vector<vector<int>>& verWalls) {
    // Queue to store the BFS state
    queue<pair<int, int>> q;
    // Visited array
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    // Distance array
    vector<vector<int>> distance(h, vector<int>(w, 0));
    
    // Start from the top-left corner
    q.push({0, 0});
    visited[0][0] = true;
    distance[0][0] = 1;
    
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        
        // Check all 4 possible directions
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (isValid(nx, ny, w, h) && !visited[ny][nx]) {
                // Check if the move is not blocked by a wall
                if ((i == 0 && !horWalls[y][x]) || // right
                    (i == 1 && !verWalls[y][x]) || // down
                    (i == 2 && x > 0 && !horWalls[y][x-1]) || // left
                    (i == 3 && y > 0 && !verWalls[y-1][x])) { // up
                    
                    visited[ny][nx] = true;
                    distance[ny][nx] = distance[y][x] + 1;
                    q.push({nx, ny});
                    
                    // If we reached the bottom-right corner, return the distance
                    if (nx == w-1 && ny == h-1) {
                        return distance[ny][nx];
                    }
                }
            }
        }
    }
    
    // If we can't reach the exit, return 0
    return 0;
}

int main() {
    while (true) {
        int w, h;
        cin >> w >> h;
        
        if (w == 0 && h == 0) break;
        
        vector<vector<int>> horWalls(h, vector<int>(w-1));
        vector<vector<int>> verWalls(h-1, vector<int>(w));
        
        for (int i = 0; i < 2 * h - 1; ++i) {
            if (i % 2 == 0) {
                for (int j = 0; j < w - 1; ++j) {
                    cin >> horWalls[i / 2][j];
                }
            } else {
                for (int j = 0; j < w; ++j) {
                    cin >> verWalls[i / 2][j];
                }
            }
        }
        
        cout << bfs(w, h, horWalls, verWalls) << endl;
    }
    
    return 0;
}