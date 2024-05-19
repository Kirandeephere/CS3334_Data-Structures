#include <iostream>
#include <sstream>

using namespace std;

const int MAX_SIZE = 1000;

void findUnique(int numbers[], int size, int adjMatrix[][MAX_SIZE], int unique[], int& uniqueSize) {
    uniqueSize = 0;

    // Initialize adjacency matrix to 0
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            adjMatrix[i][j] = 0;
        }
    }

    // Build adjacency matrix
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (numbers[i] == numbers[j]) {
                adjMatrix[i][j] = 1;
                adjMatrix[j][i] = 1;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        bool isUnique = true;

        for (int j = 0; j < size; ++j) {
            if (adjMatrix[i][j] == 1) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            unique[uniqueSize] = numbers[i];
            ++uniqueSize;
        }
    }
}

int main() {
    int numbers[MAX_SIZE] = {0};
    int size = 0; 

    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int num;

        while (iss >> num && size < MAX_SIZE) {
            numbers[size] = num;
            ++size;
        }

        int adjMatrix[MAX_SIZE][MAX_SIZE] = {0};
        int unique[MAX_SIZE] = {0};
        int uniqueSize = 0;

        findUnique(numbers, size, adjMatrix, unique, uniqueSize);

        for (int i = 0; i < uniqueSize; ++i) {
            if (i == uniqueSize - 1) {
                cout << unique[i];
            } else {
                cout << unique[i] << " ";
            }
        }
        cout << endl;

        size = 0;
    }

    return 0;
}
