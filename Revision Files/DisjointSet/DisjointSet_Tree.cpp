#include <iostream>
#include <cstring>

using namespace std;

/**
 * Disjoint Set (Union-Find) Implementation using Tree Representation in C++
 * 
 * This code provides an implementation of the disjoint set data structure (also known as Union-Find).
 * Disjoint sets are used to maintain a collection of disjoint sets and efficiently perform operations like merging sets and finding the set to which an element belongs.
 * The DisjointSet class supports operations like find, merge, and printing the tree-like structure.
 */

class DisjointSet {
private:
    int *parent;    // Array to store the parent of each element
    int *rank;      // Array to store the rank of each element's subtree
    int size;       // Number of elements in the disjoint set

public:
    // Constructor to initialize a disjoint set with n elements
    DisjointSet(int n) {
        size = n;
        parent = new int[n];
        rank = new int[n];
        memset(rank, 0, sizeof(int) * n);  // Initialize rank array to 0

        // Initializing each element as a parent of itself
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Destructor to deallocate memory
    ~DisjointSet() {
        delete[] parent;
        delete[] rank;
    }

    // Find operation with path compression
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    // Union operation by rank (Union-by-Rank)
    void merge(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) return; // Already in the same set

        // Union by rank
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }

    // Print the tree-like structure
    void printTree() {
        for (int i = 0; i < size; ++i) {
            if (parent[i] == i) {
                cout << "├──" << i << endl;
                printSubTree(i, 1);
            }
        }
    }

    // Helper function to print subtree recursively
    void printSubTree(int root, int depth) {
        for (int i = 0; i < size; ++i) {
            if (find(i) == root && parent[i] != i) {
                for (int j = 0; j < depth; ++j) {
                    cout << "│   ";
                }
                cout << "├──" << i << endl;
                printSubTree(i, depth + 1);
            }
        }
    }
};

int main() {
    cout << endl;

    int n = 11; // Number of elements
    DisjointSet ds(n);

    // Example usage
    ds.merge(3, 7);
    ds.merge(7, 10);
    ds.merge(7, 8);
    ds.merge(3, 9);
    ds.merge(4, 3);

    // Print the tree-like structure
    cout << "Tree Structure: " << endl;
    ds.printTree();

    cout << endl;

    // Test find operation
    cout << "Finding root of 10: " << ds.find(10) << endl;
    cout << "Finding root of 4: " << ds.find(4) << endl;
    cout << "Finding root of 3: " << ds.find(3) << endl;
    cout << "Finding root of 5: " << ds.find(5) << endl; // Element not in any set

    cout << endl;

    return 0;
}

/*
Sample Output:
    Tree Structure: 
    ├──0
    ├──1
    ├──2
    ├──3
    │   ├──4
    │   ├──7
    │   ├──8
    │   ├──9
    │   ├──10
    ├──5
    ├──6

    Finding root of 10: 3
    Finding root of 4: 3
    Finding root of 3: 3
    Finding root of 5: 5
*/