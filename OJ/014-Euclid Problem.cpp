/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 292996
 * Submitted at:  2024-06-07 22:17:48
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    14
 * Problem Name:  Euclid Problem
 */

#include <iostream>

using namespace std;

// Extended Euclidean Algorithm
// Function to find coefficients x, y, and the greatest common divisor d
void extended_euclidean(int a, int b, int& x, int& y, int& d) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    int x1, y1;
    extended_euclidean(b, a % b, x1, y1, d);
    x = y1;
    y = x1 - (a / b) * y1;
}

// Function to minimize |X| + |Y|
void minimize_x_y(int x, int y, int& min_sum, int& min_x, int& min_y) {
    if (abs(x) + abs(y) > abs(x + y)) {
        min_sum = x + y;
        min_x = x;
        min_y = y;
    } else {
        min_sum = abs(x) + abs(y);
        min_x = abs(x);
        min_y = abs(y);
    }
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        int x, y, d;
        extended_euclidean(a, b, x, y, d);
        int min_sum, min_x, min_y;
        minimize_x_y(x, y, min_sum, min_x, min_y);
        cout << min_x << " " << min_y << " " << d << endl;
    }
    return 0;
}