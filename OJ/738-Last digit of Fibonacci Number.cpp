/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293001
 * Submitted at:  2024-06-07 23:18:59
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    738
 * Problem Name:  Last digit of Fibonacci Number
 */

#include <iostream>
#include <vector>
using namespace std;

int fibonacci_last_digit(int n) {
    vector<int> fib = {0, 1};
    for (int i = 2; i <= n; ++i) {
        fib.push_back((fib[i - 1] + fib[i - 2]) % 10);
    }
    return fib[n];
}

int main() {
    int n;
    while (cin >> n) {
        cout << fibonacci_last_digit(n) << endl;
    }
    return 0;
}