//Q.3. Create a base class Shape with a virtual function draw(). Derive classes Circle and
// Rectangle that override draw(). Demonstrate run-time polymorphism by iterating over an
// array of Shape* pointers and invoking draw().

#include <iostream> 
using namespace std;

class Shape {
public:
    virtual void draw() const {
        cout << "Generic shape drawn." << endl;
    }

    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Cricle drawn." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        cout << "Rectangle drawn." << endl;
    }
};

int main() {

    Circle c;
    Rectangle r;
    Shape* shapes[] = {&c, &r};

    for(Shape* shape : shapes) {
        shape->draw();
    }


return 0;
}