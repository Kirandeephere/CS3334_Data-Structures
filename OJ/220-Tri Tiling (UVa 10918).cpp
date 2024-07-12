/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293100
 * Submitted at:  2024-07-12 16:02:20
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    220
 * Problem Name:  Tri Tiling (UVa 10918)
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> dp(31, 0);
    
    // Base cases
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    
    // Fill dp array
    for (int n = 3; n <= 30; ++n) {
        dp[n] = 4 * dp[n-2] - dp[n-4];
    }
    
    // Read input and output results
    int n;
    while (cin >> n && n != -1) {
        cout << dp[n] << endl;
    }
    
    return 0;
}