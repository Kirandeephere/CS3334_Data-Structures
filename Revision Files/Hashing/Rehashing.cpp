#include <iostream>
using namespace std;

// Introduction of the code:
// This C++ program demonstrates the implementation of a hash table using separate chaining for collision resolution
// and rehashing for dynamic resizing. It defines a class HashMap to represent the hash table and provides functionalities
// to insert key-value pairs, retrieve the value associated with a given key, remove a key-value pair, display the contents
// of the hash table, and rehash the table when its load factor exceeds a certain threshold. The program includes a hash function
// to map keys to indexes in the hash table and handles collisions by chaining. In the main function, it creates a sample hash
// table, inserts key-value pairs, displays the contents of the hash table, retrieves values for some keys, removes a key-value
// pair, performs rehashing, and displays the updated hash table.

// Define the initial size and the factor by which the table will be resized
const int INITIAL_SIZE = 10;
const int RESIZE_FACTOR = 2;

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
    LinkedList** table;     // Pointer to an array of pointers to linked lists
    int size;               // Current size of the hash table

public:
    HashMap() {
        size = INITIAL_SIZE;
        table = new LinkedList*[size];
        for (int i = 0; i < size; ++i) {
            table[i] = new LinkedList;
        }
    }

    // Hash function to map keys to indexes
    int hashFunction(int key) {
        return key % size;
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
        for (int i = 0; i < size; ++i) {
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

    // Function to rehash the table with a new size
    void rehash() {
        int newSize = size * RESIZE_FACTOR;
        LinkedList** newTable = new LinkedList*[newSize];
        for (int i = 0; i < newSize; ++i) {
            newTable[i] = new LinkedList;
        }

        // Move entries from the old table to the new table
        for (int i = 0; i < size; ++i) {
            HashEntry* current = table[i]->head;
            while (current != nullptr) {
                int newIndex = current->key % newSize;
                newTable[newIndex]->insert(current->key, current->value);
                HashEntry* temp = current;
                current = current->next;
                delete temp; // Free memory of the entry moved to the new table
            }
            delete table[i]; // Free memory of the linked list in the old table
        }

        delete[] table; // Free memory of the old table
        table = newTable; // Update table pointer to point to the new table
        size = newSize; // Update size of the table
    }

    // Destructor to free memory
    ~HashMap() {
        for (int i = 0; i < size; ++i) {
            delete table[i];
        }
        delete[] table;
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

    // Perform rehashing
    hashMap.rehash();
    cout << endl << "After rehashing:\n";
    hashMap.display();

    cout << endl;

    return 0;
}
