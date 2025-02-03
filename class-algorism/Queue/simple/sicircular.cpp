#include <iostream>
#include <string>
using namespace std;

// Structure for a Student node in a circular linked list
struct Student {
    int id;
    string name;
    Student* next;
};

// Enqueue student (insert at rear)
void enqueue(Student*& front, Student*& rear) {
    int id;
    string name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;

    Student* newNode = new Student{id, name, nullptr};

    if (!rear) { // Queue is empty
        front = rear = newNode;
        rear->next = front;  // Circular link
    } else {
        rear->next = newNode;
        newNode->next = front;
        rear = newNode;  // Update rear pointer
    }

    cout << "Student added: " << name << " (ID: " << id << ")\n";
}

// Dequeue student (remove from front)
void dequeue(Student*& front, Student*& rear) {
    if (!front) {
        cout << "Queue is empty!\n";
        return;
    }

    Student* temp = front;
    cout << "Removed student: " << temp->name << " (ID: " << temp->id << ")\n";

    if (front == rear) {  // Only one node
        front = rear = nullptr;
    } else {
        front = front->next;
        rear->next = front;
    }

    delete temp;
}

// Display the queue
void display(Student* front) {
    if (!front) {
        cout << "Queue is empty!\n";
        return;
    }

    Student* temp = front;
    cout << "Students in queue:\n";
    do {
        cout << "ID: " << temp->id << ", Name: " << temp->name << "\n";
        temp = temp->next;
    } while (temp != front);
}

// Search for a student by ID
void searchById(Student* front, int id) {
    if (!front) {
        cout << "Queue is empty!\n";
        return;
    }

    Student* temp = front;
    do {
        if (temp->id == id) {
            cout << "Student found: ID: " << temp->id << ", Name: " << temp->name << "\n";
            return;
        }
        temp = temp->next;
    } while (temp != front);

    cout << "Student with ID " << id << " not found.\n";
}

// Main function
int main() {
    Student* front = nullptr;
    Student* rear = nullptr;
    int choice, id;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Student (Enqueue)\n";
        cout << "2. Remove Student (Dequeue)\n";
        cout << "3. Display Students\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                enqueue(front, rear);
                break;
            case 2:
                dequeue(front, rear);
                break;
            case 3:
                display(front);
                break;
            case 4:
                cout << "Enter ID to search: ";
                cin >> id;
                searchById(front, id);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
