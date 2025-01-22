#include <iostream>
#include <cstring>
using namespace std;
struct student{
    char ID[25];
    char name[25];
    struct student *next;
};
student *head = NULL;
void push();
void pop();
void peak();
void display();
void search();
int main(){
 int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. push\n";
        cout << "2. pop\n";
        cout << "3. peak\n";
        cout << "4. display\n";
        cout<< "5. search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                 push();
                break;
            case 2:
               pop();
                break;
            case 3:
                peak();
                break;
             case 4:
                display();
                break;
            case 5:
                search();
                break;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}

void push(){
  student *temp = new student;
    cout << "Enter ID: ";
    cin >> temp->ID;
    cout << "Enter Name: ";
    cin >> temp->name;
    temp->next = head;
    head = temp;
    cout << "Student pushed successfully\n";
}

void pop(){
  if(head == NULL) {
    cout << "Stack is empty\n";
    return;
  }
  student *temp = head;
  head = head->next;
  delete temp;
  cout << "Student popped successfully\n";
}
void peak(){
  if(head == NULL) {
    cout << "Stack is empty\n";
    return;
  }
  cout << "ID: " << head->ID << endl;
  cout << "Name: " << head->name << endl;
}

void display(){
  if(head == NULL) {
    cout << "Stack is empty\n";
    return;
  }
  student *temp = head;
  while(temp != NULL) {
    cout << "ID: " << temp->ID << endl;
    cout << "Name: " << temp->name << endl;
    temp = temp->next;
  }
}
void search(){
  char searchID[25];
  if(head == NULL){
    cout << "Stack is empty\n";
    return;
  }
  cout << "Enter ID: " ;
  cin>>searchID;
  student *temp = head;
  while(temp != NULL) {
if(strcmp(temp->ID, searchID)==0){
  cout << "ID: " << temp->ID << endl;
  cout <<"name: " << temp->name << endl;
  return;
}
temp = temp->next;
  }
  cout << "the student not found here\n";
}