
#include <iostream>
#include <cstring>
using namespace std;
 struct student {
    char ID[25];
    char name[25];
    char grades[10][5];
    int gradeCount;
    struct student *next;
    struct student *priv;
} Student;

Student *start = NULL, *end = NULL;

void insert_data() {
    student *newnode = new student;
    cout << "Please enter ID: ";
    cin >> temp->ID;
    cout << "Please enter name: ";
    cin >> temp->name;
    if(start == NULL){
		start= temp;
		temp->next=NULL;
		temp->priv=NULL;
	}
	else if (start->next == Null){
		start->next=temp;
		temp->priv=start;
		temp->priv=null;
	}
    else{
		int id;
		cout<<"where you what to add";
		cin>>id;
		student *curr =start;
		while(curr->id!=id&&curr->next!=NULL){
			curr=curr->next;
			if(curr->next==NULL){
				curr->next=temp;
				temp->prev=curr;
				temp->next=NULL;
			}
			else{
				curr->next->prev=temp;
				temp->next=curr->next;
				curr->next=temp;
				temp->prev=curr;
			}
		}
	}
}

void display() {
    if (start == NULL) {
        cout << "The list is empty." << endl;
    } else {
        cout << "Students in the list:" << endl;
        for (student *curr = start; curr != NULL; curr = curr->next) {
            cout << "ID: " << curr->ID << ", Name: " << curr->name << endl;
        }
    }
}
int main() {
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert Data\n";
        cout << "2. Search Data\n";
        cout << "3. Remove Student\n";
        cout << "4. search and display\n";
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
                remove_student();
                break;
            case 4:
                seachanddesplay_student();
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
