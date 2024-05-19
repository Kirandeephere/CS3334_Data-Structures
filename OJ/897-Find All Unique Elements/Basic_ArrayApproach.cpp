#include <iostream>
#include <sstream>
using namespace std;

const int MAX_SIZE = 10000;

void findUnique(int numbers[], int size, int unique[], int& uniqueSize) {
    for (int i = 0; i < size; ++i) {
        int count = 0;
        for (int j = 0; j < size; ++j) {
            if (i != j && numbers[i] == numbers[j]) {
                count++;
                break;
            }
        }
        if (count == 0) {
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

        int unique[MAX_SIZE] = {0}; 
        int uniqueSize = 0;

        findUnique(numbers, size, unique, uniqueSize);

        for (int i = 0; i < uniqueSize; ++i) {
          if(i==uniqueSize-1){
            cout << unique[i] ;
          }
          else{
            cout << unique[i] << " ";
          }
        }
        cout << endl;
        
        size = 0;
    }

    return 0;
}

3
analyze
initiates
split
14
when
a
nuclear
reaction
initiates
the
old
uranium
nucleus
will
split
into
n
n
m
m
two
nuclei
3
analyze
initiates
split
6
i
do
not
love
university
english