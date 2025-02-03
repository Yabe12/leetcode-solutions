#include <iostream>
#include <string>
#include <stack>  // For backward traversal
using namespace std;

// Define a structure for a node representing student information
struct Student {
    int ID;
    string name;
    float GPA;
    Student* next;  // Pointer to the next node
};

// Function to add a new student at the end of the list (circular singly linked list)
void ADD_ID(Student*& head, int id, const string& name, float gpa) {
    Student* newStudent = new Student();
    newStudent->ID = id;
    newStudent->name = name;
    newStudent->GPA = gpa;
    newStudent->next = newStudent;  // Points to itself initially

    if (head == NULL) {
        head = newStudent;
    } else {
        Student* temp = head;
        // Traverse until we reach the last node
        while (temp->next != head) {
            temp = temp->next;
        }
        // Update the circular link
        temp->next = newStudent;
        newStudent->next = head;  // Last node points back to head
    }
}

// Function to search for a student by ID
void SEARCH(Student* head, int id) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Student* temp = head;
    do {
        if (temp->ID == id) {
            cout << "Student found: ID: " << temp->ID << ", Name: " << temp->name << ", GPA: " << temp->GPA << "\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Student with ID " << id << " not found.\n";
}

// Function to delete a student by ID
void DELETE(Student*& head, int id) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Student* temp = head;
    Student* prev = NULL;
    do {
        if (temp->ID == id) {
            // If the node to be deleted is the only node in the list
            if (temp->next == head && prev == NULL) {
                head = NULL;  // List becomes empty
            } else {
                // If the node to be deleted is the head
                if (temp == head) {
                    // Find the last node to update its next pointer
                    while (temp->next != head) {
                        temp = temp->next;
                    }
                    head = head->next;
                    temp->next = head;  // Update the last node's next pointer
                } else {
                    prev->next = temp->next;  // Bypass the node to be deleted
                }
            }
            delete temp;
            cout << "Student with ID " << id << " deleted successfully.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    cout << "Student with ID " << id << " not found.\n";
}

// Function to display all students in the list (forward traversal)
void DISPLAY(Student* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Student* temp = head;
    do {
        cout << "ID: " << temp->ID << ", Name: " << temp->name << ", GPA: " << temp->GPA << "\n";
        temp = temp->next;
    } while (temp != head);
}

// Function for forward and backward traversal
void TRANSVERSE(Student* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    // Forward traversal
    cout << "Forward Traversal:\n";
    Student* temp = head;
    do {
        cout << "ID: " << temp->ID << ", Name: " << temp->name << ", GPA: " << temp->GPA << "\n";
        temp = temp->next;
    } while (temp != head);

    // Backward traversal
    cout << "\nBackward Traversal (simulated):\n";
    stack<Student*> studentStack;
    temp = head;
    do {
        studentStack.push(temp);
        temp = temp->next;
    } while (temp != head);

    while (!studentStack.empty()) {
        Student* student = studentStack.top();
        studentStack.pop();
        cout << "ID: " << student->ID << ", Name: " << student->name << ", GPA: " << student->GPA << "\n";
    }
}
void TRAVERSE(Student* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Student* temp = head;
    cout << "Traversing the circular list:\n";
    do {
        cout << "ID: " << temp->ID << ", Name: " << temp->name << ", GPA: " << temp->GPA << "\n";
        temp = temp->next;
    } while (temp != head); } // Loop until we reach the head again

int main() {
    Student* head = NULL; // Initialize an empty list
    int choice, id;
    string name;
    float gpa;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display Students\n";
        cout << "5. Transverse (Forward and Backward)\n";
        cout << "6. Exit\n";
        cout<<" 7. traverse\n"; 
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter GPA: ";
                cin >> gpa;
                ADD_ID(head, id, name, gpa);
                break;

            case 2:
                cout << "Enter ID to search: ";
                cin >> id;
                SEARCH(head, id);
                break;

            case 3:
                cout << "Enter ID to delete: ";
                cin >> id;
                DELETE(head, id);
                break;

            case 4:
                cout << "Student List:\n";
                DISPLAY(head);
                break;

            case 5:
                TRANSVERSE(head);
                break;

            case 6:
                cout << "Exiting program.\n";
                break;
            case 7:
                TRAVERSE(head);
            	break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
