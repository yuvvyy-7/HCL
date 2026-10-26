//Q.2.Create a base class Person (with name and age) and a derived class Employee (adding
// employeeId and salary). Demonstrate how protected data members and base
// constructor initializers work in derived classes.

#include <iostream>
using namespace std;

class Person {
    protected: 
        string name;
        int age;
    public:
        Person(string n, int a) : name(n), age(a) {}
};

class Employee : public Person {
private:
    int employeeId;
    double salary;
public: 
    Employee(string n, int a, int id, double s) : Person(n, a), employeeId(id), salary(s) {}

    void display() const {
        cout << name << ", " << age << ", " << employeeId << ", " << salary << endl;
    }
};

int main() {
    Employee e("yuvraj", 19, 101, 100000);
    e.display();

return 0;
}