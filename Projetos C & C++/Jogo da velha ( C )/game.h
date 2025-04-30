#ifndef GAME_H
#define GAME_H

void initializeBoard(char board[3][3]);
void printBoard(char board[3][3]);
int makeMove(char board[3][3], int row, int col, char player);
int checkWin(char board[3][3]);

#endif
