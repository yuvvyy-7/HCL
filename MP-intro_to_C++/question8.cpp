//Q.8. Design a class Timer that prints a message indicating when an object is created
// (constructor) and destroyed (destructor). Demonstrate how constructor and destructor
// calls order themselves when objects enter and exit nested scopes.


#include <iostream>
using namespace std;

class Demo {
    public:
        Demo() {
            cout << "Constructor used.\n";
        } 

        ~Demo() {
            cout << "Destructor used.";
        }
};

int main() {

Demo democlass;


return 0;
}