/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293060
 * Submitted at:  2024-06-24 16:15:04
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    158
 * Problem Name:  Humble Numbers (UVa 443)
 */

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

// Function to determine the correct suffix for ordinal numbers
string getOrdinalSuffix(int n) {
    if (n % 100 / 10 == 1) {  // 11th, 12th, 13th, ...
        return "th";
    }
    if (n % 10 == 1) {
        return "st";
    } else if (n % 10 == 2) {
        return "nd";
    } else if (n % 10 == 3) {
        return "rd";
    } else {
        return "th";
    }
}

// Function to generate humble numbers up to the given limit
vector<long long> generateHumbleNumbers(int limit) {
    vector<long long> humbleNumbers;
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    unordered_set<long long> seen;
    vector<int> primes = {2, 3, 5, 7};
    
    minHeap.push(1);
    seen.insert(1);

    while (humbleNumbers.size() < limit) {
        long long curr = minHeap.top();
        minHeap.pop();
        humbleNumbers.push_back(curr);

        for (int prime : primes) {
            long long next = curr * prime;
            if (seen.find(next) == seen.end()) {
                minHeap.push(next);
                seen.insert(next);
            }
        }
    }
    
    return humbleNumbers;
}

int main() {
    const int MAX_N = 5842;  // We precompute up to the 5842nd humble number
    vector<long long> humbleNumbers = generateHumbleNumbers(MAX_N);

    int n;
    while (cin >> n && n != 0) {
        cout << "The " << n << getOrdinalSuffix(n) << " humble number is " << humbleNumbers[n - 1] << "." << endl;
    }

    return 0;
}