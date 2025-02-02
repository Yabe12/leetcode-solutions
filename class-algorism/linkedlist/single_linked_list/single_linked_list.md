Let's go step by step and cover everything in detail regarding **Singly Linked List (SLL) in C++**.

---

# **Singly Linked List in C++**
## **1. What is a Singly Linked List?**
A **Singly Linked List (SLL)** is a type of data structure where elements (nodes) are linked sequentially using pointers. Each node contains:
- **Data** (stores the value).
- **Pointer (next)** (stores the address of the next node).

The list is **unidirectional**, meaning it can be traversed only in **one direction** (from head to tail).

### **Structure of a Singly Linked List**
```
[10 | * ] --> [20 | * ] --> [30 | * ] --> NULL
 ^ Head
```
- Each node contains:
  - `10` → Data  
  - `*` → Pointer to the next node  
- The last node’s pointer is `NULL`, indicating the end of the list.

---

## **2. How Does a Singly Linked List Work?**
### **Step-by-Step Working**
1. **Initialization**  
   - The list starts with a `head` pointer, which points to the first node.
   - If the list is empty, `head = NULL`.

2. **Insertion**  
   - A new node is created dynamically.
   - The `next` pointer of the new node is updated to link it to the correct position.

3. **Traversal**  
   - Start from `head`, follow `next` pointers until reaching `NULL`.

4. **Deletion**  
   - Find the node to delete.
   - Update the previous node’s `next` pointer to bypass the deleted node.

---
# **Singly Linked List (SLL) – Detailed Explanation & Implementation in C++**  

In this detailed note, we will cover:  
1. **Insertion** (Beginning, End, Specific Position)  
2. **Deletion** (Beginning, End, Specific Position)  
3. **Searching** (Beginning, End, Specific Position, Value)  
4. **Displaying the List**  

For each operation, we will explain:  
✅ **How it works (Logic)**  
✅ **C++ Implementation**  

---

## **1️⃣ Insertion in Singly Linked List**  
### **1.1 Insertion at the Beginning**
### **🔹 Logic**
1. Create a new node.
2. Set `next` of the new node to `head`.
3. Update `head` to point to the new node.

### **🔹 Implementation**
```cpp
void insertAtBeginning(int value) {
    Node* newNode = new Node(value); // Step 1: Create a new node
    newNode->next = head;            // Step 2: Link new node to the previous head
    head = newNode;                   // Step 3: Update head to the new node
}
```

---

### **1.2 Insertion at the End**
### **🔹 Logic**
1. Create a new node.
2. If the list is empty, set `head = newNode`.
3. Traverse to the last node.
4. Set `next` of the last node to `newNode`.

### **🔹 Implementation**
```cpp
void insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (head == NULL) { 
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) { 
        temp = temp->next;
    }
    temp->next = newNode;
}
```

---

### **1.3 Insertion at a Specific Position**
### **🔹 Logic**
1. If inserting at position `1`, call `insertAtBeginning()`.
2. Traverse to the node **before** the target position.
3. Insert the new node and adjust pointers.

### **🔹 Implementation**
```cpp
void insertAtPosition(int value, int position) {
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    
    Node* newNode = new Node(value);
    Node* temp = head;
    
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range\n";
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}
```

---

## **2️⃣ Deletion in Singly Linked List**  

### **2.1 Deletion from the Beginning**
### **🔹 Logic**
1. If the list is empty, return.
2. Store `head` in a temporary pointer.
3. Move `head` to `head->next`.
4. Delete the old `head`.

### **🔹 Implementation**
```cpp
void deleteFromBeginning() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}
```

---

### **2.2 Deletion from the End**
### **🔹 Logic**
1. If the list is empty, return.
2. If only one node exists, delete `head` and set `head = NULL`.
3. Traverse to the **second-last node**.
4. Set `next` to `NULL` and delete the last node.

### **🔹 Implementation**
```cpp
void deleteFromEnd() {
    if (head == NULL) return;
    if (head->next == NULL) { 
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}
```

---

### **2.3 Deletion from a Specific Position**
### **🔹 Logic**
1. If `position == 1`, call `deleteFromBeginning()`.
2. Traverse to the **node before** the target position.
3. Unlink and delete the target node.

### **🔹 Implementation**
```cpp
void deleteFromPosition(int position) {
    if (head == NULL) return;
    if (position == 1) {
        deleteFromBeginning();
        return;
    }
    Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) return;
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}
```

---

## **3️⃣ Searching in Singly Linked List**

### **3.1 Search from the Beginning**
### **🔹 Logic**
1. Start from `head`.
2. Traverse each node, checking if `data == value`.
3. If found, return `true`; else return `false`.

### **🔹 Implementation**
```cpp
bool searchFromBeginning(int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}
```

---

### **3.2 Search from the End**
### **🔹 Logic**
1. Traverse the list and store nodes in a **stack** (Last-In-First-Out).
2. Pop nodes and check for the value.

