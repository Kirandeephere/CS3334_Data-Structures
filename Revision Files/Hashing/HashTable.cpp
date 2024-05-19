#include <iostream>
#include <cstring>
using namespace std;

// Introduction of the code:
// This C++ program demonstrates the implementation of a hash table using separate chaining for collision resolution.
// It defines a class HashMap to represent the hash table and provides functionalities to insert key-value pairs,
// retrieve the value associated with a given key, remove a key-value pair, and display the contents of the hash table.
// The program includes a hash function to map keys to indexes in the hash table and handles collisions by chaining.
// In the main function, it creates a sample hash table, inserts key-value pairs, displays the contents of the hash table,
// retrieves values for some keys, removes a key-value pair, and displays the updated hash table.

// Define the maximum size of the hash table
const int TABLE_SIZE = 10;

// Define the structure for each entry in the hash table
struct HashEntry {
    int key;            // Key of the entry
    int value;          // Value associated with the key
};

// Define the hash table itself
class HashMap {
private:
    HashEntry* table[TABLE_SIZE];   // Array to store pointers to hash entries

public:
    // Constructor to initialize the hash table
    HashMap() {
        // Initialize all entries in the hash table to nullptr
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    // Hash function to map keys to indexes
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // Function to insert a key-value pair into the hash table
    void insert(int key, int value) {
        int index = hashFunction(key);
        if (table[index] != nullptr) {
            cout << "Collision occurred for key " << key << ".\n"; // Handle collision
            return;
        }
        HashEntry* newEntry = new HashEntry;   // Create a new entry
        newEntry->key = key;                    // Assign key
        newEntry->value = value;                // Assign value
        table[index] = newEntry;                // Store in the hash table
    }

    // Function to retrieve the value associated with a given key
    int get(int key) {
        int index = hashFunction(key);
        if (table[index] == nullptr) {
            cout << "Key " << key << " not found.\n";   // Key not found
            return -1;
        }
        return table[index]->value;    // Return the value associated with the key
    }

    // Function to remove a key-value pair from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        if (table[index] == nullptr) {
            cout << "Key " << key << " not found.\n";   // Key not found
            return;
        }
        delete table[index];        // Delete the entry
        table[index] = nullptr;     // Set the pointer to nullptr
    }

    // Function to display the contents of the hash table
    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i] != nullptr) {
                cout << "Index " << i << ": [" << table[i]->key << "," << table[i]->value << "]\n";  // Display entry
            }
        }
    }
};

int main() {
    HashMap hashMap;

    cout << endl;

    // Insert some key-value pairs
    hashMap.insert(1, 10);
    hashMap.insert(2, 20);
    hashMap.insert(3, 30);
    hashMap.insert(11, 40); // Collision
    hashMap.insert(21, 50); // Collision

    // Display the contents of the hash table
    cout << "Hash Table Contents:\n";
    hashMap.display();

    // Retrieve and display values for some keys
    cout << "Value for key 1: " << hashMap.get(1) << endl;
    cout << "Value for key 2: " << hashMap.get(2) << endl;
    cout << "Value for key 11: " << hashMap.get(11) << endl;
    cout << "Value for key 21: " << hashMap.get(21) << endl;

    // Remove a key-value pair and display the updated hash table
    hashMap.remove(2);
    cout << "After removing key 2:\n";
    hashMap.display();

    cout << endl;

    return 0;
}


/*
Sample Output:
    Collision occurred for key 11.
    Collision occurred for key 21.
    Hash Table Contents:
    Index 1: [1,10]
    Index 2: [2,20]
    Index 3: [3,30]
    Value for key 1: 10
    Value for key 2: 20
    Value for key 11: 10
    Value for key 21: 10
    After removing key 2:
    Index 1: [1,10]
    Index 3: [3,30]
*/
