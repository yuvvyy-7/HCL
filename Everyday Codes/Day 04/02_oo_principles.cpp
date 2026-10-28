/**
 * File: 02_oo_principles.cpp
 * Topic: Core Object-Oriented Principles (Encapsulation, Abstraction, Modularity)
 * Concept:
 *   1. Encapsulation:
 *      - Internal representation (course vector, raw grades, credit weights)
 *        is hidden inside private scope, protecting it from external tampering.
 * 
 *   2. Abstraction:
 *      - Exposes clean, high-level interfaces (addCourse, getGPA, printTranscript).
 *      - The caller does not need to know the mathematical formula for credit-weighted
 *        cumulative GPA calculation; they simply request the result.
 *   3. Modularity:
 *      - Distinct responsibilities are separated into focused structures (CourseRecord)
 *        and classes (Student).
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


// 1. MODULARITY: Lightweight data model for course enrollment

struct CourseRecord {
    string courseCode;
    int creditHours;
    double gradePoint; // 0.0 to 4.0 scale (e.g., 4.0 = A, 3.0 = B)
};

struct Certificates {
    string courseName;
    int courseHours;
    string courseProvider;
    string courseLevel;
};

// 2. ENCAPSULATION & ABSTRACTION: Student Class

class Student {
private:
    // Encapsulated private attributes
    string name;
    int rollNo;
    string certLevel;
    vector<CourseRecord> enrolledCourses;
    vector<Certificates> certifications;

    // Private helper method: Abstraction hides the internal formula from callers
    double calculateCumulativeGPA() const {
        if (enrolledCourses.empty()) return 0.0;

        double totalGradePoints = 0.0;
        int totalCredits = 0;

        for (const auto& course : enrolledCourses) {
            totalGradePoints += (course.gradePoint * course.creditHours);
            totalCredits += course.creditHours;
        }

        if (totalCredits == 0) return 0.0;
        return totalGradePoints / totalCredits;
    }

public:
    // Public interface
    Student(string studentName, int rollNumber) 
        : name(studentName), rollNo(rollNumber) {}

    // Abstraction: Caller just supplies course information
    void addCourse(string code, int credits, double gradePoint) {
        if (credits <= 0 || gradePoint < 0.0 || gradePoint > 4.0) {
            cout << "  [Error] Invalid course parameters for " << code << endl;
            return;
        }
        enrolledCourses.push_back({code, credits, gradePoint});
        cout << "  [Enrolled] " << name << " added " << code 
             << " (" << credits << " credits, GP: " << gradePoint << ")" << endl;
    }

    void addCertificate(string certificateName, int hours, string provider) {
        if (certificateName.empty() || hours < 0 || provider.empty()) {
            cout << "  [Error] Invalid certificate parameters for " << name << endl;
            return;
        }
        if (hours < 5) {
            certLevel = "Beginner";
        } else if (hours < 10) {
            certLevel = "Intermediate";
        } else {
            certLevel = "Advanced";
        }

        certifications.push_back({certificateName, hours, provider, certLevel});
        cout << "Certificate alloted to " << name << " | Course Name: " << certificateName << endl;
    }

    // High-level query abstraction
    double getGPA() const {
        return calculateCumulativeGPA();
    }

    string getName() const { return name; }
    int getRollNo() const { return rollNo; }

    // Abstraction: Generates clean formatted report without exposing raw vector
    void printTranscript() const {
        cout << "\n==============================================" << endl;
        cout << "              ACADEMIC TRANSCRIPT             " << endl;
        cout << "==============================================" << endl;
        cout << " Student Name : " << name << endl;
        cout << " Roll Number  : " << rollNo << endl;
        cout << " Courses Completed : " << enrolledCourses.size() << endl;
        cout << "----------------------------------------------" << endl;
        cout << left << setw(15) << "Course" 
             << setw(12) << "Credits" 
             << setw(12) << "Grade Point" << endl;
        cout << "----------------------------------------------" << endl;

        for (const auto& c : enrolledCourses) {
            cout << left << setw(15) << c.courseCode 
                 << setw(12) << c.creditHours 
                 << fixed << setprecision(2) << c.gradePoint << endl;
        }

        cout << "----------------------------------------------" << endl;
        cout << " Cumulative GPA : " << fixed << setprecision(2) << getGPA() << " / 4.00" << endl;
        cout << " Academic Status: " << (getGPA() >= 3.5 ? "Dean's Honor List" : "Good Standing") << endl;
        cout << "==============================================\n\n" << endl;
        
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "                                     CERTIFICATIONS                                     " << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << left << setw(25) << "Name" 
             << setw(22) << "Duration" 
             << setw(22) << "Provider" 
             << setw(22) << "Level" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        
        for (const auto& c : certifications) {
            cout << left << setw(25) << c.courseName 
                 << setw(22) << c.courseHours 
                 << setw(22) << c.courseProvider 
                 << setw(22) <<  c.courseLevel << endl;
        }

        cout << "========================================================================================\n\n" << endl;

    }
};


// MAIN DEMONSTRATION

int main() {
    cout << "=== C++ OO Principles: Encapsulation & Abstraction ===" << endl << endl;

    // 1. Instantiating a Student
    Student s1("Asha Sharma", 101);

    // 2. Encapsulation protects direct tampering:
    // s1.enrolledCourses.clear(); // ERROR: 'enrolledCourses' is private!

    // 3. Communicating via Abstraction:
    cout << "Adding courses through high-level public interface:" << endl;
    s1.addCourse("CS101 (C++)", 4, 4.0);       // Grade A
    s1.addCourse("MATH201 (Calc)", 3, 3.7);     // Grade A-
    s1.addCourse("PHY105 (Physics)", 3, 3.3);   // Grade B+

    // 4. Client computes GPA with a single call, completely abstracted from the math
    cout << "\nQueried Cumulative GPA directly: " 
         << fixed << setprecision(2) << s1.getGPA() << endl;


    cout << "Adding certificates done by student: " << endl;
    s1.addCertificate("Intro to C++", 9, "HCL");
    s1.addCertificate("Full Stack", 15, "LinkedIn");

    // 5. Exposing clean, modular views
    s1.printTranscript();

    return 0;
}

