#include <iostream>
#include <vector>

// Global board representation
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

// Function to display the Tic-Tac-Toe board
void displayBoard() {
    system("cls"); // Clears the console screen (Windows specific)
    // For Linux/macOS, use system("clear");
    std::cout << "\n\tTic Tac Toe\n\n";
    std::cout << "\tPlayer 1 (X) - Player 2 (O)\n\n";
    std::cout << "\t     |     |     \n";
    std::cout << "\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    std::cout << "\t_____|_____|_____\n";
    std::cout << "\t     |     |     \n";
    std::cout << "\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    std::cout << "\t_____|_____|_____\n";
    std::cout << "\t     |     |     \n";
    std::cout << "\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    std::cout << "\t     |     |     \n\n";
}

// Function to get player input and update the board
void getPlayerInput() {
    int choice;
    int row, col;

    std::cout << "Player " << currentPlayer << ", enter a number: ";
    std::cin >> choice;

    // Convert choice (1-9) to board coordinates (0-2, 0-2)
    row = (choice - 1) / 3;
    col = (choice - 1) % 3;

    if (choice < 1 || choice > 9) {
        std::cout << "Invalid move. Please enter a number between 1 and 9.\n";
        getPlayerInput(); // Recursive call for invalid input
    } else if (board[row][col] == 'X' || board[row][col] == 'O') {
        std::cout << "Position already taken. Please choose another.\n";
        getPlayerInput(); // Recursive call for taken position
    } else {
        board[row][col] = currentPlayer;
    }
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to check for a win or draw
char checkGameStatus() {
    // Check rows and columns for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0]; // Row win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i]; // Column win
    }

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0]; // Main diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2]; // Anti-diagonal

    // Check for a draw (if all positions are filled)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return ' '; // Game still ongoing
        }
    }

    return 'D'; // Draw
}

int main() {
    char gameStatus;

    do {
        displayBoard();
        getPlayerInput();
        gameStatus = checkGameStatus();
        if (gameStatus == ' ') { // If game is still ongoing, switch player
            switchPlayer();
        }
    } while (gameStatus == ' ');

    displayBoard(); // Display final board
    if (gameStatus == 'D') {
        std::cout << "It's a draw!\n";
    } else {
        std::cout << "Player " << gameStatus << " wins!\n";
    }

    return 0;
}