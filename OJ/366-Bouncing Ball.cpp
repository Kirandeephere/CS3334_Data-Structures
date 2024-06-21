/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293036
 * Submitted at:  2024-06-21 22:01:46
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    366
 * Problem Name:  Bouncing Balls
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;

    for (int t = 1; t <= test_cases; ++t) {
        int nX;
        cin >> nX;
        vector<int> positions(nX);

        for (int i = 0; i < nX; ++i) {
            cin >> positions[i];
        }

        int T;
        cin >> T;

        double expected_collisions = 0.0;
        for (int i = 0; i < nX; ++i) {
            for (int j = i + 1; j < nX; ++j) {
                if (abs(positions[i] - positions[j]) <= 2 * T) {
                    expected_collisions += 0.25;
                }
            }
        }

        cout << "Case #" << t << ": " << fixed << setprecision(2) << expected_collisions << endl;
    }

    return 0;
}