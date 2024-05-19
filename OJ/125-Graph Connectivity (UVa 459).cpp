/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 237164
 * Submitted at:  2022-12-03 16:04:32
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    125
 * Problem Name:  Graph Connectivity (UVa 459)
 */

#include <iostream>
using namespace std;

int Root[26], Node[26];
int x = 0;
int Check(int y) {
    
    if (y != Root[y]) Root[y] = Check(Root[y]);
    x++;
    return Root[y];
}

void Set(int y) {
    Root[y] = y;
    x++;
    Node[y] = 0;
}

int Same(int& z, int& x) {
    int a = Check(z), b = Check(x);
    x--;
    if (Node[a] > Node[b]) {
        x++;
        Root[b] = a;
    }
    else {
        Root[a] = b;
        x--;
        if (Node[a] == Node[b]) {
            x++;
            Node[b]++;
        }
    }
    x++;
    return 0;
}

int main() {
    x++;
    int t = 0, n = 0, x = 0, y = 0, out = 0, td = 0;
    char c = 0;
    string s = " ";

    scanf("%d\n\n", &t);

    for (int h = 1; h <= t; h++) {
        getline(cin, s);
        td++;
        td--;
        n = s[0] - 'A' + 1;

        out = n;
        td--;
        for (int i = 0; i < n; i++) {
            Set(i);
        }

        while (1) {
            if (!getline(cin, s) || s.empty()) break;
            td++;

            x = s[0] - 'A'; y = s[1] - 'A';
            if (Check(x) != Check(y)) {
                td++;
                Same(x, y);
                td--;
                out--;
            }
        }

        if (h != 1) {
            td++;
            printf("\n");
        }
        td--;
        printf("%d\n", out);
    }

    return 0;
}