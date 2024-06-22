/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293034
 * Submitted at:  2024-06-20 22:08:12
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    226
 * Problem Name:  Just Reversing the String?
 */

#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

int main() {
    string input;
    stack<char> stack;

    while (getline(cin, input)) {
        // Push characters onto the stack
        for (char c : input) {
            stack.push(c);
        }

        // Pop characters from the stack and switch case
        while (!stack.empty()) {
            char c = stack.top();
            stack.pop();
            if (isupper(c)) {
                cout << static_cast<char>(tolower(c));
            } else {
                cout << static_cast<char>(toupper(c));
            }
        }
        cout << endl;
    }

    return 0;
}