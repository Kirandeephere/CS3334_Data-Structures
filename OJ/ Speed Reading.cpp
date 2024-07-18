/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293109
 * Submitted at:  2024-07-18 13:01:39
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    269
 * Problem Name:  Speed Reading
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    for (int i = 0; i < K; ++i) {
        int Si, Ti, Ri;
        cin >> Si >> Ti >> Ri;
        
        // Pages read in one reading session
        int pagesPerSession = Si * Ti;
        
        // Number of complete sessions required
        int fullSessions = N / pagesPerSession;
        
        // Remaining pages to read after full sessions
        int remainingPages = N % pagesPerSession;
        
        // Total time for full sessions (including rests)
        int totalTime = fullSessions * (Ti + Ri);
        
        // Time for the remaining pages
        if (remainingPages > 0) {
            // It will take one more reading session to complete the remaining pages
            totalTime += ceil(1.0 * remainingPages / Si);
        } else {
            // If there are no remaining pages, subtract the last rest time
            totalTime -= Ri;
        }
        
        // Print the total time required for this cow
        cout << totalTime << endl;
    }
    
    return 0;
}