/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293058
 * Submitted at:  2024-06-24 15:40:44
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    151
 * Problem Name:  Conformity (UVa 11286)
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while (cin >> n && n != 0) {
        unordered_map<string, int> combination_count;
        
        for (int i = 0; i < n; ++i) {
            vector<int> courses(5);
            for (int j = 0; j < 5; ++j) {
                cin >> courses[j];
            }
            sort(courses.begin(), courses.end());
            
            stringstream ss;
            for (int j = 0; j < 5; ++j) {
                ss << courses[j];
            }
            string combination = ss.str();
            
            if (combination_count.find(combination) == combination_count.end()) {
                combination_count[combination] = 0;
            }
            combination_count[combination]++;
        }
        
        int max_popularity = 0;
        int count_max_popularity = 0;
        
        for (auto& entry : combination_count) {
            if (entry.second > max_popularity) {
                max_popularity = entry.second;
                count_max_popularity = entry.second;
            } else if (entry.second == max_popularity) {
                count_max_popularity += entry.second;
            }
        }
        
        cout << count_max_popularity << "\n";
    }
    
    return 0;
}