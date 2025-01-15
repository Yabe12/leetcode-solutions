#include <iostream>
#include <cstring>
using namespace std;

// Define the 'student' structure with attributes to store student data
struct student {
    char ID[25];  // To store student ID
    char name[25];  // To store student name
    char grades[10][5];  // To store grades (assumes a maximum of 10 grades, each up to 4 characters)
    int gradeCount;  // To store the number of grades entered
    struct student *next;  // Pointer to the next student in the list (for next pointer navigation)
    struct student *priv;  // Pointer to the previous student in the list (for previous pointer navigation)
} Student;

// Initialize the start and end pointers to NULL
Student *start = NULL, *end = NULL;

// Function to add a student at the beginning of the list
void insert_data_big() {
    Student *newStudent = new Student;  // Create a new student node
    cout << "Enter ID: ";
    cin >> newStudent->ID;  // Input the student's ID
    cout << "Enter Name: ";
    cin >> newStudent->name;  // Input the student's name
    cout << "Enter number of grades: ";
    cin >> newStudent->gradeCount;  // Input the number of grades
    for (int i = 0; i < newStudent->gradeCount; i++) {
        cout << "Enter grade " << i + 1 << ": ";
        cin >> newStudent->grades[i];  // Input the grades
    }
    newStudent->next = start;  // The new student points to the current first student
    newStudent->priv = NULL;  // No previous student for the new first student
    if (start != NULL) {
        start->priv = newStudent;  // If the list isn't empty, update the current first student's previous pointer
    }
    start = newStudent;  // Set the new student as the start of the list
    if (end == NULL) {
        end = start;  // If the list was empty, set the new student as both the start and end
    }
    cout << "Student added at the beginning.\n";
}

// Function to add a student at the end of the list
void insert_data_end() {
    Student *newStudent = new Student;  // Create a new student node
    cout << "Enter ID: ";
    cin >> newStudent->ID;  // Input the student's ID
    cout << "Enter Name: ";
    cin >> newStudent->name;  // Input the student's name
    cout << "Enter number of grades: ";
    cin >> newStudent->gradeCount;  // Input the number of grades
    for (int i = 0; i < newStudent->gradeCount; i++) {
        cout << "Enter grade " << i + 1 << ": ";
        cin >> newStudent->grades[i];  // Input the grades
    }
    newStudent->next = NULL;  // The new student will be the last, so no next student
    newStudent->priv = end;  // The previous student will be the current last student
    if (end != NULL) {
        end->next = newStudent;  // Update the current last student's next pointer to point to the new student
    }
    end = newStudent;  // Set the new student as the end of the list
    if (start == NULL) {
        start = end;  // If the list was empty, set the new student as both the start and end
    }
    cout << "Student added at the end.\n";
}

// Function to add a student at a specific position in the list
void insert_data_specific_position() {
    int position;
    cout << "Enter position to insert: ";
    cin >> position;  // Input the position where the student should be inserted
    
    if (position < 1) {
        cout << "Invalid position.\n";
        return;  // Return if the position is invalid
    }
    
    Student *newStudent = new Student;  // Create a new student node
    cout << "Enter ID: ";
    cin >> newStudent->ID;  // Input the student's ID
    cout << "Enter Name: ";
    cin >> newStudent->name;  // Input the student's name
    cout << "Enter number of grades: ";
    cin >> newStudent->gradeCount;  // Input the number of grades
    for (int i = 0; i < newStudent->gradeCount; i++) {
        cout << "Enter grade " << i + 1 << ": ";
        cin >> newStudent->grades[i];  // Input the grades
    }
    
    // If the position is 1, insert at the beginning (reuse insert_data_big)
    if (position == 1) {
        insert_data_big();
        return;
    }
    
    Student *temp = start;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;  // Traverse to the node just before the desired position
    }
    
    if (temp == NULL) {
        cout << "Position out of range.\n";
        return;  // Return if the position is out of range
    }
    
    newStudent->next = temp->next;  // Link the new student to the next node
    if (temp->next != NULL) {
        temp->next->priv = newStudent;  // Update the previous pointer of the next node
    }
    temp->next = newStudent;  // Link the previous node to the new student
    newStudent->priv = temp;  // Set the previous pointer of the new student
    cout << "Student added at position " << position << ".\n";
}

// Function to search for a student by ID
void SearchData() {
    char searchID[25];
    cout << "Enter ID to search: ";
    cin >> searchID;  // Input the ID of the student to search for
    
    Student *temp = start;
    while (temp != NULL) {
        if (strcmp(temp->ID, searchID) == 0) {  // Compare the current student's ID with the search ID
            cout << "Student found: " << temp->name << endl;  // If found, print the student's name
            return;
        }
        temp = temp->next;  // Move to the next student
    }
    cout << "Student not found.\n";  // If the student is not found
}

