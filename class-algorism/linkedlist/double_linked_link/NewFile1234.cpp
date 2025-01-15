#include <iostream>
#include <cstring>
using namespace std;

struct student {
    char id[25];
    char name[25];
    char grade[10][5];
    int gradeCount;
    struct student *next;
    struct student *priv;
};

student *head = NULL, *tall = NULL;

void insert_data_big() {
    student *newstudent = new student;
    cout << "Enter student id: ";
    cin >> newstudent->id;
    cout << "Enter student name: ";
    cin >> newstudent->name;
    cout << "Enter number of grades: ";
    cin >> newstudent->gradeCount;

    for (int i = 0; i < newstudent->gradeCount; i++) {
        cout << "Enter grade " << i + 1 << ": ";
        cin >> newstudent->grade[i];
    }

    newstudent->next = head;
    newstudent->priv = NULL;

    if (head != NULL) {
        head->priv = newstudent;
    }
    head = newstudent;

    if (tall == NULL) {
        tall = head;
    }
    cout << "Student added at the beginning.\n";
}

void insert_data_end() {
    student *newstudent = new student;
    cout << "Enter student id: ";
    cin >> newstudent->id;
    cout << "Enter student name: ";
    cin >> newstudent->name;
    cout << "Enter number of grades: ";
    cin >> newstudent->gradeCount;

    for (int i = 0; i < newstudent->gradeCount; i++) {
        cout << "Enter grade " << i + 1 << ": ";
        cin >> newstudent->grade[i];
    }

    newstudent->next = NULL;
    newstudent->priv = tall;

    if (tall != NULL) {
        tall->next = newstudent;
    }
    tall = newstudent;

    if (head == NULL) {
        head = tall;
    }
    cout << "Student added at the end.\n";
}

void insert_data_specific_position() {
    int position;
    cout << "Enter the position to insert: ";
    cin >> position;

    if (position < 1) {
        cout << "Invalid position.\n";
        return;
    }

    if (position == 1) {
        insert_data_big();
        return;
    }

    student *newstudent = new student;
    cout << "Enter student id: ";
    cin >> newstudent->id;
    cout << "Enter student name: ";
    cin >> newstudent->name;
    cout << "Enter number of grades: ";
    cin >> newstudent->gradeCount;

    for (int i = 0; i < newstudent->gradeCount; i++) {
        cout << "Enter grade " << i + 1 << ": ";
        cin >> newstudent->grade[i];
    }

    student *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range.\n";
        return;
    }

    newstudent->next = temp->next;
    if (temp->next != NULL) {
        temp->next->priv = newstudent;
    }
    temp->next = newstudent;
    newstudent->priv = temp;

    cout << "Student added at position " << position << ".\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add at the beginning\n";
        cout << "2. Add at the end\n";
        cout << "3. Add at a specific position\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert_data_big();
                break;
            case 2:
                insert_data_end();
                break;
            case 3:
                insert_data_specific_position();
                break;
            
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
