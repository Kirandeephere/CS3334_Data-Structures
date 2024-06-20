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

int main() {
    std::string input;
    std::stack<char> stack;

    while (std::getline(std::cin, input)) {
        // Push characters onto the stack
        for (char c : input) {
            stack.push(c);
        }

        // Pop characters from the stack and switch case
        while (!stack.empty()) {
            char c = stack.top();
            stack.pop();
            if (std::isupper(c)) {
                std::cout << static_cast<char>(std::tolower(c));
            } else {
                std::cout << static_cast<char>(std::toupper(c));
            }
        }
        std::cout << std::endl;
    }

    return 0;
}