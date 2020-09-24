/*
* Check out github repository
* https://github.com/rajib-raiyat/tic-tac-toe
*/

#include <stdio.h>

int create_game_array(int board_size);

int check_input(int board_size, int input);

int check_win(int board_size, char game_array[20][20]);

void make_turn(int board_size, int player);

void view_game_array(int board_size, char game_array[20][20]);

int main() {
    int flag = 0, turn_count = 1;
    int size_of_board;

    printf("What is the size of the board you want to play in?\n");

    while (flag == 0) {
        scanf("%d", &size_of_board); // Take the size of the board.

        if (size_of_board < 3) {
            printf("Minimum size of board must be 3.\nPlease try again!\n");
        } else if (size_of_board > 15) {
            printf("Maximum size of board must be 15.\nPlease try again!\n");
        } else {
            flag = 1;
        }
    }

    create_game_array(size_of_board);

    while (turn_count != (size_of_board * size_of_board)) {
        turn_count++;

        printf("Player 1's turn [e.g 1 2]\n");
        make_turn(size_of_board, 1);

        printf("Player 2's turn [e.g 1 1]\n");
        make_turn(size_of_board, 2);
    }


    return 0;
}

void view_game_array(int board_size, char game_array[20][20]) {
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            printf("%c ", game_array[i][j]);
        }
        printf("\n");
    }
}

int check_input(int board_size, int input) {
    if (input > board_size || input < 1) {
        return 1;
    }
    return 0;
}

// This function is for create an empty board for game.
int create_game_array(int board_size){
    char game_array[20][20];

    for (int i=0; i<board_size; i++) {
        for (int j=0; j<board_size; j++) {
            game_array[i][j] = '.';
        }
    }

    view_game_array(board_size, game_array);

    return 0;
}

void make_turn(int board_size, int player) {
    char game_array[20][20];
    int flag = 0;
    int pi, pj;

    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if ((game_array[i][j] != '.') && (game_array[i][j] != 'X') && (game_array[i][j] != 'O')) {
                game_array[i][j] = '.';
            }
        }
    }

    while (flag == 0) {
        scanf("%d %d", &pi, &pj);
        if (check_input(board_size, pi) != 0 || check_input(board_size, pj) != 0) {
            printf("%d, %d is outside the board.\n", pi, pj);
            printf("Please try again\n");
            flag = 0;
        } else {
            if (game_array[pi - 1][pj - 1] == '.') {
                if (player == 1) {
                    game_array[pi - 1][pj - 1] = 'X';
                } else {
                    game_array[pi - 1][pj - 1] = 'O';
                }
                flag = 1;
            } else {
                printf("%d %d is already filled up!\n", pi, pj);
                printf("Please try again\n");
                flag = 0;
            }
        }
    }

    view_game_array(board_size, game_array);
    check_win(board_size, game_array);
}

int check_win(int board_size, char game_array[20][20]) {
    int flag = 0;
    for (int i = 0; i < board_size; i++) {
        int j = 0;
        for (int k = j + 1; k < board_size; k++) {
            if (game_array[i][j] != game_array[i][k]) {
                flag = 1;
                break;
            } else {
                flag = 0;
            }
        }

        if (flag == 0) {
            break;
        }
    }

    if (flag == 0) {
        printf("Match found");
    } else {
        printf("Match not found");
    }

    return flag;
}
