/**
 * File: classes_mem_allocation.cpp
 * Topic: Dynamic Memory Allocation for Class Objects (Stack vs Heap)
 * Concept:
 *   - Stack Allocation: Memory allocated automatically at compile/run time; freed when scope ends.
 *   - Heap Allocation: Memory dynamically allocated using 'new'; persists until explicitly 'delete'd.
 *   - Operators:
 *       - new: Allocates memory on the heap and invokes constructor. Returns a pointer.
 *       - delete: Invokes destructor and releases heap memory.
 *       - Arrow operator (->): Accesses members through an object pointer (ptr->method()).
 *       - new[] / delete[]: Allocates and frees a dynamic array of class objects.
 *   - Safety: Setting deallocated pointers to 'nullptr' prevents dangling pointers.
 */

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNo;
    double marks;

public:
    // Default constructor (required when allocating arrays of objects: new Student[N])
    Student() : name("Default Student"), rollNo(0), marks(0.0) {
        cout << "  [+] Student default constructor called." << endl;
    }

    // Parameterized constructor
    Student(string studentName, int rollNumber, double studentMarks)
        : name(studentName), rollNo(rollNumber), marks(studentMarks) {
        cout << "  [+] Student parameterized constructor called for: " << name << endl;
    }

    // Destructor
    ~Student() {
        cout << "  [-] Student destructor called for: " << name << endl;
    }

    // Setter for array population
    void setDetails(string studentName, int rollNumber, double studentMarks) {
        name = studentName;
        rollNo = rollNumber;
        marks = studentMarks;
    }

    // Member function
    void display() const {
        cout << "      [Roll " << rollNo << "] " << name 
             << " - Marks: " << marks << endl;
    }
};

int main() {
    cout << "=== Dynamic Memory Allocation for Objects (Student) ===" << endl << endl;

    // ---------------------------------------------------------
    // 1. STACK ALLOCATION (Automatic Memory Management)
    // ---------------------------------------------------------
    cout << "--- 1. Stack Allocation ---" << endl;
    {
        Student stackStudent("Asha Sharma", 101, 95.0);
        // Access via dot (.) operator
        stackStudent.display();
        cout << "Stack object will be destroyed automatically upon block exit." << endl;
    }
    cout << endl;

    // ---------------------------------------------------------
    // 2. HEAP ALLOCATION (Manual Memory Management using 'new')
    // ---------------------------------------------------------
    cout << "--- 2. Heap Allocation (Single Object) ---" << endl;
    // 'new' allocates Student on heap and returns its address
    Student* heapStudent = new Student("Ravi Kumar", 102, 88.5);

    // Access members using arrow (->) operator or dereference (*ptr).
    cout << "Accessing via arrow (->) operator:" << endl;
    heapStudent->display();

    cout << "Accessing via dereference (*ptr). syntax:" << endl;
    (*heapStudent).display();

    // Must manually release heap memory!
    cout << "Deleting heap object:" << endl;
    delete heapStudent;

    // Good practice: nullify pointer to prevent dangling pointer bugs
    heapStudent = nullptr;
    cout << "Pointer set to nullptr safely." << endl << endl;

    // ---------------------------------------------------------
    // 3. DYNAMIC ARRAY OF OBJECTS (new[] and delete[])
    // ---------------------------------------------------------
    cout << "--- 3. Dynamic Array of Objects (Cohort/Classroom) ---" << endl;
    int classroomSize = 3;
    cout << "Allocating array of " << classroomSize << " students on the heap:" << endl;
    
    // Allocates array on heap (invokes default constructor for each element)
    Student* classroom = new Student[classroomSize];

    // Populate each student
    classroom[0].setDetails("Meera Nair", 201, 91.0);
    classroom[1].setDetails("Dev Patel", 202, 84.0);
    classroom[2].setDetails("Sara Khan", 203, 79.5);

    cout << "\nDisplaying classroom students from heap array:" << endl;
    for (int i = 0; i < classroomSize; i++) {
        // Can use array indexing or pointer arithmetic
        classroom[i].display();
    }

    // Must use delete[] for arrays allocated with new[]
    cout << "\nFreeing dynamic array using delete[]:" << endl;
    delete[] classroom;
    classroom = nullptr;

    cout << "\nAll dynamic memory successfully freed." << endl;
    return 0;
}

