#include <iostream>
using namespace std;

const int MAX = 1000000; // 10^6

int main() {
    int size;
    while (cin >> size) {
        bool present[MAX] = {false}; 

        for (int i = 0; i < size; i++) {
            int num;
            cin >> num;
            if (num >= 0 && num < MAX) {
                present[num] = true; 
            }
        }

        int smallest_number = 0;
        while (present[smallest_number]) {
            smallest_number++;
        }

        cout << smallest_number << endl;
    }

    return 0;
}