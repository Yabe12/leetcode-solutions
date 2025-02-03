#include <iostream>
#include <string>
using namespace std;

// Structure for a Student node in a doubly linked list (used as a stack)
struct Student {
    int id;
    string name;
    Student* next;
    Student* prev;
};

// Push a student onto the stack (insert at the top)
void push(Student*& top) {
    int id;
    string name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;

    // Create a new node
    Student* newNode = new Student;
    newNode->id = id;
    newNode->name = name;
    newNode->next = top;
    newNode->prev = nullptr;  // New node will be the new top so no previous node

    // If the stack is not empty, update the previous pointer of the old top
    if (top != nullptr) {
        top->prev = newNode;
    }

    top = newNode;  // Update the top pointer

    cout << "Student pushed: " << name << " (ID: " << id << ")\n";
}

// Pop a student from the stack (remove from the top)
void pop(Student*& top) {
    if (!top) {
        cout << "Stack is empty!\n";
        return;
    }

    Student* temp = top;
    top = top->next;  // Move top pointer down

    // If there's a new top, update its prev pointer to nullptr
    if (top != nullptr) {
        top->prev = nullptr;
    }

    cout << "Popped student: " << temp->name << " (ID: " << temp->id << ")\n";
    delete temp;
}

// Display the stack from top to bottom
void display(Student* top) {
    if (!top) {
        cout << "Stack is empty!\n";
        return;
    }

    cout << "Students in stack (Top to Bottom):\n";
    Student* temp = top;
    while (temp) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << "\n";
        temp = temp->next;
    }
}

// Search for a student by ID
void searchById(Student* top, int id) {
    Student* temp = top;
    while (temp) {
        if (temp->id == id) {
            cout << "Student found: ID: " << temp->id << ", Name: " << temp->name << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student with ID " << id << " not found.\n";
}

// Reverse the stack
// For a doubly linked list, we can swap the next and prev pointers for each node.
// After processing, update the top pointer to point to what was originally the bottom node.
void reverseStack(Student*& top) {
    if (!top) {
        cout << "Stack is empty!\n";
        return;
    }

    Student* current = top;
    Student* temp = nullptr;

    // Traverse through the list and swap next and prev for each node
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        // Move to the next node in the original order (which is current->prev after swap)
        current = current->prev;
    }

    // After the loop, temp points to the node before NULL.
    // That node's previous pointer (after swap) is the new top.
    if (temp) {
        top = temp->prev;
    }

    cout << "Stack reversed.\n";
}

// Main function
int main() {
    Student* top = nullptr;
    int choice, id;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push Student\n";
        cout << "2. Pop Student\n";
        cout << "3. Display Stack\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Reverse Stack\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                push(top);
                break;
            case 2:
                pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                cout << "Enter ID to search: ";
                cin >> id;
                searchById(top, id);
                break;
            case 5:
                reverseStack(top);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    // Clean up any remaining nodes to avoid memory leaks.
    while (top) {
        pop(top);
    }

    return 0;
}
