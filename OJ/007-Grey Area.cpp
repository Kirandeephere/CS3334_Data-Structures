/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293080
 * Submitted at:  2024-07-06 12:18:31
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    7
 * Problem Name:  Grey Area
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <sstream> 

using namespace std;

int main() {
    while (true) {
        int n, w;
        cin >> n >> w;
        if (n == 0 && w == 0) break;
        
        vector<int> values(n);
        for (int i = 0; i < n; ++i) {
            cin >> values[i];
        }

        int maxValue = *max_element(values.begin(), values.end());
        int numIntervals = (maxValue / w) + 1;

        vector<int> histogram(numIntervals, 0);
        for (int value : values) {
            histogram[value / w]++;
        }

        int maxFrequency = *max_element(histogram.begin(), histogram.end());
        
        double totalInk = 0.01; // fixed amount for lines and characters
        for (int i = 0; i < numIntervals; ++i) {
            double heightRatio = static_cast<double>(histogram[i]) / maxFrequency;
            double darknessLevel = static_cast<double>(numIntervals - 1 - i) / (numIntervals - 1);
            double barInk = heightRatio * darknessLevel;
            totalInk += barInk;
        }

        // Convert the totalInk to string with sufficient precision
        stringstream ss;
        ss << fixed << setprecision(15) << totalInk;
        string inkStr = ss.str();

        // Remove trailing zeros
        inkStr.erase(inkStr.find_last_not_of('0') + 1, string::npos);
        if (inkStr.back() == '.') {
            inkStr.pop_back();
        }

        // Print the result
        cout << inkStr << endl;
    }

    return 0;
}