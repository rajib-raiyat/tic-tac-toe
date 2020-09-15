/*
 * Check out github repository
 * https://github.com/rajib-raiyat/tic-tac-toe
 */

#include <stdio.h>

// This function is for create an empty board for game.
void create_the_empty_board(board_size){
    // board_size -> size of the board [value type int]
    for(int i=0; i<board_size; i++){
        for(int j=0; j<board_size; j++){
            printf(".");
        }
        printf("\n");
    }
}

int main() {
    int size_fo_board;
    printf("What is the size of the board you want to play in?\n");
    scanf("%d", &size_fo_board); // Take the size of the board.

    if (size_fo_board < 3){
        printf("Minimum size of board must be 3.\n");
        return 0;
    }

    if (size_fo_board > 15){
        printf("Maximum size of board must be 15.\n");
        return 0;
    }

    create_the_empty_board(size_fo_board);

    return 0;
}
