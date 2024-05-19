#include <iostream>
#include <sstream>

using namespace std;

const int MAX_SIZE = 10000;
const int HASH_SIZE = 10000;

class Hash {
private:
    bool set[HASH_SIZE];
    int values[HASH_SIZE];
    
public:
    Hash() {
        for (int i = 0; i < HASH_SIZE; ++i) {
            set[i] = false;
            values[i] = 0;
        }
    }
    
    int hash(int key) {
        return (key % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
    }
    
    void insert(int key) {
        int index = hash(key);
        set[index] = true;
        values[index] = key;
    }

    void remove(int key) {
        int index = hash(key);
        set[index] = false;
    }

    bool contains(int key) {
        int index = hash(key);
        return set[index] && values[index] == key;
    }
};

void findUnique(int numbers[], int size, int unique[], int& uniqueSize) {
    Hash hashSet;
    Hash duplicateSet;
    
    for (int i = 0; i < size; ++i) {
        int value = numbers[i];
        

        if (hashSet.contains(value)) {
            duplicateSet.insert(value);
        } else {
            hashSet.insert(value);
        }
    }
    
    for (int i = 0; i < size; ++i) {
        int value = numbers[i];
        
        if (!duplicateSet.contains(value)) {
            unique[uniqueSize] = value;
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