#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

struct Queue {
    Node* front;
    Node* rear;
    
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == NULL) {
            front = rear = newNode; 
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued into the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue.\n";
            return;
        }
        Node* temp = front;
        cout << front->data << " dequeued from the queue.\n";
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getSize() {
        int size = 0;
        Node* temp = front;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
        cout << "Queue cleared.\n";
    }

    ~Queue() {
        clear(); 
    }
};

int main() {
    Queue q;

    while (true) {
        int choice, value;
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check if Empty\n6. Get Queue Size\n7. Clear Queue\n8. Exit\n";
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
                cout << "Queue size: " << q.getSize() << endl;
                break;
            case 7:
                q.clear();
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
