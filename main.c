/*
* Check out github repository
* https://github.com/rajib-raiyat/tic-tac-toe
*/

#include <stdio.h>
#include <stdlib.h>

int create_game_array(int board_size);

int check_input(int board_size, int input);

void check_win(int board_size, int temp_array[20][20]);

void make_turn(int board_size, int player);

void view_game_array(int board_size, char game_array[20][20]);

// The main function
int main() {
    int flag = 0;
    int size_of_board = 0;

    printf("What is the size of the board you want to play in?\n");

    while (flag == 0) { // if flag 0 it's takes the correct input until the input is correct.
        scanf("%d", &size_of_board); // Take the size of the board.

        if (size_of_board < 3) {
            printf("Minimum size of board must be 3.\nPlease try again!\n");
        } else if (size_of_board > 15) {
            printf("Maximum size of board must be 15.\nPlease try again!\n");
        } else {
            flag = 1; // Help to exit from the while loop if the input is correct.
        }
    }

    create_game_array(size_of_board); // call the function which initialize the game board.

    for (int i = 1; i <= (size_of_board + 2); i++) {
        printf("Player 1's turn\n");
        make_turn(size_of_board, 1);

        if (i == size_of_board + 2) {
            printf("Game draw!");
            break;
        }

        printf("Player 2's turn\n");
        make_turn(size_of_board, 2);
    }

    return 0;
}

// This function print the latest game board
void view_game_array(int board_size, char game_array[20][20]) {
    int temp_array[20][20];

    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            printf("%c ", game_array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (game_array[i][j] == 'X') {
                temp_array[i][j] = 1;
            } else if (game_array[i][j] == 'O') {
                temp_array[i][j] = 2;
            } else {
                temp_array[i][j] = 10;
            }
        }
    }

    check_win(board_size, temp_array);
}

// Check the input is appropriate or not
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

// This function take input from player
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
}

// This function check the win
void check_win(int board_size, int temp_array[20][20]) {
    int count = 0;

    // Main diagonal check
    for (int i = 0; i < board_size; i++) {
        count = count + temp_array[i][i];
    }

    if ((count == board_size) || (count == board_size * 2)) {
        if (count == board_size) {
            printf("Player 1 wins\n");
            exit(0);
        } else {
            printf("Player 2 wins\n");
            exit(0);
        }
    } else {
        count = 0;
    }

    // mirror diagonal check
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (i + j == ((board_size + 1) - 2)) {
                count += temp_array[i][j];
            }
        }
    }

    if ((count == board_size) || (count == board_size * 2)) {
        if (count == board_size) {
            printf("Player 1 wins\n");
            exit(0);
        } else {
            printf("Player 2 wins\n");
            exit(0);
        }
    } else {
        count = 0;
    }

    // all column result check
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            count = count + temp_array[j][i];
        }

        if ((count == board_size) || (count == board_size * 2)) {
            if (count == board_size) {
                printf("Player 1 wins\n");
                exit(0);
            } else {
                printf("Player 2 wins\n");
                exit(0);
            }
        } else {
            count = 0;
        }
    }

    // all row result check
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            count = count + temp_array[i][j];
        }

        if ((count == board_size) || (count == board_size * 2)) {
            if (count == board_size) {
                printf("Player 1 wins\n");
                exit(0);
            } else {
                printf("Player 2 wins\n");
                exit(0);
            }
        } else {
            count = 0;
        }
    }
}
