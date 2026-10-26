#include <iostream>
using namespace std;

class Student {
private:
    string name;
    double marks;
    int rollNo;

    static int totalStudents;
    static constexpr double SCOLARSHIP_CUTOFF = 85.0;
public:
    Student(string studentName, int rollNumber, double studentMarks) : 
    name(studentName), rollNo(rollNumber), marks(studentMarks) {
        totalStudents++;
    };

    ~Student() {
        totalStudents--;
    }

    //getters
    static int getTotalStudent() {
        return totalStudents;
    }

    static double getScolarshipCutoff() {
        return SCOLARSHIP_CUTOFF;
    }

    void display() const {
        cout << "[Roll No. " << rollNo << "]" << name << " - " << marks << " marks" << endl;
    }

    friend void evaluateScolarship(const Student& s);
};

int Student::totalStudents = 0;

void evaluateScolarship(const Student& s) {
    cout << ">> Scolarship Evaluation for " << s.name << " (Roll: " << s.rollNo << "): " << endl;

    if(s.marks >= Student::SCOLARSHIP_CUTOFF) {
        cout << "  [ELIGIBLE] Marks: " << s.marks
        << " >= Cutoff: " << Student::SCOLARSHIP_CUTOFF
        << ".Scolarship Granted!" << endl;
    } else {
        cout << "  [NOT ELIGIBLE] Marks: " << s.marks
        << " < Cutoff: " << Student::SCOLARSHIP_CUTOFF
        << ". Needs improvement." << endl;
    }
}

int main() {
cout << "==Static Members & Friend Function Demo (Student) ===" << endl << endl;

cout << "--- 1. Static Function & Shared Counter ----";
cout << "Initial static count: " << Student::getTotalStudent() << endl; 
cout << "Scolarship Cutoff: " << Student::getScolarshipCutoff() << " marks" << endl << endl;


cout << "--- 2. Creating Student Instances ---" << endl;
Student s1("Asha Sharma", 101, 92.5);
Student s2("Ravi Kumar", 102, 78.0);
Student s3("Meera Nair", 103, 89.0);

cout << "\nCurrent student cout: " << Student::getTotalStudent() << endl << endl;

cout << "Registered Students:" << endl;
s1.display();
s2.display();
s3.display();
cout << endl;

cout << "--- 3. Friend Function in Action ---" << endl;
evaluateScolarship(s1);
evaluateScolarship(s2);
evaluateScolarship(s3);
cout << endl;

cout << "--- 4. Demonstrating Object Destruction & Static Counter ---" << endl;
{
    cout << "Entering temporary block to add guest student..." << endl;
    Student tempStudent("Guest Student", 999, 50.0);
    cout << "Count inside block: " << Student::getTotalStudent() << endl;
}

cout << "Count after temporary student exited scope: " << Student::getTotalStudent() << endl;

return 0;
}