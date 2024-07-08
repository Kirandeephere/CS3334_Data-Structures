/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293089
 * Submitted at:  2024-07-08 21:47:00
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    490
 * Problem Name:  One more symbol
 */

#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>
#include <stdexcept>

using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*')
        return 2;
    if (op == '+')
        return 1;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '*': return a * b;
        case '^': return pow(a, b);
    }
    return 0;
}

int evaluate(const string& tokens) {
    int i = 0;
    
    stack<int> values;
    stack<char> ops;
    
    while (i < tokens.length()) {
        if (isspace(tokens[i])) {
            i++;
            continue;
        }
        
        if (isdigit(tokens[i])) {
            int val = 0;
            while (i < tokens.length() && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        }
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                int val2 = values.top();
                values.pop();
                
                int val1 = values.top();
                values.pop();
                
                char op = ops.top();
                ops.pop();
                
                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
        i++;
    }
    
    while (!ops.empty()) {
        int val2 = values.top();
        values.pop();
        
        int val1 = values.top();
        values.pop();
        
        char op = ops.top();
        ops.pop();
        
        values.push(applyOp(val1, val2, op));
    }
    
    return values.top();
}

int main() {
    string expression;
    while (getline(cin, expression)) {
        try {
            int result = evaluate(expression);
            cout << result << endl;
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    return 0;
}