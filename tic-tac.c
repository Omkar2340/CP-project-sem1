#include <stdio.h>

char board[3][3];  // 3x3 Tic-Tac-Toe board
char player = 'X';  // Current player ('X' or 'O')

// Function to initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the current state of the board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Function to check for a winner
char checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];
    
    return ' ';  // No winner yet
}

// Function to switch players ('X' <-> 'O')
void switchPlayer() {
    if (player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
}

// Function to check if the board is full (tie)
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;  // Board is not full yet
        }
    }
    return 1;  // Board is full
}

// Main function
int main() {
    int row, col;
    char winner = ' ';
    
    initializeBoard();
    printf("Welcome to Tic-Tac-Toe!\n");
    
    // Main game loop
    while (winner == ' ' && !isBoardFull()) {
        printBoard();
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);
        
        // Validate the move
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row-1][col-1] == ' ') {
            board[row-1][col-1] = player;
            winner = checkWinner();
            if (winner == ' ') {
                switchPlayer();
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    
    printBoard();
    
    if (winner != ' ') {
        printf("Player %c wins!\n", winner);
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}
