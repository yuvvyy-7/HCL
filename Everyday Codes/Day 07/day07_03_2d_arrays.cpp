#include <iostream>
using namespace std;

const int ROWS = 3, COLS = 3;

void printBoard(char board[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
}

int main() {
    char board[ROWS][COLS] = {
        {'X', 'O', 'X'},
        {' ', 'X', 'O'},
        {'O', ' ', 'X'}
    };

    printBoard(board);

    cout << "Center cell: " << board[1][1] << endl;
    board[1][0] = 'O';   // update a cell

    cout << "\nAfter move:" << endl;
    printBoard(board);

    return 0;
}
