#include "./utils.h"

void SolveTask4(void *info, int nr_avioane, int nr_obstacole, int *x, int *y, int N) {
    int i = 0, j = 0, ok = 0;

    #define A 13
    #define A1 2
    #define A2 4
    #define A3 5
    #define A4 9

    unsigned short *lin = malloc(1 * sizeof(unsigned short));

    unsigned short *col = malloc(1 * sizeof(unsigned short));

    unsigned char *directie = malloc(1 * sizeof(char));

    unsigned char *cod = malloc(4 * sizeof(unsigned char));

    unsigned int *viteza = malloc(1 * sizeof(unsigned int));

    int *obstacol = malloc(2 * sizeof(int));

    char *info_tmp = info;

    for (i = 0; i < nr_avioane; i++) {
        memcpy(lin, info_tmp + i * A, 1 * sizeof(unsigned short));

        memcpy(col, info_tmp + A1 + A * i, 1 * sizeof(unsigned short));

        memcpy(directie, info_tmp + A2 + A * i, 1 * sizeof(unsigned char));

        memcpy(cod, info_tmp + A3 + A * i, 4 * sizeof(unsigned char));

        memcpy(viteza, info_tmp + A4 + A * i, 1 * sizeof(unsigned int));

        for (j = 0; j < nr_obstacole; j++) {
            if (cod[0] == '1') {
                if (*directie == 'N') {
                    if (*(y + j) > *col - 3 && *(y + j) < *col + 3 && *(x + j) < *lin + 2) {
                        ok++;
                        break;
                    } else {
                        if (*(y + j) > *col - 2 && *(y + j) < *col + 2 && *(x + j) < *lin + 4) {
                            ok++;
                            break;
                        }
                    }
                }

                if (*directie == 'S') {
                    if (*(y + j) > *col - 3 && *(y + j) < *col + 3 && *(x + j) > *lin - 2) {
                        ok++;
                        break;
                    } else {
                        if (*(y + j) > *col - 2 && *(y + j) < *col + 2 && *(x + j) > *lin - 4) {
                            ok++;
                            break;
                        }
                    }
                }

                if (*directie == 'E') {
                    if (*(x + j) > *lin - 3 && *(x + j) < *lin + 3 && *(y + j) > *col - 2) {
                        ok++;
                        break;
                    } else {
                        if (*(x + j) > *lin - 2 && *(x + j) < *lin + 2 && *(y + j) > *col - 4) {
                            ok++;
                            break;
                        }
                    }
                }

                if (*directie == 'W') {
                    if (*(x + j) > *lin - 3 && *(x + j) < *lin + 3 && *(y + j) < *col + 2) {
                        ok++;
                        break;
                    } else {
                        if (*(x + j) > *lin - 2 && *(x + j) < *lin + 2 && *(y + j) < *col + 4) {
                            ok++;
                            break;
                        }
                    }
                }
            }

            if (cod[0] == '2') {
                if (*directie == 'N') {
                    if (*(y + j) > *col - 4 && *(y + j) < *col + 4 && *(x + j) < *lin + 3)  {
                        ok++;
                        break;
                    } else {
                        if (*(y + j) > *col - 3 && *(y + j) < *col + 3 && *(x + j) < *lin + A3) {
                            ok++;
                            break;
                        }
                    }
                }

                if (*directie == 'S') {
                    if (*(y + j) > *col - 4 && *(y + j) < *col + 4 && *(x + j) > *lin - 3)  {
                        ok++;
                        break;
                    } else {
                        if (*(y + j) > *col - 3 && *(y + j) < *col + 3 && *(x + j) > *lin - A3) {
                            ok++;
                            break;
                        }
                    }
                }

                if (*directie == 'E') {
                    if (*(x + j) > *lin - 4 && *(x + j) < *lin+ 4 && *(y + j) > *col - 3) {
                        ok++;
                        break;
                    } else {
                        if (*(x + j) > *lin - 3 && *(x + j) < *lin + 3 && *(y + j) > *col - A3) {
                            ok++;
                            break;
                        }
                    }
                }

                if (*directie == 'W') {
                    if (*(x + j) > *lin - 4 && *(x + j) < *lin + 4 && *(y + j) < *col + 3) {
                        ok++;
                        break;
                    } else {
                        if (*(x + j) > *lin - 3 && *(x + j) < *lin + 3 && *(y + j) < *col + A3) {
                            ok++;
                            break;
                        }
                    }
                }
            }
        }
    }

    printf("%d", nr_avioane - ok);
}
