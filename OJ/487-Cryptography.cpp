/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293088
 * Submitted at:  2024-07-08 21:42:13
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    487
 * Problem Name:  Cryptography
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        
        vector<long long> numbers(n);
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }
        
        long long max_product = 0;
        for (int i = 0; i < n; ++i) {
            // Calculate the product with the i-th element incremented
            long long current_product = 1;
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    current_product *= (numbers[j] + 1);
                } else {
                    current_product *= numbers[j];
                }
            }
            max_product = max(max_product, current_product);
        }
        
        cout << max_product << endl;
    }
    
    return 0;
}