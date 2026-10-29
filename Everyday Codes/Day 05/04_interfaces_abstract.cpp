#include <iostream>
using namespace std;

class Displayable {   // abstract class / interface
public:
    virtual void display() const = 0;   // pure virtual function
    virtual ~Displayable() {}
};

class Player : public Displayable {
private:
    string name;
    int score;
public:
    Player(string n, int s) : name(n), score(s) {}
    void display() const override {   // must implement, or Player is also abstract
        cout << name << " - " << score << endl;
    }
};

int main() {
    // Displayable d;   // would not compile: cannot instantiate an abstract class

    Displayable* d = new Player("Asha", 95);
    d->display();

    delete d;
    return 0;
}
