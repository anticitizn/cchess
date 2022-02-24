#ifndef MOVE_CHECKS
#define MOVE_CHECKS

void getPossibleMovesBishop(int board[8][8], const int x, const int y);
void getPossibleMovesKnight(int board[8][8], const int x, const int y);
void getPossibleMovesRook(int board[8][8], const int x, const int y);
void getPossibleMovesQueen(int board[8][8], const int x, const int y);
void getPossibleMovesKing(int board[8][8], const int x, const int y);
void getPossibleMovesPawn(int board[8][8], const int x, const int y);

#endif