/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293008
 * Submitted at:  2024-06-07 23:52:24
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    185
 * Problem Name:  Andy's First Dictionary (UVa 10815)
 */

#include <iostream>
#include <set>
#include <string>
#include <cctype> // For std::tolower

using namespace std;

int main() {
    set<string> words;
    string line;

    // Read input until EOF
    while (getline(cin, line)) {
        string word = "";
        for (char c : line) {
            // Convert to lowercase and check if alphabet
            if (isalpha(c)) {
                word += tolower(c);
            } else {
                // Non-alphabetic character, consider it as a word boundary
                if (!word.empty()) {
                    words.insert(word);
                    word = "";
                }
            }
        }
        // Check if there's any remaining word after the loop
        if (!word.empty()) {
            words.insert(word);
        }
    }

    // Output the sorted words
    for (const auto& word : words) {
        cout << word << endl;
    }

    return 0;
}