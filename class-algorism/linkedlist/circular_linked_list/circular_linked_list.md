Let's dive into the **Circular Linked List** in detail.

---

## **📌 Circular Linked List (CLL)** – Meaning & Detailed Explanation

### **🔹 1. What is a Circular Linked List?**
A **Circular Linked List (CLL)** is a variation of the linked list in which the **last node's next pointer** points back to the **first node**. This forms a loop or circle, meaning there is no **NULL** at the end of the list, unlike in a **singly** or **doubly linked list**.

### **💡 Key Concept:**
- **Singly Circular Linked List (SCLL):** In a singly circular linked list, each node has a pointer to the next node, and the last node points to the first node.
- **Doubly Circular Linked List (DCLL):** In a doubly circular linked list, each node has two pointers: one pointing to the next node and one pointing to the previous node. The last node's `next` pointer points to the first node, and the first node's `prev` pointer points to the last node.

---

### **🔹 2. How a Circular Linked List Works?**
In a **Circular Linked List**, the nodes form a continuous loop. Here's a breakdown of the pointers in different variations of a Circular Linked List:

1. **Singly Circular Linked List:**
   - **Node Structure:**
   ```cpp
   struct Node {
       int data;
       Node* next;
   };
   ```
   - The **last node**'s `next` points to the **first node**.

   Example:
   ```
   [10] -> [20] -> [30] -> [40] -> [10] (head)
   ```

2. **Doubly Circular Linked List:**
   - **Node Structure:**
   ```cpp
   struct Node {
       int data;
       Node* prev;
       Node* next;
   };
   ```
   - The **first node**'s `prev` points to the **last node**, and the **last node**'s `next` points to the **first node**.

   Example:
   ```
   NULL <- [10] <-> [20] <-> [30] <-> [40] -> [10] (head)
   ```

---

### **🔹 3. Operations in Circular Linked List**

#### **1️⃣ Insertion Operations**
1. **Insertion at the Beginning:** Insert a new node at the head of the list.
2. **Insertion at the End:** Insert a new node at the tail of the list.
3. **Insertion at a Specific Position:** Insert a new node at a specific position.

#### **2️⃣ Deletion Operations**
1. **Deletion from the Beginning:** Remove the node from the head.
2. **Deletion from the End:** Remove the node from the tail.
3. **Deletion from a Specific Position:** Remove a node at a specific position.

#### **3️⃣ Traversal Operations**
1. **Display the List:** Traverse the circular linked list and print the elements.

---

### **🔹 4. Why Use Circular Linked Lists?**
- **Efficient in Circular Applications:** Ideal for applications where the list needs to loop back, such as **round-robin scheduling** or **circular buffers**.
- **Constant Time for Last Element Insertion:** In a **singly circular list**, there’s no need to traverse to the last node for insertion or deletion.

---

### **🔹 5. Key Advantages and Disadvantages**
#### **Advantages:**
- **No NULL pointers** at the end, making it easier to implement circular structures.
- **Efficient traversal** since you can always come back to the first element.
- **Constant time operations** for insertion at both ends (for singly circular linked lists).

#### **Disadvantages:**
- **Complexity in traversal** and deletion when handling loops, since you have to ensure you don't loop infinitely.

---

Now, would you like to see **implementations of these operations** in **Singly Circular Linked List (SCLL)** or **Doubly Circular Linked List (DCLL)**? Let me know! 🚀

Let's go through how to **insert data in a Circular Linked List** (both **Singly Circular Linked List (SCLL)** and **Doubly Circular Linked List (DCLL)**). We'll break down the **logic** behind each insertion operation:

---

## **📌 Inserting Data in Circular Linked List**

### **🔹 1. Insertion at the Beginning in Circular Linked List**

**Goal:** Insert a new node at the **beginning** (head) of the circular linked list.

#### **Singly Circular Linked List (SCLL)**
In a singly circular linked list, the last node's `next` pointer points to the first node. To insert at the beginning:
- Create a new node.
- Set the new node's `next` pointer to the current head node.
- Traverse to the last node (find the node whose `next` is the head), and set its `next` pointer to the new node.
- Make the new node the new head.

**Steps:**
1. Create a new node with the desired data.
2. If the list is empty (i.e., head is `NULL`), make the new node point to itself.
3. Otherwise, make the new node's `next` point to the head node and update the last node's `next` to point to the new node.
4. Set the head to the new node.

```cpp
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    
    // If the list is empty, point new node to itself
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    // Otherwise, insert at the beginning
    Node* temp = head;
    while (temp->next != head) { // Find the last node
        temp = temp->next;
    }

    newNode->next = head; // New node points to the current head
    temp->next = newNode;  // Last node points to the new node
    head = newNode;        // Head is updated to the new node
}
```

