// Q.2.Create a base class Person (with name and age) and a derived class Employee (adding
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
    public:
        string employeeId;
        double salary;
};

int main() {




return 0;
}