## **Understanding Structures in C++**

### **📌 What is a Structure?**
A **structure** (`struct`) in C++ is a user-defined data type that groups together **multiple variables** of different types under a single name. It allows you to store related data together, similar to an object in Object-Oriented Programming.

### **🔹 How to Define a Structure**
A structure is defined using the `struct` keyword. For example:

```cpp
struct Time {
   int hour;
   int minute;
   int second;
};
```

Here:
- `Time` is the **name** of the structure.
- `hour`, `minute`, and `second` are **data members** (variables inside the structure).
- `struct Time` creates a new **data type**, which can be used to declare variables of type `Time`.

---

### **🔹 Declaring Structure Variables**
Once a structure is defined, we can create variables using it.

**Syntax:**
```cpp
struct <StructureName> <VariableName>;
```

**Example:**
```cpp
struct Time timeObject;  // Declares a structure variable
struct Time *timeptr;    // Declares a pointer to a structure variable
```

---

## **📌 Accessing Members of a Structure**
We can access the members (variables) of a structure using:
1. **The Dot Operator (`.`)** – for normal structure variables.
2. **The Arrow Operator (`->`)** – for pointers to structure variables.

---

### **🔹 1. Accessing Structure Members using the Dot Operator (`.`)**
If we have a normal (non-pointer) structure variable, we use the **dot operator** to access its members.

```cpp
cout << timeObject.hour;  // Access the 'hour' member of timeObject
```

---

### **🔹 2. Accessing Structure Members using the Arrow Operator (`->`)**
If we have a pointer to a structure, we use the **arrow operator (`->`)** to access its members.

```cpp
cout << timeptr->hour;  // Access the 'hour' member using a pointer
```

#### **Why Use the Arrow Operator?**
- The arrow operator (`->`) is a shorthand for dereferencing a pointer and accessing its members.
- The statement:
  
  ```cpp
  cout << timeptr->hour;
  ```
  is equivalent to:
  ```cpp
  cout << (*timeptr).hour;
  ```
  But since `.` has higher precedence than `*`, we need **parentheses** around `*timeptr` to ensure correct evaluation.

---

## **📌 Example Code Demonstrating Structures in C++**
```cpp
#include <iostream>
using namespace std;

// Define a structure
struct Time {
    int hour;
    int minute;
    int second;
};

int main() {
    // Declare a structure variable
    Time timeObject = {10, 30, 45};

    // Declare a pointer to a structure
    Time *timeptr = &timeObject;

    // Access members using the dot operator
    cout << "Hour (using dot operator): " << timeObject.hour << endl;
    
    // Access members using the arrow operator
    cout << "Hour (using arrow operator): " << timeptr->hour << endl;

    return 0;
}
```

---

### **📌 Summary**
| Operator | Used for | Example |
|-----------|------------|-------------|
| `.` (Dot Operator) | Access members of a normal structure variable | `timeObject.hour` |
| `->` (Arrow Operator) | Access members using a structure pointer | `timeptr->hour` |
| `(*ptr).member` | Equivalent to `ptr->member` but needs parentheses due to precedence | `(*timeptr).hour` |
### **📌 Self-Referential Structures in C++**  

#### **🔹 What is a Self-Referential Structure?**  
A **self-referential structure** is a structure that contains a pointer to an instance of **the same structure type**. This allows structures to be linked together dynamically, forming data structures like **linked lists, trees, and graphs**.  

#### **✅ Example of a Self-Referential Structure**
```cpp
struct List {
    char name[10];
    int count;
    struct List *next;  // Pointer to the next node of the same structure type
};
```
Here:
- `name` and `count` are **data members**.
- `next` is a **pointer** to another `List` structure.  

#### **🛑 Why Can't a Structure Contain an Instance of Itself?**
A structure **cannot contain a direct instance** of itself because:
1. **Infinite Recursion in Memory** – The compiler wouldn't know how much memory to allocate.
2. **Logical Impossibility** – Each instance would require another full instance inside it, leading to an infinite nesting.

**Example of Invalid Code (🚫 Not Allowed):**
```cpp
struct Invalid {
    int data;
    struct Invalid instance;  // ❌ ERROR: Infinite memory allocation
};
```
This would cause **infinite recursion** as each `Invalid` structure would contain another `Invalid` structure inside it.  

---

### **📌 Why Use Self-Referential Structures?**
They are commonly used to build **dynamic data structures**, such as:
- **Linked Lists**
- **Stacks**
- **Queues**
- **Trees and Graphs**

---

### **📌 Example: Using Self-Referential Structures in a Simple Linked List**
```cpp
#include <iostream>
using namespace std;

// Define a self-referential structure for a linked list
struct Node {
    int data;
    Node* next;  // Pointer to the next node
};

int main() {
    // Create nodes
    Node* head = new Node{10, NULL};
    Node* second = new Node{20, NULL};
    Node* third = new Node{30, NULL};

    // Linking nodes
    head->next = second;
    second->next = third;

    // Traversing the linked list
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
```
---

### **📌 Summary**
| ✅ **Allowed** | ❌ **Not Allowed** |
|--------------|------------------|
| A structure **can** contain a **pointer** to itself. | A structure **cannot** contain an **instance** of itself. |
| Used in **linked lists, trees, and graphs**. | Leads to **infinite recursion** in memory. |
| Example: `struct Node { Node *next; };` | Example: `struct Node { Node instance; };` |

### **📌 Creating Linked Lists in C++**  

A **linked list** is a **dynamic data structure** where elements (nodes) are connected **using pointers** instead of being stored in contiguous memory like arrays.  

---

## **🔹 Structure of a Linked List**  
Each **node** in a **singly linked list** consists of:  
1. **Data** (the actual value stored in the node).  
2. **Pointer to the next node** (link to the next node in the sequence).  

A **linked list** is maintained using:  
- A **special pointer** called `head` (or `start`), which **points to the first node** in the list.  
- The **last node** in the list **points to `NULL`**, indicating the end of the list.  

### **🖥 Linked List Diagram Representation**
```
[Data | Next] → [Data | Next] → [Data | Next] → [Data | NULL]
 ↑
 Head
```
- Each `[Data | Next]` represents a **node**.
- The `Head` pointer keeps track of the **first node**.
- The last node has `Next = NULL`, indicating the end.

---

## **📌 Creating a Linked List in C++**
To create a linked list, we use **structures and pointers**.

### **✅ Step 1: Define a Node Structure**
```cpp
struct Node {
    int data;     // Stores data
    Node* next;   // Pointer to the next node
};
```
- **`data`** stores the value inside the node.  
- **`next`** is a pointer to another node of the same type (`Node*`).  

---

### **✅ Step 2: Create the First Node (Head)**
```cpp
Node* head = NULL;  // Initially, the list is empty
```
- **`head`** is a pointer that keeps track of the first node.  
- When the list is empty, `head = NULL`.  

---

### **✅ Step 3: Insert Nodes**
We can add new nodes dynamically using `new`.

#### **📌 Example: Manually Creating a Simple Linked List**
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // Step 1: Create first node
    Node* head = new Node();  
    head->data = 10;  
    head->next = NULL;  

    // Step 2: Create second node
    Node* second = new Node();
    second->data = 20;
    second->next = NULL;
    head->next = second;  // Link first node to second

    // Step 3: Create third node
    Node* third = new Node();
    third->data = 30;
    third->next = NULL;
    second->next = third;  // Link second node to third

    // Display the linked list
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
```

### **🔹 Output**
```
10 -> 20 -> 30 -> NULL
```

---

## **📌 How It Works**
1. **We create the first node** and set `head` to point to it.  
2. **We create additional nodes**, linking them using `next` pointers.  
3. **We traverse the list** using a `while` loop until we reach `NULL`.  

---

### **📌 Summary**
| **Term** | **Description** |
|----------|---------------|
| `Node` | A structure representing a linked list node. |
| `data` | Stores the value inside the node. |
| `next` | A pointer to the next node in the list. |
| `head` | Pointer to the first node in the list. |
| `NULL` | Indicates the end of the list. |

---
## **📌 Defining the Data Structure for a Linked List in C++**  

A **linked list** is made up of **nodes**, where each node contains:  
1. **Data** (e.g., name, age, height, etc.).  
2. **Pointer to the next node** (which maintains the link to the next item in the list).  

---

## **🔹 Structure of a Node**
The **key part** of a linked list is the **node structure**. Here’s how we define it:

```cpp
struct node {
    char name[20];  // Name (up to 20 characters)
    int age;        // Age of the person
    float height;   // Height in meters
    node* nxt;      // Pointer to the next node
};
```

### **📌 Explanation:**
- **`char name[20]`** → Stores a person's name (up to 20 characters).  
- **`int age`** → Stores the age.  
- **`float height`** → Stores the height.  
- **`node* nxt`** → A pointer to the next node in the list.  
- **`node* start_ptr = NULL;`** → Points to the first node (initially `NULL` when the list is empty).  

---

## **🔹 Special Pointer: `start_ptr`**
We declare a pointer called **`start_ptr`**, which permanently keeps track of the **first node** of the list.

```cpp
struct node *start_ptr = NULL;  // Initially, the list is empty
```

- `start_ptr` **points to the first node**.
- If the list is **empty**, `start_ptr = NULL`.

---

## **📌 Why Use Self-Referencing Structures?**
### **1️⃣ Linking Multiple Nodes Together**
Since `node* nxt` is a pointer to the **next** node, we can link multiple nodes dynamically.

Example:
```
[Name: Alice | Age: 25 | Height: 1.7m | nxt] → [Bob | 30 | 1.8m | nxt] → [Charlie | 22 | 1.6m | NULL]
  ↑
 start_ptr
```
- The **last node** (`Charlie`) has `nxt = NULL`, indicating the **end of the list**.

---

## **📌 Example: Creating and Linking Nodes**
```cpp
#include <iostream>
#include <cstring>  // For strcpy

using namespace std;

struct node {
    char name[20];
    int age;
    float height;
    node* nxt;
};

