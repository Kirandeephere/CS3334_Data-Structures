#include <iostream>
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
    int key;                // Key of the entry
    int value;              // Value associated with the key
    HashEntry* next;        // Pointer to the next entry in the linked list
};

// Define the linked list structure
class LinkedList {
public:
    HashEntry* head;        // Pointer to the first entry in the linked list

    LinkedList() : head(nullptr) {}

    // Function to insert a key-value pair into the linked list
    void insert(int key, int value) {
        HashEntry* newEntry = new HashEntry;
        newEntry->key = key;
        newEntry->value = value;
        newEntry->next = head;
        head = newEntry;
    }

    // Function to search for a key in the linked list and return its value
    int search(int key) {
        HashEntry* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1; // Key not found
    }

    // Function to remove a key from the linked list
    void remove(int key) {
        HashEntry* current = head;
        HashEntry* prev = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
};

// Define the hash table itself
class HashMap {
private:
    LinkedList* table[TABLE_SIZE];  // Array of linked lists to store key-value pairs

public:
    // Constructor to initialize the hash table
    HashMap() {
        // Initialize all entries in the hash table to empty linked lists
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = new LinkedList;
        }
    }

    // Hash function to map keys to indexes
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // Function to insert a key-value pair into the hash table
    void insert(int key, int value) {
        int index = hashFunction(key);
        table[index]->insert(key, value);
    }

    // Function to retrieve the value associated with a given key
    int get(int key) {
        int index = hashFunction(key);
        return table[index]->search(key);
    }

    // Function to remove a key-value pair from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        table[index]->remove(key);
    }

    // Function to display the contents of the hash table
    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "Index " << i << ": ";
            HashEntry* current = table[i]->head;
            while (current != nullptr) {
                cout << "[" << current->key << "," << current->value << "] ";
                current = current->next;
            }
            cout << endl;
        }
        cout << endl;
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
    cout << endl << "Hash Table Contents:\n";
    hashMap.display();

    // Retrieve and display values for some keys
    cout << "Value for key 1: " << hashMap.get(1) << endl;
    cout << "Value for key 2: " << hashMap.get(2) << endl;
    cout << "Value for key 11: " << hashMap.get(11) << endl;
    cout << "Value for key 21: " << hashMap.get(21) << endl;

    // Remove a key-value pair and display the updated hash table
    hashMap.remove(2);
    cout << endl << "After removing key 2:\n";
    hashMap.display();

    cout << endl;

    return 0;
}


/*
Sample Output:
    Hash Table Contents:
    Index 0: 
    Index 1: [21,50] [11,40] [1,10] 
    Index 2: [2,20] 
    Index 3: [3,30] 
    Index 4: 
    Index 5: 
    Index 6: 
    Index 7: 
    Index 8: 
    Index 9: 

    Value for key 1: 10
    Value for key 2: 20
    Value for key 11: 40
    Value for key 21: 50

    After removing key 2:
    Index 0: 
    Index 1: [21,50] [11,40] [1,10] 
    Index 2: 
    Index 3: [3,30] 
    Index 4: 
    Index 5: 
    Index 6: 
    Index 7: 
    Index 8: 
    Index 9: 
*/