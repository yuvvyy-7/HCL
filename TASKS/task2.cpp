#include <iostream>
using namespace std;

class Timer {
private:
    string name;
public:
    Timer(string n) : name(n) {
        cout << "Constructor used... new class has been created: " << name << endl;
    }

    ~Timer() {
        cout << "Destructor used.... class has been destroyed: " << name << endl;
    }
};

int main() {

{
    Timer c1("ClockA");
    {
        Timer c2("ClockB");
        {
            Timer c3("ClockC");
        }
    }
}

cout << "\n This represt how constructor and destructor follow LAST IN FIRST OUT approach\n";

return 0;
}