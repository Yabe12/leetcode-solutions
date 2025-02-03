#include <iostream>
#include <string>
using namespace std;

// Structure for a Student node in a stack
struct Student {
    int id;
    string name;
    Student* next;
};

// Push student onto the stack (Insert at top)
void push(Student*& top) {
    int id;
    string name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;

    Student* newNode = new Student;
    newNode->id = id;
    newNode->name = name;
    newNode->next = top;
    top = newNode;

    cout << "Student pushed: " << name << " (ID: " << id << ")\n";
}

// Pop student from the stack (Remove from top)
void pop(Student*& top) {
    if (!top) {
        cout << "Stack is empty!\n";
        return;
    }
    Student* temp = top;
    top = top->next;
    cout << "Popped student: " << temp->name << " (ID: " << temp->id << ")\n";
    delete temp;
}

// Display the stack (Top to Bottom)
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
void reverseStack(Student*& top) {
    Student* prev = nullptr;
    Student* current = top;
    Student* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    top = prev;
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

    return 0;
}
