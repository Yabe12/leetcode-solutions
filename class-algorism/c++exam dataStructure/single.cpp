#include <iostream>
#include <cstring> 
using namespace std;

struct Node {
    int id;  
    char data[50];  
    Node* next;
};

Node* head = nullptr; 

void insertById(int id, const char* data) {
    Node* newNode = new Node;
    newNode->id = id;
    strncpy(newNode->data, data, sizeof(newNode->data) - 1);  
    newNode->data[sizeof(newNode->data) - 1] = '\0';  
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
    display();  

    searchById(2);  
    deleteById(2);
    display();  
    searchById(2);  

    return 0;
}
