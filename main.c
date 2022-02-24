#include <string.h>
#include <src/chess_utils.h>
#include <src/move_checks.h>

int main() {
    int board[8][8] = {};
    int tempboard[8][8] = {};
    initializeBoard(board);
    copyBoard(board, tempboard);
    
    getPossibleMoves(tempboard, 3, 0);
    printBoard(tempboard);

    return 0;
}