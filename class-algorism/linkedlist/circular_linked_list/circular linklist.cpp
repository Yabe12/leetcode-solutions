#include <iostream>
#include <string>
using namespace std;

// Structure for the student, with a circular doubly linked list
struct Student {
    int ID;              // Store student ID
    string name;         // Store student name
    float grades[5];     // Array to store up to 5 grades for the student
    Student *next, *priv; // Pointers for the next and previous student (for circular doubly linked list)
};

// Global pointer to keep track of the circular doubly linked list's head
Student *start = NULL;

// Function to insert a student at the beginning of the list
void insert_data_big() {
    Student *newStudent = new Student;  // Create a new student node dynamically
    cout << "Enter student ID: ";
    cin >> newStudent->ID;             // Input the student's ID
    cout << "Enter student name: ";
    cin >> newStudent->name;           // Input the student's name

    newStudent->next = newStudent;     // The 'next' pointer of the new node points to itself
    newStudent->priv = newStudent;     // The 'priv' pointer of the new node points to itself (circular reference)

    if (start == NULL) {
        start = newStudent;            // If the list is empty, make the new node the start of the list
    } else {
        Student *last = start->priv;   // Find the last node in the circular list by accessing the 'priv' pointer of the start
        last->next = newStudent;       // Set the last node's 'next' to point to the new node
        newStudent->priv = last;       // Set the new node's 'priv' to point to the last node
        start->priv = newStudent;      // The start node's 'priv' points to the new node (creating a circular link)
        newStudent->next = start;      // The new node's 'next' points to the start node (circular link)
    }

    cout << "Student added at the beginning.\n"; // Inform user that the student has been added at the beginning
}

// Function to insert a student at the end of the list
void insert_data_end() {
    Student *newStudent = new Student;  // Create a new student node dynamically
    cout << "Enter student ID: ";
    cin >> newStudent->ID;             // Input the student's ID
    cout << "Enter student name: ";
    cin >> newStudent->name;           // Input the student's name

    newStudent->next = newStudent;     // The 'next' pointer of the new node points to itself
    newStudent->priv = newStudent;     // The 'priv' pointer of the new node points to itself (circular reference)

    if (start == NULL) {
        start = newStudent;            // If the list is empty, make the new node the start of the list
    } else {
        Student *last = start->priv;   // Find the last node in the circular list by accessing the 'priv' pointer of the start
        last->next = newStudent;       // Set the last node's 'next' to point to the new node
        newStudent->priv = last;       // Set the new node's 'priv' to point to the last node
        start->priv = newStudent;      // The start node's 'priv' points to the new node (creating a circular link)
        newStudent->next = start;      // The new node's 'next' points to the start node (circular link)
    }

    cout << "Student added at the end.\n"; // Inform user that the student has been added at the end
}

// Function to insert a student at a specific position in the list
void insert_data_specific_position() {
    int position;
    cout << "Enter position to insert: ";
    cin >> position; // Get the position where the student should be inserted

    if (position < 1) { // If the position is invalid (less than 1)
        cout << "Invalid position.\n"; // Inform the user
        return;
    }

    Student *newStudent = new Student;  // Create a new student node dynamically
    cout << "Enter student ID: ";
    cin >> newStudent->ID;             // Input the student's ID
    cout << "Enter student name: ";
    cin >> newStudent->name;           // Input the student's name

    if (position == 1) {
        insert_data_big();  // If position is 1, just insert at the beginning
        return;
    }

    Student *temp = start;  // Start from the beginning of the list
    for (int i = 1; i < position && temp != NULL; i++) { // Traverse to the specified position
        temp = temp->next;
    }

    if (temp == NULL) { // If the position is out of range
        cout << "Position out of range.\n";
        delete newStudent; // Free the memory for the new node
        return;
    }

    newStudent->next = temp;     // Link the new node's next to the current node
    newStudent->priv = temp->priv; // Link the new node's priv to the previous node
    temp->priv->next = newStudent; // Link the previous node's next to the new node
    temp->priv = newStudent;      // Link the current node's priv to the new node

    cout << "Student added at position " << position << ".\n"; // Inform the user the student has been added
}

// Function to remove the first student in the list
void remove_student_big() {
    if (start == NULL) {  // If the list is empty, there's nothing to remove
        cout << "No students to remove.\n";
        return;
    }

    Student *temp = start; // Temporarily store the start node
    if (start->next == start) { // If there's only one node
        start = NULL; // Set the start to NULL to indicate the list is now empty
    } else {
        Student *last = start->priv;  // Find the last node in the list
        start = start->next;           // Move the start pointer to the next node
        last->next = start;            // Set the last node's next to point to the new start
        start->priv = last;            // Set the start's priv to point to the last node
    }

    delete temp;  // Delete the old start node to free memory
    cout << "Student removed from the beginning.\n"; // Inform the user that the student was removed
}

