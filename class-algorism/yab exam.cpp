#include <iostream>
#include <cstring> 
using namespace std;

struct student {
    char ID[25];
    char name[25];
    char grade[5];
    student *next;
} *start = NULL;

// Function to count the number of nodes in the linked list
int count_nodes() {
    int count = 0;
    student *temp = start;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to insert a new student record
void insert_data() {
    student *newnode = new student;
    cout << "Please enter ID: ";
    cin >> newnode->ID;
    cout << "Please enter name: ";
    cin >> newnode->name;
    cout << "Please enter grade: ";
    cin >> newnode->grade;
    newnode->next = start;
    start = newnode;
    cout << "Student added successfully!" << endl;
}

// Function to copy linked list data into an array
void copy_to_array(student *arr, int n) {
    student *temp = start;
    for (int i = 0; i < n && temp != NULL; i++) {
        arr[i] = *temp; // Copying student data
        temp = temp->next;
    }
}

// Function to sort the array based on student ID
void sort_array(student *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; 
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j].ID, arr[minIndex].ID) < 0) {
                minIndex = j; 
            }
        }
        if (minIndex != i) {
            student temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function to search for a student by ID
void search_data() {
    if (start == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    int n = count_nodes(); 
    student *arr = new student[n]; 
    copy_to_array(arr, n); 
    sort_array(arr, n); 

    char searchID[25];
    cout << "Enter the ID to search: ";
    cin >> searchID;

    // Binary search implementation
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (strcmp(arr[mid].ID, searchID) == 0) {
            cout << "Student found! ID: " << arr[mid].ID
                 << ", Name: " << arr[mid].name 
                 << ", Grade: " << arr[mid].grade << endl;
            delete[] arr;
            return;
        } else if (strcmp(arr[mid].ID, searchID) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << "Student with ID " << searchID << " not found." << endl;
    delete[] arr; 
}

// Function to reverse (inverse) the array
void inverse_array(student *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        student temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

// Function to remove a student by ID
void remove_student() {
    if (start == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    char removeID[25];
    cout << "Enter the ID of the student to remove: ";
    cin >> removeID;

    student *temp = start;
    student *prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->ID, removeID) == 0) {
            if (prev == NULL) {
                start = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Student with ID " << removeID << " removed successfully!" << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Student with ID " << removeID << " not found." << endl;
}

// Main function with menu
int main() {
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert Data\n";
        cout << "2. Search Data\n";
        cout << "3. Sort Data\n";
        cout << "4. Reverse Data\n";
        cout << "5. Remove Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int n = count_nodes();
        student *arr = new student[n];

        switch (choice) {
            case 1:
                insert_data();
                break;
            case 2:
                search_data();
                break;
            case 3:
                copy_to_array(arr, n);
                sort_array(arr, n);
                cout << "Students sorted by ID." << endl;
                break;
            case 4:
                copy_to_array(arr, n);
                inverse_array(arr, n);
                cout << "Students list reversed." << endl;
                break;
            case 5:
                remove_student();
                break;
            case 6:
                cout << "Exiting program." << endl;
                delete[] arr;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        delete[] arr; 
    }
}