---

#### **Doubly Circular Linked List (DCLL)**
In a doubly circular linked list, each node has both `next` and `prev` pointers. The last node’s `next` points to the first node, and the first node's `prev` points to the last node. To insert at the beginning:
- Create a new node.
- Set the new node's `next` pointer to the current head node and its `prev` pointer to the last node.
- Update the previous head node's `prev` to point to the new node.
- Update the last node's `next` to point to the new node.
- Make the new node the new head.

**Steps:**
1. Create a new node with the desired data.
2. If the list is empty, the new node’s `next` and `prev` will point to itself.
3. Otherwise, update the current head node and the last node’s pointers accordingly.
4. Set the head to the new node.

```cpp
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    // If the list is empty, point new node to itself
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    // Otherwise, insert at the beginning
    Node* last = head->prev;  // Get the last node
    newNode->next = head;     // New node points to the current head
    newNode->prev = last;     // New node's prev points to the last node
    head->prev = newNode;     // Current head's prev points to the new node
    last->next = newNode;     // Last node's next points to the new node
    head = newNode;           // Head is updated to the new node
}
```

---

### **🔹 2. Insertion at the End in Circular Linked List**

**Goal:** Insert a new node at the **end** (tail) of the circular linked list.

#### **Singly Circular Linked List (SCLL)**
To insert a new node at the end:
- Create a new node.
- If the list is empty, make the new node's `next` pointer point to itself (single node circular list).
- Otherwise, traverse the list to the last node, and update the last node’s `next` pointer to point to the new node.
- Make the new node's `next` pointer point to the head.

**Steps:**
1. Create a new node with the desired data.
2. If the list is empty, make the new node point to itself.
3. Otherwise, traverse to the last node and link it to the new node.
4. Set the new node’s `next` pointer to the head, closing the loop.

```cpp
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != head) { // Traverse to the last node
        temp = temp->next;
    }

    temp->next = newNode;  // Last node points to the new node
    newNode->next = head;  // New node points to the head
}
```

---

#### **Doubly Circular Linked List (DCLL)**
To insert a new node at the end:
- Create a new node.
- If the list is empty, the new node’s `next` and `prev` point to itself (as it’s the only node).
- Otherwise, update the `prev` pointer of the current head to point to the new node, and the new node’s `next` pointer to the head.
- Update the current last node’s `next` pointer to the new node and set the new node’s `prev` pointer to the last node.

**Steps:**
1. Create a new node with the desired data.
2. If the list is empty, the new node points to itself (both `next` and `prev`).
3. Otherwise, link the new node to the last node and update the `next` and `prev` pointers accordingly.

```cpp
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node* last = head->prev;  // Get the last node
    newNode->next = head;     // New node points to the head
    newNode->prev = last;     // New node's prev points to the last node
    last->next = newNode;     // Last node's next points to the new node
    head->prev = newNode;     // Head's prev points to the new node
}
```

---

### **🔹 3. Insertion at a Specific Position in Circular Linked List**

**Goal:** Insert a new node at a **specific position** in the circular linked list.

#### **Singly Circular Linked List (SCLL)**
To insert at a specific position:
- Create a new node.
- Traverse the list until you reach the node just before the specified position.
- Insert the new node by updating the `next` pointers.

**Steps:**
1. Create a new node with the desired data.
2. If the position is 1, insert at the beginning.
3. Otherwise, traverse to the position-1 node and update pointers.

```cpp
void insertAtPosition(int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
```

---

#### **Doubly Circular Linked List (DCLL)**
To insert at a specific position:
- Traverse the list until the node just before the specified position.
- Insert the new node by updating the `next` and `prev` pointers of the surrounding nodes.

**Steps:**
1. Create a new node with the desired data.
2. If the position is 1, insert at the beginning.
3. Otherwise, traverse to the position-1 node and update pointers accordingly.

```cpp
void insertAtPosition(int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}
```

---

These are the detailed steps and logic behind **insertion operations** for both **Singly Circular Linked List (SCLL)** and **Doubly Circular Linked List (DCLL)**.
Now, let's go through the **deletion operations** in both **Singly Circular Linked List (SCLL)** and **Doubly Circular Linked List (DCLL)**. We'll cover the logic and steps involved in deleting data from the **beginning**, **end**, and **specific position** in a circular linked list.

---

## **📌 Deleting Data in Circular Linked List**

### **🔹 1. Deletion from the Beginning in Circular Linked List**

**Goal:** Remove the node from the **beginning** (head) of the circular linked list.

