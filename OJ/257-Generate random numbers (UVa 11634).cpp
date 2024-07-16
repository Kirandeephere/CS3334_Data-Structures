/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293107
 * Submitted at:  2024-07-16 16:25:18
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    257
 * Problem Name:  Generate random numbers (UVa 11634)
 */

#include <iostream>
#include <unordered_set>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// Function to get the middle 4 digits of a number squared
int getMiddleSquare(int num) {
    int squared = num * num;
    stringstream ss;
    ss << setw(8) << setfill('0') << squared;
    string squaredStr = ss.str();
    return stoi(squaredStr.substr(2, 4));
}

int main() {
    int a0;
    
    while (cin >> a0) {
        if (a0 == 0) break;

        unordered_set<int> seen;
        int current = a0;

        while (seen.find(current) == seen.end()) {
            seen.insert(current);
            current = getMiddleSquare(current);
        }

        cout << seen.size() << endl;
    }

    return 0;
}