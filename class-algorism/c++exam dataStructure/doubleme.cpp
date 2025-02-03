#include <iostream>
using namespace std;

// Structure to store student details
struct Node {
    int id;
    char name[20];
    Node* prev;
    Node* next;
} *head = NULL, *tail = NULL;

void insertAtEnd();
void insertAtBeginning();
void insertBeforeId(int id);
void insertAfterId(int id);
void deleteById();
void display();
void reverseList();
void searchById(int id);
void sortList();

void insertAtEnd() {
    Node* temp = new Node;
    cout << "Enter the ID: ";
    cin >> temp->id;
    cout << "Enter the Name: ";
    cin >> temp->name;
    temp->next = NULL;
    temp->prev = tail;
    
    if (tail != NULL) {
        tail->next = temp;
    } else {
        head = temp;
    }
    tail = temp;
    cout << "Student added: " << temp->name << " (ID: " << temp->id << ")\n";
}

void insertAtBeginning() {
    Node* temp = new Node;
    cout << "Enter the ID: ";
    cin >> temp->id;
    cout << "Enter the Name: ";
    cin >> temp->name;
    temp->next = head;
    temp->prev = NULL;
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
    if (tail == NULL) {
        tail = temp;
    }
    cout << "Student inserted at the beginning.\n";
}

void insertBeforeId(int id) {
    Node* temp = head;
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "ID not found.\n";
        return;
    }
    Node* newNode = new Node;
    cout << "Enter the ID: ";
    cin >> newNode->id;
    cout << "Enter the Name: ";
    cin >> newNode->name;
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }
    temp->prev = newNode;
    cout << "Inserted before ID " << id << "\n";
}

void insertAfterId(int id) {
    Node* temp = head;
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "ID not found.\n";
        return;
    }
    Node* newNode = new Node;
    cout << "Enter the ID: ";
    cin >> newNode->id;
    cout << "Enter the Name: ";
    cin >> newNode->name;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    } else {
        tail = newNode;
    }
    temp->next = newNode;
    cout << "Inserted after ID " << id << "\n";
}

void deleteById() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    Node* temp = head;
    
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        cout << "Student with ID " << id << " not found.\n";
        return;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev;
    }
    
    cout << "Removed student: " << temp->name << " (ID: " << temp->id << ")\n";
    delete temp;
}

void reverseList() {
    Node* temp = NULL;
    Node* current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        head = temp->prev;
    }
    cout << "List reversed.\n";
}

void searchById(int id) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Student Found - ID: " << temp->id << ", Name: " << temp->name << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found.\n";
}

void sortList() {
    if (!head) return;
    Node* i, *j;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->id > j->id) {
                swap(i->id, j->id);
                swap(i->name, j->name);
            }
        }
    }
    cout << "List sorted.\n";
}

void display() {
    if (head == NULL) {
        cout << "No element found\n";
        return;
    }
    Node* temp = head;
    cout << "Students in List:\n";
    while (temp != NULL) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << "\n";
        temp = temp->next;
    }
}

int main() {
    int choice, id;
    do {
        cout << "\nDoubly Linked List Operations\n";
        cout << "--------------------------------\n";
        cout << "1) Insert at End\n2) Insert at Beginning\n3) Insert Before ID\n4) Insert After ID\n5) Delete by ID\n6) Display\n7) Reverse List\n8) Search by ID\n9) Sort List\n10) Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: insertAtEnd(); break;
            case 2: insertAtBeginning(); break;
            case 3: cout << "Enter ID: "; cin >> id; insertBeforeId(id); break;
            case 4: cout << "Enter ID: "; cin >> id; insertAfterId(id); break;
            case 5: deleteById(); break;
            case 6: display(); break;
            case 7: reverseList(); break;
            case 8: cout << "Enter ID: "; cin >> id; searchById(id); break;
            case 9: sortList(); break;
            case 10: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 10);
    return 0;
}
