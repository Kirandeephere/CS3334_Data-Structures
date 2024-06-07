/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 292983
 * Submitted at:  2024-06-07 21:30:54
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    2
 * Problem Name:  Output format
 */

#include <cstdio>

int main() {
    int number;
    bool first = true;

    while (scanf("%d", &number) != EOF) {
        if (!first) {
            printf("\n");
        }
        printf("%d\n", number);
        first = false;
    }

    return 0;
}