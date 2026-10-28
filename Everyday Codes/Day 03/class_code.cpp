/**
 * File: class_code.cpp
 * Topic: Introduction to Classes, Objects, and Encapsulation
 * Concept:
 *   - Class is a blueprint; Object is an instance of that class.
 *   - Access Specifiers:
 *       - private: Data members are hidden from outside the class (Encapsulation).
 *       - public:  Member functions provide a controlled interface to access/modify data.
 *   - Member Functions: Setters (with validation), Getters, and utility methods.
 *   - Dot Operator (.): Used to access public members of an object on the stack.
 */

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    // Private data members (Encapsulated: cannot be modified directly from outside)
    string name;
    int rollNo;
    double marks;

public:
    // Setter method with input validation
    void setDetails(string studentName, int rollNumber, double studentMarks) {
        name = studentName;
        rollNo = rollNumber;

        // Data validation: ensure marks are within valid range [0, 100]
        if (studentMarks >= 0.0 && studentMarks <= 100.0) {
            marks = studentMarks;
        } else {
            cout << "[Warning] Invalid marks entered for " << name 
                 << ". Defaulting marks to 0.0" << endl;
            marks = 0.0;
        }
    }

    // Getter methods (read-only access to private members)
    string getName() const {
        return name;
    }

    int getRollNo() const {
        return rollNo;
    }

    double getMarks() const {
        return marks;
    }

    // // Member function to compute grade based on marks
    // char calculateGrade() const {
    //     if (marks >= 90.0) return 'A';
    //     if (marks >= 75.0) return 'B';
    //     if (marks >= 60.0) return 'C';
    //     if (marks >= 50.0) return 'D';
    //     return 'F';
    // }

    // Member function to display student information
    void display() const {
        cout << "Roll No : " << rollNo << endl;
        cout << "Name    : " << name << endl;
        cout << "Marks   : " << marks << endl;
        // cout << "Grade   : " << calculateGrade() << endl;
        cout << "-----------------------------------" << endl;
    }
};
 
int main() {
    // cout << "=== C++ Class & Object Demo (Student) ===" << endl << endl;

    // 1. Creating objects (instances) of Student on the stack
    Student s1;
    Student s2;

    // 2. Setting values using public setter methods
    s1.setDetails("Asha Sharma", 101, 92.5);
    s2.setDetails("Ravi Kumar", 102, 105.0); // Triggers validation warning

    // Note: Direct access to private members is illegal and causes compiler error:
    // s1.marks = 95.0; // ERROR: 'marks' is a private member of 'Student'

    // 3. Displaying student records using member function
    cout << "\nStudent 1 Details:" << endl;
    s1.display();

    cout << "Student 2 Details:" << endl;
    s2.display();

    // 4. Using getters to access individual attributes
    cout << "Individual getter access for Student 1:" << endl;
    cout << s1.getName() << " secured " << s1.getMarks() << " marks." << endl;

    return 0;
}

