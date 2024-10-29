#include <iostream>
using namespace std;

void display(char grid[3][3]) {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cout << grid[y][x] << ' ';
        }
        cout << endl;
    }
}

void userInput(char turn, int& x, int& y) {
    cout << turn << "'s turn. Enter an x and y position." << endl;
    cout << "> ";
    cin >> x >> y;
}

bool checkWin(char grid[3][3], char turn) {
    bool won;
    
    // check rows
    for (int y = 0; y < 3; y++) {
        won = true;
        for (int x = 0; x < 3; x++) {
            if (grid[y][x] != turn) {
                won = false;
                break;
            }
        }
        if (won) {
            return true;
        }
    }
    
    // check columns
    for (int x = 0; x < 3; x++) {
        won = true;
        for (int y = 0; y < 3; y++) {
            if (grid[y][x] != turn) {
                won = false;
                break;
            }
        }
        if (won) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int x, y;
    char turn = 'X';
    char grid[3][3] = {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'}
    };
    
    while (true) {
        display(grid);
        userInput(turn, x, y);
        if (grid[y][x] == '.') {
            grid[y][x] = turn;
            if (checkWin(grid, turn)) {
                display(grid);
                cout << turn << " wins!" << endl;
                return 0;
            }
            if (turn == 'X') {
                turn = 'O';
            } else {
                turn = 'X';
            }
        } else {
            cout << "That space is taken." << endl;
        }
    }
}
