#include <src/chess_utils.h>
#include <stdio.h>
#include <stdlib.h>

void initializeBoard(int board[8][8])
{
    int order[8] = {Rook, Knight, Bishop, Queen, King, Bishop, Knight, Rook};
    for (int i = 0; i < 8; i++) {
        board[i][0] = order[i];
        board[i][1] = Pawn;
        board[i][6] = -Pawn;
        board[i][7] = -order[i];
    }

    return;
}

void clearBoard(int board[8][8])
{
    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = None;
        }
    }
}

void copyBoard(int board[8][8], int newboard[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            newboard[i][j] = board[i][j];
        }
    }
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
    const char figure_chars[8] = {' ', 'p', 'k', 'b', 'r', 'Q', '@'};
    if (figure < 7) 
    {
        return figure_chars[abs(figure)];
    }
    else
    {
        return ',';
    }
}

int getFigureColor(const int figure)
{
    return figure >= 0 ? 1 : -1;
}

char getFigureColorChar(const int figure)
{
    return figure >= 0 ? ' ' : ':';
}

int checkFiguresSameColor(int figure1, int figure2)
{
    if (figure1 * figure2 > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printBoard(int board[8][8])
{
    putchar('\n');
    for (int i = 7; i >= 0; i--) 
    {
        printf("%d | ", i+1);
        for (int j = 0; j < 8; j++) 
        {
            printf("%c%c ", getFigureColorChar(board[j][i]), getFigureChar(board[j][i]));
        }
        putchar('\n');
    }
    
    printf("  ");
    for (int i = 0; i < 25; i++)
    {
        putchar('-');
    }
    printf("\n    ");

    for (int i = 65; i < 73; i++) 
    {
        printf(" %c ", (char)i);
    }
    putchar('\n');
}