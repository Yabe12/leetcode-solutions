#include <iostream>
#include <cstring>  // Falcon requires cstring for string manipulation
using namespace std;

struct Node {
    int id;   // Unique identifier for the node
    char data[50];  // Fixed-size character array for compatibility
    Node* next;
};

Node* head = nullptr;  // Global head pointer for the list

void insertById(int id, const char* data) {
    Node* newNode = new Node;
    newNode->id = id;
    strncpy(newNode->data, data, sizeof(newNode->data) - 1);  // Safe copy of string
    newNode->data[sizeof(newNode->data) - 1] = '\0';  // Null-terminate
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteById(int id) {
    if (head == nullptr) return;
    if (head->id == id) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->id != id) {
        temp = temp->next;
    }
    if (temp->next != nullptr) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

void searchById(int id) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) {
            cout << "Found Node with ID " << id << ": Data = " << temp->data << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Node with ID " << id << " not found." << endl;
}

void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "[ID: " << temp->id << ", Data: " << temp->data << "] -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insertById(1, "Alice");
    insertById(2, "Bob");
    insertById(3, "Charlie");
    display();  // Output: [ID: 1, Data: Alice] -> [ID: 2, Data: Bob] -> [ID: 3, Data: Charlie] -> NULL

    searchById(2);  // Output: Found Node with ID 2: Data = Bob
    deleteById(2);
    display();  // Output: [ID: 1, Data: Alice] -> [ID: 3, Data: Charlie] -> NULL
    searchById(2);  // Output: Node with ID 2 not found.

    return 0;
}
