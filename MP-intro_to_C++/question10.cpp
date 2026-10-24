// Write a class Box with a static counter that tracks how many Box instances are currently
// alive. Include a non-member friend function compareVolume(const Box& b1, const Box&
// b2) that accesses private dimensions directly

#include <iostream>
using namespace std;

class Box {
private:
    double height;
    double width;
public:
    static int count;

    Box(double h, double w) {
        width = w;
        height = h;
        count++;
    }

    ~Box() {
        count--;
    }

    friend void compareVolume(Box b1, Box b2);
};

int Box::count = 0;

void compareVolume(Box b1, Box b2) {
    double vol1 = b1.width * b1.height;
    double vol2 = b2.width * b2.height;

    if(vol1 > vol2) cout << "Box 1 is bigger \n";
    else cout << "Box 2 is bigger \n";
}

int main() {

Box box1(10, 5);
Box box2(5, 5);

cout << "Boxes alive right now: " << Box::count << "\n";

compareVolume(box1, box2);


return 0;
}