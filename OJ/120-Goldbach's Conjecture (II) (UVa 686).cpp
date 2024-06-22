/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293041
 * Submitted at:  2024-06-22 22:51:35
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    120
 * Problem Name:  Goldbach's Conjecture (II) (UVa 686)
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

// Function to find the number of pairs of prime numbers that sum to n
int count_goldbach_pairs(int n) {
    int count = 0;
    for (int i = 2; i <= n / 2; i++) {
        if (is_prime(i) && is_prime(n - i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        cout << count_goldbach_pairs(n) << endl;
    }
    return 0;
}