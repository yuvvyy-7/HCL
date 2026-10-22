//Q.1. Write a C++ program that calculates the area and circumference of a circle given the
// radius, using a const variable for PI (3.14159) placed inside a custom Geometry
// namespace.


#include <iostream>
using namespace std;

namespace Geometry {
    const double PI = 3.14159;
}

int main() {
using namespace Geometry;

double radius;
cout << "Enter Radius: ";
cin >> radius;

double area = PI * radius * radius;
double circumference = 2 * PI * radius;

cout << "Area of the Circle: " << area << "\n";
cout << "Circumference of the Circle: " << circumference << "\n";

return 0;
}