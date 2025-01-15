#include <iostream>  // Include the input/output stream library for using 'cin' and 'cout'
#include <cstring>  // Include the string manipulation library for using 'strcmp'
using namespace std;  // Use the standard namespace to avoid needing to prefix with 'std::'

// Define the 'student' structure to store student-related data
struct student {
    char ID[25];  // Array to store the student ID (max 25 characters)
    char name[25];  // Array to store the student's name (max 25 characters)
    char grades[10][5];  // 2D array to store up to 10 grades (each grade is a string up to 4 characters)
    int gradeCount;  // Integer to track how many grades the student has
    struct student *next;  // Pointer to the next student node in the list
    struct student *priv;  // Pointer to the previous student node in the list
} Student;

// Declare two pointers, 'start' and 'end', to track the beginning and the end of the linked list
Student *start = NULL, *end = NULL;

// Function to add a new student at the beginning of the list
void insert_data_big() {
    Student *newStudent = new Student;  // Dynamically allocate memory for a new student object
    cout << "Enter ID: ";  // Ask the user to enter the student's ID
    cin >> newStudent->ID;  // Store the input ID in the 'ID' attribute of the new student
    cout << "Enter Name: ";  // Ask the user to enter the student's name
    cin >> newStudent->name;  // Store the input name in the 'name' attribute of the new student
    cout << "Enter number of grades: ";  // Ask the user to enter the number of grades
    cin >> newStudent->gradeCount;  // Store the number of grades in the 'gradeCount' attribute
    // Loop to get the grades from the user
    for (int i = 0; i < newStudent->gradeCount; i++) {
        cout << "Enter grade " << i + 1 << ": ";  // Prompt for each grade
        cin >> newStudent->grades[i];  // Store the entered grade in the 'grades' array
    }
    newStudent->next = start;  // Make the new student's next pointer point to the current first student
    newStudent->priv = NULL;  // The new student has no previous student since it's at the beginning
    if (start != NULL) {  // If there is already a student at the beginning
        start->priv = newStudent;  // Update the previous pointer of the old first student to point to the new student
    }
    start = newStudent;  // Set the new student as the first student in the list
    if (end == NULL) {  // If the list was empty
        end = start;  // Set the end pointer to point to the new student
    }
    cout << "Student added at the beginning.\n";  // Print confirmation
}

// Function to add a new student at the end of the list
void insert_data_end() {
    Student *newStudent = new Student;  // Dynamically allocate memory for a new student object
    cout << "Enter ID: ";  // Ask the user to enter the student's ID
    cin >> newStudent->ID;  // Store the input ID in the 'ID' attribute of the new student
    cout << "Enter Name: ";  // Ask the user to enter the student's name
    cin >> newStudent->name;  // Store the input name in the 'name' attribute of the new student
    cout << "Enter number of grades: ";  // Ask the user to enter the number of grades
    cin >> newStudent->gradeCount;  // Store the number of grades in the 'gradeCount' attribute
    // Loop to get the grades from the user
    for (int i = 0; i < newStudent->gradeCount; i++) {
        cout << "Enter grade " << i + 1 << ": ";  // Prompt for each grade
        cin >> newStudent->grades[i];  // Store the entered grade in the 'grades' array
    }
    newStudent->next = NULL;  // Make the new student's next pointer NULL since it's the last student
    newStudent->priv = end;  // The previous student will be the current last student
    if (end != NULL) {  // If there is already a student at the end
        end->next = newStudent;  // Update the current last student's next pointer to point to the new student
    }
    end = newStudent;  // Set the new student as the last student in the list
    if (start == NULL) {  // If the list was empty
        start = end;  // Set the start pointer to point to the new student
    }
    cout << "Student added at the end.\n";  // Print confirmation
}

// Function to add a new student at a specific position in the list
void insert_data_specific_position() {
    int position;
    cout << "Enter position to insert: ";  // Ask the user to enter the position where the student should be inserted
    cin >> position;  // Store the position in a variable
    
    if (position < 1) {  // If the position is less than 1, it's an invalid position
        cout << "Invalid position.\n";  // Print error message
        return;  // Exit the function
    }
    
    Student *newStudent = new Student;  // Dynamically allocate memory for a new student object
    cout << "Enter ID: ";  // Ask the user to enter the student's ID
    cin >> newStudent->ID;  // Store the input ID in the 'ID' attribute of the new student
    cout << "Enter Name: ";  // Ask the user to enter the student's name
    cin >> newStudent->name;  // Store the input name in the 'name' attribute of the new student
    cout << "Enter number of grades: ";  // Ask the user to enter the number of grades
    cin >> newStudent->gradeCount;  // Store the number of grades in the 'gradeCount' attribute
    // Loop to get the grades from the user
    for (int i = 0; i < newStudent->gradeCount; i++) {
        cout << "Enter grade " << i + 1 << ": ";  // Prompt for each grade
        cin >> newStudent->grades[i];  // Store the entered grade in the 'grades' array
    }
    
    // If the position is 1, we reuse the 'insert_data_big' function to add at the beginning
    if (position == 1) {
        insert_data_big();
        return;  // Exit the function after adding the student
    }
    
    Student *temp = start;  // Create a temporary pointer to traverse the list
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;  // Traverse to the node just before the desired position
    }
    
    if (temp == NULL) {  // If the position is out of range
        cout << "Position out of range.\n";  // Print error message
        return;  // Exit the function
    }
    
    newStudent->next = temp->next;  // Make the new student's next pointer point to the next node in the list
    if (temp->next != NULL) {  // If the next node exists
        temp->next->priv = newStudent;  // Update the previous pointer of the next node to point to the new student
    }
    temp->next = newStudent;  // Make the current node's next pointer point to the new student
    newStudent->priv = temp;  // Set the new student's previous pointer to the current node
    cout << "Student added at position " << position << ".\n";  // Print confirmation
}

