#include <iostream>
#include <vector>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---------" << endl;
    }
    cout << endl;
}

// Function to check if the game is over
bool gameOver(const vector<vector<char>>& board, char& winner) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            winner = board[i][0];
            return true;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            winner = board[0][i];
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        winner = board[0][0];
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        winner = board[0][2];
        return true;
    }
    // Check if the board is full
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    winner = ' ';
    return true; // Game over, but no winner (draw)
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    char winner = ' ';

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player 1: X\nPlayer 2: O" << endl;

    while (!gameOver(board, winner)) {
        displayBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (1-3): ";
        cin >> row >> col;
        row--;
        col--;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }

    displayBoard(board);
    if (winner != ' ')
        cout << "Player " << winner << " wins!" << endl;
    else
        cout << "It's a draw!" << endl;

    return 0;
}
