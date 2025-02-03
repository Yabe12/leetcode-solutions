#include <iostream>
#include <string>
using namespace std;

// Structure to store student details
struct Student {
    int id;
    string name;
    Student* next;
    Student* prev;
};

// Insert student at the front
void enqueueFront(Student*& front, Student*& rear) {
    int id;
    string name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    
    Student* newNode = new Student{id, name, front, nullptr};
    
    if (front == nullptr) {
        front = rear = newNode;
    } else {
        front->prev = newNode;
        front = newNode;
    }
    cout << "Student added at front: " << name << " (ID: " << id << ")\n";
}

// Insert student at the rear
void enqueueRear(Student*& front, Student*& rear) {
    int id;
    string name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    
    Student* newNode = new Student{id, name, nullptr, rear};
    
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Student added at rear: " << name << " (ID: " << id << ")\n";
}

// Remove student from the front
void dequeueFront(Student*& front, Student*& rear) {
    if (front == nullptr) {
        cout << "Queue is empty!\n";
        return;
    }
    Student* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    } else {
        front->prev = nullptr;
    }
    cout << "Removed student from front: " << temp->name << " (ID: " << temp->id << ")\n";
    delete temp;
}

// Remove student from the rear
void dequeueRear(Student*& front, Student*& rear) {
    if (rear == nullptr) {
        cout << "Queue is empty!\n";
        return;
    }
    Student* temp = rear;
    rear = rear->prev;
    if (rear == nullptr) {
        front = nullptr;
    } else {
        rear->next = nullptr;
    }
    cout << "Removed student from rear: " << temp->name << " (ID: " << temp->id << ")\n";
    delete temp;
}

// Display queue content
void display(Student* front) {
    if (front == nullptr) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Students in queue:\n";
    Student* temp = front;
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
        cout << "1. Add Student at Front\n";
        cout << "2. Add Student at Rear\n";
        cout << "3. Remove Student from Front\n";
        cout << "4. Remove Student from Rear\n";
        cout << "5. Display Students\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                enqueueFront(front, rear);
                break;
            case 2:
                enqueueRear(front, rear);
                break;
            case 3:
                dequeueFront(front, rear);
                break;
            case 4:
                dequeueRear(front, rear);
                break;
            case 5:
                display(front);
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
