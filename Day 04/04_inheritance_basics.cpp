/**
 * File: 04_inheritance_basics.cpp
 * Topic: Inheritance Fundamentals, Protected Access, and Constructor Chaining
 * Concept:
 *   1. Inheritance ("IS-A" Relationship):
 *      - Base Class (Student): Encapsulates foundational attributes shared by all students.
 *      - Derived Class (GraduateStudent): Specializes and extends the Base class.
 *   2. 'protected' Access Specifier:
 *      - More open than 'private': accessible by derived child classes directly.
 *      - More secure than 'public': hidden and shielded from the outside world.
 *   3. Base Constructor Chaining:
 *      - The Derived class constructor delegates initialization of inherited fields
 *        to the Base class constructor (: Student(n, r, m)).
 *      - Order of Execution: Base constructor executes FIRST, Derived executes SECOND.
 */

#include <iostream>
#include <string>

using namespace std;

// 1. BASE CLASS: Student

class Student {
protected:
    // 'protected' permits derived classes (like GraduateStudent) to access these directly,
    // while preventing external code from tampering with them.
    string name;
    int rollNo; 
    double marks;

public:
    Student(string n, int r, double m) : name(n), rollNo(r), marks(m) {
        cout << "  [+] 1. Base Student Constructor called for: " << name << endl;
    }

    void displayBasicInfo() const {
        cout << "      [Base Info] Roll: " << rollNo << " | Name: " << name 
             << " | Score: " << marks << endl;
    }
};

// 2. DERIVED CLASS: GraduateStudent inherits from Student (IS-A relationship)

class GraduateStudent : public Student {
private:
    string thesisTitle;
    int researchCredits;

public:
    // Base constructor chaining: Student(n, r, m) runs first to initialize base fields!
    GraduateStudent(string n, int r, double m, string thesis, int credits)
        : Student(n, r, m), thesisTitle(thesis), researchCredits(credits) {
        cout << "  [+] 2. Derived GraduateStudent Constructor called for thesis: \"" 
             << thesisTitle << "\"" << endl;
    }

    // Specialized derived method accessing both inherited and new fields
    void displayGraduateProfile() const {
        // Can access 'name', 'rollNo', and 'marks' directly because they are 'protected' in Student!
        cout << "\n==============================================" << endl;
        cout << "          GRADUATE RESEARCH PROFILE           " << endl;
        cout << "==============================================" << endl;
        cout << " Candidate Name   : " << name << endl;
        cout << " Roll Number      : " << rollNo << endl;
        cout << " Academic Score   : " << marks << " marks" << endl;
        cout << " Research Thesis  : \"" << thesisTitle << "\"" << endl;
        cout << " Research Credits : " << researchCredits << " hrs/week" << endl;
        cout << " Status           : " << (marks >= 85.0 ? "Eligible for Fellowship" : "Standard Research") << endl;
        cout << "==============================================\n" << endl;
    }
};

// MAIN DEMONSTRATION

int main() {
    cout << "=== C++ Inheritance Demo: Student -> GraduateStudent ===" << endl << endl;

    // 1. Notice the Constructor Execution Order:
    cout << "--- 1. Instantiating a GraduateStudent (Observing Constructor Chaining) ---" << endl;
    GraduateStudent grad("Asha Sharma", 101, 94.5, "Autonomous Drone Navigation", 12);
    cout << endl;

    // 2. Calling an inherited method from the Base class:
    cout << "--- 2. Invoking Inherited Base Method (Reusability) ---" << endl;
    grad.displayBasicInfo();
    cout << endl;

    // 3. Calling specialized method from the Derived class:
    cout << "--- 3. Invoking Specialized Derived Method ---" << endl;
    grad.displayGraduateProfile();

    // 4. Protected access guard demonstration:
    // grad.marks = 100.0; // ERROR: 'marks' is protected; external code cannot access it directly!

    return 0;
}

