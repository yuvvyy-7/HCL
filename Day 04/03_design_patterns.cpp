/**
 * File: 03_design_patterns.cpp
 * Topic: Foundational Design Patterns (Singleton & Iterator)
 * Concept:
 *   1. Singleton Pattern:
 *      - Ensures that a class has only ONE instance and provides a global point
 *        of access to it.
 *      - Private constructor prevents direct instantiation with 'new' or stack.
 *      - Deleted copy constructor and assignment operator prevent duplication.
 *      - Example: UniversityRegistry (only one central student enrollment office exists).
 *   2. Iterator Pattern:
 *      - Provides a way to sequentially access elements of an aggregate object (like a roster)
 *        without exposing its underlying internal structure (e.g. vector, list, array).
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// STUDENT MODEL

class Student {
private:
    string name;
    int rollNo;
    string department;

public:
    Student(string n, int r, string dept) 
        : name(n), rollNo(r), department(dept) {}

    string getName() const { return name; }
    int getRollNo() const { return rollNo; }
    string getDepartment() const { return department; }

    void display() const {
        cout << "  [Student Record] Roll: " << rollNo 
             << " | Name: " << name 
             << " | Department: " << department << endl;
    }
};

// 1. SINGLETON PATTERN: UniversityRegistry

class UniversityRegistry {
private:
    // Static pointer holding the unique single instance
    static UniversityRegistry* instance;

    // Internal container storing registered students
    vector<Student> enrolledStudents;

    // Private Constructor: Prevents outside code from calling 'new UniversityRegistry()'
    UniversityRegistry() {
        cout << "  [Singleton Init] Central UniversityRegistry created in memory." << endl;
    }

public:
    // Prevent cloning and assignment (Crucial for true Singleton behavior in modern C++)
    UniversityRegistry(const UniversityRegistry&) = delete;
    UniversityRegistry& operator=(const UniversityRegistry&) = delete;

    // Global static access method
    static UniversityRegistry* getInstance() {
        if (instance == nullptr) {
            instance = new UniversityRegistry();
        }
        return instance;
    }

    void enrollStudent(const Student& s) {
        enrolledStudents.push_back(s);
        cout << "  [Enrollment] Added student '" << s.getName() 
             << "' to University Registry." << endl;
    }

    int getTotalEnrolled() const {
        return static_cast<int>(enrolledStudents.size());
    }

    
    // 2. ITERATOR PATTERN: Exposing safe sequential traversal
    
    // Begin and end iterators allow callers to iterate without knowing about vector
    vector<Student>::const_iterator begin() const {
        return enrolledStudents.begin();
    }

    vector<Student>::const_iterator end() const {
        return enrolledStudents.end();
    }
};

// Initialize static member pointer to nullptr
UniversityRegistry* UniversityRegistry::instance = nullptr;

// MAIN DEMONSTRATION

int main() {
    cout << "=== C++ Design Patterns: Singleton & Iterator Patterns ===" << endl << endl;

    // ------------------------------------------------------------------------
    // Part 1: Testing Singleton Pattern
    // ------------------------------------------------------------------------
    cout << "--- 1. Testing Singleton: Requesting Registry Instances ---" << endl;
    
    // Attempting to create an instance directly causes compiler error:
    // UniversityRegistry reg; // ERROR: constructor is private!

    // Request registry from Department A
    UniversityRegistry* admissionsOffice = UniversityRegistry::getInstance();

    // Request registry from Department B
    UniversityRegistry* examinationBranch = UniversityRegistry::getInstance();

    cout << "Address obtained by Admissions Office   : " << admissionsOffice << endl;
    cout << "Address obtained by Examination Branch : " << examinationBranch << endl;

    if (admissionsOffice == examinationBranch) {
        cout << ">> PROOF: Both pointers reference the EXACT SAME central instance!" << endl;
    }
    cout << endl;

    // ------------------------------------------------------------------------
    // Part 2: Enrolling Students Through the Singleton Registry
    // ------------------------------------------------------------------------
    cout << "--- 2. Enrolling Students into the Shared Central Registry ---" << endl;
    admissionsOffice->enrollStudent(Student("Asha Sharma", 101, "Computer Science"));
    admissionsOffice->enrollStudent(Student("Ravi Kumar", 102, "Mechanical Eng"));
    examinationBranch->enrollStudent(Student("Meera Nair", 103, "Electrical Eng"));

    cout << "\nTotal students now registered in central system: " 
         << examinationBranch->getTotalEnrolled() << endl << endl;

    // ------------------------------------------------------------------------
    // Part 3: Testing Iterator Pattern
    // ------------------------------------------------------------------------
    cout << "--- 3. Testing Iterator Pattern: Roster Traversal ---" << endl;
    cout << "Iterating through student cohort using standard Iterator:" << endl;

    // Using explicit iterator syntax to demonstrate the Iterator pattern
    for (vector<Student>::const_iterator it = admissionsOffice->begin(); 
         it != admissionsOffice->end(); ++it) {
        it->display();
    }

    cout << "\nIterating with C++11 Range-based for loop (syntactic sugar over Iterator):" << endl;
    for (const auto& student : *admissionsOffice) {
        cout << "  - " << student.getName() << " (" << student.getDepartment() << ")" << endl;
    }

    return 0;
}

