/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293070
 * Submitted at:  2024-07-01 23:27:08
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    686
 * Problem Name:  Magic Number
 */

#include <iostream>
#include <string>

using namespace std;

bool isMagicNumber(const string& number) {
    size_t i = 0;
    while (i < number.size()) {
        if (number.substr(i, 3) == "144") {
            i += 3;
        } else if (number.substr(i, 2) == "14") {
            i += 2;
        } else if (number[i] == '1') {
            i += 1;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    string number;
    while (cin >> number) {
        if (isMagicNumber(number)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}