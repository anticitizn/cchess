#include <stdio.h>
#include <stdlib.h>

enum figures {None=0, Pawn=1, Knight=2, Bishop=3, Rook=4, Queen=5, King=6};
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

char getFigureChar(const int figure)
{
    return figure_chars[abs(figure)];
}

char getFigureColor(const int figure)
{
    return figure >= 0 ? ' ' : '-';
}

int main() {
    int board[8][8] = {};
    initializeBoard(board);

    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            printf("%c%c ", getFigureColor(board[i][j]), getFigureChar(board[i][j]));
        }
        putchar('\n');
    }

    return 0;
}