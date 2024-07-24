/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293117
 * Submitted at:  2024-07-24 14:03:32
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    393
 * Problem Name:  Brother Arif, please feed us!
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool is_safe(int r, int c, int R, int C, const set<pair<int, int>>& problemsetters) {
    if (r < 0 || r >= R || c < 0 || c >= C) return false;  // Out of bounds
    for (const auto& p : problemsetters) {
        if (p.first == r || p.second == c) return false;  // Same row or column
    }
    return true;
}

int main() {
    int R, C, N;
    int case_number = 1;

    while (cin >> R >> C >> N) {
        if (R == 0 && C == 0 && N == 0) break;

        set<pair<int, int>> problemsetters;
        for (int i = 0; i < N; ++i) {
            int r, c;
            cin >> r >> c;
            problemsetters.insert({r, c});
        }

        int arif_r, arif_c;
        cin >> arif_r >> arif_c;

        bool escaped = false;
        // Check all five possible positions for Brother Arif
        vector<pair<int, int>> moves = {{arif_r, arif_c}, {arif_r + 1, arif_c}, {arif_r - 1, arif_c},
                                        {arif_r, arif_c + 1}, {arif_r, arif_c - 1}};

        for (const auto& move : moves) {
            if (is_safe(move.first, move.second, R, C, problemsetters)) {
                escaped = true;
                break;
            }
        }

        if (escaped) {
            cout << "Case " << case_number << ": Escaped again! More 2D grid problems!" << endl;
        } else {
            cout << "Case " << case_number << ": Party time! Let's find a restaurant!" << endl;
        }
        ++case_number;
    }

    return 0;
}