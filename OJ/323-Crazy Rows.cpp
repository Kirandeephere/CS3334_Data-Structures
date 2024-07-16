/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293108
 * Submitted at:  2024-07-16 16:33:18
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    323
 * Problem Name:  Crazy Rows
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the minimum number of swaps required to meet the condition
int minSwaps(vector<vector<int>>& matrix, int N) {
    vector<int> rightmost_one(N, -1);
    
    // Find the rightmost 1 in each row
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] == 1) {
                rightmost_one[i] = j;
            }
        }
    }

    int swaps = 0;
    // Process each row to place it in the correct position
    for (int i = 0; i < N; ++i) {
        int target = i;
        // Find the row that can be placed in the current position
        while (target < N && rightmost_one[target] > i) {
            ++target;
        }

        // Perform swaps to bring the row to the correct position
        for (int j = target; j > i; --j) {
            swap(rightmost_one[j], rightmost_one[j - 1]);
            ++swaps;
        }
    }

    return swaps;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<vector<int>> matrix(N, vector<int>(N));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                char c;
                cin >> c;
                matrix[i][j] = c - '0';
            }
        }

        int result = minSwaps(matrix, N);
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}