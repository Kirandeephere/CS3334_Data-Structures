/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293007
 * Submitted at:  2024-06-07 23:46:20
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    745
 * Problem Name:  Poker
 */

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n;

        stack<int> cards;
        int max_card = 0;
        for (int i = 0; i < n; ++i) {
            int card;
            cin >> card;
            cards.push(card);
            max_card = max(max_card, card);
        }

        cin >> m;

        for (int i = 0; i < m; ++i) {
            char op;
            cin >> op;

            if (op == 'm') { // max operation
                cout << max_card << endl;
            } else if (op == 'r') { // remove operation
                int top_card = cards.top();
                cards.pop();
                if (top_card == max_card) {
                    max_card = 0;
                    stack<int> temp;
                    while (!cards.empty()) {
                        int temp_card = cards.top();
                        temp.push(temp_card);
                        max_card = max(max_card, temp_card);
                        cards.pop();
                    }
                    while (!temp.empty()) {
                        cards.push(temp.top());
                        temp.pop();
                    }
                }
            } else if (op == 'a') { // add operation
                int value;
                cin >> value;
                cards.push(value);
                max_card = max(max_card, value);
            }
        }
    }

    return 0;
}