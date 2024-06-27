/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293061
 * Submitted at:  2024-06-24 16:17:46
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    159
 * Problem Name:  Arbitrage (II) (UVa 436)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

struct Edge {
    int from;
    int to;
    double weight;
};

bool bellmanFord(int n, const vector<Edge>& edges) {
    vector<double> distance(n, numeric_limits<double>::infinity());
    distance[0] = 0;

    // Relax edges up to n-1 times
    for (int i = 0; i < n - 1; ++i) {
        for (const auto& edge : edges) {
            if (distance[edge.from] + edge.weight < distance[edge.to]) {
                distance[edge.to] = distance[edge.from] + edge.weight;
            }
        }
    }

    // Check for negative weight cycles
    for (const auto& edge : edges) {
        if (distance[edge.from] + edge.weight < distance[edge.to]) {
            return true; // Arbitrage detected
        }
    }
    return false;
}

int main() {
    int caseNumber = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        unordered_map<string, int> currencyIndex;
        vector<string> currencies(n);
        for (int i = 0; i < n; ++i) {
            cin >> currencies[i];
            currencyIndex[currencies[i]] = i;
        }

        int m;
        cin >> m;
        vector<Edge> edges(m);
        for (int i = 0; i < m; ++i) {
            string from, to;
            double rate;
            cin >> from >> rate >> to;
            edges[i] = {currencyIndex[from], currencyIndex[to], -log(rate)};
        }

        bool arbitrage = bellmanFord(n, edges);
        cout << "Case " << caseNumber << ": " << (arbitrage ? "Yes" : "No") << endl;
        caseNumber++;

        string blankLine;
        getline(cin, blankLine); // To handle the blank line separator
    }

    return 0;
}