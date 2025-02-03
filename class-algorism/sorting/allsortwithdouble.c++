#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string id, name;
    float marks[5]; // Assuming 5 subjects
    Student* next;
    Student* prev; // Previous pointer for doubly linked list
};

Student* head = nullptr;

void addStudent();
void deleteStudent();
void searchStudent();
void displayAll();
void updateStudent();
float calculateGPA(Student* student);
float reportTotalGPA();
void sortByInsertion();
void sortBySelection();
void sortByBubble();
void sortByShell();
void quickSort(Student* start, Student* end);
Student* partition(Student* start, Student* end);
void sortByQuick();
void sortByMerge();
Student* mergeSort(Student* head);
Student* mergeSortedLists(Student* first, Student* second);

void addStudent() {
    string id, name;
    float marks[5];

    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter 5 subject marks: ";
    for (int i = 0; i < 5; i++) cin >> marks[i];

    Student* newStudent = new Student{id, name, {}, nullptr, nullptr};

    for (int i = 0; i < 5; i++) newStudent->marks[i] = marks[i];

    if (!head) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newStudent;
        newStudent->prev = temp;
    }
}

void displayAll() {
    Student* temp = head;
    while (temp) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << ", GPA: " << calculateGPA(temp) << "\n";
        temp = temp->next;
    }
}

float calculateGPA(Student* student) {
    float sum = 0;
    for (int i = 0; i < 5; i++) sum += student->marks[i];
    return sum / 5;
}

// **Insertion Sort**
void sortByInsertion() {
    if (!head || !head->next) return;
    Student* sorted = nullptr;
    Student* current = head;

    while (current) {
        Student* next = current->next;
        if (!sorted || calculateGPA(sorted) >= calculateGPA(current)) {
            current->next = sorted;
            sorted = current;
        } else {
            Student* temp = sorted;
            while (temp->next && calculateGPA(temp->next) < calculateGPA(current))
                temp = temp->next;
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted;
}

// **Selection Sort**
void sortBySelection() {
    if (!head || !head->next) return;
    Student* temp = head;
    while (temp) {
        Student* min = temp;
        Student* next = temp->next;
        while (next) {
            if (calculateGPA(next) < calculateGPA(min)) min = next;
            next = next->next;
        }
        swap(temp->id, min->id);
        swap(temp->name, min->name);
        swap(temp->marks, min->marks);
        temp = temp->next;
    }
}

// **Bubble Sort**
void sortByBubble() {
    if (!head || !head->next) return;
    bool swapped;
    do {
        swapped = false;
        Student* temp = head;
        while (temp->next) {
            if (calculateGPA(temp) > calculateGPA(temp->next)) {
                swap(temp->id, temp->next->id);
                swap(temp->name, temp->next->name);
                swap(temp->marks, temp->next->marks);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}

// **Shell Sort**
void sortByShell() {
    int n = 0;
    for (Student* temp = head; temp; temp = temp->next) n++;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (Student* i = head; i; i = i->next) {
            Student* j = i;
            while (j->prev && calculateGPA(j->prev) > calculateGPA(j)) {
                swap(j->id, j->prev->id);
                swap(j->name, j->prev->name);
                swap(j->marks, j->prev->marks);
                j = j->prev;
            }
        }
    }
}

// **Quick Sort Helper**
Student* partition(Student* start, Student* end) {
    float pivot = calculateGPA(end);
    Student* pIndex = start;
    for (Student* i = start; i != end; i = i->next) {
        if (calculateGPA(i) < pivot) {
            swap(i->id, pIndex->id);
            swap(i->name, pIndex->name);
            swap(i->marks, pIndex->marks);
            pIndex = pIndex->next;
        }
    }
    swap(pIndex->id, end->id);
    swap(pIndex->name, end->name);
    swap(pIndex->marks, end->marks);
    return pIndex;
}

// **Quick Sort**
void quickSort(Student* start, Student* end) {
    if (start != end && start && end) {
        Student* pivot = partition(start, end);
        if (pivot->prev) quickSort(start, pivot->prev);
        if (pivot->next) quickSort(pivot->next, end);
    }
}

void sortByQuick() {
    Student* end = head;
    while (end->next) end = end->next;
    quickSort(head, end);
}

// **Merge Sort Helper**
Student* mergeSortedLists(Student* first, Student* second) {
    if (!first) return second;
    if (!second) return first;
    
    if (calculateGPA(first) < calculateGPA(second)) {
        first->next = mergeSortedLists(first->next, second);
        first->next->prev = first;
        first->prev = nullptr;
        return first;
    } else {
        second->next = mergeSortedLists(first, second->next);
        second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

// **Merge Sort**
Student* mergeSort(Student* head) {
    if (!head || !head->next) return head;

    Student* slow = head;
    Student* fast = head->next;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Student* secondHalf = slow->next;
    slow->next = nullptr;
    secondHalf->prev = nullptr;
    
    Student* left = mergeSort(head);
    Student* right = mergeSort(secondHalf);
    
    return mergeSortedLists(left, right);
}

void sortByMerge() {
    head = mergeSort(head);
}

// **Heap Sort**
void heapify(vector<Student*>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && calculateGPA(arr[left]) > calculateGPA(arr[largest]))
        largest = left;

    if (right < n && calculateGPA(arr[right]) > calculateGPA(arr[largest]))
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void sortByHeap() {
    if (!head || !head->next) return;

    vector<Student*> arr;
    for (Student* temp = head; temp; temp = temp->next)
        arr.push_back(temp);

    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    head = arr[0];
    Student* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = arr[i];
        arr[i]->prev = temp;
        temp = arr[i];
    }
    temp->next = nullptr;
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student\n2. Display All\n3. Insertion Sort\n4. Selection Sort\n5. Bubble Sort";
        cout << "\n6. Shell Sort\n7. Quick Sort\n8. Merge Sort\n9. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: sortByInsertion(); break;
            case 4: sortBySelection(); break;
            case 5: sortByBubble(); break;
            case 6: sortByShell(); break;
            case 7: sortByQuick(); break;
            case 8: sortByMerge(); break;
        }
    } while (choice != 9);
    return 0;
}

