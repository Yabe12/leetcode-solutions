#include <iostream>
#include <cstring>
using namespace std;
struct student{
	char id [25];
	char name [25];
	char grade[10][5];
	int gradeCount; 
    struct student *next; 
	struct student*priv;
}student;
student *head = NULL, *tall = NULL;

void insert_data_big(){
	student * newstudent = new student;
	cout<<"Enter student id";
	cin>>newstudent->id;
	cout<<"Enter student name";
	cin>>newstudent->name;
	cout << "Enter number of grades: ";  
    cin >> newStudent->gradeCount;  
  
    for (int i = 0; i < newStudent->gradeCount; i++) {
        cout << "Enter grade " << i + 1 << ": "; 
        cin >> newStudent->grades[i];  
    }
    newstudent->next=head;
    newstudent->priv= NULL;
    if(head!=NULL){
		head->priv=newstudent;
	}
	head=newstudent;
	if(tall==NULL){
		tall=head;
	}
	cout<<"student add at the big";
}
void insert_data_end(){
	student * newstudent = new student;
	cout<<"Enter student id";
	cin>>newstudent->id;
	cout<<"Enter student name";
	cin>>newstudent->name;
	cout << "Enter number of grades: ";  
    cin >> newStudent->gradeCount;  
  
    for (int i = 0; i < newStudent->gradeCount; i++) {
        cout << "Enter grade " << i + 1 << ": "; 
        cin >> newStudent->grades[i];  
    }
    newstudent->next=head;
    newstudent->priv= NULL;
    if(tall!=NULL){
		tall->next=newstudent;
	}
	tall=newstudent;
	if(head==NULL){
		head=tall;
	}
	cout<<"student add at the end";
}
void insert_data_specific_position(){
	  cout<<"enter the postion to insert";
    cin>>postion;
    if(postion<1){
		cout<<"invalid position"
	}
	student * newstudent = new student;
	if(postion==1){
		insert_data_big();
	}
	cout<<"Enter student id";
	cin>>newstudent->id;
	cout<<"Enter student name";
	cin>>newstudent->name;
	cout << "Enter number of grades: ";  
    cin >> newStudent->gradeCount;  
  
    for (int i = 0; i < newStudent->gradeCount; i++) {
        cout << "Enter grade " << i + 1 << ": "; 
        cin >> newStudent->grades[i];  
    }
  student *temp=head;
   for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;  // Traverse to the node just before the desired position
    }
    
    if (temp == NULL) {  // If the position is out of range
        cout << "Position out of range.\n";  // Print error message
        return;  // Exit the function
    }
    newstudent->next=temp->next;
    if (temp->next != NULL) {  // If the next node exists
        temp->next->priv = newStudent;  // Update the previous pointer of the next node to point to the new student
    }
    temp->next = newStudent;  
   newstudent->priv=temp;
	cout << "Student added at position " << position << ".\n";
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
                insert_data_end();  
                break;
            case 3:
                insert_data_specific_position(); 
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
