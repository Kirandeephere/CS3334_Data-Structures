/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293042
 * Submitted at:  2024-06-22 23:01:53
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    130
 * Problem Name:  Black and white painting (UVa 11231)
 */

#include <iostream>

using namespace std;

int main() {
    while (true) {
        int n, m, c;
        cin >> n >> m >> c;
        if (n == 0 && m == 0 && c == 0) break;

        // Number of valid 8x8 grids in n rows and m columns
        int numRows = n - 7; // number of valid starting rows
        int numCols = m - 7; // number of valid starting columns

        // Total number of valid 8x8 grids
        int totalGrids = numRows * numCols;

        // Depending on the bottom right corner color, adjust the count
        int validGrids;
        if (c == 1) {
            // If the bottom right corner is white
            validGrids = (numRows * numCols + 1) / 2;
        } else {
            // If the bottom right corner is black
            validGrids = (numRows * numCols) / 2;
        }

        cout << validGrids << endl;
    }
    return 0;
}