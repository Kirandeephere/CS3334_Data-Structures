/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 292992
 * Submitted at:  2024-06-07 22:12:09
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    12
 * Problem Name:  Yodaness Level
 */

#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

const int MAX_N = 30001;

int bit[MAX_N];

void update(int idx, int val, int n) {
    while (idx <= n) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        unordered_map<string, int> word_indices;
        
        for (int i = 1; i <= n; ++i) {
            string word;
            cin >> word;
            word_indices[word] = i;
        }

        memset(bit, 0, sizeof(bit));

        long long yodaness_level = 0;
        for (int i = 0; i < n; ++i) {
            string word;
            cin >> word;
            int idx = word_indices[word];
            yodaness_level += i - query(idx);
            update(idx, 1, n);
        }

        cout << yodaness_level << endl;
    }

    return 0;
}