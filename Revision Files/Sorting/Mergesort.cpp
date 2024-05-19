#include <iostream>
using namespace std;

/**
 * Merge Sort Implementation for Linked List in C++
 * 
 * This code provides an implementation of the Merge Sort algorithm to sort a linked list of integers.
 * Merge Sort works by recursively dividing the linked list into halves until each sublist contains only one element.
 * Then, it merges the sorted sublists in a pairwise manner to obtain the final sorted linked list.
 * 
 * The main function demonstrates the usage of the Merge Sort algorithm by sorting a linked list of integers.
 */

// Linked list node structure
struct ListNode {
    int data;         // Data held by the node
    ListNode* next;   // Pointer to the next node in the list

    ListNode(int val) : data(val), next(nullptr) {} // Constructor to initialize node
};

// Merge two sorted linked lists
ListNode* merge(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2; // If the first list is empty, return the second list
    }
    if (l2 == nullptr) {
        return l1; // If the second list is empty, return the first list
    }

    ListNode* result = nullptr; // Initialize the result list
    if (l1->data <= l2->data) { // Compare data of the nodes
        result = l1; // Choose the smaller data node
        result->next = merge(l1->next, l2); // Recursively merge the next node
    } else {
        result = l2;
        result->next = merge(l1, l2->next);
    }
    return result; // Return the merged list
}

// Split the linked list into two halves
void split(ListNode* head, ListNode** firstHalf, ListNode** secondHalf) {
    ListNode* slow = head; // Slow pointer for finding the middle
    ListNode* fast = head->next; // Fast pointer for finding the middle

    // Move fast pointer two steps and slow pointer one step at a time
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *firstHalf = head; // First half starts from head
    *secondHalf = slow->next; // Second half starts from the next of slow
    slow->next = nullptr; // Terminate the first half
}

// Merge sort for linked list
void mergeSort(ListNode** head) {
    if (*head == nullptr || (*head)->next == nullptr) {
        return; // Base case: if head is null or there's only one element
    }

    ListNode* firstHalf = nullptr;
    ListNode* secondHalf = nullptr;
    split(*head, &firstHalf, &secondHalf); // Split the list into two halves

    mergeSort(&firstHalf); // Recursively sort the first half
    mergeSort(&secondHalf); // Recursively sort the second half

    *head = merge(firstHalf, secondHalf); // Merge the sorted halves
}

// Utility function to insert a node at the front of the linked list
void push(ListNode** head, int val) {
    ListNode* newNode = new ListNode(val); // Create a new node
    newNode->next = *head; // Point the new node to the current head
    *head = newNode; // Update head to the new node
}

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->data << " "; // Print data of each node
        head = head->next; // Move to the next node
    }
    cout << endl; // Print a new line at the end
}

// Driver code
int main() {
    ListNode* head = nullptr; // Initialize the head of the linked list

    cout << endl;

    // Push elements to the linked list
    push(&head, 5);
    push(&head, 3);
    push(&head, 8);
    push(&head, 1);
    push(&head, 6);

    cout << "Original Linked List: ";
    printList(head); // Print the original linked list

    mergeSort(&head); // Sort the linked list using Merge Sort

    cout << "Sorted Linked List: ";
    printList(head); // Print the sorted linked list

    cout << endl;
    
    return 0; // End of the program
}

/*
Sample Output:
Original Linked List: 6 1 8 3 5 
Sorted Linked List: 1 3 5 6 8 
*/
