#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
using namespace std;

struct stack {
    int id;
    string name;
    stack *next;
} *start = NULL;

void push();
void pop();
void peek();
void display();

int main() {
    char ch = 'y';
    do {
        system("cls");
        int choice = 0;
        cout << "1) for push\n"
             << "2) for pop\n"
             << "3) for peek\n"
             << "4) display\n"
             << "5) exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: ch = 'n'; cout << "Goodbye!"; break;
            default: cout << "Please enter a number between 1-5\n"; break;
        }

        if (choice != 4 && ch == 'y') {
            cout << "Press any key to continue...\n";
            getch();
        }

    } while (ch == 'y');

    return 0;
}

void push() {
    stack *temp = new stack;
    cout << "Please insert ID: ";
    cin >> temp->id;
    cout << "Please insert name: ";
    cin >> temp->name;

    if (start == NULL) {
        start = temp;
        temp->next = NULL;
    } else {
        temp->next = start;
        start = temp;
    }
}

void pop() {
    if (start == NULL) {
        cout << "Underflow\n";
    } else {
        stack *current = start;
        start = start->next;
        delete current;
        cout << "One student is deleted\n";
    }
}

void peek() {
    if (start == NULL) {
        cout << "None\n";
    } else {
        cout << "ID: " << start->id << endl;
        cout << "Name: " << start->name << endl;
    }
}

void display() {
    if (start == NULL) {
        cout << "Stack is empty\n";
    } else {
        for (stack *i = start; i != NULL; i = i->next) {
            cout << "ID: " << i->id << endl;
            cout << "Name: " << i->name << endl;
        }
    }
    getch();
}
