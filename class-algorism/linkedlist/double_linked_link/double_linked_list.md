I'll now provide a **detailed** note on **Doubly Linked Lists (DLL)** in C++, explaining every operation, the logic behind it, and a complete implementation.  

---

# **📌 Doubly Linked List (DLL) – Detailed Explanation & Implementation in C++**

## **🔹 1. What is a Doubly Linked List?**
A **Doubly Linked List (DLL)** is a type of linked list where **each node** contains:
- **Data** → The actual value stored in the node.
- **Pointer to the next node** → This allows traversal in the **forward direction**.
- **Pointer to the previous node** → This allows traversal in the **backward direction**.

💡 **Key Differences from Singly Linked List:**
- DLL allows **two-way traversal** (forward & backward).
- DLL requires **extra memory** for storing the previous pointer.
- Deleting a node in DLL is **easier** since we have a direct link to the previous node.

---

## **🔹 2. How a Doubly Linked List Works?**
Each **Node** in DLL contains:
```cpp
struct Node {
    int data;
    Node* prev; // Pointer to the previous node
    Node* next; // Pointer to the next node
};
```
### **Example DLL Structure**
```
NULL <- [10] <-> [20] <-> [30] -> NULL
```
- The **head** points to the first node.
- The **last node’s next pointer** is `NULL`, indicating the end.
- The **first node’s previous pointer** is `NULL`, indicating the start.

---

## **🔹 3. Operations in Doubly Linked List**

### **1️⃣ Insertion in DLL**
We can insert a new node at:
1. **The Beginning**
2. **The End**
3. **A Specific Position**

---

### **🔹 1.1 Insertion at the Beginning**
**Logic Behind It:**  
1. Create a new node.
2. Set `newNode->next = head` (connect the new node to the old head).
3. If the list is not empty, update `head->prev = newNode`.
4. Update `head = newNode` to make it the first node.

```cpp
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    
    head = newNode;
}
```
✅ **Time Complexity:** `O(1)`, since we are just updating a few pointers.

---

### **🔹 1.2 Insertion at the End**
**Logic Behind It:**  
1. Create a new node.
2. If the list is empty, set `head = newNode`.
3. Traverse to the last node.
4. Update `last->next = newNode` and `newNode->prev = last`.

```cpp
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}
```
✅ **Time Complexity:** `O(n)`, because we traverse to the last node.

---

### **🔹 1.3 Insertion at a Specific Position**
**Logic Behind It:**  
1. If `position == 1`, call `insertAtBeginning()`.
2. Traverse to the node **before** the target position.
3. Insert the new node, updating `prev` and `next` pointers accordingly.

```cpp
void insertAtPosition(int value, int position) {
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    Node* temp = head;
    
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;
    
    newNode->next = temp->next;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}
```
✅ **Time Complexity:** `O(n)`, since we traverse to the target position.

---

### **2️⃣ Deletion in DLL**
We can delete a node from:
1. **The Beginning**
2. **The End**
3. **A Specific Position**

---

### **🔹 2.1 Deletion from the Beginning**
**Logic Behind It:**  
1. If the list is empty, return.
2. Store `head` in a temporary pointer.
3. Move `head` to `head->next`.
4. Update `head->prev = NULL` and delete old `head`.

```cpp
void deleteFromBeginning() {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;
    
    if (head != NULL) {
        head->prev = NULL;
    }
    
    delete temp;
}
```
✅ **Time Complexity:** `O(1)`, since only a few pointers are updated.

---

### **🔹 2.2 Deletion from the End**
**Logic Behind It:**  
1. If the list is empty, return.
2. Traverse to the last node.
3. Update `prev->next = NULL` and delete the last node.

```cpp
void deleteFromEnd() {
    if (head == NULL) return;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }

    delete temp;
}
```
✅ **Time Complexity:** `O(n)`, because we traverse to the last node.

---

### **🔹 2.3 Deletion from a Specific Position**
**Logic Behind It:**  
1. If `position == 1`, call `deleteFromBeginning()`.
2. Traverse to the target node.
3. Update `prev->next` and `next->prev`, then delete the node.

```cpp
void deleteFromPosition(int position) {
    if (head == NULL) return;

    Node* temp = head;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    
    if (position == 1) head = temp->next;
    
    delete temp;
}
```
✅ **Time Complexity:** `O(n)`, since we traverse to the target position.

---

### **3️⃣ Searching in DLL**
We can search:
1. **From the Beginning**
2. **From the End**
3. **At a Specific Position**

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
✅ **Time Complexity:** `O(n)`, worst case when the element is at the end.

