#include <iostream>
#include <string>
using namespace std;

// Student structure for holding student information
struct Student {
    int ID;  // ID of the student
    string name;  // Name of the student
    Student *next;  // Pointer to the next node in the list (single linked list)
};

// Global pointer for the start of the list
Student *start = NULL;  // Initialize start as NULL (empty list)

// Function to add student data at the beginning
void insert_data_big() {
    // Create a new student node
    Student *newStudent = new Student;

    // Prompt the user to enter student ID
    cout << "Enter student ID: ";
    cin >> newStudent->ID;

    // Prompt the user to enter student name
    cout << "Enter student name: ";
    cin.ignore();  // Ignore the leftover newline character from previous input
    getline(cin, newStudent->name);  // Read the full name including spaces

    // The new student should point to the current start of the list
    newStudent->next = start;

    // Update the start of the list to the new student
    start = newStudent;

    // Confirm that the student has been added at the beginning
    cout << "Student added at the beginning.\n";
}

// Function to add student data at the end
void insert_data_end() {
    // Create a new student node
    Student *newStudent = new Student;

    // Prompt the user to enter student ID
    cout << "Enter student ID: ";
    cin >> newStudent->ID;

    // Prompt the user to enter student name
    cout << "Enter student name: ";
    cin.ignore();  // Ignore the leftover newline character from previous input
    getline(cin, newStudent->name);  // Read the full name including spaces

    // Set the new student's next pointer to NULL as it will be the last student
    newStudent->next = NULL;

    if (start == NULL) {  // If the list is empty
        // The new student becomes the start of the list
        start = newStudent;
    } else {
        // Traverse the list to find the last student
        Student *temp = start;
        while (temp->next != NULL) {  // Keep traversing until the last student
            temp = temp->next;
        }

        // The last student's next pointer should now point to the new student
        temp->next = newStudent;
    }

    // Confirm that the student has been added at the end
    cout << "Student added at the end.\n";
}

// Function to add student data at a specific position
void insert_data_specific_position() {
    int pos;
    // Prompt the user to enter the position to insert the new student
    cout << "Enter position to insert: ";
    cin >> pos;

    if (pos <= 0) {
        cout << "Invalid position.\n";  // Ensure the position is valid
        return;
    }

    // Create a new student node
    Student *newStudent = new Student;

    // Prompt the user to enter student ID
    cout << "Enter student ID: ";
    cin >> newStudent->ID;

    // Prompt the user to enter student name
    cout << "Enter student name: ";
    cin.ignore();  // Ignore the leftover newline character from previous input
    getline(cin, newStudent->name);  // Read the full name including spaces

    if (pos == 1) {  // If the position is 1, insert at the beginning
        // The new student's next pointer points to the current start
        newStudent->next = start;
        // Update the start to the new student
        start = newStudent;
        cout << "Student added at position 1.\n";
    } else {
        // Traverse the list to find the student at position pos-1
        Student *temp = start;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;  // Move to the next student
        }

        // If temp is NULL or temp->next is NULL, the position is out of bounds
        if (temp == NULL) {
            cout << "Position out of bounds.\n";
        } else {
            // The new student's next pointer should point to temp->next
            newStudent->next = temp->next;
            // Temp's next pointer should point to the new student
            temp->next = newStudent;
            cout << "Student added at position " << pos << ".\n";
        }
    }
}

// Function to remove student from the beginning
void remove_student_big() {
    if (start == NULL) {  // Check if the list is empty
        cout << "No students in the list.\n";
        return;
    }

    // Create a temporary pointer to hold the student to be deleted
    Student *temp = start;
    // Move the start pointer to the next student
    start = start->next;
    // Delete the student at the beginning
    delete temp;

    cout << "Student removed from the beginning.\n";
}

