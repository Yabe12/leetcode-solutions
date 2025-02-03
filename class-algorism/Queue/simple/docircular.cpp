#include <iostream>
#include <string>
using namespace std;

// Structure for a Student node in a circular doubly linked list
struct Student {
    int id;
    string name;
    Student* next;
    Student* prev;
};

// Enqueue student at the front
void enqueueFront(Student*& front, Student*& rear) {
    int id;
    string name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;

    Student* newNode = new Student{id, name, nullptr, nullptr};

    if (!front) {  // Queue is empty
        front = rear = newNode;
        front->next = front->prev = front;  // Circular linkage
    } else {
        newNode->next = front;
        newNode->prev = rear;
        front->prev = newNode;
        rear->next = newNode;
        front = newNode;  // Update front pointer
    }
    cout << "Student added at front: " << name << " (ID: " << id << ")\n";
}

// Enqueue student at the rear
void enqueueRear(Student*& front, Student*& rear) {
    int id;
    string name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;

    Student* newNode = new Student{id, name, nullptr, nullptr};

    if (!rear) {  // Queue is empty
        front = rear = newNode;
        front->next = front->prev = front;
    } else {
        newNode->next = front;
        newNode->prev = rear;
        rear->next = newNode;
        front->prev = newNode;
        rear = newNode;  // Update rear pointer
    }
    cout << "Student added at rear: " << name << " (ID: " << id << ")\n";
}

// Dequeue student from the front
void dequeueFront(Student*& front, Student*& rear) {
    if (!front) {
        cout << "Queue is empty!\n";
        return;
    }
    
    Student* temp = front;
    cout << "Removed student from front: " << temp->name << " (ID: " << temp->id << ")\n";

    if (front == rear) {  // Only one node
        front = rear = nullptr;
    } else {
        front = front->next;
        front->prev = rear;
        rear->next = front;
    }
    delete temp;
}

// Dequeue student from the rear
void dequeueRear(Student*& front, Student*& rear) {
    if (!rear) {
        cout << "Queue is empty!\n";
        return;
    }
    
    Student* temp = rear;
    cout << "Removed student from rear: " << temp->name << " (ID: " << temp->id << ")\n";

    if (front == rear) {  // Only one node
        front = rear = nullptr;
    } else {
        rear = rear->prev;
        rear->next = front;
        front->prev = rear;
    }
    delete temp;
}

// Display the queue from front to rear
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

// Reverse the queue
void reverseQueue(Student*& front, Student*& rear) {
    if (!front || front == rear) return;  // No need to reverse if 0 or 1 node

    Student* current = front;
    Student* temp = nullptr;
    
    do {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    } while (current != front);

    temp = front;
    front = rear;
    rear = temp;

    cout << "Queue reversed.\n";
}

// Main function
int main() {
    Student* front = nullptr;
    Student* rear = nullptr;
    int choice, id;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Student at Front\n";
        cout << "2. Add Student at Rear\n";
        cout << "3. Remove Student from Front\n";
        cout << "4. Remove Student from Rear\n";
        cout << "5. Display Students\n";
        cout << "6. Search Student by ID\n";
        cout << "7. Reverse Queue\n";
        cout << "8. Exit\n";
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
                cout << "Enter ID to search: ";
                cin >> id;
                searchById(front, id);
                break;
            case 7:
                reverseQueue(front, rear);
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
