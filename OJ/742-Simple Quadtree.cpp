/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293002
 * Submitted at:  2024-06-07 23:29:59
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    742
 * Problem Name:  Simple Quadtree
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    bool isLeaf;
    Node *children[4];

    Node() {
        isLeaf = true;
        for (int i = 0; i < 4; ++i) {
            children[i] = nullptr;
        }
    }
};

int buildQuadtree(vector<string>& image, int x, int y, int size) {
    if (size == 1) {
        return 1;
    }

    // Check if all pixels in the area are the same color
    char color = image[x][y];
    bool sameColor = true;
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (image[i][j] != color) {
                sameColor = false;
                break;
            }
        }
        if (!sameColor) {
            break;
        }
    }

    if (sameColor) {
        return 1;
    }

    // If colors are different, recursively divide the area into quadrants
    int mid = size / 2;
    int totalNodes = 1; // Current node (root)
    totalNodes += buildQuadtree(image, x, y, mid); // NW quadrant
    totalNodes += buildQuadtree(image, x, y + mid, mid); // NE quadrant
    totalNodes += buildQuadtree(image, x + mid, y, mid); // SW quadrant
    totalNodes += buildQuadtree(image, x + mid, y + mid, mid); // SE quadrant

    return totalNodes;
}

int main() {
    int k;
    while (cin >> k) {
        int n = 1 << k;
        vector<string> image(n);
        for (int i = 0; i < n; ++i) {
            cin >> image[i];
        }
        cout << buildQuadtree(image, 0, 0, n) << endl;
    }
    return 0;
}