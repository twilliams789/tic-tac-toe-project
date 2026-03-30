
#include <iostream>
using namespace std;


// Function Prototypes
void initializeBoard(char[][3]);
void printBoard(char[][3]);
void play(char[][3], int);
int getStatus(char[][3]);

int main() {
    // 3x3 Tic-Tac-Toe board
    char board[3][3];
    // Initialize board with blank spaces
    initializeBoard(board);
    // Display empty board
    printBoard(board);
    int status = 3;     // 3 = game still in progress
    int player = 1;     // Player 1 starts
    // Continue game until someone wins or tie occurs
    while (status == 3) {
        // Current player makes a move
        play(board, player);
        // Display updated board
        printBoard(board);
        // Check game status
        status = getStatus(board);
        // If game not finished, switch players
        if (status == 3) {
            if (player == 1)
                player = 2;
            else
                player = 1;
        } }
    // Display final result
    if (status == 1)
        cout << "Player#1 has won!" << endl;
    else if (status == 2)
        cout << "Player#2 has won!" << endl;
    else
        cout << "Game tied!" << endl;
    return 0;
}

// Fills the board with blank spaces
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        cout << board[i][0] << " | "
            << board[i][1] << " | "
<< board[i][2] << endl;
        // Print divider between rows
        if (i < 2)
            cout << "---------" << endl;
    }
}
// Determines current status of the game
// Returns:
// 1 = Player 1 wins
// 2 = Player 2 wins
// 3 = Game still in progress
// 0 = Tie
int getStatus(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            if (board[i][0] == 'X')
                return 1;
            else
                return 2;
            } }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] != ' ' &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i]) {
            if (board[0][i] == 'X')
                return 1;
            else
                return 2;
            } }
    // Check main diagonal
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        if (board[0][0] == 'X')
            return 1;
        else
            return 2;
        }
    // Check opposite diagonal
    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        if (board[0][2] == 'X')
            return 1;
        else
            return 2;
        }
    // Check if any empty spaces remain
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 3;   // Game not finished
        } }
    // If no winner and no empty spaces → tie
    return 0;
}
// Handles a player's move
void play(char board[3][3], int player) {
    int row, col;
    cout << "Player#" << player << ", enter your position: ";
    cin >> row >> col;
    // Validate input:
    // 1–3 range AND position must be empty
    while (row < 1 || row > 3 ||
        col < 1 || col > 3 ||
        board[row - 1][col - 1] != ' ') {
        cout << "Illegal position, enter again: ";
        cin >> row >> col;
        }
    // Assign mark based on player number
    if (player == 1)
        board[row - 1][col - 1] = 'X';
    else
        board[row - 1][col - 1] = 'O';
}








