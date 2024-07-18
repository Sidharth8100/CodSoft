//tic-tac-toe by Sidharth Bhagat
#include <iostream>
#include <vector>

using namespace std;

void displayBoard(vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool isWin(vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool isDraw(vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == '-') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char& player) {
    player = (player == 'X') ? 'O' : 'X';
}

void playGame() {
    vector<vector<char>> board(3, vector<char>(3, '-'));
    char currentPlayer = 'X';
    bool gameOngoing = true;

    while (gameOngoing) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        int row, col;
        cin >> row >> col;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if (isWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOngoing = false;
        } else if (isDraw(board)) {
            displayBoard(board);
            cout << "The game is a draw!" << endl;
            gameOngoing = false;
        } else {
            switchPlayer(currentPlayer);
        }
    }
}

int main() {
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }
    return 0;
}