#### **Singly Circular Linked List (SCLL)**
To delete the node from the beginning:
- If the list has only one node, set the `head` to `NULL`.
- Otherwise, update the `head` to the next node.
- Traverse to the last node (the node whose `next` points to the `head`), and update its `next` to point to the new head.

**Steps:**
1. If the list is empty, return (no deletion).
2. If there is only one node, make the list empty by setting `head` to `NULL`.
3. Otherwise, update the `head` to the next node and adjust the last node's `next` pointer to the new head.

```cpp
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    // If there is only one node
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    // Traverse to the last node
    while (temp->next != head) {
        temp = temp->next;
    }

    // Update the head and adjust the last node's next pointer
    temp->next = head->next;
    delete head;
    head = head->next;
}
```

---

#### **Doubly Circular Linked List (DCLL)**
To delete from the beginning:
- If the list has only one node, set the `head` to `NULL`.
- Otherwise, update the `head` to the next node, and set the `prev` pointer of the new head to the last node.
- Update the last node's `next` pointer to point to the new head.

**Steps:**
1. If the list is empty, return (no deletion).
2. If there is only one node, set `head` to `NULL`.
3. Otherwise, update the `head` to the next node and adjust the `prev` pointer of the new head and the last node's `next` pointer.

```cpp
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    // If there is only one node
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* last = head->prev;  // Get the last node
    Node* temp = head;
    
    head = head->next;         // Update the head
    head->prev = last;         // New head's prev points to the last node
    last->next = head;         // Last node's next points to the new head
    delete temp;               // Delete the old head
}
```

---

### **🔹 2. Deletion from the End in Circular Linked List**

**Goal:** Remove the node from the **end** (tail) of the circular linked list.

#### **Singly Circular Linked List (SCLL)**
To delete the node from the end:
- If the list has only one node, set the `head` to `NULL`.
- Otherwise, traverse the list to find the node before the last node (the one whose `next` points to the last node), and update its `next` pointer to point to the `head`.
- Delete the last node.

**Steps:**
1. If the list is empty, return (no deletion).
2. If there is only one node, set `head` to `NULL`.
3. Otherwise, traverse to the second-to-last node and update its `next` to point to the `head`, then delete the last node.

```cpp
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    // If there is only one node
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    // Traverse to the second-to-last node
    while (temp->next->next != head) {
        temp = temp->next;
    }

    Node* lastNode = temp->next;
    temp->next = head;  // Second-to-last node points to the head
    delete lastNode;    // Delete the last node
}
```

---

#### **Doubly Circular Linked List (DCLL)**
To delete from the end:
- If the list has only one node, set the `head` to `NULL`.
- Otherwise, traverse the list to find the last node and update the previous node’s `next` pointer to point to the `head`.
- Update the `prev` pointer of the `head` to the new last node and delete the old last node.

**Steps:**
1. If the list is empty, return (no deletion).
2. If there is only one node, set `head` to `NULL`.
3. Otherwise, traverse to the second-to-last node and update pointers accordingly.

```cpp
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    // If there is only one node
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* last = head->prev;  // Get the last node
    Node* secondLast = last->prev;  // Get the second-to-last node
    
    secondLast->next = head;  // Second-to-last node points to the head
    head->prev = secondLast;  // Head's prev points to the second-to-last node
    delete last;              // Delete the last node
}
```

---

### **🔹 3. Deletion from a Specific Position in Circular Linked List**

**Goal:** Remove a node from a **specific position** in the circular linked list.

#### **Singly Circular Linked List (SCLL)**
To delete from a specific position:
- Traverse to the node just before the specified position.
- Update the `next` pointer of the previous node to point to the node after the one being deleted.
- Delete the node at the specified position.

**Steps:**
1. If the list is empty, return (no deletion).
2. If the position is 1, delete from the beginning.
3. Otherwise, traverse the list to the node just before the specified position, then update pointers.

```cpp
void deleteFromPosition(int position) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    // If position is 1, delete from the beginning
    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    // Check if position is valid
    if (temp->next == head) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}
```

---

#### **Doubly Circular Linked List (DCLL)**
To delete from a specific position:
- Traverse to the node just before the specified position.
- Update the `next` pointer of the previous node and the `prev` pointer of the next node.
- Delete the node at the specified position.

**Steps:**
1. If the list is empty, return (no deletion).
2. If the position is 1, delete from the beginning.
3. Otherwise, traverse the list to the node just before the specified position and adjust pointers.

```cpp
void deleteFromPosition(int position) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    // If position is 1, delete from the beginning
    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    // Check if position is valid
    if (temp->next == head) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    nodeToDelete->next->prev = temp;
    delete nodeToDelete;
}
```

