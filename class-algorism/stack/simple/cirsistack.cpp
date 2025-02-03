#include <iostream>
#include <string>
using namespace std;

// Structure for a Student node in a circular singly linked list (used as a stack)
struct Student {
    int id;
    string name;
    Student* next;
};

// Push a student onto the stack (insert at the top)
void push(Student*& top) {
    int id;
    string name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    
    // Create new node
    Student* newNode = new Student;
    newNode->id = id;
    newNode->name = name;
    
    if (top == nullptr) {
        // List is empty: new node points to itself.
        newNode->next = newNode;
        top = newNode;
    } else {
        // Find the tail node (node whose next points to top)
        Student* tail = top;
        while (tail->next != top) {
            tail = tail->next;
        }
        // Insert new node before the current top.
        newNode->next = top;  // new node points to old top
        tail->next = newNode; // tail now points to new node
        top = newNode;        // update top pointer to new node
    }
    cout << "Student pushed: " << name << " (ID: " << id << ")\n";
}

// Pop a student from the stack (remove from the top)
void pop(Student*& top) {
    if (top == nullptr) {
        cout << "Stack is empty!\n";
        return;
    }
    
    // If there's only one node in the stack
    if (top->next == top) {
        cout << "Popped student: " << top->name << " (ID: " << top->id << ")\n";
        delete top;
        top = nullptr;
    } else {
        // Find the tail node (node whose next points to top)
        Student* tail = top;
        while (tail->next != top) {
            tail = tail->next;
        }
        // Remove the top node.
        Student* temp = top;
        tail->next = top->next; // tail's next now points to the new top
        top = top->next;        // update top pointer
        cout << "Popped student: " << temp->name << " (ID: " << temp->id << ")\n";
        delete temp;
    }
}

// Display the stack from top to bottom
void display(Student* top) {
    if (top == nullptr) {
        cout << "Stack is empty!\n";
        return;
    }
    
    cout << "Students in stack (Top to Bottom):\n";
    Student* temp = top;
    do {
        cout << "ID: " << temp->id << ", Name: " << temp->name << "\n";
        temp = temp->next;
    } while (temp != top);
}

// Search for a student by ID
void searchById(Student* top, int id) {
    if (top == nullptr) {
        cout << "Stack is empty!\n";
        return;
    }
    
    Student* temp = top;
    do {
        if (temp->id == id) {
            cout << "Student found: ID: " << temp->id << ", Name: " << temp->name << "\n";
            return;
        }
        temp = temp->next;
    } while (temp != top);
    
    cout << "Student with ID " << id << " not found.\n";
}

// Reverse the stack
// To reverse the circular singly linked list, we break the circle,
// reverse the singly linked list as usual, and then re-establish the circle.
void reverseStack(Student*& top) {
    if (top == nullptr) {
        cout << "Stack is empty!\n";
        return;
    }
    
    // If there is only one node, no need to reverse.
    if (top->next == top) {
        cout << "Stack reversed.\n";
        return;
    }
    
    // First, break the circular link by finding the tail.
    Student* tail = top;
    while (tail->next != top) {
        tail = tail->next;
    }
    tail->next = nullptr;  // Break the circle to form a linear list.
    
    // Reverse the singly linked list.
    Student* prev = nullptr;
    Student* current = top;
    Student* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    // Now, prev is the new head of the reversed list.
    top = prev;
    
    // Re-establish the circular link.
    // Find the new tail (last node in the list)
    tail = top;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = top;  // Make it circular again.
    
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
    
    // Clean up any remaining nodes.
    if (top != nullptr) {
        // Break the circular link.
        Student* tail = top;
        while (tail->next != top) {
            tail = tail->next;
        }
        tail->next = nullptr;
        
        // Delete nodes.
        while (top != nullptr) {
            Student* temp = top;
            top = top->next;
            delete temp;
        }
    }
    
    return 0;
}
