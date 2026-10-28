/**
 * File: destructor_sample.cpp
 * Topic: Destructors, Object Lifetime, and Scope in C++
 * Concept:
 *   - A Destructor is a special member function called automatically when an object
 *     is destroyed (e.g., goes out of scope or is deleted).
 *   - Syntax: ~ClassName(), no arguments, no return type. A class can have only ONE destructor.
 *   - Lifetime & Scope:
 *       - Stack objects are created in their enclosing scope block { ... }.
 *       - Destructors run immediately when the closing brace } is reached.
 *   - Order of Destruction (LIFO):
 *       - Objects created on the stack are destroyed in REVERSE order of creation (Last-In, First-Out).
 */

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNo;

public:
    // Constructor
    Student(string studentName, int rollNumber) 
        : name(studentName), rollNo(rollNumber) {
        cout << "  [+] Constructor: Student '" << name 
             << "' (Roll " << rollNo << ") created." << endl;
    }

    // Destructor
    ~Student() {
        cout << "  [-] Destructor : Student '" << name 
             << "' (Roll " << rollNo << ") destroyed." << endl;
    }

    void display() const {
        cout << "      Student: " << name << " [Roll: " << rollNo << "]" << endl;
    }
};

int main() {
    cout << "=== C++ Destructor & Lifetime Demo (Student) ===" << endl << endl;

    cout << "1. Creating student 'Asha' in main scope..." << endl;
    Student s1("Asha Sharma", 101);
    s1.display();

    cout << "\n2. Entering an inner block scope { ... }..." << endl;
    {
        cout << "   Creating student 'Ravi' and 'Kavya' inside inner scope:" << endl;
        Student s2("Ravi Kumar", 102);
        Student s3("Kavya Patel", 103);

        cout << "   Both inner students exist inside this block." << endl;
        s2.display();
        s3.display();

        cout << "   Exiting inner block scope now..." << endl;
        // Watch LIFO order here: s3 (created second) is destroyed before s2 (created first)!
    }

    cout << "\n3. Back in main scope. Inner students are already destroyed." << endl;
    cout << "   Student 'Asha' is still alive here." << endl;
    s1.display();
    // s3.display(); // This will cause a compile-time error since s3 is out of scope.

    cout << "\n4. Reaching the end of main()..." << endl;
    // s1 will be destroyed right after main returns.
    return 0;
}

