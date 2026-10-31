/**
 * File: day07_01_storing_game_entries.cpp
 * Topic: Storing Game Entries in an Array
 * Syllabus: Unit III - Using Arrays: Storing Game Entries in an Array
 * 
 * Concepts Demonstrated:
 *   1. GameEntry Class: Represents a single record with player name and score.
 *   2. Scores Array Manager: Maintains an array of GameEntry objects in sorted (descending) order.
 *   3. Insertion with Shifting: Inserts new entry in sorted order; shifts lower scores right.
 *      If array is full, lowest entry falls off.
 *   4. Removal with Shifting: Removes entry at given index; shifts remaining entries left.
 */

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// 1. GAME ENTRY CLASS
class GameEntry {
private:
    string name;
    int score;

public:
    GameEntry(const string& n = "", int s = 0) : name(n), score(s) {}

    string getName() const { return name; }
    int getScore() const { return score; }

    void display() const {
        cout << name << " - " << score;
    }
};

// 2. SCORES LEADERBOARD ARRAY MANAGER
class Scores {
private:
    static const int MAX_ENTRIES = 5;
    GameEntry entries[MAX_ENTRIES];
    int numEntries;

public:
    Scores() : numEntries(0) {}

    int getNumEntries() const { return numEntries; }

    // Add entry in descending order of score
    void add(const GameEntry& e) {
        int newScore = e.getScore();

        // If array is full and new score is not high enough to enter
        if (numEntries == MAX_ENTRIES) {
            if (newScore <= entries[numEntries - 1].getScore()) {
                cout << "[Rejected] " << e.getName() << "'s score (" << newScore 
                     << ") is not high enough for top " << MAX_ENTRIES << "." << endl;
                return;
            }
        } else {
            numEntries++; // Increase count if we still have room
        }

        // Shift lower scores right to make room
        int i = numEntries - 1;
        while (i > 0 && entries[i - 1].getScore() < newScore) {
            entries[i] = entries[i - 1]; // Shift right
            i--;
        }
        entries[i] = e; // Insert in place
        cout << "[Added] " << e.getName() << " (" << newScore << ") at rank " << (i + 1) << endl;
    }

    // Remove entry at given index and shift left
    GameEntry remove(int index) {
        if (index < 0 || index >= numEntries) {
            throw out_of_range("Invalid index for removal!");
        }

        GameEntry removedEntry = entries[index];
        // Shift remaining entries left to close the gap
        for (int j = index; j < numEntries - 1; j++) {
            entries[j] = entries[j + 1];
        }
        numEntries--;
        cout << "[Removed] Entry at index " << index << " (" << removedEntry.getName() << ")" << endl;
        return removedEntry;
    }

    // Print leaderboard
    void display() const {
        cout << "\n--- High Scores Leaderboard (" << numEntries << "/" << MAX_ENTRIES << ") ---" << endl;
        for (int i = 0; i < numEntries; i++) {
            cout << "  " << (i + 1) << ". ";
            entries[i].display();
            cout << endl;
        }
        cout << "------------------------------------------\n" << endl;
    }
};

int main() {
    cout << "=== Storing Game Entries in an Array Demo ===" << endl;

    Scores leaderboard;

    // Adding entries
    leaderboard.add(GameEntry("Asha", 95));
    leaderboard.add(GameEntry("Ravi", 80));
    leaderboard.add(GameEntry("Meera", 88));
    leaderboard.add(GameEntry("Dev", 72));
    leaderboard.add(GameEntry("Kavya", 91));
    leaderboard.display();

    // Adding when full: should knock off the lowest score (72)
    cout << "Attempting to add new high score when full:" << endl;
    leaderboard.add(GameEntry("Arjun", 85));
    leaderboard.display();

    // Removing an entry by index
    leaderboard.remove(2); // Removes rank 3 (88)
    leaderboard.display();

    return 0;
}

