#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum figures {None=0, Pawn=1, Knight=2, Bishop=3, Rook=4, Queen=5, King=6};
enum utility_figures {Passable=7, Castling=8, Enpassant=9};
const char figure_chars[8] = {' ', 'p', 'k', 'b', 'r', 'Q', '@'};

void initializeBoard(int board[8][8]) 
{
    int order[8] = {Rook, Knight, Bishop, Queen, King, Bishop, Knight, Rook};
    for (int i = 0; i < 8; i++) {
        board[0][i] = order[i];
        board[1][i] = Pawn;
        board[6][i] = -Pawn;
        board[7][i] = -order[i];
    }

    return;
}

int isWithinBoard(const int x, const int y)
{
    if (x >= 0 && x < 8 && y >= 0 && y < 8)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char getFigureChar(const int figure)
{
    if (figure < 7) 
    {
        return figure_chars[abs(figure)];
    }
    else
    {
        return '%';
    }
}

char getFigureColor(const int figure)
{
    return figure >= 0 ? ' ' : '-';
}

void getPossibleMovesKnight(int board[8][8], const int x, const int y)
{
    /*    
    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = None;
        }
    }
    */

    int x_positions[4] = {};
    x_positions[0] = x-2;
    x_positions[1] = x-1;
    x_positions[2] = x+2;
    x_positions[3] = x+1;

    int y_positions[4] = {};
    y_positions[0] = y-2;
    y_positions[1] = y-1;
    y_positions[2] = y+2;
    y_positions[3] = y+1;

    for (int i = 0; i < 4; i++) 
    {
        int xt = x_positions[i];
        int yt = y_positions[(i+1) % 4];
        if (isWithinBoard(xt, yt))
        {
            board[yt][xt] = Passable;
        }
    }

    for (int i = 0; i < 4; i++) 
    {
        int xt = x_positions[i];
        int yt = y_positions[(i-1) % 4];
        if (isWithinBoard(xt, yt))
        {
            board[yt][xt] = Passable;
        }
    }
    
    return;
}

void getPossibleMoves(int board[8][8], const int x, const int y) 
{
    return;
}

void printBoard(int board[8][8])
{
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            printf("%c%c ", getFigureColor(board[i][j]), getFigureChar(board[i][j]));
        }
        putchar('\n');
    }
}

int main() {
    int board[8][8] = {};
    initializeBoard(board);

    printBoard(board);

    getPossibleMovesKnight(board, 1, 0);
    printBoard(board);

    return 0;
}