int main() {
    // Step 1: Create first node
    node* first = new node();
    strcpy(first->name, "Alice");
    first->age = 25;
    first->height = 1.7;
    first->nxt = NULL;  // Initially, it's the only node

    // Step 2: Create second node
    node* second = new node();
    strcpy(second->name, "Bob");
    second->age = 30;
    second->height = 1.8;
    second->nxt = NULL;

    // Link first node to second
    first->nxt = second;

    // Step 3: Create third node
    node* third = new node();
    strcpy(third->name, "Charlie");
    third->age = 22;
    third->height = 1.6;
    third->nxt = NULL;

    // Link second node to third
    second->nxt = third;

    // Step 4: Set start_ptr to first node
    node* start_ptr = first;

    // Step 5: Display the linked list
    node* temp = start_ptr;
    while (temp != NULL) {
        cout << "Name: " << temp->name << ", Age: " << temp->age << ", Height: " << temp->height << "m\n";
        temp = temp->nxt;  // Move to next node
    }

    return 0;
}
```

### **🔹 Output**
```
Name: Alice, Age: 25, Height: 1.7m
Name: Bob, Age: 30, Height: 1.8m
Name: Charlie, Age: 22, Height: 1.6m
```

---

## **📌 How This Works**
1. **We create three nodes dynamically** using `new`.  
2. **We link the nodes** using the `nxt` pointer.  
3. **We use `start_ptr` to track the first node** and print the list.  

---

## **📌 Summary**
| **Concept** | **Explanation** |
|-------------|----------------|
| **Node Structure** | A structure (`node`) containing **data + pointer to next node**. |
| **Self-Referential Pointer** | `node* nxt;` allows linking nodes dynamically. |
| **Start Pointer (`start_ptr`)** | Always points to the **first node** in the list. |
| **Last Node** | The last node has `nxt = NULL`. |
| **Dynamic Memory Allocation** | `new node();` creates nodes at runtime. |

---
## **📌 Adding a Node at the End of a Singly Linked List (C++)**  

### **🔹 Problem Statement**
We need to add a node to the end of a **singly linked list** dynamically. The new node will store the **name, age, and height** of a person.

---

## **🔹 Steps to Add a Node at the End**
### **1️⃣ Create a New Node**
- Allocate memory for the new node using `new node`.
- Fill in the details (`name`, `age`, `height`).
- Set `nxt = NULL` (since this will be the last node).

### **2️⃣ If the List is Empty**
- Set the `start_ptr` (head pointer) to point to the new node.

### **3️⃣ If the List is Not Empty**
- Use a **temporary pointer (`temp2`)** to traverse the list.
- Move `temp2` until it reaches the last node (`nxt == NULL`).
- Attach the new node at the end (`temp2->nxt = temp`).

---

## **📌 Code Implementation**
```cpp
#include <iostream>
#include <cstring>  // For strcpy

using namespace std;

struct node {
    char name[20];  // Name of up to 20 characters
    int age;
    float height;
    node* nxt;  // Pointer to the next node
};

node* start_ptr = NULL;  // Head pointer (initially NULL)

// Function to add a node at the end
void add_node_at_end() {
    node *temp, *temp2;  // Temporary pointers

    // Step 1: Allocate memory for the new node
    temp = new node;

    // Step 2: Input data from the user
    cout << "Please enter the name of the person: ";
    cin >> temp->name;
    cout << "Please enter the age of the person: ";
    cin >> temp->age;
    cout << "Please enter the height of the person: ";
    cin >> temp->height;
    temp->nxt = NULL;  // This node will be the last node

    // Step 3: If the list is empty, set start_ptr to this new node
    if (start_ptr == NULL) {
        start_ptr = temp;
    } 
    else {
        // Step 4: Traverse the list to find the last node
        temp2 = start_ptr;
        while (temp2->nxt != NULL) {
            temp2 = temp2->nxt;
        }

        // Step 5: Link the last node to the new node
        temp2->nxt = temp;
    }
}

// Function to display the linked list
void display_list() {
    node* temp = start_ptr;
    
    if (temp == NULL) {
        cout << "The list is empty.\n";
        return;
    }

    cout << "\nLinked List Contents:\n";
    while (temp != NULL) {
        cout << "Name: " << temp->name << ", Age: " << temp->age << ", Height: " << temp->height << "m\n";
        temp = temp->nxt;  // Move to the next node
    }
}

int main() {
    // Adding nodes to the list
    add_node_at_end();
    add_node_at_end();
    add_node_at_end();

    // Display the list
    display_list();

    return 0;
}
```

---

## **📌 Explanation of the Logic**
### **🔹 Step-by-Step Breakdown**
1. **Creating a Node**
   - `temp = new node;` → Allocates memory for a new node.
   - We take user input (`name`, `age`, `height`).
   - `temp->nxt = NULL;` → This ensures it's the **last node**.

2. **Checking if List is Empty**
   - If `start_ptr == NULL`, we set it to `temp`, making this the **first node**.

3. **Finding the Last Node**
   - We use `temp2 = start_ptr;` to start from the first node.
   - A `while` loop moves `temp2` until `temp2->nxt == NULL` (end of the list).
   - Once found, we attach the new node: `temp2->nxt = temp;`.

4. **Displaying the List**
   - A loop traverses the list, printing the details of each node.

---

## **📌 Example Output**
```
Please enter the name of the person: Alice
Please enter the age of the person: 25
Please enter the height of the person: 1.7

Please enter the name of the person: Bob
Please enter the age of the person: 30
Please enter the height of the person: 1.8

Please enter the name of the person: Charlie
Please enter the age of the person: 22
Please enter the height of the person: 1.6

Linked List Contents:
Name: Alice, Age: 25, Height: 1.7m
Name: Bob, Age: 30, Height: 1.8m
Name: Charlie, Age: 22, Height: 1.6m
```

---

## **📌 Complexity Analysis**
| **Operation**      | **Time Complexity** |
|--------------------|--------------------|
| **Adding at End**  | **O(n)** (Traverses to last node) |
| **Adding at Start** | **O(1)** (Directly updates `start_ptr`) |
| **Displaying List** | **O(n)** |

---

## **📌 Summary**
| **Concept** | **Explanation** |
|-------------|----------------|
| **Creating a Node** | Uses `new` to allocate memory dynamically. |
| **Checking Empty List** | If `start_ptr == NULL`, make the new node the first node. |
| **Finding the Last Node** | Traverse the list using `while (temp2->nxt != NULL)`. |
| **Inserting at End** | Set `temp2->nxt = temp` to attach the new node. |
| **Displaying the List** | Traverse each node and print its data. |

---

## **📌 Displaying the List of Nodes in a Singly Linked List (C++)**  

### **🔹 Problem Statement**
Once we have added nodes to a **singly linked list**, we need to display the list of nodes on the screen.

---

## **🔹 Steps to Display a Singly Linked List**
### **1️⃣ Initialize a Temporary Pointer**
- Set a pointer (`temp`) to point to `start_ptr` (head of the list).

### **2️⃣ Check if List is Empty**
- If `temp == NULL`, print **"End of list"** and stop.

### **3️⃣ Traverse the List**
- While `temp != NULL`, do the following:
  - Print the `name`, `age`, and `height` of the current node.
  - Move `temp` to the **next node** using `temp = temp->nxt;`.

### **4️⃣ Repeat Until End of List**
- Continue until `temp` reaches `NULL`, which indicates the end of the list.

---

## **📌 Code Implementation**
```cpp
#include <iostream>
#include <cstring>  // For string operations

using namespace std;

struct node {
    char name[20];  // Name of up to 20 characters
    int age;
    float height;
    node* nxt;  // Pointer to the next node
};

node* start_ptr = NULL;  // Head pointer (initially NULL)

// Function to display the linked list
void display_list() {
    node* temp = start_ptr;  // Start from the head

    // Step 1: Check if the list is empty
    if (temp == NULL) {
        cout << "The list is empty.\n";
        return;
    }

    // Step 2: Traverse and print each node
    cout << "\nLinked List Contents:\n";
    while (temp != NULL) {
        cout << "Name: " << temp->name << "\n";
        cout << "Age: " << temp->age << "\n";
        cout << "Height: " << temp->height << "m\n";
        cout << "---------------------\n";
        temp = temp->nxt;  // Move to next node
    }
}

// Function to add a node at the end
void add_node_at_end() {
    node *temp, *temp2;

    // Step 1: Allocate memory for the new node
    temp = new node;

    // Step 2: Input data from the user
    cout << "Please enter the name of the person: ";
    cin >> temp->name;
    cout << "Please enter the age of the person: ";
    cin >> temp->age;
    cout << "Please enter the height of the person: ";
    cin >> temp->height;
    temp->nxt = NULL;  // This node will be the last node

    // Step 3: If the list is empty, set start_ptr to this new node
    if (start_ptr == NULL) {
        start_ptr = temp;
    } else {
        // Step 4: Traverse the list to find the last node
        temp2 = start_ptr;
        while (temp2->nxt != NULL) {
            temp2 = temp2->nxt;
        }
        // Step 5: Link the last node to the new node
        temp2->nxt = temp;
    }
}

int main() {
    // Adding nodes to the list
    add_node_at_end();
    add_node_at_end();
    add_node_at_end();

    // Display the list
    display_list();

    return 0;
}
```

---

## **📌 Explanation of the Logic**
### **🔹 Step-by-Step Breakdown**
1. **Checking if the List is Empty**
   - If `start_ptr == NULL`, print **"The list is empty."** and stop.

2. **Setting Up the Temporary Pointer**
   - `temp = start_ptr;` initializes traversal from the first node.

3. **Traversing the List**
   - **While** `temp != NULL`:
     - Print the `name`, `age`, and `height` of the current node.
     - Move `temp` to the **next node** (`temp = temp->nxt;`).

4. **Stopping at the End**
   - The loop continues until `temp == NULL`, meaning we've reached the **end of the list**.

---

## **📌 Example Output**
```
Please enter the name of the person: Alice
Please enter the age of the person: 25
Please enter the height of the person: 1.7

Please enter the name of the person: Bob
Please enter the age of the person: 30
Please enter the height of the person: 1.8

Please enter the name of the person: Charlie
Please enter the age of the person: 22
Please enter the height of the person: 1.6