### **🔹 Implementation**
```cpp
bool searchFromEnd(int value) {
    vector<Node*> stack;
    Node* temp = head;
    while (temp != NULL) {
        stack.push_back(temp);
        temp = temp->next;
    }
    while (!stack.empty()) {
        temp = stack.back();
        stack.pop_back();
        if (temp->data == value) return true;
    }
    return false;
}
```

---

### **3.3 Search from a Specific Position**
### **🔹 Logic**
1. Traverse to the specified position.
2. Check if `data == value`.

### **🔹 Implementation**
```cpp
bool searchFromPosition(int position, int value) {
    Node* temp = head;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return false;
    return temp->data == value;
}
```

---

## **4️⃣ Displaying the List**
### **🔹 Logic**
1. Start from `head`.
2. Traverse and print each node.

### **🔹 Implementation**
```cpp
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
```

---

## **5️⃣ Complete Code**
```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) { data = value; next = NULL; }
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() { head = NULL; }
    
    void insertAtBeginning(int value) { ... }
    void insertAtEnd(int value) { ... }
    void insertAtPosition(int value, int position) { ... }
    void deleteFromBeginning() { ... }
    void deleteFromEnd() { ... }
    void deleteFromPosition(int position) { ... }
    bool searchFromBeginning(int value) { ... }
    bool searchFromEnd(int value) { ... }
    bool searchFromPosition(int position, int value) { ... }
    void display() { ... }
};

int main() {
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.display();
    list.deleteFromBeginning();
    list.display();
    return 0;
}
```

---


### **Complete C++ Code for Singly Linked List**
```cpp
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;       // Data part
    Node* next;     // Pointer to the next node

    // Constructor
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Singly Linked List Class
class SinglyLinkedList {
private:
    Node* head; // Pointer to the first node
public:
    // Constructor
    SinglyLinkedList() {
        head = NULL;
    }

    // 1. Insert at Beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value); // Create a new node
        newNode->next = head;            // Link new node to the previous head
        head = newNode;                   // Update head to new node
    }

    // 2. Insert at End
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {  // If list is empty, make new node the head
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode; // Link last node to new node
    }

    // 3. Insert at a Specific Position
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);
        if (position == 1) { // Insert at beginning
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; temp != NULL && i < position - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of range\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 4. Delete a Node by Value
    void deleteNode(int value) {
        if (head == NULL) return;
        if (head->data == value) { // If head needs to be deleted
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL && temp->data != value) { // Find the node to delete
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) return; // If value not found
        prev->next = temp->next; // Unlink the node
        delete temp;
    }

    // 5. Search for a Value
    bool search(int value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // 6. Display the List
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main Function to Test the Singly Linked List
int main() {
    SinglyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtPosition(15, 2); // Insert 15 at position 2

    cout << "Linked List: ";
    list.display();

    cout << "Searching for 20: " << (list.search(20) ? "Found\n" : "Not Found\n");

    list.deleteNode(20);
    cout << "After Deleting 20: ";
    list.display();

    return 0;
}
```

---

## **4. Explanation of the Implementation**
### **1. Node Structure**
- `struct Node` contains:
  - `int data` → stores data.
  - `Node* next` → stores the address of the next node.
- Constructor initializes `data` and sets `next` to `NULL`.

### **2. Singly Linked List Class**
- `head` is used to track the first node.
- `insertAtBeginning(value)`: Creates a node and inserts it at the start.
- `insertAtEnd(value)`: Creates a node and inserts it at the end.
- `insertAtPosition(value, pos)`: Inserts at a specific position.
- `deleteNode(value)`: Finds and deletes a node.
- `search(value)`: Searches for a value.
- `display()`: Prints the linked list.

### **3. Main Function**
- Creates an instance of `SinglyLinkedList`.
- Inserts nodes at different positions.
- Displays the list before and after deletion.
- Searches for a value.

---

## **5. Example Execution Output**
```
Linked List: 10 -> 15 -> 20 -> 30 -> NULL
Searching for 20: Found
After Deleting 20: 10 -> 15 -> 30 -> NULL
```

---

## **6. Time Complexity Analysis**
| Operation         | Best Case | Worst Case |
|------------------|-----------|------------|
| Insert at Beginning | O(1) | O(1) |
| Insert at End | O(1) (if tail pointer exists) | O(n) |
| Insert at Position | O(1) (if at head) | O(n) |
| Delete Node | O(1) (if at head) | O(n) |
| Search | O(1) (if at head) | O(n) |
| Display | O(n) | O(n) |

---

## **7. Summary**
- **Singly Linked List** is a dynamic structure using nodes.
- **Insertions & Deletions** are efficient compared to arrays.
- **Implementation in C++** involves `Node` struct and class functions.
- **Operations include** Insert, Delete, Search, and Display.

