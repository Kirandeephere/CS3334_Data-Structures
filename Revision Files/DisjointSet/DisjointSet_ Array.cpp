#include <iostream>
#include <cstring>

using namespace std;

/**
 * Disjoint Set (Union-Find) Implementation using Array Representation in C++
 * 
 * This code provides a simple implementation of the disjoint set data structure (also known as Union-Find).
 * Disjoint sets are used to maintain a collection of disjoint sets and efficiently perform operations like merging sets and finding the set to which an element belongs.
 * The DisjointSet class supports operations like find, merge, getSize, and getSetCount.
 */

class DisjointSet {
private:
    int *parent;    // Array to store the parent of each element
    int *rank;      // Array to store the rank of each element's subtree
    int *setSize;   // Array to store the size of each set
    int totalSets;  // Total number of disjoint sets

public:
    // Constructor to initialize a disjoint set with n elements
    DisjointSet(int n) {
        totalSets = n;
        parent = new int[n];
        rank = new int[n];
        setSize = new int[n];
        memset(rank, 0, sizeof(int) * n);  // Initialize rank array to 0
        memset(setSize, 1, sizeof(int) * n); // Initialize setSize array to 1 (each element is initially in its own set)

        // Initializing each element as a parent of itself
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Destructor to deallocate memory
    ~DisjointSet() {
        delete[] parent;
        delete[] rank;
        delete[] setSize;
    }

    // Find operation with path compression
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    // Union operation
    void merge(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) return; // Already in the same set

        // Union by rank
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
            setSize[rootV] += setSize[rootU];
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
            setSize[rootU] += setSize[rootV];
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
            setSize[rootU] += setSize[rootV];
        }
        totalSets--;
    }

    // Get the size of the set containing element u
    int getSize(int u) {
        int root = find(u);
        return setSize[root];
    }

    // Get the total number of disjoint sets
    int getSetCount() {
        return totalSets;
    }
};

int main() {

    cout << endl;

    int n = 6; // Number of elements
    DisjointSet ds(n);

    // Example usage
    ds.merge(0, 1);
    ds.merge(1, 2);
    ds.merge(3, 4);
    ds.merge(4, 5);

    // Test if elements belong to the same set
    cout << "0 and 2 are in the same set: " << (ds.find(0) == ds.find(2)) << endl;
    cout << "0 and 4 are in the same set: " << (ds.find(0) == ds.find(4)) << endl;

    // Merge sets and get information
    ds.merge(0, 3);
    cout << "Set size after merging: " << ds.getSize(0) << endl;
    cout << "Number of disjoint sets: " << ds.getSetCount() << endl;

    cout << endl;

    return 0;
}

/*
Sample Output:
    0 and 2 are in the same set: 1
    0 and 4 are in the same set: 0
    Set size after merging: 101058054
    Number of disjoint sets: 1
*/