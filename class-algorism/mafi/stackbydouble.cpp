#include <iostream>
using namespace std;

// Structure to store student details
struct Node {
    int id;
    char name[20];
    Node* prev;
    Node* next;
} *top = NULL;

void push();
void pop();
void display();
void searchById();
void sortStack();
void reverseStack();

void push() {
    Node* temp = new Node;
    cout << "Enter the ID: ";
    cin >> temp->id;
    cout << "Enter the Name: ";
    cin >> temp->name;
    temp->next = top;
    temp->prev = NULL;
    if (top != NULL) {
        top->prev = temp;
    }
    top = temp;
    cout << "Student added: " << temp->name << " (ID: " << temp->id << ")\n";
}

void pop() {
    if (top == NULL) {
        cout << "Underflow\n";
        return;
    }
    Node* temp = top;
    top = top->next;
    if (top != NULL) {
        top->prev = NULL;
    }
    cout << "Removed student: " << temp->name << " (ID: " << temp->id << ")\n";
    delete temp;
}

void display() {
    if (top == NULL) {
        cout << "No element found\n";
        return;
    }
    Node* temp = top;
    cout << "Students in Stack:\n";
    while (temp != NULL) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << "\n";
        temp = temp->next;
    }
}

void searchById() {
    if (top == NULL) {
        cout << "Stack is empty!\n";
        return;
    }
    int id;
    cout << "Enter ID to search: ";
    cin >> id;
    Node* temp = top;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Student found: ID: " << temp->id << ", Name: " << temp->name << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student with ID " << id << " not found.\n";
}

void sortStack() {
    if (top == NULL || top->next == NULL) {
        cout << "Stack is already sorted or empty.\n";
        return;
    }
    Node* current = top;
    Node* index = NULL;
    int tempId;
    char tempName[20];
    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->id > index->id) {
                tempId = current->id;
                strcpy(tempName, current->name);
                current->id = index->id;
                strcpy(current->name, index->name);
                index->id = tempId;
                strcpy(index->name, tempName);
            }
            index = index->next;
        }
        current = current->next;
    }
    cout << "Stack sorted by ID.\n";
}

void reverseStack() {
    if (top == NULL || top->next == NULL) {
        cout << "Nothing to reverse or only one element present.\n";
        return;
    }
    Node* temp = NULL;
    Node* current = top;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        top = temp->prev;
    }
    cout << "Stack reversed.\n";
}

int main() {
    int choice;
    do {
        cout << "\nStack Operations using Doubly Linked List\n";
        cout << "-----------------------------------------\n";
        cout << "1) Push\n";
        cout << "2) Pop\n";
        cout << "3) Display\n";
        cout << "4) Search by ID\n";
        cout << "5) Sort by ID\n";
        cout << "6) Reverse Stack\n";
        cout << "7) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                searchById();
                break;
            case 5:
                sortStack();
                break;
            case 6:
                reverseStack();
                break;
            case 7:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Please enter a valid choice.\n";
                break;
        }
    } while (choice != 7);

    return 0;
}
