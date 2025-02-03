#include <iostream>
using namespace std;

// Structure to store student details
struct Node {
    int id;
    char name[20];
    Node* next;
} *last = NULL;

void insert();
void remove();
void display();
void searchById();
void sortList();
void reverseList();

void insert() {
    Node* temp = new Node;
    cout << "Enter the ID: ";
    cin >> temp->id;
    cout << "Enter the Name: ";
    cin >> temp->name;
    if (last == NULL) {
        last = temp;
        last->next = last;
    } else {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
    cout << "Student added: " << temp->name << " (ID: " << temp->id << ")\n";
}

void remove() {
    if (last == NULL) {
        cout << "Underflow\n";
    } else if (last->next == last) {
        cout << "Removed student: " << last->name << " (ID: " << last->id << ")\n";
        delete last;
        last = NULL;
    } else {
        Node* temp = last->next;
        last->next = temp->next;
        cout << "Removed student: " << temp->name << " (ID: " << temp->id << ")\n";
        delete temp;
    }
}

void display() {
    if (last == NULL) {
        cout << "No element found\n";
    } else {
        Node* temp = last->next;
        cout << "Students in Circular Linked List:\n";
        do {
            cout << "ID: " << temp->id << ", Name: " << temp->name << "\n";
            temp = temp->next;
        } while (temp != last->next);
    }
}

void searchById() {
    if (last == NULL) {
        cout << "List is empty!\n";
        return;
    }
    int id;
    cout << "Enter ID to search: ";
    cin >> id;
    Node* temp = last->next;
    do {
        if (temp->id == id) {
            cout << "Student found: ID: " << temp->id << ", Name: " << temp->name << "\n";
            return;
        }
        temp = temp->next;
    } while (temp != last->next);
    cout << "Student with ID " << id << " not found.\n";
}

void sortList() {
    if (last == NULL || last->next == last) {
        cout << "List is already sorted or empty.\n";
        return;
    }
    Node* current = last->next;
    Node* index = NULL;
    int tempId;
    char tempName[20];
    do {
        index = current->next;
        while (index != last->next) {
            if (current->id > index->id) {
                tempId = current->id;
                strcpy(tempName, current->name);
                current->id = index->id;
                strcpy(current->name, index->name);
                index->id = tempId;
                strcpy(index->name, tempName);
            }
            index = index->next;
        }
        current = current->next;
    } while (current != last->next);
    cout << "List sorted by ID.\n";
}

void reverseList() {
    if (last == NULL || last->next == last) {
        cout << "Nothing to reverse or only one element present.\n";
        return;
    }
    Node* prev = last;
    Node* current = last->next;
    Node* next = NULL;
    Node* first = last->next;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != first);
    last = first;
    cout << "List reversed.\n";
}

int main() {
    int choice;
    do {
        cout << "\nCircular Linked List Operations\n";
        cout << "----------------------------\n";
        cout << "1) Insert\n";
        cout << "2) Remove\n";
        cout << "3) Display\n";
        cout << "4) Search by ID\n";
        cout << "5) Sort by ID\n";
        cout << "6) Reverse List\n";
        cout << "7) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                remove();
                break;
            case 3:
                display();
                break;
            case 4:
                searchById();
                break;
            case 5:
                sortList();
                break;
            case 6:
                reverseList();
                break;
            case 7:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Please enter a valid choice.\n";
                break;
        }
    } while (choice != 7);

    return 0;
}