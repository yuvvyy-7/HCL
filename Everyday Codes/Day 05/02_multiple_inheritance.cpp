#include <iostream>
using namespace std;

class Scorable {
public:
    int score = 0;
    void addScore(int s) { score += s; }
};

class Rankable {
public:
    int rank = 0;
    void setRank(int r) { rank = r; }
};

class Player : public Scorable, public Rankable {   // multiple inheritance
public:
    string name;
    Player(string n) : name(n) {}
};

int main() {
    Player p("Asha");
    p.addScore(95);    // from Scorable
    p.setRank(1);       // from Rankable

    cout << p.name << ": score=" << p.score << ", rank=" << p.rank << endl;

    return 0;
}
