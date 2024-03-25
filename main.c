#include <string.h>
#include <src/chess_utils.h>
#include <src/move_checks.h>

int main() {
    int board[8][8] = {};
    int tempboard[8][8] = {};
    initializeBoard(board);
    
    board[6][4] = Queen;
    board[2][4] = Pawn;
    copyBoard(board, tempboard);

    getPseudoMoves(tempboard, 5, 6);
    printBoard(board);
    printBoard(tempboard);

    return 0;
}