/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293106
 * Submitted at:  2024-07-13 13:39:17
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    466
 * Problem Name:  Sum of Different Primes
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 1120;
const int MAX_K = 14;

vector<int> generatePrimes(int max_n) {
    vector<bool> is_prime(max_n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= max_n; ++p) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= max_n; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }
    vector<int> primes;
    for (int p = 2; p <= max_n; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
    return primes;
}

int main() {
    vector<int> primes = generatePrimes(MAX_N);
    int dp[MAX_N + 1][MAX_K + 1];

    int n, k;
    while (cin >> n >> k && (n != 0 || k != 0)) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (int prime : primes) {
            for (int sum = MAX_N; sum >= prime; --sum) {
                for (int count = 1; count <= MAX_K; ++count) {
                    dp[sum][count] += dp[sum - prime][count - 1];
                }
            }
        }
        cout << dp[n][k] << endl;
    }
    return 0;
}