// Function to remove the last student in the list
void remove_student_end() {
    if (start == NULL) {  // If the list is empty, there's nothing to remove
        cout << "No students to remove.\n";
        return;
    }

    Student *temp = start->priv; // Store the last node temporarily
    if (start->next == start) {  // If there's only one node in the list
        start = NULL; // Set the start pointer to NULL to empty the list
    } else {
        start->priv = temp->priv; // Set the start's priv to the second-last node
        temp->priv->next = start; // Set the second-last node's next to point to the start
    }

    delete temp;  // Delete the last node to free memory
    cout << "Student removed from the end.\n"; // Inform the user that the student was removed
}

// Function to remove a student from a specific position
void remove_student_specific_position() {
    int position;
    cout << "Enter position to remove: ";
    cin >> position;  // Get the position to remove from

    if (position < 1) { // If the position is invalid (less than 1)
        cout << "Invalid position.\n";
        return;
    }

    if (start == NULL) { // If the list is empty, there's nothing to remove
        cout << "No students to remove.\n";
        return;
    }

    Student *temp = start;  // Start from the beginning of the list
    for (int i = 1; i < position && temp != NULL; i++) { // Traverse to the specified position
        temp = temp->next;
    }

    if (temp == NULL) {  // If the position is out of range
        cout << "Position out of range.\n";
        return;
    }

    if (temp == start) {  // If the student to remove is at the beginning
        remove_student_big();  // Call remove from the beginning
        return;
    }

    if (temp == start->priv) {  // If the student to remove is at the end
        remove_student_end();  // Call remove from the end
        return;
    }

    temp->priv->next = temp->next;  // Link the previous node's next to the next node
    temp->next->priv = temp->priv;  // Link the next node's priv to the previous node

    delete temp;  // Delete the student node to free memory
    cout << "Student removed from position " << position << ".\n"; // Inform the user the student was removed
}

// Function to traverse the list from head to tail (forward direction)
void traverse_head_to_tail() {
    if (start == NULL) {  // If the list is empty
        cout << "No students in the list.\n";
        return;
    }

    Student *temp = start;  // Start from the beginning of the list
    do {
        cout << "ID: " << temp->ID << ", Name: " << temp->name << "\n"; // Print student details
        temp = temp->next;  // Move to the next student
    } while (temp != start);  // Continue until we've looped back to the start

    cout << "Traversal complete from head to tail.\n";  // End of traversal message
}

// Function to traverse the list from tail to head (reverse direction)
void traverse_tail_to_head() {
    if (start == NULL) {  // If the list is empty
        cout << "No students in the list.\n";
        return;
    }

    Student *temp = start->priv;  // Start from the last node (priv pointer of the start)
    do {
        cout << "ID: " << temp->ID << ", Name: " << temp->name << "\n"; // Print student details
        temp = temp->priv;  // Move to the previous student
    } while (temp != start->priv);  // Continue until we've looped back to the last node

    cout << "Traversal complete from tail to head.\n";  // End of traversal message
}

// Function to search for a student by ID
void search_student() {
    int searchID;
    cout << "Enter student ID to search: ";
    cin >> searchID; // Get the student ID to search for

    if (start == NULL) {  // If the list is empty
        cout << "No students in the list.\n";
        return;
    }

    Student *temp = start;  // Start from the first node
    do {
        if (temp->ID == searchID) {  // If the ID matches the search ID
            cout << "Student found: ID = " << temp->ID << ", Name = " << temp->name << "\n"; // Display student info
            return;
        }
        temp = temp->next;  // Move to the next node
    } while (temp != start);  // Continue until we've looped back to the start

    cout << "Student with ID " << searchID << " not found.\n"; // If no match is found
}

int main() {
    int choice;
    
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
        cin >> choice;
        
        switch (choice) {
            case 1:
                insert_data_big();  // Insert student at the beginning
                break;
            case 2:
                insert_data_end();  // Insert student at the end
                break;
            case 3:
                insert_data_specific_position();  // Insert student at a specific position
                break;
            case 4:
                search_student();  // Search for a student
                break;
            case 5:
                remove_student_big();  // Remove student from the beginning
                break;
            case 6:
                remove_student_end();  // Remove student from the end
                break;
            case 7:
                remove_student_specific_position();  // Remove student from a specific position
                break;
            case 8:
                traverse_head_to_tail();  // Traverse from head to tail
                break;
            case 9:
                traverse_tail_to_head();  // Traverse from tail to head
                break;
            case 10:
                return 0;  // Exit the program
            default:
                cout << "Invalid choice! Please enter a valid number.\n";  // Invalid option
                break;
        }
    }

    return 0;  // End the program
}
