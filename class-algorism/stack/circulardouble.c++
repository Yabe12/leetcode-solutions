#include <iostream>
#include <string>

using namespace std;

// Structure for Student node
struct Student {
    string id, name;
    float marks[5];
    Student* next;
    Student* prev;
};

// Top pointer for the stack (circular doubly linked list)
Student* top = nullptr;

// Function prototypes
void pushStudent();
void pushAtPosition(int position);
void popStudent();
void popAtPosition(int position);
void searchStudent();
void displayStack();
void updateStudent();
float calculateGPA(Student* student);
float reportTotalGPA();

// Push (Insert at Top - Stack behavior)
void pushStudent() {
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

    if (!top) {
        newStudent->next = newStudent;
        newStudent->prev = newStudent;
        top = newStudent;
    } else {
        Student* last = top->prev;

        newStudent->next = top;
        newStudent->prev = last;
        last->next = newStudent;
        top->prev = newStudent;
        top = newStudent;
    }

    cout << "Student pushed onto stack.\n";
}

// Push at a Specific Position
void pushAtPosition(int position) {
    if (position <= 1 || !top) {
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

    Student* newStudent = new Student{id, name, {}, nullptr, nullptr};
    for (int i = 0; i < 5; i++) {
        newStudent->marks[i] = marks[i];
    }

    Student* temp = top;
    for (int i = 1; temp->next != top && i < position - 1; i++) {
        temp = temp->next;
    }

    newStudent->next = temp->next;
    newStudent->prev = temp;
    temp->next->prev = newStudent;
    temp->next = newStudent;

    cout << "Student added at position " << position << ".\n";
}

// Pop (Remove from Top - Stack behavior)
void popStudent() {
    if (!top) {
        cout << "Stack is empty! No student to remove.\n";
        return;
    }

    if (top->next == top) {
        delete top;
        top = nullptr;
    } else {
        Student* last = top->prev;
        Student* temp = top;

        last->next = top->next;
        top->next->prev = last;
        top = top->next;

        delete temp;
    }

    cout << "Student popped from stack.\n";
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
    for (int i = 1; temp->next != top && i < position; i++) {
        temp = temp->next;
    }

    if (temp == top) {
        cout << "Position out of range.\n";
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;

    cout << "Student popped at position " << position << ".\n";
}

// Search Student by ID or Name
void searchStudent() {
    int choice;
    string value;
    cout << "\n1. Search by ID\n2. Search by Name\nEnter choice: ";
    cin >> choice;
    cout << "Enter " << (choice == 1 ? "ID: " : "Name: ");
    cin >> value;

    Student* temp = top;
    if (top) {
        do {
            if ((choice == 1 && temp->id == value) || (choice == 2 && temp->name == value)) {
                cout << "Found: ID: " << temp->id << " Name: " << temp->name << " GPA: " << calculateGPA(temp) << "\n";
                return;
            }
            temp = temp->next;
        } while (temp != top);
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
    Student* temp = top;

    if (top) {
        do {
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
        } while (temp != top);
    }
    cout << "Student not found\n";
}

// Display Stack (From Top to Bottom)
void displayStack() {
    if (!top) {
        cout << "Stack is empty!\n";
        return;
    }

    Student* temp = top;
    cout << "Students in Stack (Top to Bottom):\n";
    do {
        cout << "ID: " << temp->id << ", Name: " << temp->name << "\nMarks: ";
        for (int i = 0; i < 5; i++) cout << temp->marks[i] << " ";
        cout << "\nGPA: " << calculateGPA(temp) << "\n\n";
        temp = temp->next;
    } while (temp != top);
}

// Calculate GPA
float calculateGPA(Student* student) {
    float sum = 0;
    for (int i = 0; i < 5; i++) sum += student->marks[i];
    return sum / 5;
}

// Report Total GPA
float reportTotalGPA() {
    Student* temp = top;
    float totalGPA = 0;
    int count = 0;
    if (top) {
        do {
            totalGPA += calculateGPA(temp);
            count++;
            temp = temp->next;
        } while (temp != top);
    }
    return (count > 0) ? (totalGPA / count) : 0;
}

// Main Menu
int main() {
    int choice, position;
    do {
        cout << "\n1. Push Student\n2. Push at Position\n3. Pop Student\n4. Pop at Position\n5. Search Student\n6. Display Stack\n7. Update Student\n8. Report GPA\n9. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: pushStudent(); break;
            case 2: cout << "Enter position: "; cin >> position; pushAtPosition(position); break;
            case 3: popStudent(); break;
            case 4: cout << "Enter position: "; cin >> position; popAtPosition(position); break;
            case 5: searchStudent(); break;
            case 6: displayStack(); break;
            case 7: updateStudent(); break;
            case 8: cout << "Total GPA: " << reportTotalGPA() << "\n"; break;
        }
    } while (choice != 9);
    return 0;
}
