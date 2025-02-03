#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
using namespace std;

struct queue {
    int id;
    string name;
    queue *next;
} *front = NULL, *rear = NULL;

void enqueue();
void dequeue();
void peek();
void display();

int main() {
    char ch = 'y';
    do {
        system("cls");
        int choice = 0;
        cout << "1) Enqueue\n"
             << "2) Dequeue\n"
             << "3) Peek\n"
             << "4) Display\n"
             << "5) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
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

void enqueue() {
    queue *temp = new queue;
    cout << "Please insert ID: ";
    cin >> temp->id;
    cout << "Please insert name: ";
    cin >> temp->name;
    temp->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    cout << "Element added to the queue!\n";
}

void dequeue() {
    if (front == NULL) {
        cout << "Underflow! Queue is empty.\n";
    } else {
        queue *temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        cout << "One element dequeued from the queue.\n";
    }
}

void peek() {
    if (front == NULL) {
        cout << "The queue is empty.\n";
    } else {
        cout << "ID: " << front->id << endl;
        cout << "Name: " << front->name << endl;
    }
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
    } else {
        for (queue *i = front; i != NULL; i = i->next) {
            cout << "ID: " << i->id << endl;
            cout << "Name: " << i->name << endl;
        }
    }
    getch();
}
