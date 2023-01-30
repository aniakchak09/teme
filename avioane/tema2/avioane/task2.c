#include "./utils.h"

void SolveTask2(void *info, int nr_avioane, int N, char **mat) {
    unsigned short i = 0, j = 0;

    #define A 13
    #define A1 2
    #define A2 4
    #define A3 5
    #define A4 9

    unsigned short *x = malloc(1 * sizeof(unsigned short));

    unsigned short *y = malloc(1 * sizeof(unsigned short));

    unsigned char *directie = malloc(1 * sizeof(char));

    unsigned char *cod = malloc(4 * sizeof(unsigned char));

    unsigned int *viteza = malloc(1 * sizeof(unsigned int));

    char *info_tmp = info;

for (int k = 0; k < nr_avioane; k++) {
    memcpy(x, info_tmp + k * A, 1 * sizeof(unsigned short));

    memcpy(y, info_tmp + A1 + A * k, 1 * sizeof(unsigned short));

    memcpy(directie, info_tmp + A2 + A * k, 1 * sizeof(unsigned char));

    memcpy(cod, info_tmp + A3 + A * k, 4 * sizeof(unsigned char));

    memcpy(viteza, info_tmp + A4 + A * k, 1 * sizeof(unsigned int));

    if (cod[0] == '1') {
        if (*directie == 'N') {
            for (i = *x; i < *x + 4; i++) {
                    mat[i][*y] = '*';
                }

            for (j = *y - 2; j < *y + 3; j++) {
                    mat[*x + 1][j] = '*';
                }

            for (j = *y - 1; j < *y + 2; j++) {
                    mat[*x + 3][j] = '*';
                }
                }

        if (*directie == 'S') {
            for (i = *x - 3; i < *x + 1; i++) {
                    mat[i][*y] = '*';
                }

            for (j = *y - 2; j < *y + 3; j++) {
                    mat[*x - 1][j] = '*';
                }

            for (j = *y - 1; j < *y + 2; j++) {
                    mat[*x - 3][j] = '*';
                }
            }

        if (*directie == 'E') {
            for (j = *y - 3; j < *y + 1; j++) {
                    mat[*x][j] = '*';
                }

            for (i = *x - 1; i < *x + 2; i++) {
                    mat[i][*y - 3] = '*';
                }

            for (i = *x - 2; i < *x + 3; i++) {
                    mat[i][*y - 1] = '*';
                }
            }

        if (*directie == 'W') {
            for (j = *y; j < *y + 4; j++) {
                    mat[*x][j] = '*';
                }

            for (i = *x - 2; i < *x + 3; i++) {
                    mat[i][*y + 1] = '*';
                }

            for (i = *x - 1; i < *x + 2; i++) {
                    mat[i][*y + 3] = '*';
                }
            }
    }

    if (cod[0] == '2') {
        if (*directie == 'N') {
            for (i = *x; i < *x + A3; i++) {
                    mat[i][*y] = '*';
                }

            for (j = *y - 1; j < *y + 2; j++) {
                mat[*x + 1][j] = '*';
            }

            for (j = *y - 3; j < *y + 4; j++) {
                mat[*x + 2][j] = '*';
            }

            for (j = *y - 2; j < *y + 3; j++) {
                mat[*x + 4][j] = '*';
            }
        }

        if (*directie == 'S') {
            for (i = *x - 4; i < *x + 1; i++) {
                    mat[i][*y] = '*';
                }

            for (j = *y - 1; j < *y + 2; j++) {
                mat[*x - 1][j] = '*';
            }

            for (j = *y - 3; j < *y + 4; j++) {
                mat[*x - 2][j] = '*';
            }

            for (j = *y - 2; j < *y + 3; j++) {
                mat[*x - 4][j] = '*';
            }
        }

        if (*directie == 'E') {
            for (j = *y - 4; j < *y + 1; j++) {
                    mat[*x][j] = '*';
                }

            for (i = *x - 2; i < *x + 3; i++) {
                    mat[i][*y - 4] = '*';
                }

            for (i = *x - 3; i < *x + 4; i++) {
                    mat[i][*y - 2] = '*';
                }

            for (i = *x - 1; i < *x + 2; i++) {
                    mat[i][*y - 1] = '*';
                }
            }

        if (*directie == 'W') {
            for (j = *y; j < *y + A3; j++) {
                    mat[*x][j] = '*';
                }

            for (i = *x - 2; i < *x + 3; i++) {
                    mat[i][*y + 4] = '*';
                }

            for (i = *x - 3; i < *x + 4; i++) {
                    mat[i][*y + 2] = '*';
                }

            for (i = *x - 1; i < *x + 2; i++) {
                    mat[i][*y + 1] = '*';
                }
            }
    }
}

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", mat[i][j]);
        }

        printf("\n");
    }
}
