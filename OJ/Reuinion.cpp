#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 100;
const int UPPER_LIMIT = 1005;

int main() {
    int K, N, M;
    cin >> K >> N >> M;

    // Read the cities where the friends live
    int cities[K];
    for (int i = 0; i < K; ++i) {
        cin >> cities[i];
    }

    // Create an adjacency matrix to represent the graph
    bool adjMatrix[MAX_N + 1][MAX_N + 1];
    memset(adjMatrix, false, sizeof(adjMatrix));

    // Populate the adjacency matrix based on the flights
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adjMatrix[a][b] = true;
    }

    // Function to perform BFS to find reachable cities
    auto bfs = [&](int start) {
        bool visited[MAX_N + 1];
        memset(visited, false, sizeof(visited));

        visited[start] = true;
        for (int i = 1; i <= N; ++i) {
            if (adjMatrix[start][i]) {
                visited[i] = true;
            }
        }

        for (int i = 1; i <= N; ++i) {
            if (visited[i]) {
                for (int j = 1; j <= N; ++j) {
                    if (adjMatrix[i][j]) {
                        visited[j] = true;
                    }
                }
            }
        }

        int reachableCities = 0;
        for (int i = 1; i <= N; ++i) {
            if (visited[i]) {
                reachableCities++;
            }
        }

        return reachableCities;
    };

    // Find the number of reachable cities for each friend
    int minReachableCities = UPPER_LIMIT;
    for (int i = 0; i < K; ++i) {
        int reachableCities = bfs(cities[i]);
        if (reachableCities < minReachableCities) {
            minReachableCities = reachableCities;
        }
    }

    cout << minReachableCities << endl;

    return 0;
}
