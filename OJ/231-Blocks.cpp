/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293101
 * Submitted at:  2024-07-12 16:04:05
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    231
 * Problem Name:  Blocks
 */

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int C;
    cin >> C;

    for (int case_num = 1; case_num <= C; ++case_num) {
        int N;
        cin >> N;

        // Find minimum surface area
        int min_surface_area = INT_MAX;

        // Try to find dimensions a, b, c such that a * b * c >= N and minimize 2(ab + bc + ca)
        for (int a = 1; a <= sqrt(N); ++a) {
            if (N % a == 0) {
                for (int b = a; b <= sqrt(N / a); ++b) {
                    if ((N / a) % b == 0) {
                        int c = N / (a * b);
                        // Check if a * b * c >= N
                        if (a * b * c >= N) {
                            // Calculate surface area
                            int surface_area = 2 * (a*b + b*c + c*a);
                            if (surface_area < min_surface_area) {
                                min_surface_area = surface_area;
                            }
                        }
                    }
                }
            }
        }

        cout << min_surface_area << endl;
    }

    return 0;
}