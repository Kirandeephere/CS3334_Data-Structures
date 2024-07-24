/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293120
 * Submitted at:  2024-07-24 14:13:29
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    389
 * Problem Name:  Store Credit
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int credit, numItems;
        cin >> credit >> numItems;
        
        vector<int> prices(numItems);
        unordered_map<int, int> priceIndexMap;
        
        for (int i = 0; i < numItems; ++i) {
            cin >> prices[i];
            priceIndexMap[prices[i]] = i;
        }
        
        for (int i = 0; i < numItems; ++i) {
            int currentPrice = prices[i];
            int complement = credit - currentPrice;
            
            if (priceIndexMap.find(complement) != priceIndexMap.end()) {
                int complementIndex = priceIndexMap[complement];
                if (complementIndex != i) {
                    // Ensure the output is in increasing index order
                    if (i < complementIndex) {
                        cout << "Case #" << t << ": " << i + 1 << " " << complementIndex + 1 << endl;
                    } else {
                        cout << "Case #" << t << ": " << complementIndex + 1 << " " << i + 1 << endl;
                    }
                    break;
                }
            }
        }
    }

    return 0;
}