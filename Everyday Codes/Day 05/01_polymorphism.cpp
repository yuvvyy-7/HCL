#include <iostream>
using namespace std;

class Player {
public:
    virtual void display() const {
        cout << "Generic player" << endl;
    }
    virtual ~Player() {}   // virtual destructor
};

class TeamPlayer : public Player {
public:
    void display() const override {
        cout << "Team player" << endl;
    }
};

void showInfo(const Player& p) {   // takes base reference
    p.display();   // resolved at runtime based on actual object type
}

int main() {
    Player p1;
    TeamPlayer p2;

    showInfo(p1);   // Generic player
    showInfo(p2);   // Team player - runtime dispatch

    return 0;
}
