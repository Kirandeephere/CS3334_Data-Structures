/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293094
 * Submitted at:  2024-07-11 15:35:49
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    566
 * Problem Name:  Meeting Schedule Arrangement
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    string line;
    int N, Q;

    while (getline(cin, line)) {
        istringstream iss(line);
        iss >> N >> Q;

        if (N == 0 && Q == 0)
            break;

        unordered_map<int, int> dateCount; // To count frequency of each date

        // Read each member's convenient dates
        for (int i = 0; i < N; ++i) {
            getline(cin, line);
            istringstream memberStream(line);
            int M;
            memberStream >> M;
            for (int j = 0; j < M; ++j) {
                int date;
                memberStream >> date;
                dateCount[date]++;
            }
        }

        // Find the date with the highest frequency that meets or exceeds the quorum
        int bestDate = 0;
        int maxMembers = 0;

        for (auto& pair : dateCount) {
            int date = pair.first;
            int count = pair.second;
            if (count >= Q) {
                if (count > maxMembers || (count == maxMembers && date < bestDate)) {
                    maxMembers = count;
                    bestDate = date;
                }
            }
        }

        // Output the best date for the current dataset
        if (maxMembers >= Q) {
            cout << bestDate << endl;
        } else {
            cout << "0" << endl;
        }
    }

    return 0;
}