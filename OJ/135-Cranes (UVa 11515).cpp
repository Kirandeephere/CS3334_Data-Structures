/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293050
 * Submitted at:  2024-06-24 14:44:08
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    135
 * Problem Name:  Cranes (UVa 11515)
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Crane {
    int x, y, r;
};

bool doCraneOverlap(const Crane& c1, const Crane& c2) {
    int dx = c1.x - c2.x;
    int dy = c1.y - c2.y;
    int distanceSquared = dx * dx + dy * dy;
    int radiiSum = c1.r + c2.r;
    return distanceSquared < radiiSum * radiiSum;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int C;
        cin >> C;
        vector<Crane> cranes(C);
        
        for (int i = 0; i < C; ++i) {
            cin >> cranes[i].x >> cranes[i].y >> cranes[i].r;
        }
        
        int maxArea = 0;
        int totalCombinations = 1 << C; // 2^C combinations
        
        for (int mask = 0; mask < totalCombinations; ++mask) {
            bool isValid = true;
            int area = 0;
            
            for (int i = 0; i < C && isValid; ++i) {
                if (mask & (1 << i)) {
                    for (int j = i + 1; j < C; ++j) {
                        if (mask & (1 << j)) {
                            if (doCraneOverlap(cranes[i], cranes[j])) {
                                isValid = false;
                                break;
                            }
                        }
                    }
                    if (isValid) {
                        area += cranes[i].r * cranes[i].r;
                    }
                }
            }
            
            if (isValid) {
                maxArea = max(maxArea, area);
            }
        }
        
        cout << maxArea << endl;
    }
    
    return 0;
}