---

### **4️⃣ Displaying the List**
```cpp
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
```

---


I'll continue with the remaining parts of **Doubly Linked List (DLL)**, including **searching** (from the end and at a specific position), and then provide the **full implementation** in C++.  

---

# **📌 Doubly Linked List (DLL) – Continued**

## **🔹 3. Searching in DLL**
We can search for a **specific value** in three ways:  
1️⃣ **From the Beginning** – Already provided.  
2️⃣ **From the End (Backward Search)**  
3️⃣ **At a Specific Position**  

---

### **🔹 3.2 Searching from the End (Backward Search)**
💡 **Logic:**  
- Start from the **last node**.  
- Traverse backward using `prev` pointer.  
- If the value is found, return `true`.  
- Otherwise, return `false`.

```cpp
bool searchFromEnd(int value) {
    if (head == NULL) return false;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;  // Move to the last node
    }

    // Traverse backward
    while (temp != NULL) {
        if (temp->data == value) return true;
        temp = temp->prev;
    }

    return false;
}
```
✅ **Time Complexity:** `O(n)`, worst case when the element is at the front.

---

### **🔹 3.3 Searching at a Specific Position**
💡 **Logic:**  
- Start from `head`.  
- Traverse the list using a counter.  
- If the position matches, return the value at that position.  

```cpp
int searchAtPosition(int position) {
    if (head == NULL || position < 1) return -1; // Invalid position

    Node* temp = head;
    int index = 1;

    while (temp != NULL && index < position) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL) return -1; // Position out of range

    return temp->data;
}
```
✅ **Time Complexity:** `O(n)`, worst case when position is at the end.

---

## **🔹 4. Displaying the List**
💡 **Logic:**  
- Start from `head` and print each node’s value.  
- Use `next` pointer to move forward.  

```cpp
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
```
✅ **Time Complexity:** `O(n)`, since we traverse the entire list.

---

# **📌 Full Implementation of Doubly Linked List (DLL)**
Below is the **complete** implementation of all DLL operations.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() { head = NULL; }

    // Insert at Beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL) {
            head->prev = newNode;
        }

        head = newNode;
    }

    // Insert at End
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert at a Specific Position
    void insertAtPosition(int value, int position) {
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;
        Node* temp = head;

        for (int i = 1; temp != NULL && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL) return;

        newNode->next = temp->next;
        if (temp->next != NULL) temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete from Beginning
    void deleteFromBeginning() {
        if (head == NULL) return;

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        delete temp;
    }

    // Delete from End
    void deleteFromEnd() {
        if (head == NULL) return;

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        if (temp->prev != NULL) {
            temp->prev->next = NULL;
        } else {
            head = NULL;
        }

        delete temp;
    }

    // Delete from a Specific Position
    void deleteFromPosition(int position) {
        if (head == NULL) return;

        Node* temp = head;
        for (int i = 1; temp != NULL && i < position; i++) {
            temp = temp->next;
        }

        if (temp == NULL) return;

        if (temp->prev != NULL) temp->prev->next = temp->next;
        if (temp->next != NULL) temp->next->prev = temp->prev;

        if (position == 1) head = temp->next;

        delete temp;
    }

    // Search from Beginning
    bool searchFromBeginning(int value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    // Search from End
    bool searchFromEnd(int value) {
        if (head == NULL) return false;

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        while (temp != NULL) {
            if (temp->data == value) return true;
            temp = temp->prev;
        }

        return false;
    }

    // Search at a Specific Position
    int searchAtPosition(int position) {
        if (head == NULL || position < 1) return -1;

        Node* temp = head;
        int index = 1;

        while (temp != NULL && index < position) {
            temp = temp->next;
            index++;
        }

        if (temp == NULL) return -1;

        return temp->data;
    }

    // Display List
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    
    // Insert elements
    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtPosition(15, 2);

    cout << "Doubly Linked List after insertions:\n";
    dll.display();

    // Delete elements
    dll.deleteFromBeginning();
    dll.deleteFromEnd();
    dll.deleteFromPosition(2);

    cout << "Doubly Linked List after deletions:\n";
    dll.display();

    // Search elements
    cout << "Search 20 from beginning: " << dll.searchFromBeginning(20) << "\n";
    cout << "Search 15 from end: " << dll.searchFromEnd(15) << "\n";
    cout << "Element at position 1: " << dll.searchAtPosition(1) << "\n";

    return 0;
}
```

---

This is a **fully functional Doubly Linked List** implementation in C++. Let me know if you need any modifications or explanations! 🚀🔥