#include <iostream>
#include <stdexcept>
using namespace std;

class InvalidScoreException : public runtime_error {   // custom exception object
public:
    InvalidScoreException(const string& msg) : runtime_error(msg) {}
};

int validateScore(int score) {
    if (score < 0 || score > 100) {
        throw InvalidScoreException("Score out of range: " + to_string(score));
    }
    return score;
}

int main() {
    int s = validateScore(835);
    cout << "Valid score: " << s << endl;

    return 0;
}
