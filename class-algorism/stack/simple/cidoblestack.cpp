#include <iostream>
#include <string>
using namespace std;

// Structure for a Student node in a circular doubly linked list (used as a stack)
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

    // Create new node
    Student* newNode = new Student;
    newNode->id = id;
    newNode->name = name;

    if (top == nullptr) {
        // First node in the circular list: next and prev point to itself.
        newNode->next = newNode;
        newNode->prev = newNode;
        top = newNode;
    } else {
        // Insert new node before the current top:
        // Find the tail node (which is top->prev)
        Student* tail = top->prev;

        newNode->next = top;   // new node points forward to old top
        newNode->prev = tail;  // new node points back to tail

        tail->next = newNode;  // tail now points forward to new node
        top->prev = newNode;   // old top now points back to new node

        top = newNode;         // new node becomes the top of the stack
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
        // More than one node: Remove the top node and adjust pointers
        Student* tail = top->prev; // tail node
        Student* temp = top;       // node to be removed
        
        top = top->next;           // move top pointer to the next node
        
        tail->next = top;          // tail's next now points to the new top
        top->prev = tail;          // new top's previous now points to tail
        
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
    // Since it's circular, loop until we reach the top node again.
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
// For a circular doubly linked list, swap the next and prev pointers of each node.
// Finally, update the top pointer to point to the new top.
void reverseStack(Student*& top) {
    if (top == nullptr) {
        cout << "Stack is empty!\n";
        return;
    }
    
    Student* current = top;
    // Since the list is circular, we use a do-while loop.
    do {
        // Swap the next and prev pointers for the current node.
        Student* temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        
        // Move to the next node in the original order.
        current = temp;
    } while (current != top);
    
    // After swapping, the node that was originally at the tail is now the top.
    // top->prev originally pointed to the tail, but after swap, top->prev becomes the old top->next.
    // A simpler way is to set top = top->next (after reversal, top->next is the new top).
    top = top->next;
    
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
    if (top != nullptr) {
        // Break the circular link to avoid an infinite loop.
        Student* tail = top->prev;
        tail->next = nullptr;
        while (top) {
            Student* temp = top;
            top = top->next;
            delete temp;
        }
    }
    
    return 0;
}
