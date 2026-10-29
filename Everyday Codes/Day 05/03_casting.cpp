#include <iostream>
using namespace std;

class Player {
public:
    virtual ~Player() {}   // needed for dynamic_cast to work
};

class TeamPlayer : public Player {
public:
    void cheerTeam() const { cout << "Go team!" << endl; }
};

int main() {
    Player* p1 = new TeamPlayer();   // base pointer to a derived object

    // dynamic_cast: safe, checked at runtime
    TeamPlayer* tp = dynamic_cast<TeamPlayer*>(p1);
    if (tp != nullptr) {
        tp->cheerTeam();
    } else {
        cout << "Cast failed: not a TeamPlayer" << endl;
    }

    // static_cast: fast, NOT checked - programmer guarantees correctness
    double scoreAsDouble = 95;
    int scoreAsInt = static_cast<int>(scoreAsDouble);
    cout << "Converted: " << scoreAsInt << endl;

    delete p1;
    return 0;
}
