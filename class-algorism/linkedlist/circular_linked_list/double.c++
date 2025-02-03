#include <iostream>
#include <string>

using namespace std;

struct Student {
    string id, name;
    float marks[5];  // Assuming 5 subjects
    Student* next;
    Student* prev;
};

Student* head = nullptr;

void addStudent();
void deleteStudent();
void searchStudent();
void displayAll();
void updateStudent();
float calculateGPA(Student* student);
float reportTotalGPA();

void addStudent() {
    int choice, position;
    string id, name;
    float marks[5];
    
    cout << "\n1. Add at Start\n2. Add at End\n3. Add at Position\nEnter choice: ";
    cin >> choice;
    
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter 5 subject marks: ";
    for (int i = 0; i < 5; i++) cin >> marks[i];
    
    Student* newStudent = new Student{id, name, {}, nullptr, nullptr};
    
    // Copy marks into the new student's array
    for (int i = 0; i < 5; i++) {
        newStudent->marks[i] = marks[i];
    }

    if (choice == 1 || head == nullptr) {
        newStudent->next = head;
        newStudent->prev = nullptr;
        if (head) {
            head->prev = newStudent;
        }
        head = newStudent;
        if (head->next == nullptr) {
            head->next = head;
            head->prev = head;  // Make it circular if there's only one node
        }
    } else if (choice == 2) {
        Student* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newStudent;
        newStudent->prev = temp;
        newStudent->next = head;
        head->prev = newStudent;
    } else if (choice == 3) {
        cout << "Enter position: ";
        cin >> position;
        Student* temp = head;
        for (int i = 0; temp && i < position - 1; i++) temp = temp->next;
        if (!temp || temp->next == head) {
            cout << "Position out of range\n";
            delete newStudent;
            return;
        }
        newStudent->next = temp->next;
        newStudent->prev = temp;
        temp->next->prev = newStudent;
        temp->next = newStudent;
    }
}

void deleteStudent() {
    int choice;
    string value;
    cout << "\n1. Delete from Start\n2. Delete from End\n3. Delete by ID\n4. Delete by Name\nEnter choice: ";
    cin >> choice;
    
    if (choice == 1 && head) {
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Student* temp = head;
            head = head->next;
            head->prev = nullptr;
            temp->next = nullptr;
            delete temp;
        }
    } else if (choice == 2 && head) {
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Student* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->prev->next = head;
        head->prev = temp->prev;
        delete temp;
    } else if (choice == 3 || choice == 4) {
        cout << "Enter " << (choice == 3 ? "ID: " : "Name: ");
        cin >> value;
        
        if (head && (choice == 3 ? head->id == value : head->name == value)) {
            Student* temp = head;
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }
            while (temp->next != head) temp = temp->next;
            temp->next = head->next;
            head->next->prev = temp;
            delete head;
            head = temp->next;
            return;
        }
        
        Student* temp = head;
        while (temp->next != head && (choice == 3 ? temp->next->id != value : temp->next->name != value)) temp = temp->next;
        if (temp->next == head) return;  // Element not found
        
        Student* toDelete = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        delete toDelete;
    }
}

void searchStudent() {
    int choice;
    string value;
    cout << "\n1. Search by ID\n2. Search by Name\nEnter choice: ";
    cin >> choice;
    cout << "Enter " << (choice == 1 ? "ID: " : "Name: ");
    cin >> value;
    
    Student* temp = head;
    if (head) {
        do {
            if ((choice == 1 && temp->id == value) || (choice == 2 && temp->name == value)) {
                cout << "Found: ID: " << temp->id << " Name: " << temp->name << " GPA: " << calculateGPA(temp) << "\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }
    cout << "Student not found\n";
}

void updateStudent() {
    string id, newId, newName;
    float newMarks[5];
    int choice;
    
    cout << "Enter ID to update: ";
    cin >> id;
    Student* temp = head;
    
    if (head) {
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
                    
                    // Copy marks into the student's array
                    for (int i = 0; i < 5; i++) {
                        temp->marks[i] = newMarks[i];
                    }
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }
    cout << "Student not found\n";
}

void displayAll() {
    Student* temp = head;
    if (head) {
        do {
            cout << "ID: " << temp->id << ", Name: " << temp->name << "\nMarks: ";
            for (int i = 0; i < 5; i++) cout << temp->marks[i] << " ";
            cout << "\nTotal GPA: " << calculateGPA(temp) << "\n\n";
            temp = temp->next;
        } while (temp != head);
    }
}

float calculateGPA(Student* student) {
    float sum = 0;
    for (int i = 0; i < 5; i++) sum += student->marks[i];
    return sum / 5;
}

float reportTotalGPA() {
    Student* temp = head;
    float totalGPA = 0;
    int count = 0;
    if (head) {
        do {
            totalGPA += calculateGPA(temp);
            count++;
            temp = temp->next;
        } while (temp != head);
    }
    return (count > 0) ? (totalGPA / count) : 0;
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student\n2. Delete Student\n3. Search Student\n4. Display All\n5. Update Student\n6. Report GPA\n7. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: searchStudent(); break;
            case 4: displayAll(); break;
            case 5: updateStudent(); break;
            case 6: cout << "Total GPA: " << reportTotalGPA() << "\n"; break;
        }
    } while (choice != 7);
    return 0;
}
