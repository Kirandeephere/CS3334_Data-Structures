/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293052
 * Submitted at:  2024-06-24 15:02:57
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    139
 * Problem Name:  Virtual Friends (UVa 11503)
 */

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

const int MAXN = 100001;

int parent[MAXN];
int size[MAXN];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

void union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX != rootY) {
        // Union by size
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
    }
    
    cout << size[rootX] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int f;
        cin >> f;
        
        // Reset DSU structures for each test case
        for (int i = 1; i < MAXN; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
        
        unordered_map<string, int> index;
        int currentIndex = 1;
        
        while (f--) {
            string person1, person2;
            cin >> person1 >> person2;
            
            if (index.count(person1) == 0) {
                index[person1] = currentIndex++;
            }
            if (index.count(person2) == 0) {
                index[person2] = currentIndex++;
            }
            
            int id1 = index[person1];
            int id2 = index[person2];
            
            union_sets(id1, id2);
        }
    }
    
    return 0;
}