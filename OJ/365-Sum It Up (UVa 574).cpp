/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293037
 * Submitted at:  2024-06-21 22:06:38
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    365
 * Problem Name:  Sum It Up (UVa 574)
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;

// Function to perform backtracking and find all sums that add up to t
void findSums(int t, int start, int currentSum, vector<int>& nums, vector<int>& currentCombination, set<vector<int>>& results) {
    if (currentSum == t) {
        results.insert(currentCombination);
        return;
    }
    if (currentSum > t) return;

    for (int i = start; i < nums.size(); ++i) {
        currentCombination.push_back(nums[i]);
        findSums(t, i + 1, currentSum + nums[i], nums, currentCombination, results);
        currentCombination.pop_back();
    }
}

int main() {
    string line;
    while (getline(cin, line)) {
        // Parse the input line
        istringstream iss(line);
        int t, n;
        iss >> t >> n;
        if (n == 0) break;

        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            iss >> nums[i];
        }

        set<vector<int>> results;
        vector<int> currentCombination;

        findSums(t, 0, 0, nums, currentCombination, results);

        cout << "Sums of " << t << ":\n";
        if (results.empty()) {
            cout << "NONE\n";
        } else {
            vector<vector<int>> resultList(results.begin(), results.end());
            sort(resultList.rbegin(), resultList.rend());
            for (const auto& combination : resultList) {
                for (size_t i = 0; i < combination.size(); ++i) {
                    if (i > 0) cout << "+";
                    cout << combination[i];
                }
                cout << "\n";
            }
        }
    }
    return 0;
}