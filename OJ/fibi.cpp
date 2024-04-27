#include <iostream>
#include <algorithm>

using namespace std;

// Function to generate the Fibonacci sequence modulo Q
void generateFibonacci(long long fib[], int n, int Q) {
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % Q;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, Q;
        cin >> n >> Q;

        long long fib[n + 1];
        generateFibonacci(fib, n, Q);

        long long sortedFib[n];
        for (int i = 1; i <= n; ++i) {
            sortedFib[i - 1] = fib[i];
        }

        sort(sortedFib, sortedFib + n);

        long long weightedSum = 0;
        for (int i = 0; i < n; ++i) {
            weightedSum = (weightedSum + (i + 1) * sortedFib[i]) % Q;
        }

        cout << weightedSum << endl;
    }

    return 0;
}
