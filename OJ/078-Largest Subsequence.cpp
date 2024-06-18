/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293028
 * Submitted at:  2024-06-18 20:58:26
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    78
 * Problem Name:  Largest Subsequence
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the lexicographically largest subsequence
string findLargestSubsequence(const string& s) {
    string result;
    char max_char = '\0';
    // Traverse the string from right to left
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] >= max_char) {
            max_char = s[i];
            result.push_back(max_char);
        }
    }
    // The result is in reverse order, so reverse it before returning
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<string> results(N);
    for (int i = 0; i < N; ++i) {
        string x;
        cin >> x;
        results[i] = findLargestSubsequence(x);
    }
    for (const auto& res : results) {
        cout << res << endl;
    }
    return 0;
}