Linked List Contents:
Name: Alice
Age: 25
Height: 1.7m
---------------------
Name: Bob
Age: 30
Height: 1.8m
---------------------
Name: Charlie
Age: 22
Height: 1.6m
---------------------
```

---

## **📌 Complexity Analysis**
| **Operation**        | **Time Complexity** |
|----------------------|--------------------|
| **Adding at End**    | **O(n)** (Traverses to last node) |
| **Displaying List**  | **O(n)** (Traverses entire list) |

---

## **📌 Summary**
| **Concept**          | **Explanation** |
|----------------------|----------------|
| **Checking if Empty** | If `start_ptr == NULL`, print "The list is empty." |
| **Traversing the List** | Use a `while` loop to move through nodes. |
| **Printing Node Data** | Display each node's `name`, `age`, and `height`. |
| **Stopping Condition** | When `temp == NULL`, end the loop. |

---
## **📌 Navigating and Modifying a Singly Linked List in C++**  

In this section, we'll implement:
- **Moving forward and backward in the linked list** 🏃‍♂️
- **Editing a node's details** ✏️
- **Adding a node after the current position** ➕
- **Deleting a node after the current position** ❌

---

## **🔹 1. Moving Through the Linked List**
We define a pointer `current` that:
- Starts at the first node (`start_ptr`).
- Moves **forward** using `current = current->nxt;`.
- Moves **backward** by traversing the list from the start.

### **📝 Code to Move Forward**
```cpp
if (current->nxt == NULL)
    cout << "You are at the end of the list." << endl;
else
    current = current->nxt;
```

### **📝 Code to Move Backward**
```cpp
if (current == start_ptr)
    cout << "You are at the start of the list" << endl;
else {
    node *previous = start_ptr;  // Start from the first node
    while (previous->nxt != current) {
        previous = previous->nxt;  // Move forward
    }
    current = previous;  // Move current back one step
}
```

---

## **🔹 2. Editing a Node's Details**
Once we navigate to a specific node, we can modify its details.

### **📝 Code to Modify Node Data**
```cpp
cout << "Please enter the new name of the person: ";
cin >> current->name;
cout << "Please enter the new age of the person: ";
cin >> current->age;
cout << "Please enter the new height of the person: ";
cin >> current->height;
```

---

## **🔹 3. Adding a Node After the Current Node**
To insert a node **after the current node**:
1. Allocate memory for a new node.
2. Input details into the new node.
3. Adjust the `nxt` pointers to insert the new node correctly.

### **📝 Code to Insert a Node After the Current Node**
```cpp
if (current->nxt == NULL) {
    add_node_at_end();  // If current is the last node, add at end
} else {
    node *temp = new node;  // Create a new node
    cout << "Enter name: "; cin >> temp->name;
    cout << "Enter age: "; cin >> temp->age;
    cout << "Enter height: "; cin >> temp->height;

    // Step 1: New node points to the next node
    temp->nxt = current->nxt;
    
    // Step 2: Current node points to the new node
    current->nxt = temp;
}
```

---

## **🔹 4. Deleting a Node After the Current Node**
To delete the node after `current`:
1. Assign a temporary pointer (`temp`) to `current->nxt`.
2. Make `current->nxt` point to `temp->nxt`, skipping the node.
3. Delete `temp`.

### **📝 Code to Delete a Node After the Current Node**
```cpp
if (current->nxt == NULL) {
    cout << "There is no node after current" << endl;
} else {
    node *temp = current->nxt;  // Store the node to be deleted
    current->nxt = temp->nxt;   // Bypass temp
    delete temp;  // Free memory
}
```

---

## **📌 Full Implementation in C++**
```cpp
#include <iostream>
#include <cstring>  

using namespace std;

struct node {
    char name[20];
    int age;
    float height;
    node* nxt;
};

node* start_ptr = NULL;
node* current = NULL;  // Pointer to navigate the list

// Function to add node at the end
void add_node_at_end() {
    node *temp, *temp2;
    temp = new node;

    cout << "Enter name: "; cin >> temp->name;
    cout << "Enter age: "; cin >> temp->age;
    cout << "Enter height: "; cin >> temp->height;
    temp->nxt = NULL;

    if (start_ptr == NULL) {
        start_ptr = temp;
    } else {
        temp2 = start_ptr;
        while (temp2->nxt != NULL) {
            temp2 = temp2->nxt;
        }
        temp2->nxt = temp;
    }
    if (current == NULL) {
        current = start_ptr;  // Set current to the first node
    }
}

// Function to move forward in the list
void move_forward() {
    if (current->nxt == NULL)
        cout << "You are at the end of the list." << endl;
    else
        current = current->nxt;
}

// Function to move backward in the list
void move_backward() {
    if (current == start_ptr)
        cout << "You are at the start of the list." << endl;
    else {
        node *previous = start_ptr;
        while (previous->nxt != current) {
            previous = previous->nxt;
        }
        current = previous;
    }
}

// Function to edit current node
void edit_node() {
    cout << "Enter new name: "; cin >> current->name;
    cout << "Enter new age: "; cin >> current->age;
    cout << "Enter new height: "; cin >> current->height;
}

// Function to delete the node after the current node
void delete_next_node() {
    if (current->nxt == NULL) {
        cout << "No node to delete after current." << endl;
    } else {
        node *temp = current->nxt;
        current->nxt = temp->nxt;
        delete temp;
    }
}

// Function to insert a node after the current node
void insert_after_current() {
    if (current->nxt == NULL) {
        add_node_at_end();
    } else {
        node *temp = new node;
        cout << "Enter name: "; cin >> temp->name;
        cout << "Enter age: "; cin >> temp->age;
        cout << "Enter height: "; cin >> temp->height;

        temp->nxt = current->nxt;
        current->nxt = temp;
    }
}

// Function to display the list
void display_list() {
    node* temp = start_ptr;
    if (temp == NULL) {
        cout << "The list is empty.\n";
        return;
    }
    cout << "\nLinked List Contents:\n";
    while (temp != NULL) {
        cout << "Name: " << temp->name << "\n";
        cout << "Age: " << temp->age << "\n";
        cout << "Height: " << temp->height << "m\n";
        cout << "---------------------\n";
        temp = temp->nxt;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add node at end\n";
        cout << "2. Move forward\n";
        cout << "3. Move backward\n";
        cout << "4. Edit current node\n";
        cout << "5. Delete next node\n";
        cout << "6. Insert after current\n";
        cout << "7. Display list\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: add_node_at_end(); break;
            case 2: move_forward(); break;
            case 3: move_backward(); break;
            case 4: edit_node(); break;
            case 5: delete_next_node(); break;
            case 6: insert_after_current(); break;
            case 7: display_list(); break;
            case 8: return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
```

---

## **📌 Features of This Code**
✅ Add a node at the end  
✅ Move **forward** and **backward** in the list  
✅ Edit the details of the **current node**  
✅ Insert a node **after the current node**  
✅ Delete the **next node**  
✅ Display the **entire list**  



### **Description of the Above Notes on Linked List Operations**  

The notes describe various operations on a **singly linked list** in C++, focusing on adding, displaying, navigating, and deleting nodes. Below is a structured breakdown of each section:

---

### **1. Adding a Node to the End of the List**  
- A new node is created dynamically using `new node`.
- The user inputs the person's **name, age, and height**.
- The `nxt` pointer of the new node is set to `NULL` (indicating the last node).
- If the list is empty (`start_ptr == NULL`), the new node becomes the first node.
- If the list has existing nodes, a temporary pointer (`temp2`) is used to traverse to the last node, where the new node is added.

---

### **2. Displaying the List of Nodes**  
- A temporary pointer (`temp`) is assigned to `start_ptr` (first node).
- The list is traversed using a `do-while` loop.
- If the list is empty (`temp == NULL`), it prints **"End of list"**.
- Otherwise, it prints the **name, age, and height** of each node before moving to the next node.

---

### **3. Navigating Through the List**  
- A pointer (`current`) is used for traversal, initially set to `start_ptr`.
- Moving forward is done using:  
  ```cpp
  current = current->nxt;
  ```
- Moving backward is more complex because a **singly linked list** does not have a previous pointer:
  - A temporary pointer (`previous`) is set to `start_ptr`.
  - It traverses the list to find the node before `current`.
  - If `current` is the first node, a message **"You are at the start of the list"** is printed.

---

### **4. Deleting a Node**  
#### **a) Deleting the First Node**
- The `start_ptr` moves to the next node.
- The first node is deleted using `delete temp`.

#### **b) Deleting the Last Node**
- Two pointers, `temp1` and `temp2`, are used.
- `temp1` traverses to the last node, while `temp2` tracks the second-last node.
- The last node (`temp1`) is deleted, and `temp2->nxt` is set to `NULL`.

#### **c) Handling Edge Cases**
- If the list is empty (`start_ptr == NULL`), a message **"The list is empty!"** is displayed.
- If the list has only **one node**, it is deleted, and `start_ptr` is set to `NULL`.

---

### **Summary**
This guide explains **basic linked list operations**, including:
1. **Adding** a node at the end.
2. **Displaying** all nodes.
3. **Navigating** through the list.
4. **Deleting** nodes from the **start and end**.



### **Description of Stack Data Structure Notes**

A **stack** is a **linear data structure** that follows the **LIFO (Last In, First Out)** principle, meaning that the last item added (pushed) is the first one removed (popped). 

---

## **1. Stack Operations**
### **a) PUSH Operation (Insertion)**
- **Push** adds an element to the **top** of the stack.
- If there is space available, the element is inserted.
- If the stack is full (overflow), an error message is shown.

### **b) POP Operation (Deletion)**
- **Pop** removes the **top** element from the stack.
- If the stack is not empty, it retrieves and removes the top item.
- If the stack is empty (underflow), an error message is displayed.

### **c) CreateStack (Initialization)**
- Clears all existing items from the stack.
- Initializes the stack as empty.

---

## **2. Stack Implementation**
Stacks can be implemented in **two ways**:
1. **Array-based Stack (Static)**
   - Uses a fixed-size array.
   - Faster but has a limited size.

2. **Linked List Stack (Dynamic)**
   - Uses nodes with pointers.
   - Flexible size, but requires extra memory for pointers.

---

## **3. Purpose of the Stack Implementation**
- The goal is to implement a stack that is **generic** and can handle **different data types**.
- The stack operations should work for both **array-based** and **linked list-based** implementations without affecting programs that use them.

---

## **4. Stack Representation**
### **Example of Stack Operations**
| **Operation** | **Stack Content** |
|--------------|----------------|
| Initial Stack | `4` |
| Push(8) | `8 → 4` (8 is on top) |
| Pop() | `4` (8 is removed) |

---

## **5. Summary**
- **Stacks use LIFO (Last In, First Out).**
- **Push** inserts an element at the top.
- **Pop** removes the top element.
- **Stacks can be implemented using arrays or linked lists.**
- **A generic stack should work for any data type.**

### **Array Implementation of Stack in C++**

This implementation uses an array-based **static stack** where:
- **PUSH** operation inserts an element at the top of the stack.
- **POP** operation removes the top element from the stack.
- **Stack Overflow** occurs when trying to push into a full stack.
- **Stack Underflow** occurs when trying to pop from an empty stack.

---

### **C++ Implementation**
```cpp
#include <iostream>
#define UPPERLIMIT 5  // Define the max size of the stack

using namespace std;

class Stack {
private:
    int stack[UPPERLIMIT]; // Static array for stack
    int top; // Top pointer

public:
    // Constructor to initialize stack
    Stack() {
        top = -1;
    }

    // PUSH operation
    void push(int item) {
        if (top >= UPPERLIMIT - 1) {
            cout << "Stack Overflow!" << endl;
        } else {
            top++;
            stack[top] = item;
            cout << item << " pushed into stack." << endl;
        }
    }

    // POP operation
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return -1;
        } else {
            int del_val = stack[top];
            top--;  // Move top pointer down
            return del_val;
        }
    }

    // Function to display stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

// Main function
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60); // Will show "Stack Overflow!"

    s.display();

    cout << "Popped element: " << s.pop() << endl;
    s.display();

    return 0;
}
```

---

### **Explanation**
1. **Push Operation:**
   - Increments `top` and adds an element to the array.
   - If `top` exceeds `UPPERLIMIT - 1`, it prints **"Stack Overflow"**.
  
2. **Pop Operation:**
   - Returns the top element and decrements `top`.
   - If `top == -1`, it prints **"Stack Underflow"**.

3. **Display Function:**
   - Prints stack elements from **top to bottom**.

---

### **Example Output**
```
10 pushed into stack.
20 pushed into stack.
30 pushed into stack.
40 pushed into stack.
50 pushed into stack.
Stack Overflow!
Stack elements: 50 40 30 20 10 
Popped element: 50
Stack elements: 40 30 20 10
```
### **Linked List Implementation of Stack (PUSH Operation) in C++**

This implementation uses a **dynamically allocated linked list** instead of an array. The advantage of this approach is:
- **No size limit** (no "Stack Overflow" condition).
- **Efficient memory usage** since memory is allocated dynamically.

---

### **C++ Implementation**
```cpp
#include <iostream>

