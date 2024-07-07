/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293086
 * Submitted at:  2024-07-06 21:44:10
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    718
 * Problem Name:  Phone Number
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isPrefix(const string& a, const string& b) {
    if (a.length() > b.length()) return false;
    return b.substr(0, a.length()) == a;
}

int main() {
    int N;
    
    while (cin >> N) {
        if (N == 0) break;
        
        vector<string> numbers(N);
        for (int i = 0; i < N; ++i) {
            cin >> numbers[i];
        }
        
        // Sort the phone numbers
        sort(numbers.begin(), numbers.end());
        
        bool foundPrefix = false;
        for (int i = 0; i < N - 1; ++i) {
            if (isPrefix(numbers[i], numbers[i + 1])) {
                foundPrefix = true;
                break;
            }
        }
        
        if (foundPrefix) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    
    return 0;
}