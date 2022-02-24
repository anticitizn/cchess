#include <string.h>
#include <src/chess_utils.h>
#include <src/move_checks.h>

int main() {
    int board[8][8] = {};
    initializeBoard(board);

    printBoard(board);

    getPossibleMoves(board, 3, 0);

    return 0;
}