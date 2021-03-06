#include <string.h>
#include <src/chess_utils.h>
#include <src/move_checks.h>

int main() {
    int board[8][8] = {};
    int tempboard[8][8] = {};
    initializeBoard(board);
    
    board[4][4] = Queen;
    copyBoard(board, tempboard);

    getPseudoMoves(tempboard, 4, 4);
    printBoard(board);
    printBoard(tempboard);

    return 0;
}