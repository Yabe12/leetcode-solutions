#include <iostream>
#include <string>

using namespace std;

// Structure for Student node (Doubly Linked List)
struct Student {
    string id, name;
    float marks[5];
    Student* next;
    Student* prev;
};

// Front and Rear pointers for the queue
Student* front = nullptr;
Student* rear = nullptr;

// Function prototypes
void enqueueStudent();
void enqueueAtPosition(int position);
void dequeueStudent();
void dequeueAtPosition(int position);
void searchStudent();
void displayQueue();
void updateStudent();
float calculateGPA(Student* student);
float reportTotalGPA();

// Enqueue (Insert at Rear - Queue behavior)
void enqueueStudent() {
    string id, name;
    float marks[5];

    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter 5 subject marks: ";
    for (int i = 0; i < 5; i++) cin >> marks[i];

    Student* newStudent = new Student{id, name, {}, nullptr, nullptr};

    // Copy marks
    for (int i = 0; i < 5; i++) {
        newStudent->marks[i] = marks[i];
    }

    if (!rear) {
        front = rear = newStudent;
    } else {
        rear->next = newStudent;
        newStudent->prev = rear;
        rear = newStudent;
    }

    cout << "Student enqueued successfully.\n";
}

// Enqueue at a Specific Position
void enqueueAtPosition(int position) {
    if (position <= 1 || !front) {
        enqueueStudent();
        return;
    }

    string id, name;
    float marks[5];

    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter 5 subject marks: ";
    for (int i = 0; i < 5; i++) cin >> marks[i];

    Student* newStudent = new Student{id, name, {}, nullptr, nullptr};
    for (int i = 0; i < 5; i++) {
        newStudent->marks[i] = marks[i];
    }

    Student* temp = front;
    for (int i = 1; temp->next != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    newStudent->next = temp->next;
    newStudent->prev = temp;

    if (temp->next) {
        temp->next->prev = newStudent;
    }

    temp->next = newStudent;

    if (!newStudent->next) {
        rear = newStudent;
    }

    cout << "Student added at position " << position << ".\n";
}

// Dequeue (Remove from Front - Queue behavior)
void dequeueStudent() {
    if (!front) {
        cout << "Queue is empty! No student to remove.\n";
        return;
    }

    Student* temp = front;
    front = front->next;
    if (front) {
        front->prev = nullptr;
    } else {
        rear = nullptr;
    }
    
    delete temp;
    cout << "Student dequeued successfully.\n";
}

// Dequeue at a Specific Position
void dequeueAtPosition(int position) {
    if (!front) {
        cout << "Queue is empty! No student to remove.\n";
        return;
    }

    if (position == 1) {
        dequeueStudent();
        return;
    }

    Student* temp = front;
    for (int i = 1; temp->next != nullptr && i < position; i++) {
        temp = temp->next;
    }

    if (!temp->next && i < position) {
        cout << "Position out of range.\n";
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next) {
        temp->next->prev = temp->prev;
    } else {
        rear = temp->prev;
    }

    delete temp;
    cout << "Student dequeued at position " << position << ".\n";
}

// Search Student by ID or Name
void searchStudent() {
    int choice;
    string value;
    cout << "\n1. Search by ID\n2. Search by Name\nEnter choice: ";
    cin >> choice;
    cout << "Enter " << (choice == 1 ? "ID: " : "Name: ");
    cin >> value;

    Student* temp = front;
    while (temp) {
        if ((choice == 1 && temp->id == value) || (choice == 2 && temp->name == value)) {
            cout << "Found: ID: " << temp->id << " Name: " << temp->name << " GPA: " << calculateGPA(temp) << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found\n";
}

// Update Student Details
void updateStudent() {
    string id, newId, newName;
    float newMarks[5];
    int choice;

    cout << "Enter ID to update: ";
    cin >> id;
    Student* temp = front;

    while (temp) {
        if (temp->id == id) {
            cout << "\n1. Update ID\n2. Update Name\n3. Update Marks\n4. Update All\nEnter choice: ";
            cin >> choice;

            if (choice == 1 || choice == 4) {
                cout << "Enter new ID: ";
                cin >> newId;
                temp->id = newId;
            }
            if (choice == 2 || choice == 4) {
                cout << "Enter new Name: ";
                cin >> newName;
                temp->name = newName;
            }
            if (choice == 3 || choice == 4) {
                cout << "Enter new marks: ";
                for (int i = 0; i < 5; i++) cin >> newMarks[i];

                for (int i = 0; i < 5; i++) {
                    temp->marks[i] = newMarks[i];
                }
            }
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found\n";
}

// Display Queue (From Front to Rear)
void displayQueue() {
    if (!front) {
        cout << "Queue is empty!\n";
        return;
    }

    Student* temp = front;
    cout << "Students in Queue (Front to Rear):\n";
    while (temp) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << "\nMarks: ";
        for (int i = 0; i < 5; i++) cout << temp->marks[i] << " ";
        cout << "\nGPA: " << calculateGPA(temp) << "\n\n";
        temp = temp->next;
    }
}

// Calculate GPA
float calculateGPA(Student* student) {
    float sum = 0;
    for (int i = 0; i < 5; i++) sum += student->marks[i];
    return sum / 5;
}

// Report Total GPA
float reportTotalGPA() {
    Student* temp = front;
    float totalGPA = 0;
    int count = 0;
    while (temp) {
        totalGPA += calculateGPA(temp);
        count++;
        temp = temp->next;
    }
    return (count > 0) ? (totalGPA / count) : 0;
}

// Main Menu
int main() {
    int choice, position;
    do {
        cout << "\n1. Enqueue Student\n2. Enqueue at Position\n3. Dequeue Student\n4. Dequeue at Position\n5. Search Student\n6. Display Queue\n7. Update Student\n8. Report GPA\n9. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: enqueueStudent(); break;
            case 2: cout << "Enter position: "; cin >> position; enqueueAtPosition(position); break;
            case 3: dequeueStudent(); break;
            case 4: cout << "Enter position: "; cin >> position; dequeueAtPosition(position); break;
            case 5: searchStudent(); break;
            case 6: displayQueue(); break;
            case 7: updateStudent(); break;
            case 8: cout << "Total GPA: " << reportTotalGPA() << "\n"; break;
        }
    } while (choice != 9);
    return 0;
}