// Function to search for a student by ID
void SearchData() {
    char searchID[25];
    cout << "Enter ID to search: ";  // Ask the user to input the ID of the student they want to search for
    cin >> searchID;  // Store the input ID in a variable
    
    Student *temp = start;  // Create a temporary pointer to traverse the list
    while (temp != NULL) {  // Loop until we reach the end of the list
        if (strcmp(temp->ID, searchID) == 0) {  // Compare the current student's ID with the search ID
            cout << "Student found: " << temp->name << endl;  // If the student is found, print their name
            return;  // Exit the function after finding the student
        }
        temp = temp->next;  // Move to the next student in the list
    }
    cout << "Student not found.\n";  // If the student is not found, print an error message
}

// Function to remove a student from the beginning of the list
void remove_student_big() {
    if (start == NULL) {  // If the list is empty, there are no students to remove
        cout << "No students to remove.\n";  // Print an error message
        return;  // Exit the function
    }
    
    Student *temp = start;  // Create a temporary pointer to hold the student to be removed
    start = start->next;  // Move the start pointer to the next student
    if (start != NULL) {  // If there are still students in the list
        start->priv = NULL;  // Set the previous pointer of the new first student to NULL
    } else {  // If the list is empty after removal
        end = NULL;  // Set the end pointer to NULL
    }
    delete temp;  // Delete the removed student
    cout << "Student removed from the beginning.\n";  // Print confirmation
}

// Function to remove a student from the end of the list
void remove_student_end() {
    if (end == NULL) {  // If the list is empty, there are no students to remove
        cout << "No students to remove.\n";  // Print an error message
        return;  // Exit the function
    }
    
    Student *temp = end;  // Create a temporary pointer to hold the student to be removed
    end = end->priv;  // Move the end pointer to the previous student
    if (end != NULL) {  // If there are still students in the list
        end->next = NULL;  // Set the next pointer of the new last student to NULL
    } else {  // If the list is empty after removal
        start = NULL;  // Set the start pointer to NULL
    }
    delete temp;  // Delete the removed student
    cout << "Student removed from the end.\n";  // Print confirmation
}

// Function to remove a student from a specific position in the list
void remove_student_specific_position() {
    int position;
    cout << "Enter position to remove: ";  // Ask the user to enter the position to remove a student
    cin >> position;  // Store the position in a variable
    
    if (position < 1) {  // If the position is less than 1, it's invalid
        cout << "Invalid position.\n";  // Print error message
        return;  // Exit the function
    }
    
    Student *temp = start;  // Create a temporary pointer to traverse the list
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;  // Traverse the list until the desired position
    }
    
    if (temp == NULL) {  // If the position is out of range
        cout << "Position out of range.\n";  // Print error message
        return;  // Exit the function
    }
    
    if (temp == start) {  // If the student to be removed is at the beginning
        remove_student_big();  // Call the function to remove from the beginning
        return;  // Exit the function
    }
    if (temp == end) {  // If the student to be removed is at the end
        remove_student_end();  // Call the function to remove from the end
        return;  // Exit the function
    }
    
    temp->priv->next = temp->next;  // Update the previous student's next pointer to skip the student being removed
    if (temp->next != NULL) {  // If there is a next student
        temp->next->priv = temp->priv;  // Update the next student's previous pointer to skip the student being removed
    }
    delete temp;  // Delete the student being removed
    cout << "Student removed from position " << position << ".\n";  // Print confirmation
}

// Function to traverse the list from head to tail
void traverse_head_to_tail() {
    Student *temp = start;  // Create a temporary pointer to traverse the list
    while (temp != NULL) {  // Loop until we reach the end of the list
        cout << "ID: " << temp->ID << " Name: " << temp->name << endl;  // Print the student's ID and name
        temp = temp->next;  // Move to the next student in the list
    }
}

// Function to traverse the list from tail to head
void traverse_tail_to_head() {
    Student *temp = end;  // Create a temporary pointer to start at the end of the list
    while (temp != NULL) {  // Loop until we reach the beginning of the list
        cout << "ID: " << temp->ID << " Name: " << temp->name << endl;  // Print the student's ID and name
        temp = temp->priv;  // Move to the previous student in the list
    }
}

int main() {
    int choice;
    
    while (true) {  // Infinite loop to keep showing the menu
        cout << "\nMenu:\n";
        cout << "1. Add at the beginning\n";
        cout << "2. Add at the end\n";
        cout << "3. Add at a specific position\n";
        cout << "4. Search Data\n";
        cout << "5. Remove from the beginning\n";
        cout << "6. Remove from the end\n";
        cout << "7. Remove from a specific position\n";
        cout << "8. Traverse from head to tail\n";
        cout << "9. Traverse from tail to head\n";
        cout << "10. Exit\n";  // Exit option
        cout << "Enter your choice: ";  // Prompt for user input
        cin >> choice;  // Read the user's choice
        
        switch (choice) {  // Perform action based on the user's choice
            case 1:
                insert_data_big();  // Call function to add at the beginning
                break;
            case 2:
                insert_data_end();  // Call function to add at the end
                break;
            case 3:
                insert_data_specific_position();  // Call function to add at a specific position
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
    return 0;  // Exit the program
}
