/**
 * File: 05_student_hierarchy.cpp
 * Topic: Polymorphic Student Hierarchy & Virtual Destructors
 * Concept:
 *   1. Polymorphism ("Many Forms"):
 *      - Ability of a Base class pointer (Student*) to point to different Derived
 *        class instances (UndergradStudent, GraduateStudent) and invoke their
 *        specialized behaviors dynamically at runtime.
 *   2. 'virtual' functions & 'override':
 *      - virtual enables dynamic dispatch via the virtual method table (vtable).
 *      - 'override' keyword verifies at compile time that the method matches
 *        a virtual signature in the base class.
 *   3. Virtual Destructor (Crucial in C++!):
 *      - If deleting a derived object through a base pointer (delete p), the base class
 *        destructor MUST be marked 'virtual'.
 *      - Without 'virtual ~Student()', only the base destructor runs, leaking any
 *        derived class resources!
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ============================================================================
// 1. BASE CLASS: Student (Polymorphic Root)
// ============================================================================
class Student {
protected:
    string name;
    int rollNo;
    double marks;

public:
    Student(string n, int r, double m) : name(n), rollNo(r), marks(m) {}

    // Virtual function enables runtime dynamic dispatch
    virtual void display() const {
        cout << "  [General Student] Roll: " << rollNo 
             << " | " << name << " - " << marks << " marks" << endl;
    }

    // Virtual destructor guarantees full cleanup of derived objects through base pointers
    virtual ~Student() {
        cout << "  [-] ~Student() Base destructor cleaned up: " << name << endl;
    }
};

// ============================================================================
// 2. DERIVED CLASS 1: UndergradStudent
// ============================================================================
class UndergradStudent : public Student {
private:
    string major;
    int yearOfStudy;

public:
    UndergradStudent(string n, int r, double m, string maj, int year)
        : Student(n, r, m), major(maj), yearOfStudy(year) {}

    // Override base display implementation
    void display() const override {
        cout << "  [Undergrad (Year " << yearOfStudy << ")] " << name 
             << " | Major: " << major 
             << " | GPA Marks: " << marks << endl;
    }

    ~UndergradStudent() override {
        cout << "  [-] ~UndergradStudent() Derived destructor called for: " << name << endl;
    }
};

// ============================================================================
// 3. DERIVED CLASS 2: GraduateStudent
// ============================================================================
class GraduateStudent : public Student {
private:
    string thesisTitle;
    string advisor;

public:
    GraduateStudent(string n, int r, double m, string thesis, string adv)
        : Student(n, r, m), thesisTitle(thesis), advisor(adv) {}

    // Override base display implementation
    void display() const override {
        cout << "  [Graduate Researcher] " << name 
             << " | Thesis: \"" << thesisTitle << "\""
             << " | Advisor: Dr. " << advisor << endl;
    }

    ~GraduateStudent() override {
        cout << "  [-] ~GraduateStudent() Derived destructor called for: " << name << endl;
    }
};

// ============================================================================
// MAIN DEMONSTRATION
// ============================================================================
int main() {
    cout << "=== C++ Polymorphic Hierarchy: Student Roster Demo ===" << endl << endl;

    // ------------------------------------------------------------------------
    // Part 1: Polymorphic Container of Base Pointers (Student*)
    // ------------------------------------------------------------------------
    cout << "--- 1. Assembling Polymorphic Classroom Roster ---" << endl;
    vector<Student*> cohort;

    // We can store pointers to ANY derived class in a vector<Student*>!
    cohort.push_back(new Student("Ravi Kumar", 101, 82.0));
    cohort.push_back(new UndergradStudent("Asha Sharma", 102, 95.0, "Computer Science", 3));
    cohort.push_back(new GraduateStudent("Meera Nair", 103, 89.5, "Quantum Cryptography", "Subramanian"));

    cout << "Enrolled 3 students of diverse specializations into vector<Student*>.\n" << endl;

    vector<Student> cohort2;

    cohort2.push_back(Student("Noy", 104, 99.0));
    cohort2.push_back(UndergradStudent("Mitya", 105, 99.8, "Cosmic Energy", 4));
    cohort2.push_back(GraduateStudent("Eftirvit", 106, 88.0, "Celestial Sleep", "Dr. Tsaritsa"));
 
    // ------------------------------------------------------------------------
    // Part 2: Dynamic Dispatch at Runtime
    // ------------------------------------------------------------------------
    cout << "--- 2. Dynamic Dispatch: Calling virtual display() ---" << endl;
    for (const Student* s : cohort) {
        // C++ automatically resolves the correct display() for each object at runtime!
        s->display();
    }
    cout << endl;

    for (const Student s : cohort2) {
        // C++ automatically resolves the correct display() for each object at runtime!
        s.display();
    }
    cout << endl;

    // ------------------------------------------------------------------------
    // Part 3: Demonstrating Virtual Destructor Cleanup Order
    // ------------------------------------------------------------------------
    cout << "--- 3. Memory Cleanup: Proving Virtual Destructor Order ---" << endl;
    cout << "Deleting objects via Base Class Pointers (Student*):" << endl;

    for (Student* s : cohort) {
        // Because ~Student() is virtual, C++ first calls the Derived destructor,
        // and then automatically calls the Base destructor!
        delete s;
        cout << "  ---" << endl;
    }
    cohort.clear();

    cout << "\nAll dynamic memory successfully reclaimed without leaks!" << endl;
    return 0;
}

