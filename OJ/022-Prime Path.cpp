/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293022
 * Submitted at:  2024-06-17 10:58:15
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    22
 * Problem Name:  Prime Path
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <string>
#include <unordered_set>

using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Function to generate all 4-digit primes
unordered_set<int> generateFourDigitPrimes() {
    unordered_set<int> primes;
    for (int i = 1000; i <= 9999; ++i) {
        if (isPrime(i)) {
            primes.insert(i);
        }
    }
    return primes;
}

// Function to get all prime neighbors of a given prime
vector<int> getPrimeNeighbors(int prime, const unordered_set<int>& primeSet) {
    vector<int> neighbors;
    string primeStr = to_string(prime);

    for (int i = 0; i < 4; ++i) {
        char originalDigit = primeStr[i];
        for (char digit = '0'; digit <= '9'; ++digit) {
            if (digit == originalDigit) continue;
            primeStr[i] = digit;
            int newPrime = stoi(primeStr);
            if (primeSet.find(newPrime) != primeSet.end()) {
                neighbors.push_back(newPrime);
            }
        }
        primeStr[i] = originalDigit;
    }

    return neighbors;
}

// BFS to find the shortest path between two primes
int bfs(int start, int goal, const unordered_set<int>& primeSet) {
    queue<pair<int, int>> q;
    set<int> visited;

    q.push(make_pair(start, 0));
    visited.insert(start);

    while (!q.empty()) {
        pair<int, int> front = q.front();
        int current = front.first;
        int cost = front.second;
        q.pop();

        if (current == goal) {
            return cost;
        }

        for (int neighbor : getPrimeNeighbors(current, primeSet)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(make_pair(neighbor, cost + 1));
            }
        }
    }

    return -1;  // If no path found
}

int main() {
    int testCases;
    cin >> testCases;

    unordered_set<int> primeSet = generateFourDigitPrimes();

    while (testCases--) {
        int start, goal;
        cin >> start >> goal;

        int cost = bfs(start, goal, primeSet);
        if (cost == -1) {
            cout << "Impossible" << endl;
        } else {
            cout << cost << endl;
        }
    }

    return 0;
}