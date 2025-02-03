#include <iostream>
using namespace std;

// Structure to store student details
struct stack {
    int id;
    char name[20];
    stack* next;
} *start = NULL;

void push();
void pop();
void peak();
void display();
void searchById();
void reverseStack();

void push() {
    stack* temp = new stack;
    cout << "Enter the ID: ";
    cin >> temp->id;
    cout << "Enter the Name: ";
    cin >> temp->name;
    if (start == NULL) {
        start = temp;
        start->next = NULL;
    } else {
        temp->next = start;
        start = temp;
    }
    cout << "Student added: " << temp->name << " (ID: " << temp->id << ")\n";
}

void pop() {
    if (start == NULL) {
        cout << "Underflow\n";
    } else {
        stack* curr = start;
        start = start->next;
        cout << "Removed student: " << curr->name << " (ID: " << curr->id << ")\n";
        delete curr;
    }
}

void peak() {
    if (start == NULL) {
        cout << "No first element\n";
    } else {
        cout << "Top Student: " << start->id << " - " << start->name << "\n";
    }
}

void display() {
    if (start == NULL) {
        cout << "No element found\n";
    } else {
        cout << "Students in stack:\n";
        for (stack* i = start; i != NULL; i = i->next) {
            cout << "ID: " << i->id << ", Name: " << i->name << "\n";
        }
    }
}

void searchById() {
    if (start == NULL) {
        cout << "Stack is empty!\n";
        return;
    }
    int id;
    cout << "Enter ID to search: ";
    cin >> id;
    stack* temp = start;
    while (temp) {
        if (temp->id == id) {
            cout << "Student found: ID: " << temp->id << ", Name: " << temp->name << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student with ID " << id << " not found.\n";
}

void reverseStack() {
    stack* prev = NULL;
    stack* current = start;
    stack* next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
    cout << "Stack reversed.\n";
}

int main() {
    int choice;
    do {
        cout << "\nStack Operations\n";
        cout << "----------------------------\n";
        cout << "1) Push\n";
        cout << "2) Pop\n";
        cout << "3) Peak\n";
        cout << "4) Display\n";
        cout << "5) Search by ID\n";
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
                peak();
                break;
            case 4:
                display();
                break;
            case 5:
                searchById();
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
