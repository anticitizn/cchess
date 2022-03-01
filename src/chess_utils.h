#ifndef CHESS_UTILS
#define CHESS_UTILS

enum figures {None=0, Pawn=1, Knight=2, Bishop=3, Rook=4, Queen=5, King=6};
enum utility_figures {Passable=7, Attackable=8, Castling=9, Enpassant=10};

void initializeBoard(int board[8][8]);
void clearBoard(int board[8][8]);
void copyBoard(int board[8][8], int newboard[8][8]);
int isWithinBoard(const int x, const int y);
char getFigureChar(const int figure);
int getFigureColor(const int figure);
int checkFiguresSameColor(int figure1, int figure2);
void printBoard(int board[8][8]);

#endif