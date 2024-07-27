/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293122
 * Submitted at:  2024-07-27 14:59:16
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    550
 * Problem Name:  Room Assignment Phase
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        vector<int> ratings(N);
        for (int i = 0; i < N; ++i) {
            cin >> ratings[i];
        }
        int K;
        cin >> K;

        // Sort the ratings in descending order
        vector<int> sortedRatings = ratings;
        sort(sortedRatings.begin(), sortedRatings.end(), greater<int>());

        // Find your rating
        int yourRating = ratings[0];

        // Determine the room assignments
        vector<vector<int>> rooms(K);
        for (int i = 0; i < N; ++i) {
            rooms[i % K].push_back(sortedRatings[i]);
        }

        // Find your room and count how many in that room have higher ratings than yours
        int yourRoomIndex = -1;
        for (int i = 0; i < N; ++i) {
            if (sortedRatings[i] == yourRating) {
                yourRoomIndex = i % K;
                break;
            }
        }

        int strongerCompetitors = 0;
        for (int rating : rooms[yourRoomIndex]) {
            if (rating > yourRating) {
                strongerCompetitors++;
            }
        }

        cout << strongerCompetitors << endl;
    }

    return 0;
}