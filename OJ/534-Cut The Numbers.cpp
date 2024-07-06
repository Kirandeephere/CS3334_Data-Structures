/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293082
 * Submitted at:  2024-07-06 21:28:22
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    534
 * Problem Name:  Cut The Numbers
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int getMaxSum(vector<string>& board) {
    int R = board.size();
    int C = board[0].size();
    int maxSum = 0;

    // There are 2^(R*C) possible configurations of strips
    for (int mask = 0; mask < (1 << (R * C)); ++mask) {
        int sum = 0;

        // Horizontal strips
        for (int i = 0; i < R; ++i) {
            int num = 0;
            for (int j = 0; j < C; ++j) {
                int pos = i * C + j;
                if (mask & (1 << pos)) {
                    num = num * 10 + (board[i][j] - '0');
                } else {
                    sum += num;
                    num = 0;
                }
            }
            sum += num;
        }

        // Vertical strips
        for (int j = 0; j < C; ++j) {
            int num = 0;
            for (int i = 0; i < R; ++i) {
                int pos = i * C + j;
                if (!(mask & (1 << pos))) {
                    num = num * 10 + (board[i][j] - '0');
                } else {
                    sum += num;
                    num = 0;
                }
            }
            sum += num;
        }

        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main() {
    vector<string> board;
    string line;
    while (getline(cin, line)) {
        if (isdigit(line[0])) {
            int R = stoi(line);
            board.clear();
            for (int i = 0; i < R; ++i) {
                getline(cin, line);
                board.push_back(line);
            }
            cout << getMaxSum(board) << endl;
        }
    }
    return 0;
}