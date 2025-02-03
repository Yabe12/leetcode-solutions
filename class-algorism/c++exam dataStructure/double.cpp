#include <iostream>
#include <cstring>  
using namespace std;

struct Node {
    int id;   
    char data[50]; 
    Node* next;
    Node* prev;
};

Node* head = NULL; 

void insertById(int id, const char* data) {
    Node* newNode = new Node;
    newNode->id = id;
    strncpy(newNode->data, data, sizeof(newNode->data) - 1);
    newNode->data[sizeof(newNode->data) - 1] = '\0';  
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteById(int id) {
    if (head == NULL) return;

    if (head->id == id) {
        Node* toDelete = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete toDelete;
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }

    if (temp) {
        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        delete temp;
    }
}

void searchById(int id) {
    Node* temp = head;
    while (temp != NULL) {
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
    cout << "Current List: ";
    while (temp != NULL) {
        cout << "[ID: " << temp->id << ", Data: " << temp->data << "] <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void reverseDisplay() {
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        cout << "[ID: " << temp->id << ", Data: " << temp->data << "] <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void updateById(int id, const char* newData) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            strncpy(temp->data, newData, sizeof(temp->data) - 1);
            temp->data[sizeof(temp->data) - 1] = '\0';
            return;
        }
        temp = temp->next;
    }
    cout << "Node with ID " << id << " not found for update." << endl;
}

void reverseList() {
    Node *temp = NULL, *current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) head = temp->prev;
}

int main() {
    int choice, id;
    char data[50];
    do {
        cout << "\nDoubly Linked List Operations:\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Search Node\n";
        cout << "4. Display List\n";
        cout << "5. Reverse Display\n";
        cout << "6. Count Nodes\n";
        cout << "7. Update Node\n";
        cout << "8. Reverse List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Data: ";
                cin.ignore();
                cin.getline(data, 50);
                insertById(id, data);
                break;
            case 2:
                cout << "Enter ID to delete: ";
                cin >> id;
                deleteById(id);
                break;
            case 3:
                cout << "Enter ID to search: ";
                cin >> id;
                searchById(id);
                break;
            case 4:
                display();
                break;
            case 5:
                reverseDisplay();
                break;
            case 6:
                cout << "Total Nodes: " << countNodes() << endl;
                break;
            case 7:
                cout << "Enter ID to update: ";
                cin >> id;
                cout << "Enter new Data: ";
                cin.ignore();
                cin.getline(data, 50);
                updateById(id, data);
                break;
            case 8:
                reverseList();
                cout << "List reversed." << endl;
                break;
        }
    } while (choice != 9);
    return 0;
}
