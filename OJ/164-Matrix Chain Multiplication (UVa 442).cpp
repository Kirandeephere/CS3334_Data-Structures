/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293065
 * Submitted at:  2024-06-24 17:11:03
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    164
 * Problem Name:  Matrix Chain Multiplication (UVa 442)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

// Define a structure to store matrix dimensions
struct Matrix {
    int rows;
    int cols;
};

// Function to evaluate the number of multiplications
pair<int, Matrix> evaluateExpression(const string &expr, const unordered_map<char, Matrix> &matrixMap, int &pos) {
    if (expr[pos] == '(') {
        pos++; // Skip '('
        auto leftResult = evaluateExpression(expr, matrixMap, pos);
        while (expr[pos] == ' ') pos++; // Skip spaces
        auto rightResult = evaluateExpression(expr, matrixMap, pos);
        while (expr[pos] == ' ') pos++; // Skip spaces
        pos++; // Skip ')'

        // Check for errors in sub-expressions
        if (leftResult.first == -1 || rightResult.first == -1) {
            return { -1, {0, 0} };
        }

        if (leftResult.second.cols != rightResult.second.rows) {
            return { -1, {0, 0} }; // Error due to non-matching dimensions
        }

        int multiplications = leftResult.first + rightResult.first + leftResult.second.rows * leftResult.second.cols * rightResult.second.cols;
        Matrix resultMatrix = { leftResult.second.rows, rightResult.second.cols };

        return { multiplications, resultMatrix };
    } else {
        char matrixName = expr[pos];
        pos++; // Move to next character
        if (matrixMap.find(matrixName) == matrixMap.end()) {
            return { -1, {0, 0} }; // Error if matrix not found
        }
        return { 0, matrixMap.at(matrixName) };
    }
}

int main() {
    int n;
    cin >> n;
    
    unordered_map<char, Matrix> matrixMap;
    for (int i = 0; i < n; ++i) {
        char name;
        int rows, cols;
        cin >> name >> rows >> cols;
        matrixMap[name] = { rows, cols };
    }

    cin.ignore(); // Ignore the newline after the last matrix definition

    string line;
    while (getline(cin, line)) {
        int pos = 0;
        auto result = evaluateExpression(line, matrixMap, pos);
        if (result.first == -1) {
            cout << "error" << endl;
        } else {
            cout << result.first << endl;
        }
    }

    return 0;
}