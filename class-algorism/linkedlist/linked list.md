**Linked Lists in C++**.

---

### **1. What is a Linked List?**
A **linked list** is a dynamic data structure used to store a collection of elements. Unlike arrays, which store elements in contiguous memory locations, linked lists store elements in **nodes** that are connected using **pointers**.

Each node in a linked list typically contains:
- **Data** (stores the actual value)
- **Pointer (next)** (stores the address of the next node in the sequence)

---

### **2. Purpose of Linked Lists**
Linked lists are used instead of arrays when:
- **Dynamic Memory Allocation** is required (size can grow or shrink at runtime).
- **Efficient Insertions & Deletions** are needed (arrays require shifting elements).
- **Flexibility** is necessary (data is scattered in memory, not stored contiguously).

---

### **3. General Concept of Linked List**
A linked list consists of **nodes** that are linked together using **pointers**. The first node is called the **head**, and the last node points to `NULL`, indicating the end of the list.

#### **Types of Linked Lists:**
1. **Singly Linked List** – Each node has a pointer to the next node only.
2. **Doubly Linked List** – Each node has pointers to both the next and previous nodes.
3. **Circular Linked List** – The last node points back to the first node instead of `NULL`.

---


---

## **1. What is a Node?**
A **Node** is the basic building block of a linked list. Each node contains two parts:  
1. **Data** – Stores the actual information.  
2. **Pointer (next)** – Stores the address of the next node in the list.

### **Node Representation in C++**
```cpp
struct Node {
    int data;  // Stores data
    Node* next;  // Pointer to the next node
};
```
---

## **2. What is a Pointer?**
A **pointer** in C++ is a variable that stores the memory address of another variable.  
In linked lists, pointers are used to connect nodes.

### **Example: Pointer in C++**
```cpp
int x = 10;
int* ptr = &x;  // Pointer storing the address of x
```

In linked lists, a pointer of type `Node*` is used to store the address of the next node.
```cpp
Node* head; // A pointer to the first node of the list
```
---

## **3. What is a Reference?**
A **reference** is an alias for another variable. Unlike pointers, references cannot be null or reassigned.

### **Reference Example in C++**
```cpp
int x = 10;
int& ref = x; // ref is another name for x
```

### **References in Linked Lists**
References are used in functions to modify the linked list without copying it.
```cpp
void insert(Node*& head, int value); // Pass by reference to modify head
```
---

## **4. How Linked Lists Work**
A linked list works by **chaining nodes together** using pointers.  

### **Working Mechanism of a Singly Linked List**
1. **Start with a Head Pointer**  
   - The `head` pointer points to the first node.
2. **Create Nodes**  
   - Each node contains data and a pointer to the next node.
3. **Insert Nodes**  
   - New nodes are added by updating pointers.
4. **Traverse the List**  
   - Start from the head and follow `next` pointers until reaching `NULL`.
5. **Delete Nodes**  
   - Update the previous node’s pointer to skip the deleted node.

### **Diagram of a Singly Linked List**
```
[10 | * ] --> [20 | * ] --> [30 | * ] --> NULL
 ^ Head
```
Each node contains:
- `10` → Data  
- `*` → Pointer to the next node  

---
