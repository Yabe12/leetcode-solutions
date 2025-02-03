#include <iostream>
#include <string>

using namespace std;

// Structure for Student node
struct Student {
    string id, name;
    float marks[5];  // Assuming 5 subjects
    Student* next;
};

// Stack top pointer
Student* top = nullptr;

// Function prototypes
void pushStudent();
void pushAtPosition(int position);
void popStudent();
void popAtPosition(int position);
void peekStudent();
void displayStack();
float calculateGPA(Student* student);

// Push (Insert at Top)
void pushStudent() {
    string id, name;
    float marks[5];

    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter 5 subject marks: ";
    for (int i = 0; i < 5; i++) cin >> marks[i];

    // Create new student
    Student* newStudent = new Student{id, name, {}, top}; 
    for (int i = 0; i < 5; i++) {
        newStudent->marks[i] = marks[i];
    }

    // Move top to the new node
    top = newStudent;
    cout << "Student pushed onto stack.\n";
}

// Push at a Specific Position
void pushAtPosition(int position) {
    if (position <= 1) {
        pushStudent();
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

    Student* newStudent = new Student{id, name, {}, nullptr};
    for (int i = 0; i < 5; i++) {
        newStudent->marks[i] = marks[i];
    }

    Student* temp = top;
    for (int i = 1; temp && i < position - 1; i++) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Position out of range. Adding at the end.\n";
    }

    newStudent->next = temp->next;
    temp->next = newStudent;
    cout << "Student added at position " << position << ".\n";
}

// Pop (Remove from Top)
void popStudent() {
    if (!top) {
        cout << "Stack is empty! No student to remove.\n";
        return;
    }

    Student* temp = top;
    top = top->next;  // Move top to the next node

    cout << "Popped Student: " << temp->id << " - " << temp->name << endl;
    delete temp;
}

// Pop at a Specific Position
void popAtPosition(int position) {
    if (!top) {
        cout << "Stack is empty! No student to remove.\n";
        return;
    }

    if (position == 1) {
        popStudent();
        return;
    }

    Student* temp = top;
    for (int i = 1; temp->next && i < position - 1; i++) {
        temp = temp->next;
    }

    if (!temp->next) {
        cout << "Position out of range.\n";
        return;
    }

    Student* toDelete = temp->next;
    temp->next = toDelete->next;
    cout << "Popped Student at position " << position << ": " << toDelete->id << " - " << toDelete->name << endl;
    delete toDelete;
}

// Peek (Show Top Student)
void peekStudent() {
    if (!top) {
        cout << "Stack is empty!\n";
        return;
    }

    cout << "Top Student -> ID: " << top->id << ", Name: " << top->name;
    cout << ", GPA: " << calculateGPA(top) << "\n";
}

// Display Stack (From Top to Bottom)
void displayStack() {
    if (!top) {
        cout << "Stack is empty!\n";
        return;
    }

    Student* temp = top;
    cout << "Students in Stack (Top to Bottom):\n";
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

// Main Menu
int main() {
    int choice, position;
    do {
        cout << "\n1. Push Student\n2. Push at Position\n3. Pop Student\n4. Pop at Position\n5. Peek Student\n6. Display Stack\n7. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: pushStudent(); break;
            case 2: 
                cout << "Enter position to push: ";
                cin >> position;
                pushAtPosition(position);
                break;
            case 3: popStudent(); break;
            case 4:
                cout << "Enter position to pop: ";
                cin >> position;
                popAtPosition(position);
                break;
            case 5: peekStudent(); break;
            case 6: displayStack(); break;
        }
    } while (choice != 7);

    return 0;
}
