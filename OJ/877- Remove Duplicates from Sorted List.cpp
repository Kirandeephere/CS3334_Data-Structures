/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293045
 * Submitted at:  2024-06-22 23:12:59
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    877
 * Problem Name:  Remove Duplicates from Sorted List
 */

#include <iostream>
#include <set>
#include <list>
#include <sstream>
#include <vector>

using namespace std;

// Function to remove duplicates and sort the linked list
list<int> removeDuplicatesAndSort(list<int> &inputList) {
    set<int> uniqueElements(inputList.begin(), inputList.end());
    list<int> result(uniqueElements.begin(), uniqueElements.end());
    return result;
}

int main() {
    string line;
    vector<string> results;

    // Read input until EOF
    while (getline(cin, line)) {
        list<int> inputList;
        stringstream ss(line);
        int number;
        
        // Reading numbers from the line
        while (ss >> number) {
            inputList.push_back(number);
        }

        // Remove duplicates and sort
        list<int> outputList = removeDuplicatesAndSort(inputList);
        
        // Prepare the result string
        stringstream result;
        for (auto it = outputList.begin(); it != outputList.end(); ++it) {
            if (it != outputList.begin()) {
                result << " ";
            }
            result << *it;
        }
        results.push_back(result.str());
    }

    // Print all results without extra newline
    for (size_t i = 0; i < results.size(); ++i) {
        cout << results[i];
        if (i != results.size() - 1) {
            cout << endl;
        }
    }

    return 0;
}