// Function to remove a student from the beginning of the list
void remove_student_big() {
    if (start == NULL) {
        cout << "No students to remove.\n";
        return;  // If the list is empty, print an error message and return
    }
    
    Student *temp = start;
    start = start->next;  // Move the start pointer to the next student
    if (start != NULL) {
        start->priv = NULL;  // Set the previous pointer of the new first student to NULL
    } else {
        end = NULL;  // If the list becomes empty, set the end pointer to NULL
    }
    delete temp;  // Delete the student node
    cout << "Student removed from the beginning.\n";
}

// Function to remove a student from the end of the list
void remove_student_end() {
    if (end == NULL) {
        cout << "No students to remove.\n";
        return;  // If the list is empty, print an error message and return
    }
    
    Student *temp = end;
    end = end->priv;  // Move the end pointer to the previous student
    if (end != NULL) {
        end->next = NULL;  // Set the next pointer of the new last student to NULL
    } else {
        start = NULL;  // If the list becomes empty, set the start pointer to NULL
    }
    delete temp;  // Delete the student node
    cout << "Student removed from the end.\n";
}

// Function to remove a student from a specific position in the list
void remove_student_specific_position() {
    int position;
    cout << "Enter position to remove: ";
    cin >> position;  // Input the position of the student to remove
    
    if (position < 1) {
        cout << "Invalid position.\n";
        return;  // If the position is invalid, return
    }
    
    // If the position is 1, remove from the beginning (reuse remove_student_big)
    if (position == 1) {
        remove_student_big();
        return;
    }
    
    Student *temp = start;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;  // Traverse to the desired position
    }
    
    if (temp == NULL) {
        cout << "Position out of range.\n";
        return;  // If the position is out of range, return
    }
    
    if (temp->next != NULL) {
        temp->next->priv = temp->priv;  // Update the previous pointer of the next student
    }
    if (temp->priv != NULL) {
        temp->priv->next = temp->next;  // Update the next pointer of the previous student
    }
    
    delete temp;  // Delete the student node
    cout << "Student removed from position " << position << ".\n";
}

// Function to traverse the list from head to tail using next pointers
void traverse_head_to_tail() {
    if (start == NULL) {
        cout << "No students to display.\n";
        return;  // If the list is empty, return
    }
    
    Student *temp = start;
    while (temp != NULL) {
        cout << "ID: " << temp->ID << ", Name: " << temp->name << endl;  // Print the student information
        temp = temp->next;  // Move to the next student
    }
}

// Function to traverse the list from tail to head using priv (previous) pointers
void traverse_tail_to_head() {
    if (end == NULL) {
        cout << "No students to display.\n";
        return;  // If the list is empty, return
    }
    
    Student *temp = end;
    while (temp != NULL) {
        cout << "ID: " << temp->ID << ", Name: " << temp->name << endl;  // Print the student information
        temp = temp->priv;  // Move to the previous student
    }
}

int main() {
    int choice;
    
    // Menu-driven loop for the user to choose an operation
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add at the beginning\n";
        cout << "2. Add at the end\n";
        cout << "3. Add at a specific position\n";
        cout << "4. Search Data\n";
        cout << "5. Remove from the beginning\n";
        cout << "6. Remove from the end\n";
        cout << "7. Remove from a specific position\n";
        cout << "8. Traverse from the head to the tail using the next pointers\n";
        cout << "9. Traverse from the tail to the head using the priv pointers\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;  // Input the user's choice
        
        switch (choice) {
            case 1:
                insert_data_big();  // Call function to add student at the beginning
                break;
            case 2:
                insert_data_end();  // Call function to add student at the end
                break;
            case 3:
                insert_data_specific_position();  // Call function to add student at a specific position
                break;
            case 4:
                SearchData();  // Call function to search student by ID
                break;
            case 5:
                remove_student_big();  // Call function to remove student from the beginning
                break;
            case 6:
                remove_student_end();  // Call function to remove student from the end
                break;
            case 7:
                remove_student_specific_position();  // Call function to remove student from a specific position
                break;
            case 8:
                traverse_head_to_tail();  // Call function to traverse the list head to tail
                break;
            case 9:
                traverse_tail_to_head();  // Call function to traverse the list tail to head
                break;
            case 10:
                exit(0);  // Exit the program
            default:
                cout << "Invalid choice.\n";  // Print error message for invalid choices
        }
    }
    return 0;
}
