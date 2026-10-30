#include <iostream>
#include <stdexcept>
using namespace std;

int validateScore(int score) {
    if (score < 0 || score > 100) {
        throw invalid_argument("Score out of range: " + to_string(score));
    }
    return score;
}

void processScore(int rawScore) {
    try {
        int s = validateScore(rawScore);
        cout << "Processed score: " << s << endl;
    } catch (const invalid_argument& e) {
        cout << "Caught in processScore: " << e.what() << endl;
        throw;   // rethrow to let the caller also react
    }
}

int main() {
    try {
        processScore(150);
    } catch (const exception& e) {   // catches the rethrown exception
        cout << "Caught in main: " << e.what() << endl;
    }

    cout << "Program continues normally." << endl;
    return 0;
}