using namespace std;

// Define the structure for a stack node
struct Node {
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node
};

// Stack class using linked list
class Stack {
private:
    Node* top; // Pointer to the top node of the stack

public:
    // Constructor to initialize an empty stack
    Stack() {
        top = NULL;
    }

    // PUSH operation (Insert at top)
    void push(int item) {
        Node* newnode = new Node(); // Step-1: Create a new node
        newnode->data = item;
        newnode->next = top; // Step-2: Link new node to previous top
        top = newnode;  // Step-3: Update top pointer
        cout << item << " pushed into stack." << endl;
    }

    // POP operation (Remove from top)
    int pop() {
        if (top == NULL) {
            cout << "Stack Underflow!" << endl;
            return -1;
        } else {
            int popped_value = top->data;
            Node* temp = top;
            top = top->next; // Move top pointer to next node
            delete temp; // Free memory
            return popped_value;
        }
    }

    // Function to display stack elements
    void display() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Popped element: " << s.pop() << endl;
    s.display();

    return 0;
}
```

---

### **Explanation**
1. **Push Operation:**
   - Creates a new node dynamically.
   - Links the new node to the current **top**.
   - Updates **top** to point to the new node.

2. **Pop Operation:**
   - Checks if the stack is empty (**Stack Underflow**).
   - Stores the top value, updates **top** to the next node, and deletes the old node.

3. **Display Function:**
   - Traverses the stack from **top** to **NULL**, printing each element.

---

### **Example Output**
```
10 pushed into stack.
20 pushed into stack.
30 pushed into stack.
Stack elements: 30 20 10 
Popped element: 30
Stack elements: 20 10
```
### **Linked List Implementation of Stack (POP Operation) in C++**

This implementation removes the **topmost element** from the stack, ensuring **Last In, First Out (LIFO)** behavior. If the stack is empty, it returns a **"Stack Underflow"** error.

---

### **C++ Implementation**
```cpp
#include <iostream>

using namespace std;

// Define the structure for a stack node
struct Node {
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node
};

// Stack class using linked list
class Stack {
private:
    Node* top;  // Pointer to the top node of the stack
    Node* bottom; // Pointer to the bottom node of the stack

public:
    // Constructor to initialize an empty stack
    Stack() {
        top = NULL;
        bottom = NULL;
    }

    // PUSH operation (Insert at top)
    void push(int item) {
        Node* newnode = new Node();
        newnode->data = item;
        newnode->next = NULL;

        if (top == NULL) {
            // First node in the stack
            top = bottom = newnode;
        } else {
            top->next = newnode;
            top = newnode;
        }

        cout << item << " pushed into stack." << endl;
    }

    // POP operation (Remove from top)
    int pop() {
        if (top == NULL) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }

        int pop_val;
        if (top == bottom) { 
            // Only one element in the stack
            pop_val = top->data;
            delete top;
            top = bottom = NULL;
        } else {
            // More than one element
            Node* target = bottom;
            while (target->next != top) {  // Find second last node
                target = target->next;
            }

            pop_val = top->data;
            delete top;
            top = target;
            top->next = NULL;
        }

        return pop_val;
    }

    // Function to display stack elements
    void display() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = bottom;
        cout << "Stack elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Popped element: " << s.pop() << endl;
    s.display();

    cout << "Popped element: " << s.pop() << endl;
    s.display();

    return 0;
}
```

---

### **Explanation**
1. **Push Operation:**
   - Creates a new node dynamically.
   - Links the new node to the **top**.
   - Updates **top** to point to the new node.

2. **Pop Operation:**
   - If the stack is empty, prints **Stack Underflow**.
   - If there's only **one element**, deletes it and sets `top = bottom = NULL`.
   - Otherwise, traverses the list to find the **second-last node**, deletes the top node, and updates `top`.

3. **Display Function:**
   - Traverses the stack from **bottom** to **top**, printing each element.

---

### **Example Output**
```
10 pushed into stack.
20 pushed into stack.
30 pushed into stack.
Stack elements: 10 20 30 
Popped element: 30
Stack elements: 10 20 
Popped element: 20
Stack elements: 10
```
### **Postfix Expression Evaluation Using Stack in C++**

The **postfix (Reverse Polish Notation - RPN)** expression evaluation can be efficiently handled using **stacks**. This implementation follows the algorithm outlined in your notes.

---

### **C++ Implementation**
```cpp
#include <iostream>
#include <stack>
#include <cmath>  // For power function

using namespace std;

// Function to evaluate a postfix expression
double evaluatePostfix(string expression) {
    stack<double> s;

    for (size_t i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        // Ignore spaces
        if (ch == ' ') continue;

        // If character is a digit, push it onto the stack
        if (isdigit(ch)) {
            s.push(ch - '0');  // Convert char to integer
        }
        // If character is an operator, pop operands and perform operation
        else {
            double x = s.top(); s.pop();
            double y = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(y + x); break;
                case '-': s.push(y - x); break;
                case '*': s.push(y * x); break;
                case '/': s.push(y / x); break;
                case '^': s.push(pow(y, x)); break;
                default: cout << "Invalid operator: " << ch << endl; return -1;
            }
        }
    }
    return s.top();  // Final result
}

