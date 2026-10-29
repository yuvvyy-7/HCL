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

class Idable {
public:
    string id; 
    void setId(string i) { id = i; }
};

class Player : public Scorable, public Rankable, public Idable {   // multiple inheritance
public:
    string name;
    Player(string n) : name(n) {}
};

int main() {
    Player p("Asha");
    p.addScore(95);    // from Scorable
    p.setRank(1);       // from Rankable
    p.setId("SU101");

    cout << "ID: " << p.id << " | name: " << p.name << ": score=" << p.score << ", rank=" << p.rank << endl;

    return 0;
}
