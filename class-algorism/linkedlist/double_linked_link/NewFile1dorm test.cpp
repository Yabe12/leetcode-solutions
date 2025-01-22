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
        cout << "8. Traverse from head to tail\n";
        cout << "9. Traverse from tail to head\n";
        cout << "10. Exit\n"; 
        cout << "Enter your choice: ";  
        cin >> choice; 
        
        switch (choice) { 
            case 1:
                insert_data_big();  
                break;
            case 2:
                //insert_data_end();  
                break;
            case 3:
                //insert_data_specific_position(); 
                break;
            case 4:
                //SearchData();  
                break;
            case 5:
                //remove_student_big();  
                break;
            case 6:
                //remove_student_end();
                break;
            case 7:
                //remove_student_specific_position();  
                break;
            case 8:
                //traverse_head_to_tail(); 
                break;
            case 9:
                //traverse_tail_to_head(); 
				 break; 
            case 10:
                //exit(0); 
            default:
                cout << "Invalid choice.\n";  
        }
    }
    return 0; 
}










#include <iostream>
using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate the mid-point to avoid overflow

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter the target value to search: ";
    cin >> target;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}




#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];  // Element to be compared
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;  // Place the key in the correct position
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    insertionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
