#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 3;
    int count = 0, flag = 0;
    int array[20][20] = {
            {10, 10, 10},
            {10, 10, 10},
            {10, 10, 10},
    };

    // Main diagonal check
    for (int i = 0; i < size; i++) {
        count = count + array[i][i];
    }

    if ((count == size) || (count == size * 2)) {
        if (count == size) {
            printf("P1 win\n");
            flag = 1;
        } else {
            printf("P2 win\n");
            flag = 1;
        }
    } else {
        count = 0;
    }

    // mirror diagonal check
    if (flag == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i + j == ((size + 1) - 2)) {
                    count += array[i][j];
                }
            }
        }
        if ((count == size) || (count == size * 2)) {
            if (count == size) {
                printf("P1 win\n");
                flag = 1;
            } else {
                printf("P2 win\n");
                flag = 1;
            }
        } else {
            count = 0;
        }
    }

    // all column result check
    if (flag == 0) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                count = count + array[j][i];
            }
            if ((count == size) || (count == size * 2)) {
                if (count == size) {
                    printf("P1 win\n");
                    flag = 1;
                } else {
                    printf("P2 win\n");
                    flag = 1;
                }
            }
            count = 0;
        }
    }

    if (flag == 0) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                count = count + array[i][j];
            }
            if ((count == size) || (count == size * 2)) {
                if (count == size) {
                    printf("P1 win\n");
                    flag = 1;
                } else {
                    printf("P2 win\n");
                    flag = 1;
                }
            }
            count = 0;
        }
    }

    if (flag == 0) {
        printf("Draw");
    }

    return 0;
}
