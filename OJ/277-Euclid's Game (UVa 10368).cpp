/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293046
 * Submitted at:  2024-06-24 14:29:03
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    277
 * Problem Name:  Euclid's Game (UVa 10368)
 */

#include <iostream>
#include <algorithm>

using namespace std;

// Function to determine the winner given two numbers
string determine_winner(int a, int b) {
    // Ensure that a >= b
    if (a < b) swap(a, b);

    // Check if a % b == 0
    if (a % b == 0) {
        // If a is a multiple of b, the current player wins
        return "Stan wins";
    }

    // If a / b is at least 2, the current player wins
    if (a / b >= 2) {
        return "Stan wins";
    }

    // Otherwise, recursively determine the winner for the next turn
    string next_winner = determine_winner(b, a % b);

    // If the next player wins, then the current player loses
    return (next_winner == "Stan wins") ? "Ollie wins" : "Stan wins";
}

int main() {
    int a, b;

    while (cin >> a >> b) {
        if (a == 0 && b == 0) {
            break;
        }

        cout << determine_winner(a, b) << endl;
    }

    return 0;
}