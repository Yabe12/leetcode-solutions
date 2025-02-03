#include <iostream>
using namespace std;

struct Queue {
    int front;
    int rear;
    int capacity;
    int* arr;

    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) {
            front = 0; 
        }
        arr[++rear] = value;
        cout << value << " enqueued into the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue.\n";
            return;
        }
        cout << arr[front] << " dequeued from the queue.\n";
        if (front == rear) {
            front = rear = -1; 
        } else {
            front++;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getSize() {
        if (isEmpty()) {
            return 0;
        }
        return rear - front + 1;
    }

    void clear() {
        front = rear = -1;
        cout << "Queue cleared.\n";
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);

    while (true) {
        int choice, value;
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check if Empty\n6. Check if Full\n7. Get Queue Size\n8. Clear Queue\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Front element: " << q.peek() << endl;
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 6:
                cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 7:
                cout << "Queue size: " << q.getSize() << endl;
                break;
            case 8:
                q.clear();
                break;
            case 9:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
