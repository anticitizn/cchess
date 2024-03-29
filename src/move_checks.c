#include <src/move_checks.h>
#include <src/chess_utils.h>

#include <stdlib.h>

void getPseudoMovesPawn(int board[8][8], const int x, const int y)
{
    int temp = board[x][y] > 0 ? 1 : -1;

    // Two square advance - only possible if pawn has not moved yet
    if ((y == 1 || y == 6) && board[x][y+temp] == None)
    {
        board[x][y+temp*2] = Passable;
    }

    // One square advance
    if (isWithinBoard(x, y + temp) && board[x][y+temp] == None)
    {
        board[x][y+temp] = Passable;
    }
    
    // Capturing
    // To the right
    if (isWithinBoard(x+1, y+temp) && board[x+1][y+temp] != None && !checkFiguresSameColor(board[x][y], board[x+1][y+temp]))
    {
        board[x+1][y+temp] = Attackable;
    }

    // To the left
    if (isWithinBoard(x-1, y+temp) && board[x-1][y+temp] != None && !checkFiguresSameColor(board[x][y], board[x-1][y+temp]))
    {
        board[x-1][y+temp] = Attackable;
    }

    // TO-DO: En passant
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

// Returns a board with all possible pseudo moves populated,
// including ones that would result in the king being in check
void getAllPseudoMoves(int board[8][8], const int x, const int y) 
{
    int pseudomove_board[8][8] = {};
    copyBoard(board, pseudomove_board);

    if (!isWithinBoard(x,y))
    {
        return;
    }

    switch(abs(board[x][y]))
    {
        case Pawn:
            getPseudoMovesPawn(pseudomove_board, x, y);
            break;
        case Bishop:
            getPseudoMovesBishop(pseudomove_board, x, y);
            break;
        case Knight:
            getPseudoMovesKnight(pseudomove_board, x, y);
            break;
        case Rook:
            getPseudoMovesRook(pseudomove_board, x, y);
            break;
        case Queen:
            getPseudoMovesQueen(pseudomove_board, x, y);
            break;
        case King:
            getPseudoMovesKing(pseudomove_board, x, y);
            break;
    }

    removeOccupiedMoves(board, pseudomove_board, x, y);

    copyBoard(pseudomove_board, board);

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
                getAllPseudoMoves(tempboard, i, j);
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

// Returns a board with all legal pseudo moves populated
void getPseudoMoves(int board[8][8], int x, int y)
{
    int pseudomove_board[8][8] = {};
    copyBoard(board, pseudomove_board);
    getAllPseudoMoves(pseudomove_board, x, y);
    
    // Remove all pseudomoves that result in a check
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (pseudomove_board[i][j] == Passable || pseudomove_board[i][j] == Attackable)
            {
                int tempboard[8][8] = {};
                copyBoard(pseudomove_board, tempboard);

                tempboard[i][j] = tempboard[x][y];
                tempboard[x][y] = None;

                if (isKingInCheck(getFigureColor(tempboard[i][j]), tempboard))
                {
                    // Remove the pseudomove from the square and replace it with its original content
                    pseudomove_board[i][j] = board[i][j];
                }
            }
        }
    }

    copyBoard(pseudomove_board, board);
}