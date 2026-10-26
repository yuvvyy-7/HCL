// Q.5. Write a small class hierarchy where class D inherits from both B and C, both of which
// inherit from class A. Demonstrate how the compiler handles the ambiguity and how
// virtual base classes resolve the diamond problem.

#include <iostream>
using namespace std;

class A {

};

class B : public A {

};

class C : public A {

};

class D : public B, public C {

};

int main() {




return 0;
}