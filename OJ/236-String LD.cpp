/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293113
 * Submitted at:  2024-07-21 14:54:49
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    236
 * Problem Name:  String LD
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

int main() {
    while (true) {
        int n;
        std::cin >> n;
        if (n == 0) break;

        std::vector<std::string> words(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> words[i];
        }

        int steps = 0;
        bool condition_met = false;

        while (true) {
            std::unordered_set<std::string> word_set;
            for (std::string& word : words) {
                word = word.substr(1);  // Apply stringld function
                if (word.empty() || !word_set.insert(word).second) {
                    condition_met = true;
                    break;
                }
            }
            if (condition_met) break;
            ++steps;
        }

        std::cout << steps << std::endl;
    }

    return 0;
}