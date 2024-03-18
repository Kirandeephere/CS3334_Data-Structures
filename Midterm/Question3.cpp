#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    while (testcases != 0) {
        int n, m;
        cin >> n;
        cin >> m; // minimum 

        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        int finalsum = 0;
        int sum = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] == m) {
                count++;
            }

            if (count > 1) {
                sum = 0;
                count = 1;
            }

            sum += A[i];
            finalsum = max(finalsum, sum);
        }

        cout << finalsum << endl;
        testcases--;
    }


    return 0;
}