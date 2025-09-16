#include <iostream>
using namespace std;

char board[3][3];   // Game board
char currentPlayer; // Current player (X or O)

// Function to initialize the board
void initializeBoard() {
    char pos = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = pos++;
        }
    }
}

// Function to display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to check if a move is valid
bool isValidMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return (board[row][col] != 'X' && board[row][col] != 'O');
}

// Function to make a move
void makeMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = currentPlayer;
}

// Function to check for a win
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

// Function to check for a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char playAgain;
    do {
        initializeBoard();
        currentPlayer = 'X';
        bool gameWon = false;
        bool gameDraw = false;

        cout << "\nWelcome to Tic-Tac-Toe!\n";
        displayBoard();

        while (!gameWon && !gameDraw) {
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (move < 1 || move > 9 || !isValidMove(move)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            makeMove(move);
            displayBoard();

            gameWon = checkWin();
            gameDraw = checkDraw();

            if (!gameWon && !gameDraw) {
                switchPlayer();
            }
        }

        if (gameWon) {
            cout << "🎉 Player " << currentPlayer << " wins!\n";
        } else {
            cout << "It's a draw!\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
