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

void sort_array(student *arr,n) {
	int n = count_nodes(); 
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; 
        for (int j = i + 1; j < n; j++) {
            if ((arr[j].ID, arr[minIndex].ID) < 0) {
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
void search_data(student *arr,n) {
    if (start == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

  
  
    

    char searchID[25];
    cout << "Enter the ID to search: ";
    cin >> searchID;

  
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (strcmp(arr[mid].ID, searchID) == 0) {
            cout << "Student ID: " << arr[mid].ID << arr[mid].name<< arr[mid].grade << endl;
          
            return;
        } else if (strcmp(arr[mid].ID, searchID) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << "Student with ID " << searchID  << endl;
  
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

    char reID[25];
    cout << "Enter the ID of the student to remove: ";
    cin >> reID;

    student *temp = start;
    

    while (temp != NULL) {
    	for (int i = 0; i < n - 1; i++) {
			 if (strcmp(temp->ID, reID) == arr[i]) {
            delete temp;
            cout << "Student with ID " << removeID << " removed" << endl;
            return;
        } else{
			  cout << "Student with ID " << removeID << " not found." << endl;
		}
		}
  
    }

  
}

int main(){
	sort_array();
  insert_data();
  search_data();
   remove_student();
   inverse_array();
   return 0;
}