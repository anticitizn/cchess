#ifndef MOVE_CHECKS
#define MOVE_CHECKS

void getPseudoMovesBishop(int board[8][8], const int x, const int y);
void getPseudoMovesKnight(int board[8][8], const int x, const int y);
void getPseudoMovesRook(int board[8][8], const int x, const int y);
void getPseudoMovesQueen(int board[8][8], const int x, const int y);
void getPseudoMovesKing(int board[8][8], const int x, const int y);
void getPseudoMovesPawn(int board[8][8], const int x, const int y);
void getPseudoMoves(int board[8][8], const int x, const int y);

#endif