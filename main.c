#include <stdio.h>
#include <stdlib.h>

enum figures {None=0, Pawn=1, Knight=2, Bishop=3, Rook=4, Queen=5, King=6};

short** initializeBoard() 
{
    short** board = malloc(8*sizeof(short*));
    for (int i = 0; i < 8; i++)
    {
        board[i] = malloc( 8*sizeof(short));

        for (int j = 0; j < 8; j++) 
        {
            board[i][j] = 0;
        }
    }

    // White figures
    board[0][0] = Rook;
    board[1][0] = Knight;
    board[2][0] = Bishop;
    board[3][0] = Queen;
    board[4][0] = King;
    board[5][0] = Bishop;
    board[6][0] = Knight;
    board[7][0] = Rook;
    
    for (int i = 0; i < 8; i++) 
    {
        board[i][1] = Pawn;
    }
    
    // Black figures
    board[0][0] = -Rook;
    board[1][0] = -Knight;
    board[2][0] = -Bishop;
    board[3][0] = -Queen;
    board[4][0] = -King;
    board[5][0] = -Bishop;
    board[6][0] = -Knight;
    board[7][0] = -Rook;
    
    for (int i = 0; i < 8; i++) 
    {
        board[i][1] = -Pawn;
    }

    return board;
}

void main() {
    short** board = initializeBoard();
}