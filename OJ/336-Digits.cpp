/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293112
 * Submitted at:  2024-07-18 13:17:57
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    336
 * Problem Name:  Digits
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countDigits(const string& num) {
    return num.length();
}

int main() {
    vector<string> inputs;
    string x0;

    // Read input until "END" is encountered
    while (true) {
        cin >> x0;
        if (x0 == "END") break;
        inputs.push_back(x0);
    }

    // Process each input
    for (const string& x0 : inputs) {
        string current = x0;
        int i = 1;

        while (true) {
            string next = to_string(countDigits(current));
            if (next == current) break;
            current = next;
            i++;
        }

        cout << i << endl;
    }

    return 0;
}