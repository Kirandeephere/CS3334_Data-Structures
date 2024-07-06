/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293081
 * Submitted at:  2024-07-06 12:23:11
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    8
 * Problem Name:  Expected Allowance
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

double expected_bills(int n, int m, int k) {
    vector<vector<long long>> dp(n + 1, vector<long long>(n * m + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= i * m; ++j) {
            dp[i][j] = 0;
            for (int p = 1; p <= m; ++p) {
                if (j - p >= 0) {
                    dp[i][j] += dp[i - 1][j - p];
                }
            }
        }
    }

    long long total_combinations = pow(m, n);
    double expected_value = 0.0;

    for (int sum = n; sum <= n * m; ++sum) {
        double probability = static_cast<double>(dp[n][sum]) / total_combinations;
        expected_value += probability * max(sum - k, 1);
    }

    return expected_value;
}

int main() {
    int n, m, k;
    cout << fixed << setprecision(8);

    while (cin >> n >> m >> k) {
        if (n == 0 && m == 0 && k == 0) {
            break;
        }
        cout << expected_bills(n, m, k) << endl;
    }

    return 0;
}