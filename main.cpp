/**
 * File: 01_oo_design_goals.cpp
 * Topic: Object-Oriented Design Goals (Robustness, Adaptability, Reusability)
 * Concept:
 *   1. Robustness:
 *      - Software must handle unexpected or invalid input gracefully without crashing
 *        or corrupting internal object state.
 *   2. Adaptability:
 *      - Code should be structured so validation rules and behaviors can be updated
 *        or extended without rewriting the core application.
 *   3. Reusability:
 *      - Separate business validation logic into dedicated classes/functions
 *        (e.g., StudentValidator) that can be reused across different parts of the system.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. REUSABILITY & ROBUSTNESS: Dedicated Validator Class

class StudentValidator {
public:
    // Reusable static validation methods
    static bool isValidName(const string& name) {
        // Name must not be empty and cannot consist solely of whitespace
        return !name.empty() && name.find_first_not_of(" \t\n") != string::npos;
    }

    static bool isValidRollNo(int rollNo) {
        // Roll number must be a positive integer
        return rollNo > 0;
    }

    static bool isValidMarks(double marks) {
        // Marks must reside in the standard range [0.0, 100.0]
        return marks >= 0.0 && marks <= 100.0;
    }

    static bool isValidEmail(const string& email){
        return !email.empty() && email.find_first_of("@") != string::npos && email.find_first_of(".") != string::npos;
    }
};

// 2. ADAPTABILITY & ROBUSTNESS: Resilient Student Model

class Student {
private:
    string name;
    int rollNo;
    double marks;
    string email;
    bool isValid;

public:
    // Robust Constructor: Validates raw data before committing to object state
    Student(string studentName, int rollNumber, double studentMarks, string studentEmail) : isValid(true) {
        if (!StudentValidator::isValidName(studentName)) {
            cout << "  [Error] Robustness check failed: Invalid name entered." << endl;
            name = "Invalid_Student";
            isValid = false;
        } else {
            name = studentName;
        }

        if (!StudentValidator::isValidRollNo(rollNumber)) {
            cout << "  [Error] Robustness check failed: Roll number must be positive (Got: " 
                 << rollNumber << ")." << endl;
            rollNo = 0;
            isValid = false;
        } else {
            rollNo = rollNumber;
        }

        if (!StudentValidator::isValidMarks(studentMarks)) {
            cout << "  [Error] Robustness check failed: Marks must be in [0, 100] (Got: " 
                 << studentMarks << ")." << endl;
            marks = 0.0;
            isValid = false;
        } else {
            marks = studentMarks;
        }
        if(!StudentValidator::isValidEmail(studentEmail)) {
            cout << " [Error] Robustness check failed: Email is not valid (Got: " << studentEmail << ")." << endl;
            email = "Invalid_Email";
            isValid = false;
        } else {
            email = studentEmail;
        }

        if (isValid) {
            cout << "  [Success] Student record created successfully for: " << name << endl;
        }
    }

    // Setters return a boolean status flag to let callers handle recovery
    bool setMarks(double newMarks) {
        if (StudentValidator::isValidMarks(newMarks)) {
            marks = newMarks;
            return true;
        }
        cout << "  [Rejected] Cannot update marks to invalid value: " << newMarks << endl;
        return false;
    }

    void display() const {
        if (!isValid) {
            cout << "  [Record Status: Incomplete / Corrupted Data]" << endl;
        }
        cout << "  Student [Roll: " << rollNo << "] Name: " << name 
             << " | Score: " << marks << " | Email: " << email << endl;
    }
};

// ============================================================================
// MAIN DEMONSTRATION
// ============================================================================
int main() {
    cout << "=== C++ OO Design Goals: Robustness, Adaptability & Reusability ===" << endl << endl;

    // Scenario A: Testing Valid Student Input (Happy Path)

    cout << "--- 1. Testing Valid Input (Robust Student Creation) ---" << endl;
    Student s1("Asha Sharma", 101, 92.5, "asha@gmail.com");
    s1.display();
    cout << endl;

    // Scenario B: Testing Corrupted / Invalid Inputs (Handling without Crashing)
 
    cout << "--- 2. Testing Robustness Against Faulty Data ---" << endl;
    
    cout << "Attempting to create student with negative roll number and score > 100:" << endl;
    Student s2("Ravi Kumar", -15, 125.0, "ravi@gmail.com"); // Triggers graceful validation errors
    s2.display();
    cout << endl;

    cout << "Attempting to create student with empty name:" << endl;
    Student s3("   ", 102, 85.0, "hello@gmail.com"); // Triggers empty name validation
    s3.display();
    cout << endl;

    cout << "Attempting to create student with empty name:" << endl;
    Student s4("rahul", 112, 86.0, "rahulgmail.com"); // Triggers empty name validation
    s4.display();
    cout << endl;
    // Scenario C: Reusability Demonstration in Batch Processing
 
    cout << "--- 3. Reusability: Using StudentValidator in Batch Ingestion ---" << endl;
    vector<double> incomingTestScores = {88.0, 95.5, -5.0, 72.0, 110.0};

    cout << "Ingesting external score feed:" << endl;
    for (double score : incomingTestScores) {
        if (StudentValidator::isValidMarks(score)) {
            cout << "  [Accepted] Score " << score << " passed reusable validator." << endl;
        } else {
            cout << "  [Rejected] Score " << score << " blocked by validator." << endl;
        }
    }   

    return 0;
}
