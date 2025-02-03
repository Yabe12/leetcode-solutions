#include <iostream>
#include <string>
using namespace std;

// Structure to store student details
struct Student {
    int id;
    string name;
    Student* next;
};

// Push student onto the stack
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
    newNode->next = nullptr;
    
    if (top == nullptr) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
    
    cout << "Student added: " << name << " (ID: " << id << ")\n";
}

// Pop student from the stack
void pop(Student*& top) {
    if (top == nullptr) {
        cout << "Stack is empty!\n";
        return;
    }
    Student* temp = top;
    top = top->next;
    cout << "Removed student: " << temp->name << " (ID: " << temp->id << ")\n";
    delete temp;
}

// Display stack content
void display(Student* top) {
    if (top == nullptr) {
        cout << "Stack is empty!\n";
        return;
    }
    Student* temp = top;
    cout << "Students in stack:\n";
    while (temp) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << "\n";
        temp = temp->next;
    }
}

int main() {
    Student* top = nullptr;
    int choice;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Display Students\n";
        cout << "4. Exit\n";
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
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
    
    return 0;
}