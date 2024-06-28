/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293062
 * Submitted at:  2024-06-24 16:21:46
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    160
 * Problem Name:  The Tower of Babylon (UVa 437)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Block {
    int x, y, z;

    Block(int x, int y, int z) : x(x), y(y), z(z) {}

    bool canPlaceOn(const Block &b) const {
        return (x < b.x && y < b.y);
    }
};

int main() {
    int n, caseNumber = 1;
    while (cin >> n && n > 0) {
        vector<Block> blocks;

        for (int i = 0; i < n; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            blocks.emplace_back(x, y, z);
            blocks.emplace_back(x, z, y);
            blocks.emplace_back(y, x, z);
            blocks.emplace_back(y, z, x);
            blocks.emplace_back(z, x, y);
            blocks.emplace_back(z, y, x);
        }

        sort(blocks.begin(), blocks.end(), [](const Block &a, const Block &b) {
            return a.x * a.y > b.x * b.y;
        });

        int m = blocks.size();
        vector<int> dp(m);

        int maxHeight = 0;
        for (int i = 0; i < m; ++i) {
            dp[i] = blocks[i].z;
            for (int j = 0; j < i; ++j) {
                if (blocks[i].canPlaceOn(blocks[j])) {
                    dp[i] = max(dp[i], dp[j] + blocks[i].z);
                }
            }
            maxHeight = max(maxHeight, dp[i]);
        }

        cout << "Case " << caseNumber++ << ": maximum height = " << maxHeight << endl;
    }

    return 0;
}