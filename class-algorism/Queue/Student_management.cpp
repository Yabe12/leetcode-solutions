#include<iostream>
#include<cstring>
using namespace std;
struct student{
    char ID[25];
    char name[25];
    struct student *next;
};
student *head=NULL;

int counter = 0;
int maxsize = 5;
bool ISEmpty (){
    if (counter){
        return true;
    }else{
        return false;
    }
}
bool IsFull(){
  if (counter<maxsize){
    return false;
}
bool Enqueue(){
  if (IsFull()){
    student *new_node = new student;
    cout << "Enter ID: ";
    cin >> new_node->ID;
    cout << "Enter Name: ";
    cin >> new_node->name;
    new_node->next = head;
    head = new_node;
    counter++;
  }else{
    cout << "Queue is full\n";
  }
};

bool Dequeue(){
  if (ISEmpty()){
    cout << "Queue is empty\n";
  } else {
    student *temp = head;
    head = head->next;
    cout << "Dequeued student ID: " << temp->ID << ", Name: " << temp->name << "\n";
    delete temp;
    counter--;
  }
}
void Queue::DisplayQueue(){
  if (ISEmpty()){
    cout << "Queue is empty\n";
  } else {
    student *temp = head;
    cout << "Queue: ";
    while (temp != NULL) {
      cout << "ID: " << temp->ID << ", Name: " << temp->name << " -> ";
      temp = temp->next;
    }
    cout << "NULL\n";
  }
}int main(void) {
cout << "Enqueue 5 items." << endl;
for (int x = 0; x < 5; x++)
Enqueue(x);
cout << "Now attempting to enqueue again..." << endl;
Enqueue(5);
DisplayQueue();
int value;
value = Dequeue();
cout << "Deleted element = " << value << endl;
DisplayQueue();
Enqueue(7);
DisplayQueue();
return 0;
}