// Function to remove student from the end
void remove_student_end() {
    if (start == NULL) {  // If the list is empty
        cout << "No students in the list.\n";
        return;
    }

    if (start->next == NULL) {  // If there is only one student
        delete start;  // Delete the only student
        start = NULL;  // Set the start to NULL (empty list)
        cout << "Student removed from the end.\n";
        return;
    }

    // Traverse the list to find the second last student
    Student *temp = start;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;  // Move to the next student
    }

    // Delete the last student
    delete temp->next;
    // Set the second last student's next pointer to NULL
    temp->next = NULL;

    cout << "Student removed from the end.\n";
}

// Function to remove student from a specific position
void remove_student_specific_position() {
    int pos;
    // Prompt the user to enter the position to remove the student
    cout << "Enter position to remove: ";
    cin >> pos;

    if (start == NULL) {  // If the list is empty
        cout << "No students in the list.\n";
        return;
    }

    if (pos <= 0) {
        cout << "Invalid position.\n";  // Ensure the position is valid
        return;
    }

    if (pos == 1) {  // If the position is 1, remove the student at the beginning
        // Create a temporary pointer to hold the student to be deleted
        Student *temp = start;
        // Move the start pointer to the next student
        start = start->next;
        // Delete the student at the beginning
        delete temp;
        cout << "Student removed from position 1.\n";
        return;
    }

    // Traverse the list to find the student at position pos-1
    Student *temp = start;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;  // Move to the next student
    }

    // If temp is NULL or temp->next is NULL, the position is out of bounds
    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of bounds.\n";
    } else {
        // Create a pointer to the student to be deleted
        Student *delNode = temp->next;
        // Temp's next pointer should point to the next student's next pointer
        temp->next = temp->next->next;
        // Delete the student at the given position
        delete delNode;
        cout << "Student removed from position " << pos << ".\n";
    }
}

// Function to search for a student by ID
void search_student() {
    int searchID;
    // Prompt the user to enter student ID for search
    cout << "Enter student ID to search: ";
    cin >> searchID;

    if (start == NULL) {  // If the list is empty
        cout << "No students in the list.\n";
        return;
    }

    // Traverse the list to find the student with the matching ID
    Student *temp = start;
    while (temp != NULL) {
        if (temp->ID == searchID) {  // If ID matches
            cout << "Student found: ID = " << temp->ID << ", Name = " << temp->name << "\n";
            return;
        }
        temp = temp->next;  // Move to the next student
    }

    // If no student is found with the entered ID
    cout << "Student with ID " << searchID << " not found.\n";
}

// Function to traverse and print the list from head to tail
void traverse_head_to_tail() {
    if (start == NULL) {  // If the list is empty
        cout << "No students in the list.\n";
        return;
    }

    // Traverse the list and print each student's details
    Student *temp = start;
    while (temp != NULL) {
        cout << "ID: " << temp->ID << ", Name: " << temp->name << "\n";
        temp = temp->next;  // Move to the next student
    }

    // Indicate the end of the traversal
    cout << "Traversal complete from head to tail.\n";
}

// Main function
int main() {
    int choice;
    
    while (true) {
        // Display the menu of options to the user
        cout << "\nMenu:\n";
        cout << "1. Add at the beginning\n";
        cout << "2. Add at the end\n";
        cout << "3. Add at a specific position\n";
        cout << "4. Search Data\n";
        cout << "5. Remove from the beginning\n";
        cout << "6. Remove from the end\n";
        cout << "7. Remove from a specific position\n";
        cout << "8. Traverse from the head to the tail\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                insert_data_big();  // Insert at the beginning
                break;
            case 2:
                insert_data_end();  // Insert at the end
                break;
            case 3:
                insert_data_specific_position();  // Insert at a specific position
                break;
            case 4:
                search_student();  // Search for a student
                break;
            case 5:
                remove_student_big();  // Remove from the beginning
                break;
            case 6:
                remove_student_end();  // Remove from the end
                break;
            case 7:
                remove_student_specific_position();  // Remove from a specific position
                break;
            case 8:
                traverse_head_to_tail();  // Traverse from head to tail
                break;
            case 9:
                return 0;  // Exit the program
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
