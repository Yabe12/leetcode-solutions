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

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node* tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
}

void deleteById(int id) {
    if (head == NULL) return;
    
    Node* temp = head;
    do {
        if (temp->id == id) {
            if (temp->next == temp) {
                delete temp;
                head = NULL;
                return;
            }
            
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (temp == head) head = temp->next;
            delete temp;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void searchById(int id) {
    if (head == NULL) {
        cout << "Node with ID " << id << " not found." << endl;
        return;
    }

    Node* temp = head;
    do {
        if (temp->id == id) {
            cout << "Found Node with ID " << id << ": Data = " << temp->data << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    
    cout << "Node with ID " << id << " not found." << endl;
}

void display() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << "[ID: " << temp->id << ", Data: " << temp->data << "] <-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)" << endl;
}

void reverseDisplay() {
    if (head == NULL) return;
    
    Node* temp = head->prev;
    do {
        cout << "[ID: " << temp->id << ", Data: " << temp->data << "] <-> ";
        temp = temp->prev;
    } while (temp != head->prev);
    cout << "(head)" << endl;
}

int countNodes() {
    if (head == NULL) return 0;
    
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

void updateById(int id, const char* newData) {
    if (head == NULL) return;
    
    Node* temp = head;
    do {
        if (temp->id == id) {
            strncpy(temp->data, newData, sizeof(temp->data) - 1);
            temp->data[sizeof(temp->data) - 1] = '\0';
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Node with ID " << id << " not found for update." << endl;
}

void reverseList() {
    if (head == NULL) return;
    
    Node* current = head;
    Node* temp = NULL;
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != head);
    
    head = temp->prev;
}

int main() {
    int choice, id;
    char data[50];
    do {
        cout << "\nCircular Doubly Linked List Operations:\n";
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
