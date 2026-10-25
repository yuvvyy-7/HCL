#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    double marks;
public:
    Student() : name("Unassigned"), rollNo(0), marks(0.0) {
        cout << "[Deafault Constructor] Initialized default student." << endl; 
    }

    Student(string studentName, int rollNumber) : 
        name(studentName), rollNo(rollNumber), marks(0.0) {
            cout << "[Parameterized Constructor [2 Params]] Created student: " << name << endl;
    }

    Student(string studentName, int rollNumber, double studentMarks) :
        name(studentName), rollNo(rollNumber), marks(studentMarks) {
        cout << "[Parameterized Constructor [3 Params]] Created student: " << name << " with makrs " << marks << endl;
    }

    Student(const Student& other) :
        name(other.name), rollNo(other.rollNo), marks(other.marks) {
            cout << "[Copy Constructor] Copied student from: " << other.name << endl;
    }

    ~Student() {
        cout << "\nClass: " << name << " destructed" << endl;
    }

    void display() {
        cout << "\n";
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "\n";
    }
};

int main() {

    Student student1;
    student1.display();

    Student student2("Ram", 1);
    student2.display();

    Student student3("Shyam", 2, 56);
    student3.display();

    Student student4(student2);
    student4.display();


    //using heap memory insread of stack
    Student* student5 = new Student("Megh", 3, 89);
    student5->display();
    
    delete student5;

    //making array in heap memory
    int size = 2;
    Student* studentGang = new Student[size];

    studentGang[0] = Student("boy1", 4, 29);
    studentGang[1] = Student("boy2", 5, 30);

    for(int i = 0; i < size; i++) {
    studentGang[i].display();
}

    delete[] studentGang;
return 0;
}
