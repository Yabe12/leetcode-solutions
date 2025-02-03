#include <iostream>
#include <string>
using namespace std;

// Structure to store student details
struct Student {
    int id;
    string name;
    Student* next;
};

// Enqueue student into the queue
void enqueue(Student*& front, Student*& rear) {
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
    
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    
    cout << "Student added: " << name << " (ID: " << id << ")\n";
}

// Dequeue student from the queue
void dequeue(Student*& front, Student*& rear) {
    if (front == nullptr) {
        cout << "Queue is empty!\n";
        return;
    }
    Student* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    cout << "Removed student: " << temp->name << " (ID: " << temp->id << ")\n";
    delete temp;
}

// Display queue content
void display(Student* front) {
    if (front == nullptr) {
        cout << "Queue is empty!\n";
        return;
    }
    Student* temp = front;
    cout << "Students in queue:\n";
    while (temp) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << "\n";
        temp = temp->next;
    }
}

int main() {
    Student* front = nullptr;
    Student* rear = nullptr;
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
                enqueue(front, rear);
                break;
            case 2:
                dequeue(front, rear);
                break;
            case 3:
                display(front);
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