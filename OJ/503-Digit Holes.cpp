/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293090
 * Submitted at:  2024-07-08 22:01:06
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    503
 * Problem Name:  Digit Holes
 */

#include <iostream>
#include <map>
#include <string>
using namespace std;

// Function to count the number of holes in a given number
int countHoles(const string& number) {
    // Mapping of each digit to the number of holes it contains
    map<char, int> holesMap = {
        {'0', 1}, {'1', 0}, {'2', 0}, {'3', 0}, {'4', 1},
        {'5', 0}, {'6', 1}, {'7', 0}, {'8', 2}, {'9', 1}
    };
    
    int totalHoles = 0;
    // Iterate through each character in the number string
    for (char digit : number) {
        totalHoles += holesMap[digit];
    }
    
    return totalHoles;
}

int main() {
    string number;
    // Read input until EOF
    while (cin >> number) {
        // Calculate and print the number of holes for each number
        cout << countHoles(number) << endl;
    }
    return 0;
}