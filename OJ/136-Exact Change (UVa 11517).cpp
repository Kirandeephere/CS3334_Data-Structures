/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293051
 * Submitted at:  2024-06-24 14:51:57
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    136
 * Problem Name:  Exact Change (UVa 11517)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int price;
        cin >> price;
        
        int n;
        cin >> n;
        
        vector<int> coins(n);
        for (int i = 0; i < n; ++i) {
            cin >> coins[i];
        }
        
        // Define the maximum possible value we might need to consider
        int max_value = 10000 + *max_element(coins.begin(), coins.end());
        
        // Initialize the dp array with a large number (INT_MAX)
        vector<int> dp(max_value + 1, INT_MAX);
        dp[0] = 0; // 0 coins needed to make 0 cents
        
        // Fill dp array
        for (int coin : coins) {
            for (int j = max_value; j >= coin; --j) {
                if (dp[j - coin] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coin] + 1);
                }
            }
        }
        
        // Find the minimum amount paid that is at least the price
        int min_amount_paid = price;
        while (dp[min_amount_paid] == INT_MAX) {
            ++min_amount_paid;
        }
        
        cout << min_amount_paid << " " << dp[min_amount_paid] << endl;
    }
    
    return 0;
}