---

These are the detailed steps and logic behind **deleting data** from a **Singly Circular Linked List (SCLL)** and **Doubly Circular Linked List (DCLL)**.



Let's go through the **search operations** in both **Singly Circular Linked List (SCLL)** and **Doubly Circular Linked List (DCLL)**. We'll cover the logic and steps involved in searching for data from the **beginning**, **end**, and **specific position** in a circular linked list.

---

## **📌 Searching Data in Circular Linked List**

### **🔹 1. Searching from the Beginning in Circular Linked List**

**Goal:** Find if a specific value exists starting from the **beginning** of the circular linked list.

#### **Singly Circular Linked List (SCLL)**
In a **singly circular linked list**, you start from the `head` node and traverse through each node, checking if the data matches. Since it's circular, you stop once you reach the `head` node again.

**Steps:**
1. Start from the `head` node.
2. Traverse through the list, checking the `data` of each node.
3. If the data matches, return the node or indicate the match.
4. If the traversal completes a full cycle (back to `head`), return **not found**.

```cpp
Node* searchFromBeginning(int value) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return NULL;
    }

    Node* temp = head;
    do {
        if (temp->data == value) {
            cout << "Found: " << value << endl;
            return temp;  // Node found
        }
        temp = temp->next;
    } while (temp != head);  // Stop when we loop back to the head

    cout << "Value " << value << " not found!" << endl;
    return NULL;  // Value not found
}
```

---

#### **Doubly Circular Linked List (DCLL)**
In a **doubly circular linked list**, you can traverse in both directions (using the `next` and `prev` pointers), but the logic is similar to a singly circular linked list.

**Steps:**
1. Start from the `head` node.
2. Traverse through the list, checking the `data` of each node.
3. If the data matches, return the node or indicate the match.
4. If the traversal completes a full cycle (back to `head`), return **not found**.

```cpp
Node* searchFromBeginning(int value) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return NULL;
    }

    Node* temp = head;
    do {
        if (temp->data == value) {
            cout << "Found: " << value << endl;
            return temp;  // Node found
        }
        temp = temp->next;
    } while (temp != head);  // Stop when we loop back to the head

    cout << "Value " << value << " not found!" << endl;
    return NULL;  // Value not found
}
```

---

### **🔹 2. Searching from the End in Circular Linked List**

**Goal:** Find if a specific value exists starting from the **end** (tail) of the circular linked list.

#### **Singly Circular Linked List (SCLL)**
To search from the **end**, we need to traverse the list in reverse, but since singly circular lists don't have a `prev` pointer, you can only move forward. However, you can first traverse the entire list to get to the last node and then search back through it (if we need to simulate reverse traversal).

