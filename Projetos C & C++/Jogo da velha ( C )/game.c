#include <stdio.h>
#include "game.h"

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

int makeMove(char board[3][3], int row, int col, char player) {
    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
        return 0;
    board[row][col] = player;
    return 1;
}

int checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        // linhas
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;

        // colunas
        if (board[0][i] != ' ' &&
            board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }

    // diagonais
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}
