#include <iostream>
#include <cstring> 
#include <conio.h> 
using namespace std;
struct student {
    char ID[25];
    char name[25];
    char grade[5];
    student *next;
} *start = NULL;
int count_nodes() {
    int count = 0;
    student *temp = start;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int n = count_nodes(); 
student *arr = new student[n]; 
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
}void search_data() {
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

   
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (strcmp(arr[mid].ID, searchID) == 0) {
            cout << "Student found! ID: " << arr[mid].ID
                 << ", Name: " << arr[mid].name << endl;
            cout << "Grades: ";
            for (int i = 0; i < arr[mid].gradeCount; i++) {
                cout << arr[mid].grades[i] << " ";
            }
            cout << endl;
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

void inverse_array(student *arr,n) {
	int n = count_nodes(); 
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i; 
        for (int j = i + 1; j < n; j++) {
            if ((arr[j].ID, arr[minIndex].ID) > 0) {
                maxIndex = j; 
            }
        }
        if (maxIndex != i) {
            student temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}
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


int main() {
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert Data\n";
        cout << "2. Search Data\n";
        cout << "3. sort\n";
        cout << "4. inverse_array\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert_data();
                break;
            case 2:
                search_data();
                break;
            case 3:
                sort_array();
                break;
            case 4:
                inverse_array();
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << " Please try again." << endl;
        }
    }
}

