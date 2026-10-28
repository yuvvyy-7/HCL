/**
 * File: constructor_sample.cpp
 * Topic: Constructors in C++
 * Concept:
 *   - A Constructor is a special member function automatically called when an object is created.
 *   - Same name as the class, no return type (not even void).
 *   - Types of Constructors demonstrated:
 *       1. Default Constructor: Initializes object with default values.
 *       2. Parameterized Constructor: Initializes object with specific values.
 *       3. Constructor Overloading: Multiple constructors with different parameters.
 *       4. Member Initializer List: ': name(n), rollNo(r)' initializes members before body runs.
 *       5. Copy Constructor: Initializes a new object as a copy of an existing object.
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
    // 1. Default Constructor
    Student() : name("Unassigned"), rollNo(0), marks(0.0) {
        cout << "[Default Constructor] Initialized default student." << endl;
    }

    // 2. Overloaded Parameterized Constructor (2 parameters: name, rollNo)
    Student(string studentName, int rollNumber) 
        : name(studentName), rollNo(rollNumber), marks(0.0) {
        cout << "[Parameterized Constructor (2 params)] Created student: " << name << endl;
    }

    // 3. Fully Parameterized Constructor (3 parameters) using Member Initializer List
    Student(string studentName, int rollNumber, double studentMarks) 
        : name(studentName), rollNo(rollNumber), marks(studentMarks) {
        cout << "[Parameterized Constructor (3 params)] Created student: " 
             << name << " with marks: " << marks << endl;
    }

    // 4. Copy Constructor (passes existing Student by const reference)
    Student(const Student& other) 
        : name(other.name ), rollNo(other.rollNo), marks(other.marks) {
        cout << "[Copy Constructor] Copied student from: " << other.name << endl;
    }

    // Display student details
    void display() const {
        cout << "Roll No: " << rollNo 
             << " | Name: " << name 
             << " | Marks: " << marks << endl;
    }
};

int main() {
    cout << "=== C++ Constructors Demo (Student) ===" << endl << endl;

    // 1. Invoking Default Constructor
    cout << "--- 1. Default Constructor ---" << endl;
    Student s1;
    s1.display();
    cout << endl;

    // 2. Invoking Overloaded Parameterized Constructor (2 arguments)
    cout << "--- 2. Parameterized Constructor (Partial Info) ---" << endl;
    Student s2("Ravi Kumar", 101);
    s2.display();
    cout << endl;

    // 3. Invoking Full Parameterized Constructor (3 arguments)
    cout << "--- 3. Full Parameterized Constructor ---" << endl;
    Student s3("Asha Sharma", 102, 94.5);
    s3.display();
    cout << endl;

    // 4. Invoking Copy Constructor
    cout << "--- 4. Copy Constructor ---" << endl;
    Student s4(s3); // Or: Student s4 = s3;
    s4.display();
    cout << endl;

    return 0;
}

