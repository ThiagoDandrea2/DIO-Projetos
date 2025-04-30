#include <stdio.h>
#include "game.h"

int main() {
    char board[3][3];
    char player = 'X';
    int row, col;
    int moves = 0;
    int result;

    initializeBoard(board);

    while (1) {
        printBoard(board);
        printf("Jogador %c, escolha a linha (0-2): ", player);
        scanf("%d", &row);
        printf("Jogador %c, escolha a coluna (0-2): ", player);
        scanf("%d", &col);

        if (!makeMove(board, row, col, player)) {
            printf("Movimento inválido. Tente novamente.\n");
            continue;
        }

        moves++;
        result = checkWin(board);
        if (result == 1) {
            printBoard(board);
            printf("Jogador %c venceu!\n", player);
            break;
        } else if (moves == 9) {
            printBoard(board);
            printf("Empate!\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
