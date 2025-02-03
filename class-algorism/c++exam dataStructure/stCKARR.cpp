#include <iostream>
using namespace std;

struct Stack {
    int top;
    int capacity;
    int* arr;

    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into the stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }
        cout << arr[top--] << " popped from the stack.\n";
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getSize() {
        return top + 1;
    }

    void clear() {
        top = -1;
        cout << "Stack cleared.\n";
    }

    int getMin() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        int min = arr[0];
        for (int i = 1; i <= top; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack s(size);

    while (true) {
        int choice, value;
        cout << "\nStack Operations:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check if Empty\n6. Check if Full\n7. Get Stack Size\n8. Clear Stack\n9. Get Min Element\n10. Exit\n";
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
                cout << (s.isFull() ? "Stack is full.\n" : "Stack is not full.\n");
                break;
            case 7:
                cout << "Stack size: " << s.getSize() << endl;
                break;
            case 8:
                s.clear();
                break;
            case 9:
                cout << "Minimum element in stack: " << s.getMin() << endl;
                break;
            case 10:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
