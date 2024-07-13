/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293103
 * Submitted at:  2024-07-13 13:32:11
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    333
 * Problem Name:  Laser Sculpture (UVa 11683)
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int A, C;
    while (true) {
        cin >> A >> C;
        if (A == 0 && C == 0) break;

        vector<int> finalHeights(C);
        for (int i = 0; i < C; ++i) {
            cin >> finalHeights[i];
        }

        int laserOnCount = 0;
        int currentHeight = A;

        for (int i = 0; i < C; ++i) {
            if (finalHeights[i] < currentHeight) {
                laserOnCount += currentHeight - finalHeights[i];
                currentHeight = finalHeights[i];
            } else {
                currentHeight = finalHeights[i];
            }
        }

        cout << laserOnCount << endl;
    }

    return 0;
}