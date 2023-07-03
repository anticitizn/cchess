#include <src/move_checks.h>
#include <src/chess_utils.h>

void getPseudoMovesPawn(int board[8][8], const int x, const int y)
{
    int temp = board[x][y] > 0 ? 1 : -1;

    // Two-Square advance  
    if ((y == 1 || y == 6) && board[x][y+temp] == None)
    {
        board[x][y+temp*2] = Passable;
    }

    // Normal moving
    if (isWithinBoard(x, y + temp))
    {
        board[x][y+temp] = Passable;
    }
    
    // Capturing
    if (isWithinBoard(x+1, y+temp) && board[x+1][y+temp] != None && !checkFiguresSameColor(board[x][y], board[x+1][y+temp]))
    {
        board[x+1][y+temp] = Attackable;
    }

    if (isWithinBoard(x-1, y+temp) && board[x-1][y+temp] != None && !checkFiguresSameColor(board[x][y], board[x-1][y+temp]))
    {
        board[x-1][y+temp] = Attackable;
    }
}

void getPseudoMovesBishop(int board[8][8], const int x, const int y)
{
    for (int j = 1; j < 8; j++)
    {
        int xt = x + j;
        int yt = y + j;

        if (!isWithinBoard(xt,yt)) break;

        int exit = board[xt][yt] != None ? 1 : 0;
        board[xt][yt] = Attackable;
        if (exit) break;
    }

    for (int j = 1; j < 8; j++)
    {
        int xt = x + j;
        int yt = y - j;

        if (!isWithinBoard(xt,yt)) break;

        int exit = board[xt][yt] != None ? 1 : 0;
        board[xt][yt] = Attackable;
        if (exit) break;
    }

    for (int j = 1; j < 8; j++)
    {
        int xt = x - j;
        int yt = y + j;

        if (!isWithinBoard(xt,yt)) break;

        int exit = board[xt][yt] != None ? 1 : 0;
        board[xt][yt] = Attackable;
        if (exit) break;
    }

    for (int j = 1; j < 8; j++)
    {
        int xt = x - j;
        int yt = y - j;

        if (!isWithinBoard(xt,yt)) break;

        int exit = board[xt][yt] != None ? 1 : 0;
        board[xt][yt] = Attackable;
        if (exit) break;
    }
}

void getPseudoMovesKnight(int board[8][8], const int x, const int y)
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

void getPseudoMovesRook(int board[8][8], const int x, const int y)
{
    for (int i = 1; i < 8; i++)
    {
        int xt = x + i;
        int yt = y;
        
        if (!isWithinBoard(xt,yt)) break;

        int exit = board[xt][yt] != None ? 1 : 0;
        board[xt][yt] = Attackable;
        if (exit) break;
    }

    for (int i = 1; i < 8; i++)
    {
        int xt = x - i;
        int yt = y;

        if (!isWithinBoard(xt,yt)) break;

        int exit = board[xt][yt] != None ? 1 : 0;
        board[xt][yt] = Attackable;
        if (exit) break;
    }

    for (int i = 1; i < 8; i++)
    {
        int xt = x;
        int yt = y + i;
        
        if (!isWithinBoard(xt,yt)) break;

        int exit = board[xt][yt] != None ? 1 : 0;
        board[xt][yt] = Attackable;
        if (exit) break;
    }

    for (int i = 1; i < 8; i++)
    {
        int xt = x;
        int yt = y - i;
        
        if (!isWithinBoard(xt,yt)) break;

        int exit = board[xt][yt] != None ? 1 : 0;
        board[xt][yt] = Attackable;
        if (exit) break;
    }
}

void getPseudoMovesQueen(int board[8][8], const int x, const int y)
{
    getPseudoMovesRook(board, x, y);
    getPseudoMovesBishop(board, x, y);
}

void getPseudoMovesKing(int board[8][8], const int x, const int y)
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

void getPseudoMoves(int board[8][8], const int x, const int y) 
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
            getPseudoMovesPawn(tempboard, x, y);
            break;
        case Bishop:
            getPseudoMovesBishop(tempboard, x, y);
            break;
        case Knight:
            getPseudoMovesKnight(tempboard, x, y);
            break;
        case Rook:
            getPseudoMovesRook(tempboard, x, y);
            break;
        case Queen:
            getPseudoMovesQueen(tempboard, x, y);
            break;
        case King:
            getPseudoMovesKing(tempboard, x, y);
            break;
    }

    removeOccupiedMoves(board, tempboard, x, y);

    // remove all moves that result in check
    // TO-DO: implement function that can *check* if specified color is in check on a given board
    // TO-DO: split move checks into multiple files; pseudomoves and others maybe?

    copyBoard(tempboard, board);

    return;
}

unsigned int isKingInCheck(int color, int board[8][8])
{
    if (color > 0)
    {
        color = 1;
    }
    else
    {
        color = -1;
    }

    int tempboard[8][8] = {};
    copyBoard(board, tempboard);

    int kingX = -1;
    int kingY = -1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == King * color)
            {
                kingX = i;
                kingY = j;
                break;
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (!checkFiguresSameColor(color, board[i][j]))
            {
                getPseudoMoves(tempboard, i, j);
            }
        }
    }

    if (tempboard[kingX][kingY] == Attackable)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}