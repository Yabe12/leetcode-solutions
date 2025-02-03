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

// Search student by ID
void searchById(Student* front, int id) {
    Student* temp = front;
    while (temp) {
        if (temp->id == id) {
            cout << "Student found: ID: " << temp->id << ", Name: " << temp->name << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student with ID " << id << " not found.\n";
}

// Reverse the queue
void reverseQueue(Student*& front, Student*& rear) {
    Student* prev = nullptr;
    Student* current = front;
    Student* next = nullptr;
    rear = front;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    front = prev;
    cout << "Queue reversed.\n";
}

int main() {
    Student* front = nullptr;
    Student* rear = nullptr;
    int choice, id;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Display Students\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Reverse Queue\n";
        cout << "6. Exit\n";
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
                reverseQueue(front, rear);
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