**Steps:**
1. Traverse to the last node in the list (this node's `next` will point to the `head`).
2. Traverse through the list in reverse, checking for matches. This requires extra traversal but can be simulated by traversing the list once and backtracking (if the list had a `prev` pointer).
3. Stop if you find the value, or return **not found** if you complete a cycle.

```cpp
Node* searchFromEnd(int value) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return NULL;
    }

    Node* temp = head;
    Node* last = head;
    
    // Find the last node
    while (last->next != head) {
        last = last->next;
    }

    // Search from the end (reverse traversal simulation)
    while (last != head) {
        if (last->data == value) {
            cout << "Found: " << value << endl;
            return last;
        }
        last = last->prev;  // Go to the previous node (this works only in doubly linked lists)
    }

    // Check the head node
    if (last->data == value) {
        cout << "Found: " << value << endl;
        return last;
    }

    cout << "Value " << value << " not found!" << endl;
    return NULL;
}
```

---

#### **Doubly Circular Linked List (DCLL)**
In a **doubly circular linked list**, we can traverse backwards (using `prev` pointers) to search from the **end**. The logic is simpler because we can access both `next` and `prev` pointers.

**Steps:**
1. Start from the `head` node and traverse until you reach the last node.
2. Start traversing backward (using the `prev` pointer).
3. If the data matches, return the node or indicate the match.
4. If the traversal completes a full cycle (back to `head`), return **not found**.

```cpp
Node* searchFromEnd(int value) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return NULL;
    }

    Node* last = head->prev;  // Start from the last node

    do {
        if (last->data == value) {
            cout << "Found: " << value << endl;
            return last;  // Node found
        }
        last = last->prev;  // Move to the previous node
    } while (last != head);  // Stop when we loop back to the head

    cout << "Value " << value << " not found!" << endl;
    return NULL;  // Value not found
}
```

---

### **🔹 3. Searching at a Specific Position in Circular Linked List**

**Goal:** Find if a specific value exists at a **specific position** in the circular linked list.

#### **Singly Circular Linked List (SCLL)**
In a **singly circular linked list**, you can traverse to a specific node by moving from the `head` node until you reach the desired position.

**Steps:**
1. Start from the `head` node.
2. Traverse through the list node-by-node until you reach the specified position.
3. If the node at the position matches the value, return the node or indicate the match.
4. If the position is invalid (out of bounds), return **not found**.

```cpp
Node* searchAtPosition(int position, int value) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return NULL;
    }

    Node* temp = head;
    int i = 1;
    
    // Traverse to the specified position
    while (temp != head && i < position) {
        temp = temp->next;
        i++;
    }

    // Check if the position is valid
    if (i == position && temp->data == value) {
        cout << "Found: " << value << " at position " << position << endl;
        return temp;
    }

    cout << "Position " << position << " or value " << value << " not found!" << endl;
    return NULL;  // Value not found
}
```

---

#### **Doubly Circular Linked List (DCLL)**
In a **doubly circular linked list**, the logic is similar, but you have the flexibility of traversing in both directions (using `next` and `prev` pointers).

**Steps:**
1. Start from the `head` node.
2. Traverse to the specific position.
3. If the node at the position matches the value, return the node or indicate the match.
4. If the position is invalid (out of bounds), return **not found**.

```cpp
Node* searchAtPosition(int position, int value) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return NULL;
    }

    Node* temp = head;
    int i = 1;

    // Traverse to the specified position
    while (temp != head && i < position) {
        temp = temp->next;
        i++;
    }

    // Check if the position is valid
    if (i == position && temp->data == value) {
        cout << "Found: " << value << " at position " << position << endl;
        return temp;
    }

    cout << "Position " << position << " or value " << value << " not found!" << endl;
    return NULL;  // Value not found
}
```

---

These are the detailed steps and logic behind **searching for data** in a **Singly Circular Linked List (SCLL)** and **Doubly Circular Linked List (DCLL)**.

To display the elements in a **Circular Linked List** (both **Singly Circular Linked List (SCLL)** and **Doubly Circular Linked List (DCLL)**), you need to traverse the list from the `head` node and print the data of each node until you loop back to the starting point (since the list is circular).

Here's how you can **display** the elements in both types of circular linked lists:

---

### **📌 Displaying Data in Circular Linked List**

---

### **🔹 1. Display in Singly Circular Linked List (SCLL)**

**Goal:** Traverse through each node starting from the `head` and print the data until you loop back to the `head`.

**Steps:**
1. Start from the `head` node.
2. Traverse through the nodes, printing each node's data.
3. Stop when you reach the `head` node again, indicating the end of the list.

#### **Code Example (Singly Circular Linked List)**

```cpp
void display() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;  // Move to the next node
    } while (temp != head);  // Stop when we loop back to the head

    cout << endl;  // End the line after displaying all elements
}
```

**Explanation:**
- The `do-while` loop ensures that the list is traversed once fully (since it's circular).
- We start from the `head` node and keep printing each node's data (`temp->data`).
- We stop when we come back to the `head` node, completing one cycle.

---

### **🔹 2. Display in Doubly Circular Linked List (DCLL)**

**Goal:** Similarly, traverse the list from the `head`, but in a doubly circular linked list, you have the flexibility to traverse in both directions (using both `next` and `prev` pointers).

**Steps:**
1. Start from the `head` node.
2. Traverse through the nodes, printing each node's data using the `next` pointer.
3. Stop when you loop back to the `head` node, indicating the end of the list.

#### **Code Example (Doubly Circular Linked List)**

```cpp
void display() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;  // Move to the next node
    } while (temp != head);  // Stop when we loop back to the head

    cout << endl;  // End the line after displaying all elements
}
```

**Explanation:**
- Like in the singly circular linked list, we start at the `head` and use the `next` pointer to traverse the list.
- The loop stops when it reaches the `head` node again.
- Since it's a **doubly** circular linked list, you can also use the `prev` pointer if you want to display the list in reverse order (i.e., from the `tail` back to the `head`).

---

### **📌 Summary of Display Logic**

- **Start from the `head`** of the list.
- **Traverse** node by node using the `next` pointer.
- **Stop** once you come back to the `head` node, ensuring the list is fully displayed.
- **Edge Case:** If the list is empty (`head == NULL`), display a message indicating the list is empty.

---

This is how you can **display** all the elements in a **Circular Linked List** (both **Singly Circular Linked List** and **Doubly Circular Linked List**).