// Driver function
int main() {
    string expression = "6 5 2 3 + 8 * + 3 + *";  // Postfix expression

    cout << "Postfix Expression: " << expression << endl;
    cout << "Evaluated Result: " << evaluatePostfix(expression) << endl;

    return 0;
}
```

---

### **How it Works**
1. **Push numbers** onto the stack.
2. **When an operator is encountered**, pop the top two values, apply the operator, and push the result back.
3. **At the end**, the only value left in the stack is the final result.

---

### **Example Execution**
#### **Input**
```cpp
string expression = "6 5 2 3 + 8 * + 3 + *";
```
#### **Step-by-Step Evaluation**
| Stack Before | Read Element | Stack After | Operation |
|-------------|-------------|-------------|-----------|
| _empty_ | 6 | 6 | Push |
| 6 | 5 | 6 5 | Push |
| 6 5 | 2 | 6 5 2 | Push |
| 6 5 2 | 3 | 6 5 2 3 | Push |
| 6 5 2 3 | + | 6 5 5 | 3+2=5 |
| 6 5 5 | 8 | 6 5 5 8 | Push |
| 6 5 5 8 | * | 6 5 40 | 5×8=40 |
| 6 5 40 | + | 6 45 | 5+40=45 |
| 6 45 | 3 | 6 45 3 | Push |
| 6 45 3 | + | 6 48 | 45+3=48 |
| 6 48 | * | 288 | 6×48=288 |

#### **Output**
```
Postfix Expression: 6 5 2 3 + 8 * + 3 + *
Evaluated Result: 288
```

---

### **Why Use Postfix?**
✅ **No Parentheses Needed** – Operator precedence is handled implicitly.  
✅ **Single Pass Evaluation** – Only one traversal is required.  
✅ **Simple Algorithm** – Uses **stacks**, making it easy to implement.  

### **Infix to Postfix (RPN) Conversion Using Stack in C++**

The **infix to postfix conversion** follows an algorithm that:
1. **Directly appends operands** to the output.
2. **Pushes operators onto the stack** while ensuring proper precedence.
3. **Handles parentheses** by popping operators until `(` is encountered.

---

### **C++ Implementation**
```cpp
#include <iostream>
#include <stack>
#include <cctype>  // For isalnum function

using namespace std;

// Function to get precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3; // Higher precedence for power
    return 0; // Lower precedence for non-operators
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {
        // If operand, append to postfix
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If left parenthesis, push to stack
        else if (ch == '(') {
            s.push(ch);
        }
        // If right parenthesis, pop until '(' is found
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop '('
        }
        // Operator encountered
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Driver function
int main() {
    string infix = "a+b*c+(d*e+f)*g";
    
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;

    return 0;
}
```

---

### **Step-by-Step Execution**
#### **Input**
```cpp
string infix = "a+b*c+(d*e+f)*g";
```

#### **Conversion Process**
| Stack (TOS at bottom) | Output | Read Character |
|----------------------|--------|---------------|
| `+`                 | `a`    | `a` (operand) |
| `+`                 | `ab`   | `b` (operand) |
| `+ *`               | `abc`  | `c` (operand) |
| `+`                 | `abc*` | `*` (higher precedence than `+`) |
| Empty               | `abc*+` | `+` (popped) |
| `( +`               | `abc*+` | `(` (push) |
| `( + *`             | `abc*+d` | `d` (operand) |
| `( + *`             | `abc*+de` | `e` (operand) |
| `( +`               | `abc*+de*` | `*` (operator) |
| `( +`               | `abc*+de*f` | `f` (operand) |
| `( +`               | `abc*+de*f+` | `+` (operator) |
| Empty               | `abc*+de*f+g*+` | `*` (after popping `+`) |

#### **Final Postfix Output**
```
abc*+de*f+g*+
```

---

### **Why This Works**
✅ **Operator precedence handled correctly**  
✅ **Parentheses removed naturally**  
✅ **Efficient and simple stack-based approach**  


### **Function Calls and the Role of the Stack**
When a function is called in a program, **several important pieces of data** are stored temporarily in memory to ensure that the function executes correctly and returns control to the calling function. The **stack** is used for this purpose.

---

### **Why Use a Stack for Function Calls?**
1. **Return Address Storage**  
   - When a function is called, execution jumps to that function’s code.
   - The **return address** (the instruction where execution should continue after the function finishes) must be saved.
   - If we stored it in a **fixed memory location**, it would be overwritten in recursive calls.

2. **Function Arguments**  
   - When calling a function, arguments (parameters) are passed.
   - They need to be stored temporarily before execution.

3. **Local Variables**  
   - Each function may declare local variables.
   - These variables should not interfere with the variables of another function call.

4. **Recursive Function Calls**  
   - When a function calls itself, it requires a **new instance of its execution state**.
   - This includes:
     - A new return address.
     - A new set of local variables.
   - The **stack** allows **multiple function calls to be tracked separately**.

---

### **Stack-Based Function Call Mechanism**
Each function call involves the following **stack operations**:

#### **1. Call a Function**
- **Push return address** onto the stack.
- **Push function arguments** onto the stack.
- **Jump to the function’s memory location**.

#### **2. Inside the Function**
- **Push local variables** onto the stack.

#### **3. Return from the Function**
- **Pop local variables** from the stack.
- **Pop return address** from the stack.
- **Jump back to the return address** and continue execution.

---

### **Example: Function Call Stack with Recursion**
Let’s analyze how function calls are managed in a **recursive function** using a stack.

#### **Example: Recursive Function**
```cpp
#include <iostream>
using namespace std;

void recursiveFunction(int n) {
    if (n <= 0) {
        return; // Base case: stops recursion
    }
    cout << "Calling function with n = " << n << endl;
    recursiveFunction(n - 1);
    cout << "Returning from function call with n = " << n << endl;
}

int main() {
    recursiveFunction(3);
    return 0;
}
```

#### **Function Call Stack Execution**
##### **Step-by-Step Breakdown**
| Stack (TOS at bottom) | Function Call |
|----------------------|--------------|
| `main()`            | `main()` calls `recursiveFunction(3)` |
| `recursiveFunction(3)` | Calls `recursiveFunction(2)` |
| `recursiveFunction(2)` | Calls `recursiveFunction(1)` |
| `recursiveFunction(1)` | Calls `recursiveFunction(0)` |
| `recursiveFunction(0)` | Base case reached, returns to `recursiveFunction(1)` |
| `recursiveFunction(1)` | Returns to `recursiveFunction(2)` |
| `recursiveFunction(2)` | Returns to `recursiveFunction(3)` |
| `recursiveFunction(3)` | Returns to `main()` |
| `main()` finishes | Program ends |

#### **Output**
```
Calling function with n = 3
Calling function with n = 2
Calling function with n = 1
Returning from function call with n = 1
Returning from function call with n = 2
Returning from function call with n = 3
```

---

### **Key Takeaways**
✅ **The stack stores return addresses, function arguments, and local variables.**  
✅ **Each function call gets its own stack frame, ensuring recursion works correctly.**  
✅ **When a function completes, its stack frame is removed (popped), and execution resumes at the saved return address.**  


The provided explanation covers **Queue** operations using both **simple arrays** and **circular arrays** in C++. Below is a refined version of the **queue implementation**, addressing syntax issues and ensuring correctness.

---

### **1. Simple Queue Implementation using an Array**
A simple queue uses a linear array but suffers from wasted space when elements are dequeued.

```cpp
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int FRONT = -1, REAR = -1, QUEUESIZE = 0;
int Num[MAX_SIZE]; // Queue array

void enqueue(int x) {
    if (REAR < MAX_SIZE - 1) { // Check if queue is not full
        REAR++;
        Num[REAR] = x;
        QUEUESIZE++;

        if (FRONT == -1) // First element case
            FRONT = 0;

        cout << "Enqueued: " << x << endl;
    } else {
        cout << "Queue Overflow" << endl;
    }
}

int dequeue() {
    if (QUEUESIZE > 0) { // Check if queue has elements
        int x = Num[FRONT];
        FRONT++;
        QUEUESIZE--;

        if (QUEUESIZE == 0) // Reset queue when empty
            FRONT = REAR = -1;

        cout << "Dequeued: " << x << endl;
        return x;
    } else {
        cout << "Queue Underflow" << endl;
        return -1; // Error value
    }
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // Underflow case

    return 0;
}
```

### **2. Circular Queue Implementation**
The **circular queue** overcomes the simple queue's problem of wasted space by reusing memory.

```cpp
#include <iostream>
using namespace std;

const int MAX_SIZE = 4;
int FRONT = -1, REAR = -1, QUEUESIZE = 0;
int Num[MAX_SIZE];

void enqueue(int x) {
    if (QUEUESIZE < MAX_SIZE) { // Check if space is available
        REAR = (REAR + 1) % MAX_SIZE; // Circular increment
        Num[REAR] = x;
        QUEUESIZE++;

        if (FRONT == -1) // First element case
            FRONT = 0;

        cout << "Enqueued: " << x << endl;
    } else {
        cout << "Queue Overflow" << endl;
    }
}

int dequeue() {
    if (QUEUESIZE > 0) { // Check if queue has elements
        int x = Num[FRONT];
        FRONT = (FRONT + 1) % MAX_SIZE; // Circular increment
        QUEUESIZE--;

        if (QUEUESIZE == 0) // Reset queue when empty
            FRONT = REAR = -1;

        cout << "Dequeued: " << x << endl;
        return x;
    } else {
        cout << "Queue Underflow" << endl;
        return -1;
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5); // Should overflow

    dequeue();
    dequeue();
    enqueue(6);
    enqueue(7); // Circular behavior

    dequeue();
    dequeue();
    dequeue();
    dequeue(); // Should underflow

    return 0;
}
```

### **Key Takeaways**
✅ **Simple Queue** wastes space as dequeued elements are not reused.  
✅ **Circular Queue** efficiently reuses freed space using modulo (`%`) arithmetic.  
✅ **Edge Cases Handled**: Overflow when full, underflow when empty, resetting when cleared.


### **Test Descriptions for Simple Queue and Circular Queue Implementations**

---

## **1. Simple Queue Test Cases**
**Objective**: Verify correct functionality of enqueue and dequeue operations.

| **Test Case** | **Description** | **Expected Output** |
|--------------|---------------|--------------------|
| **Test 1: Enqueue elements** | Add elements to the queue. | `Enqueued: 5`, `Enqueued: 10`, `Enqueued: 15` |
| **Test 2: Dequeue elements** | Remove elements from the queue. | `Dequeued: 5`, `Dequeued: 10`, `Dequeued: 15` |
| **Test 3: Dequeue from empty queue** | Try to remove an element when the queue is empty. | `Queue Underflow` |
| **Test 4: Queue overflow** | Fill the queue beyond `MAX_SIZE`. | `Queue Overflow` |
| **Test 5: Queue reset after emptying** | Check if the queue resets correctly when all elements are dequeued. | Should allow re-enqueue after emptying |

**Example Execution Output**
```plaintext
Enqueued: 5
Enqueued: 10
Enqueued: 15
Dequeued: 5
Dequeued: 10
Dequeued: 15
Queue Underflow
```

---

## **2. Circular Queue Test Cases**
**Objective**: Validate the circular behavior and correct handling of edge cases.

| **Test Case** | **Description** | **Expected Output** |
|--------------|---------------|--------------------|
| **Test 1: Enqueue elements** | Add elements to the queue. | `Enqueued: 1`, `Enqueued: 2`, `Enqueued: 3`, `Enqueued: 4` |
| **Test 2: Queue overflow** | Try to enqueue when full. | `Queue Overflow` |
| **Test 3: Dequeue elements** | Remove a few elements. | `Dequeued: 1`, `Dequeued: 2` |
| **Test 4: Circular enqueue** | Add elements after dequeuing (should reuse space). | `Enqueued: 6`, `Enqueued: 7` |
| **Test 5: Circular dequeue** | Remove all elements and check correct order. | `Dequeued: 3`, `Dequeued: 4`, `Dequeued: 6`, `Dequeued: 7` |
| **Test 6: Dequeue from empty queue** | Try to remove an element when the queue is empty. | `Queue Underflow` |

**Example Execution Output**
```plaintext
Enqueued: 1
Enqueued: 2
Enqueued: 3
Enqueued: 4
Queue Overflow
Dequeued: 1
Dequeued: 2
Enqueued: 6
Enqueued: 7
Dequeued: 3
Dequeued: 4
Dequeued: 6
Dequeued: 7
Queue Underflow
```

---

### **Summary**
✅ **Simple Queue** correctly handles FIFO operations but wastes space.  
✅ **Circular Queue** efficiently reuses space and prevents overflow with proper handling.  
✅ **Edge cases** (overflow, underflow, queue reset) are validated in both implementations.

# **Detailed Description of Queue Concepts and Implementations**

## **1. Linked List Implementation of Queue**
A **queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle, where elements are added at the **rear** and removed from the **front**. When implemented using a **linked list**, dynamic memory allocation is used, allowing for an unlimited number of elements as long as memory is available.

### **1.1. Enqueue Operation (Insert at Rear)**
- Create a new node with the given value.
- If the queue is empty, set both **front** and **rear** to the new node.
- Otherwise, insert the new node at the **end (rear)** and update the rear pointer.

### **1.2. Dequeue Operation (Delete from Front)**
- If the queue is empty, return an error ("Queue Underflow").
- Otherwise, remove the **front node**, update the front pointer, and free the memory.

---

## **2. Double-Ended Queue (Deque)**
A **deque** (pronounced *deck*) is an **extension of a queue** that allows insertions and deletions at **both ends**. It is best implemented using a **doubly linked list** for efficient insertions and deletions.

### **2.1. Operations in a Deque**
| Operation      | Description |
|---------------|------------|
| **EnqueueFront** | Inserts an element at the front of the deque. |
| **DequeueFront** | Removes an element from the front of the deque. |
| **EnqueueRear** | Inserts an element at the rear of the deque. |
| **DequeueRear** | Removes an element from the rear of the deque. |

### **2.2. Advantages of Deque**
- **More flexible** than a regular queue.
- Can be used to efficiently implement **both stack and queue** operations.

---

## **3. Priority Queue**
A **priority queue** is a queue where each element has a **priority value** that determines the order of removal. Elements with a **higher priority** are dequeued before those with a lower priority.

### **3.1. Priority Queue Operations**
| Operation      | Description |
|---------------|------------|
| **Enqueue** | Inserts an element into the queue along with its priority. |
| **Dequeue** | Removes the element with the **highest priority** (instead of the first element like in a normal queue). |

### **3.2. Example of a Priority Queue**
Consider a queue where **females** have higher priority than **males**:

#### **Initial Queue:**
| Name   | Gender  |
|--------|--------|
| Aster  | Female |
| Meron  | Female |
| Abebe  | Male   |
| Alemu  | Male   |
| Belay  | Male   |
| Kedir  | Male   |
| Yonas  | Male   |

#### **Dequeue Operations:**
1. **Dequeue() →** Aster (highest priority - female)
2. **Dequeue() →** Meron (highest priority - female)
3. **Dequeue() →** Abebe (male - now follows FIFO)
4. **Dequeue() →** Alemu
5. **Dequeue() →** Belay
6. **Dequeue() →** Kedir
7. **Dequeue() →** Yonas (last remaining)

---

## **4. Demerging Queues**
### **4.1. Definition**
Demerging is the process of splitting a **single queue into multiple queues** based on priority.

### **4.2. Example:**
Using the **gender-based priority queue**, we can create two separate queues:

#### **Females Queue**  
- Aster  
- Meron  

#### **Males Queue**  
- Abebe  
- Alemu  
- Belay  
- Kedir  
- Yonas  

### **4.3. Algorithm for Demerging Queues**
1. Create **two empty queues**: `FemalesQueue` and `MalesQueue`.
2. While `PriorityQueue` is not empty:
   - Dequeue an element.
   - If **Female**, enqueue into `FemalesQueue`.
   - If **Male**, enqueue into `MalesQueue`.

---

## **5. Merging Queues**
### **5.1. Definition**
Merging is the **opposite of demerging**, where two or more queues are combined into a **single priority queue**.

### **5.2. Example:**
#### **Before Merging:**
**Females Queue:**  
- Aster  
- Meron  

**Males Queue:**  
- Abebe  
- Alemu  
- Belay  
- Kedir  
- Yonas  

#### **After Merging into a Priority Queue:**
| Name   | Gender  |
|--------|--------|
| Aster  | Female |
| Meron  | Female |
| Abebe  | Male   |
| Alemu  | Male   |
| Belay  | Male   |
| Kedir  | Male   |
| Yonas  | Male   |

### **5.3. Algorithm for Merging Queues**
1. Create an **empty priority queue**.
2. While `FemalesQueue` is not empty:
   - Dequeue an element and enqueue it into `PriorityQueue`.
3. While `MalesQueue` is not empty:
   - Dequeue an element and enqueue it into `PriorityQueue`.

---

## **6. Application of Queues**
Queues are widely used in real-world applications, including:

### **6.1. Print Server**
A print server maintains a **queue of print jobs** and processes them in FIFO order.
```cpp
void Print(Document doc) {
    EnqueuePrintQueue(doc);
}

void EndOfPrint() {
    DequeuePrintQueue();
}
```

### **6.2. Disk Driver**
Queues manage disk **input/output requests**, ensuring efficient processing of read/write operations.

### **6.3. Task Scheduler in Multiprocessing Systems**
- Operating systems use **priority queues** to manage processes.
- **Higher priority tasks** are executed first.

### **6.4. Telephone Calls in Busy Networks**
- Calls are handled **on a first-come, first-served basis**.
- If multiple calls exist, priority may be given based on **VIP status**.

### **6.5. Simulation of a Waiting Line**
- Used in **banks, hospitals, and customer service** to manage waiting lists.
- Ensures fair service in **first-come, first-served** order.

---

## **Summary**
| **Concept**         | **Description** |
|---------------------|----------------|
| **Queue (Linked List)** | A dynamically allocated queue with enqueue at the rear and dequeue at the front. |
| **Deque (Double-Ended Queue)** | Allows insertions and deletions from both ends, implemented using a doubly linked list. |
| **Priority Queue** | Elements are dequeued based on priority instead of FIFO order. |
| **Demerging Queues** | Splitting a single queue into multiple queues based on attributes. |
| **Merging Queues** | Combining multiple queues into a single priority queue. |
| **Queue Applications** | Used in printing, disk operations, scheduling, and customer service. |

---

### **Conclusion**
Queues are essential in **data structures and real-world applications**. Implementing them efficiently using **linked lists, doubly linked lists, and priority queues** allows for **flexibility and performance improvements**.
Here are C++ implementations for each queue type:  

---

## **1. Linked List Implementation of Queue (Enqueue & Dequeue)**  
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
```

---

## **2. Double-Ended Queue (Deque)**
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    void enqueueFront(int val) {
        Node* newNode = new Node(val);
        if (!front) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void enqueueRear(int val) {
        Node* newNode = new Node(val);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void dequeueFront() {
        if (!front) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front) front->prev = nullptr;
        else rear = nullptr;
        delete temp;
    }

    void dequeueRear() {
        if (!rear) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if (rear) rear->next = nullptr;
        else front = nullptr;
        delete temp;
    }

    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    dq.enqueueFront(10);
    dq.enqueueRear(20);
    dq.enqueueRear(30);
    dq.display();
    dq.dequeueFront();
    dq.display();
    dq.dequeueRear();
    dq.display();
    return 0;
}
```

---

## **3. Priority Queue Implementation**
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data, priority;
    Node* next;
    Node(int val, int prio) : data(val), priority(prio), next(nullptr) {}
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() : front(nullptr) {}

    void enqueue(int val, int prio) {
        Node* newNode = new Node(val, prio);
        if (!front || prio > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next && temp->next->priority >= prio)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void dequeue() {
        if (!front) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    void display() {
        Node* temp = front;
        while (temp) {
            cout << "(" << temp->data << ", " << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(10, 2);
    pq.enqueue(20, 5);
    pq.enqueue(30, 1);
    pq.display();
    pq.dequeue();
    pq.display();
    return 0;
}
```

---

## **4. Demerging Queues**
```cpp
#include <iostream>
#include <queue>
using namespace std;

struct Person {
    string name;
    string gender;
};

void demergeQueue(queue<Person>& pq, queue<Person>& females, queue<Person>& males) {
    while (!pq.empty()) {
        Person p = pq.front();
        pq.pop();
        if (p.gender == "Female")
            females.push(p);
        else
            males.push(p);
    }
}

int main() {
    queue<Person> pq;
    pq.push({"Aster", "Female"});
    pq.push({"Abebe", "Male"});
    pq.push({"Meron", "Female"});
    pq.push({"Alemu", "Male"});

    queue<Person> females, males;
    demergeQueue(pq, females, males);

    cout << "Females Queue: ";
    while (!females.empty()) {
        cout << females.front().name << " ";
        females.pop();
    }

    cout << "\nMales Queue: ";
    while (!males.empty()) {
        cout << males.front().name << " ";
        males.pop();
    }
    return 0;
}
```

---

## **5. Merging Queues**
```cpp
#include <iostream>
#include <queue>
using namespace std;

void mergeQueues(queue<int>& priorityQueue, queue<int>& females, queue<int>& males) {
    while (!females.empty()) {
        priorityQueue.push(females.front());
        females.pop();
    }
    while (!males.empty()) {
        priorityQueue.push(males.front());
        males.pop();
    }
}

int main() {
    queue<int> females, males, priorityQueue;
    females.push(1);  // Aster
    females.push(2);  // Meron
    males.push(3);    // Abebe
    males.push(4);    // Alemu

    mergeQueues(priorityQueue, females, males);

    cout << "Merged Priority Queue: ";
    while (!priorityQueue.empty()) {
        cout << priorityQueue.front() << " ";
        priorityQueue.pop();
    }
    return 0;
}
```

---

## **6. Queue Applications**
### **Print Server Example**
```cpp
#include <iostream>
#include <queue>
using namespace std;

void printDocument(queue<string>& printQueue, string doc) {
    printQueue.push(doc);
}

void endOfPrint(queue<string>& printQueue) {
    if (!printQueue.empty()) {
        cout << "Printing: " << printQueue.front() << endl;
        printQueue.pop();
    }
}

int main() {
    queue<string> printQueue;
    printDocument(printQueue, "Report.pdf");
    printDocument(printQueue, "Assignment.docx");

    endOfPrint(printQueue);
    endOfPrint(printQueue);
    return 0;
}
```

---
### **Detailed Explanation of Trees and Their Types**  

A **tree** is a hierarchical data structure used in computer science for efficient searching, sorting, and organizing hierarchical data. It consists of **nodes** connected by **edges** and follows specific rules based on the type of tree.

---

## **1. Basic Tree Terminologies**  

### **1.1. Root**
- The **topmost node** of the tree with no parent.
- Example: In the tree below, **A** is the root.  
```
       A
      / \
     B   C
```

### **1.2. Parent and Child**
- **Parent**: A node that has children.
- **Child**: A node directly connected to a parent.
- Example: **B** is a child of **A** in the tree above.

### **1.3. Internal Node**
- A node that has at least one child.
- Example: **A, B, and F** are internal nodes in the tree below.
```
       A
      / \
     B   F
    / \   \
   C   D   J
```

### **1.4. External (Leaf) Node**
- A node that has **no children**.
- Example: **C, D, and J** are leaf nodes in the tree above.

### **1.5. Ancestors and Descendants**
- **Ancestors**: All nodes from the root to a given node.
- **Descendants**: All nodes below a given node.
- Example: In the tree above:
  - **Ancestors of J** → A, F
  - **Descendants of A** → B, C, D, F, J

### **1.6. Depth of a Node**
- Number of edges from the **root** to that node.
- Example: Depth of **J** in the above tree is **2**.

### **1.7. Height of a Tree**
- Depth of the **deepest node**.
- Example: The height of the tree above is **2**.

### **1.8. Subtree**
- A tree formed by a node and its descendants.
- Example: The subtree rooted at **B**:
```
     B
    / \
   C   D
```

---

## **2. Types of Trees**  

### **2.1. Binary Tree**
- A tree in which **each node has at most two children** (Left and Right).
- Example:
```
       A
      / \
     B   C
    / \
   D   E
```

### **2.2. Full Binary Tree**
- Each node has either **0 or 2 children** (No single child nodes).
- Example:
```
       A
      / \
     B   C
    / \   / \
   D   E F   G
```
- **Invalid Full Binary Tree**:  
```
       A
      / 
     B  
    / \
   D   E
```
(Because A has only one child)

### **2.3. Balanced Binary Tree**
- The **left and right subtrees of every node differ in height by at most 1**.
- Example:
```
       A
      / \
     B   C
    / \   \
   D   E   F
```
- **Not Balanced**:  
```
       A
      /
     B
    /
   C
```
(Left subtree is much deeper than the right)

### **2.4. Complete Binary Tree**
- Every level **except possibly the last is completely filled**.
- Nodes at the last level are **filled from left to right**.
- Example:
```
       A
      / \
     B   C
    / \  /
   D   E F
```
- **Invalid Complete Tree**:  
```
       A
      / \
     B   C
    /    /
   D     F
```
(Leaves are not filled left to right)

### **2.5. Binary Search Tree (BST)**
- A binary tree where:
  - **Left subtree** contains nodes **smaller** than the root.
  - **Right subtree** contains nodes **larger** than the root.
  - The left and right subtrees are also BSTs.
- Example:
```
       50
      /  \
    30    70
   /  \   /  \
  20  40 60  80
```
- **Invalid BST**:
```
       50
      /  \
    30    70
   /  \   /  \
  20  60 40  80
```
(60 is on the left of 50, which is incorrect)

---

## **3. Implementation Examples**

### **3.1. Binary Tree Implementation in C++**
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left, *right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() { root = nullptr; }

    void inorderTraversal(Node* node) {
        if (!node) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
};

int main() {
    BinaryTree tree;
    tree.root = new Node(10);
    tree.root->left = new Node(20);
    tree.root->right = new Node(30);
    tree.root->left->left = new Node(40);

    cout << "Inorder Traversal: ";
    tree.inorderTraversal(tree.root);
    return 0;
}
```

---

### **3.2. Binary Search Tree (BST) Implementation**
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() { root = nullptr; }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }

    void inorderTraversal(Node* node) {
        if (!node) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
};

int main() {
    BST tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Inorder Traversal of BST: ";
    tree.inorderTraversal(tree.root);
    return 0;
}
```

---

### **3.3. Checking if a Binary Tree is Balanced**
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left, *right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int height(Node* node) {
    if (!node) return 0;
    return max(height(node->left), height(node->right)) + 1;
}

bool isBalanced(Node* node) {
    if (!node) return true;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    cout << (isBalanced(root) ? "Tree is balanced" : "Tree is not balanced");
    return 0;
}
```

---

### **Detailed Explanation of Binary Search Tree (BST) Operations**

A **Binary Search Tree (BST)** is a type of binary tree where each node has at most two children, and the left subtree contains only nodes with values less than the parent node, while the right subtree contains only nodes with values greater than the parent.

---

## **1. Structure of a Binary Tree**
A node in a BST is represented using a struct in C++:
```cpp
struct Node {
    int Num; 
    Node *Left, *Right;
};
Node *RootNodePtr = NULL;
```
- `Num` → Stores the value of the node.
- `Left` → Pointer to the left child node.
- `Right` → Pointer to the right child node.
- `RootNodePtr` → Pointer to the root of the tree.

---

## **2. Insertion in a BST**
When inserting a new node into a BST, the placement of the new node must follow BST properties.

### **Case 1: The Tree is Empty**
If `RootNodePtr` is `NULL`, the new node becomes the root.

### **Case 2: The Tree is Not Empty**
- Start from the root.
- Compare the new value with the current node:
  - If it's smaller, move to the left subtree.
  - If it's larger, move to the right subtree.
- Repeat the process until an empty position is found.

### **Iterative Implementation**
```cpp
void InsertBST(Node *RNP, Node *INP) {  
    int Inserted = 0;
    while (Inserted == 0) {
        if (RNP->Num > INP->Num) {  // Go left
            if (RNP->Left == NULL) {
                RNP->Left = INP;
                Inserted = 1;
            } else {
                RNP = RNP->Left;
            }
        } else {  // Go right
            if (RNP->Right == NULL) {
                RNP->Right = INP;
                Inserted = 1;
            } else {
                RNP = RNP->Right;
            }
        }
    }
}
```

### **Recursive Implementation**
```cpp
void InsertBST(Node *RNP, Node *INP) {  
    if (RNP->Num > INP->Num) {  // Go left
        if (RNP->Left == NULL) {
            RNP->Left = INP;
        } else {
            InsertBST(RNP->Left, INP);
        }
    } else {  // Go right
        if (RNP->Right == NULL) {
            RNP->Right = INP;
        } else {
            InsertBST(RNP->Right, INP);
        }
    }
}
```

---

## **3. Tree Traversal**
Tree traversal refers to visiting all the nodes in a BST in a specific order. There are **three types of traversal**:

### **a) Preorder Traversal (Root → Left → Right)**
- Visit the root.
- Traverse the left subtree.
- Traverse the right subtree.

#### **Implementation**
```cpp
void Preorder(Node *CurrNodePtr) { 
    if (CurrNodePtr != NULL) {
        cout << CurrNodePtr->Num << " "; 
        Preorder(CurrNodePtr->Left);
        Preorder(CurrNodePtr->Right);
    }
}
```
#### **Example Output**
For the given BST:

```
        10
       /  \
      6    15
     / \   /  \
    4   8 14   18
       /  / \    \
      7  12  16   19
        / \
       11  13
```
Preorder Traversal Output:  
**10, 6, 4, 8, 7, 15, 14, 12, 11, 13, 18, 16, 17, 19**

---

### **b) Inorder Traversal (Left → Root → Right)**
- Traverse the left subtree.
- Visit the root.
- Traverse the right subtree.

#### **Implementation**
```cpp
void Inorder(Node *CurrNodePtr) { 
    if (CurrNodePtr != NULL) {
        Inorder(CurrNodePtr->Left);
        cout << CurrNodePtr->Num << " ";  
        Inorder(CurrNodePtr->Right);
    }
}
```
#### **Example Output**
Inorder Traversal Output:  
**4, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19**  
➡️ *Used to display nodes in ascending order.*

---

### **c) Postorder Traversal (Left → Right → Root)**
- Traverse the left subtree.
- Traverse the right subtree.
- Visit the root.

#### **Implementation**
```cpp
void Postorder(Node *CurrNodePtr) { 
    if (CurrNodePtr != NULL) {
        Postorder(CurrNodePtr->Left);
        Postorder(CurrNodePtr->Right);
        cout << CurrNodePtr->Num << " ";  
    }
}
```
#### **Example Output**
Postorder Traversal Output:  
**4, 7, 8, 6, 11, 13, 12, 14, 17, 16, 19, 18, 15, 10**

---

## **4. Applications of BST Traversal**
- **Preorder Traversal**  
  Used to generate mathematical expressions in **prefix notation**.  
  Example: `+ - A * B C + D / E F → Prefix notation`
  
- **Inorder Traversal**  
  Used to generate expressions in **infix notation**.  
  Example: `A - B * C + D + E / F → Infix notation`
  
- **Postorder Traversal**  
  Used to generate expressions in **postfix notation**.  
  Example: `A B C * - D E F / + + → Postfix notation`

---

## **5. Summary**
| Operation | Purpose | Complexity |
|-----------|---------|------------|
| **Insertion** | Inserts a new node into BST | O(log N) |
| **Preorder Traversal** | Root → Left → Right | O(N) |
| **Inorder Traversal** | Left → Root → Right | O(N) |
| **Postorder Traversal** | Left → Right → Root | O(N) |

---

## **Conclusion**
A **Binary Search Tree (BST)** provides an efficient way to store and retrieve ordered data. The three traversal methods—Preorder, Inorder, and Postorder—serve different applications, including **expression evaluation** and **sorting**.
Here's a summarized description of the detailed notes on **Binary Search Tree (BST):**  

---

### **Binary Search Tree (BST) Summary**
A **Binary Search Tree (BST)** is a hierarchical data structure where:  
- The left child contains values **smaller** than the parent.  
- The right child contains values **greater** than the parent.  
- The root node is the entry point to the tree.  

---

### **1. BST Structure**
BST nodes are defined using a struct with:  
- `Num`: Stores the value of the node.  
- `Left`: Pointer to the left child.  
- `Right`: Pointer to the right child.  
- `RootNodePtr`: Pointer to the root of the tree.  

---

### **2. Insertion in a BST**
Insertion ensures BST properties are maintained:  
- **If the tree is empty**, the new node becomes the root.  
- **If the tree has nodes**, find the correct position by comparing values recursively or iteratively.

---

### **3. Tree Traversal Methods**
Traversal visits all nodes in a tree. There are three types:  

#### **a) Preorder Traversal (Root → Left → Right)**
- Used for **prefix notation** in expressions.  

#### **b) Inorder Traversal (Left → Root → Right)**
- **Displays values in ascending order** (sorted output).  
- Used for **infix notation** in expressions.  

#### **c) Postorder Traversal (Left → Right → Root)**
- Used for **postfix notation** in expressions.  

---

### **4. Applications**
BST traversal is widely used for:  
- **Expression evaluation** (prefix, infix, postfix).  
- **Sorting data efficiently** using inorder traversal.  
- **Database indexing and searching** in log-time complexity.  

---

### **5. Complexity & Summary**
| Operation | Purpose | Complexity |
|-----------|---------|------------|
| **Insertion** | Places a node in correct order | O(log N) |
| **Preorder Traversal** | Root → Left → Right | O(N) |
| **Inorder Traversal** | Left → Root → Right (sorted order) | O(N) |
| **Postorder Traversal** | Left → Right → Root | O(N) |

---

### **Conclusion**
A **BST** provides an efficient way to **store, retrieve, and process ordered data**. Different traversal methods have specific use cases in **expression parsing, sorting, and searching algorithms**.


### **Searching in a Binary Search Tree (BST)**  

Searching in a **Binary Search Tree (BST)** follows the tree’s ordered structure. Given a **target value (`x`)**, we navigate the tree to check if the value exists.  

---

## **1. Searching for an Element (Boolean Return Type)**  
This function returns `true` if the element exists, otherwise `false`.

### **Function Call**
```cpp
bool ElementExists = SearchBST(RootNodePtr, Number);
```

### **Implementation**
```cpp
bool SearchBST(Node *RNP, int x) { 
    if (RNP == NULL)  
        return false;  // Element not found
    else if (RNP->Num == x)  
        return true;   // Element found
    else if (RNP->Num > x)  
        return SearchBST(RNP->Left, x);  // Search in left subtree
    else  
        return SearchBST(RNP->Right, x); // Search in right subtree
}
```

### **Algorithm Steps**
1. If the current node is `NULL`, return `false` (element is not found).
2. If the current node’s value equals `x`, return `true` (element found).
3. If `x` is **less than** the current node’s value, search the **left subtree**.
4. Otherwise, search the **right subtree**.

### **Time Complexity:**  
- **Best case:** `O(1)` (element found at the root).
- **Average case:** `O(log N)` (balanced BST).
- **Worst case:** `O(N)` (skewed BST).

---

## **2. Searching and Returning the Node Pointer**
Instead of returning `true` or `false`, this function returns a **pointer** to the node containing `x` (if found), or `NULL` (if not found).

### **Function Call**
```cpp
Node *SearchedNodePtr = SearchBST(RootNodePtr, Number);
```

### **Implementation**
```cpp
Node* SearchBST(Node *RNP, int x) { 
    if ((RNP == NULL) || (RNP->Num == x))  
        return RNP;  // Return node pointer if found, or NULL if not found
    else if (RNP->Num > x)  
        return SearchBST(RNP->Left, x);  // Search in left subtree
    else  
        return SearchBST(RNP->Right, x); // Search in right subtree
}
```

### **Algorithm Steps**
1. If `RNP` is `NULL` or `RNP->Num == x`, return `RNP` (found or not found).
2. If `x` is smaller, search the **left subtree**.
3. If `x` is larger, search the **right subtree**.

### **Use Case**
- If the function returns `NULL`, the element **does not exist**.
- If it returns a **valid node pointer**, it contains the searched value.

---

### **3. Summary**
| Search Type | Return Type | Purpose |
|-------------|------------|---------|
| **Boolean Search** | `true` / `false` | Checks if the element exists. |
| **Pointer Search** | `Node*` | Returns a pointer to the found node or `NULL`. |

**Complexity:**  
- **Balanced BST:** `O(log N)`.  
- **Worst case (skewed tree):** `O(N)`.  

This method ensures **efficient searching** in a BST. 🚀
### **Deletion in a Binary Search Tree (BST)**  

Deleting a node from a **Binary Search Tree (BST)** requires careful handling to maintain the **BST property**. There are four cases to consider:  

---

## **Case 1: Deleting a Leaf Node (No Child)**  
- A **leaf node** has no children.  
- Simply remove the node by setting the parent’s left or right child to `NULL`.  

### **Example**  
Deleting **7** from the BST:
```
Before:
        10
       /  \
      6    14
     / \    / \
    3   7  12 18

After:
        10
       /  \
      6    14
     /     / \
    3     12 18
```

### **Implementation**
```cpp
if (PDNP->Left == DNP)  
    PDNP->Left = NULL;  
else  
    PDNP->Right = NULL;  

delete DNP;
```

---

## **Case 2: Deleting a Node with One Child**  
- The deleted node has **only one child**.  
- Replace the node with its child.  

### **Example**  
Deleting **2** from the BST:
```
Before:
       10
      /  \
     6    14
    / \     \
   3   7     18
  /
 2  

After:
       10
      /  \
     6    14
    / \     \
   3   7     18
```

### **Implementation**
```cpp
if (DNP->Left != NULL)  
    DNP = DNP->Left;  
else  
    DNP = DNP->Right;
```
- If **left child exists**, it takes the place of `DNP`.  
- If **right child exists**, it takes the place of `DNP`.  

---

## **Case 3: Deleting a Node with Two Children**  
- The deleted node has **two children**.  
- We can replace it using either:
  1. **Deletion by merging**: Move left subtree up and attach right subtree.  
  2. **Deletion by copying**: Replace with **largest in the left subtree** or **smallest in the right subtree**.  

### **Example**  
Deleting **6**:
```
Before:
        10
       /  \
      6    14
     / \    / \
    3   8  12 18

After (by copying **largest in left subtree, 5**):
        10
       /  \
      5    14
     / \    / \
    3   8  12 18
```

### **Implementation**
```cpp
if (DNP->Left != NULL) {  // Find max in left subtree
    PDNP = DNP;
    DNP = DNP->Left;
    while (DNP->Right != NULL) {
        PDNP = DNP;
        DNP = DNP->Right;
    }
} else {  // Find min in right subtree
    PDNP = DNP;
    DNP = DNP->Right;
    while (DNP->Left != NULL) {
        PDNP = DNP;
        DNP = DNP->Left;
    }
}
RNP->Num = DNP->Num;
DeleteBST(DNP, PDNP, DNP->Num);
```

---

## **Case 4: Deleting the Root Node**  
- If **root has no children**, set it to `NULL`.  
- If **root has one child**, make that child the new root.  
- If **root has two children**, use **deletion by merging or copying**.

### **Example**
Deleting **10**:
```
Before:
        10
       /  \
      6    14
     / \    / \
    3   8  12 18

After:
        9
       /  \
      6    14
     / \    / \
    3   8  12 18
```

### **Implementation**
```cpp
if ((RootNodePtr->Left == NULL) && (RootNodePtr->Right == NULL)) {  
    delete RootNodePtr;  
    RootNodePtr = NULL;  
} else {  
    DeleteBST(RootNodePtr, RootNodePtr, RootNodePtr->Num);
}
```

---

## **Complete Function: DeleteBST**
```cpp
void DeleteBST(Node *RNP, Node *PDNP, int x) {
    Node *DNP;
    
    if (RNP == NULL) {
        cout << "Data not found\n";
        return;
    }

    if (RNP->Num > x)
        DeleteBST(RNP->Left, RNP, x);
    else if (RNP->Num < x)
        DeleteBST(RNP->Right, RNP, x);
    else {
        DNP = RNP;

        // Case 1: Node has no children (Leaf)
        if ((DNP->Left == NULL) && (DNP->Right == NULL)) {
            if (PDNP->Left == DNP)
                PDNP->Left = NULL;
            else
                PDNP->Right = NULL;
            delete DNP;
        }
        // Case 2 & 3: Node has one or two children
        else {
            if (DNP->Left != NULL) { // Find max in left
                PDNP = DNP;
                DNP = DNP->Left;
                while (DNP->Right != NULL) {
                    PDNP = DNP;
                    DNP = DNP->Right;
                }
            } else { // Find min in right
                PDNP = DNP;
                DNP = DNP->Right;
                while (DNP->Left != NULL) {
                    PDNP = DNP;
                    DNP = DNP->Left;
                }
            }

            RNP->Num = DNP->Num;
            DeleteBST(DNP, PDNP, DNP->Num);
        }
    }
}
```

---

## **Summary Table**
| Case | Node Type | Solution |
|------|----------|----------|
| **1** | Leaf (No Child) | Remove the node |
| **2** | One Child | Replace with child |
| **3** | Two Children | Replace with largest in left / smallest in right |
| **4** | Root Node | Handle like Case 1, 2, or 3 |

This method ensures that **BST properties are maintained** while efficiently deleting nodes. 🚀