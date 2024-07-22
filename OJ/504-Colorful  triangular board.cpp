/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293114
 * Submitted at:  2024-07-22 12:52:02
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    504
 * Problem Name:  Colorful  triangular board
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Helper function to count the frequency of each color in a string
unordered_map<char, int> getColorFrequency(const string& s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        if (c != '*') {
            freq[c]++;
        }
    }
    return freq;
}

// Function to check if init can be transformed into goal with the given repaint limit
int minRepaints(string init, const string& goal) {
    unordered_map<char, int> initFreq = getColorFrequency(init);
    unordered_map<char, int> goalFreq = getColorFrequency(goal);
    
    int repaints = 0;
    
    // Calculate the number of repaints needed
    for (auto& pair : goalFreq) {
        char color = pair.first;
        int goalCount = pair.second;
        int initCount = initFreq[color];
        
        if (initCount < goalCount) {
            repaints += (goalCount - initCount);
        }
    }
    
    return repaints;
}

int main() {
    string init, goal;
    int testCaseNumber = 1;
    
    while (cin >> init >> goal) {
        cout << "Case #" << testCaseNumber << ": ";
        
        unordered_map<char, int> initFreq = getColorFrequency(init);
        unordered_map<char, int> goalFreq = getColorFrequency(goal);
        
        bool solvable = true;
        for (auto& pair : goalFreq) {
            char color = pair.first;
            int goalCount = pair.second;
            int initCount = initFreq[color];
            
            if (initCount < goalCount) {
                solvable = false;
                break;
            }
        }
        
        if (solvable) {
            cout << 0 << endl;
        } else {
            cout << minRepaints(init, goal) << endl;
        }
        
        ++testCaseNumber;
    }
    
    return 0;
}