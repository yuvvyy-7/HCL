// Q.6. Write a snippet demonstrating the difference between static_cast and dynamic_cast
// when downcasting a base class pointer Base* to a derived class pointer Derived*. Show
// how dynamic_cast behaves when the cast fails on pointers.


#include <iostream>
using namespace std;

class Animal {
public:
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Woof!\n";
    }
};

int main() {
    Dog d;
    Animal a;

    Animal* p1 = &d;
    Animal* p2 = &a;

    Dog* dog1 = dynamic_cast<Dog*>(p1);
    Dog* dog2 = dynamic_cast<Dog*>(p2);
    Dog* dog3 = static_cast<Dog*>(p2);

    if (dog1 != nullptr)
        cout << "p1: ";
        dog1->bark();

    if (dog2 == nullptr)
        cout << "p2:  is not a Dog\n";

    if(dog3 != nullptr) {
        cout << "p3: ";
        dog3->bark();
        cout << "It's woofing even though it's not pointing to a dog address. Hence, disadvantage of static_cast";
    }
}