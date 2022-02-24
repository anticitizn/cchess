#include <src/move_checks.h>
#include <src/chess_utils.h>

void getPossibleMovesPawn(int board[8][8], const int x, const int y)
{
    if (board[y][x] > 0)
    {
        if (isWithinBoard(x, y+1))
        {
            board[x][y+1] = Passable;
        }
    }
    else
    {
        if (isWithinBoard(x, y-1))
        {
            board[x][y-1] = Passable;
        }
    }
}

void getPossibleMovesBishop(int board[8][8], const int x, const int y)
{
    for (int j = 0; j < 8; j++)
    {
        int xt = x + j;
        int yt = y + j;
        if (isWithinBoard(xt, yt))
        {
            board[xt][yt] = Attackable;
        }
    }

    for (int j = 0; j < 8; j++)
    {
        int xt = x + j;
        int yt = y - j;
        if (isWithinBoard(xt, yt))
        {
            board[xt][yt] = Attackable;
        }
    }

    for (int j = 0; j < 8; j++)
    {
        int xt = x - j;
        int yt = y + j;
        if (isWithinBoard(xt, yt))
        {
            board[xt][yt] = Attackable;
        }
    }

    for (int j = 0; j < 8; j++)
    {
        int xt = x - j;
        int yt = y - j;
        if (isWithinBoard(xt, yt))
        {
            board[xt][yt] = Attackable;
        }
    }
}

void getPossibleMovesKnight(int board[8][8], const int x, const int y)
{
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
            board[xt][yt] = Attackable;
        }
    }

    for (int i = 0; i < 4; i++) 
    {
        int xt = x_positions[i];
        int yt = y_positions[(i-1) % 4];
        if (isWithinBoard(xt, yt))
        {
            board[xt][yt] = Attackable;
        }
    }
    
    return;
}

void getPossibleMovesRook(int board[8][8], const int x, const int y)
{
    for (int i = 0; i < 8; i++)
    {
        int xt = x + i;
        int yt = y;
        if (isWithinBoard(xt, yt))
        {
            board[xt][yt] = Attackable;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        int xt = x - i;
        int yt = y;
        if (isWithinBoard(xt, yt))
        {
            board[xt][yt] = Attackable;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        int xt = x;
        int yt = y + i;
        if (isWithinBoard(xt, yt))
        {
            board[xt][yt] = Attackable;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        int xt = x;
        int yt = y - i;
        if (isWithinBoard(xt, yt))
        {
            board[xt][yt] = Attackable;
        }
    }
}

void getPossibleMovesQueen(int board[8][8], const int x, const int y)
{
    getPossibleMovesRook(board, x, y);
    getPossibleMovesBishop(board, x, y);
}

void getPossibleMovesKing(int board[8][8], const int x, const int y)
{
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            int xt = x + i;
            int yt = y + j;
            if (isWithinBoard(xt, yt) && (xt != x || yt != y))
            {
                
                board[xt][yt] = Attackable;
            }
        }
    }
}

void removeOccupiedMoves(int board[8][8], int moveboard[8][8], const int x, const int y)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // If tile is passable or attackable and is occupied by same color figure
            // remove it from the moveable tiles array
            if ((moveboard[i][j] == Passable || moveboard[i][j] == Attackable) && checkFiguresSameColor(board[x][y], board[i][j]))
            {
                moveboard[i][j] = board[i][j];
            }
        }
    }
}

void getPossibleMoves(int board[8][8], const int x, const int y) 
{
    int tempboard[8][8] = {};
    copyBoard(board, tempboard);

    if (!isWithinBoard(x,y))
    {
        return;
    }

    switch(board[x][y])
    {
        case Pawn:
            getPossibleMovesPawn(tempboard, x, y);
            break;
        case Bishop:
            getPossibleMovesBishop(tempboard, x, y);
            break;
        case Knight:
            getPossibleMovesKnight(tempboard, x, y);
            break;
        case Rook:
            getPossibleMovesRook(tempboard, x, y);
            break;
        case Queen:
            getPossibleMovesQueen(tempboard, x, y);
            break;
        case King:
            getPossibleMovesKing(tempboard, x, y);
            break;
    }

    removeOccupiedMoves(board, tempboard, x, y);
    printBoard(tempboard);

    return;
}