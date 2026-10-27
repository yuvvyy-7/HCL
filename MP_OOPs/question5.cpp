// Q.5. Write a small class hierarchy where class D inherits from both B and C, both of which
// inherit from class A. Demonstrate how the compiler handles the ambiguity and how
// virtual base classes resolve the diamond problem.

#include <iostream>
using namespace std;

class A {
public:
    int value = 10;
};

class B : virtual public A {

};

class C : virtual public A {

};

class D : public B, public C {

};

int main() {

D object;
cout << object.value;
// applying virtual befor the inheritance to remove ambiguous problem of value
// Virtual inheritance ensures that a shared base class is represented by one subobject in the final derived object.

return 0;
}