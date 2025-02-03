#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(NULL) {}
};

struct Stack {
    Node* top;
    int size;

    Stack() : top(NULL), size(0) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
        cout << value << " pushed into the stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from the stack.\n";
        top = top->next;
        delete temp;
        size--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getSize() {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
        cout << "Stack cleared.\n";
    }
};

int main() {
    Stack s;

    while (true) {
        int choice, value;
        cout << "\nStack Operations:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check if Empty\n6. Size of Stack\n7. Clear Stack\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top element: " << s.peek() << endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << (s.isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
                break;
            case 6:
                cout << "Stack size: " << s.getSize() << endl;
                break;
            case 7:
                s.clear();
                break;
            case 8:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
