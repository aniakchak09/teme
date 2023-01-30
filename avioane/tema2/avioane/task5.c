#include "./utils.h"

void SolveTask5(void *info, int nr_avioane, int T, int nr_pct_coord, int *X, int *Y, int N) {
    unsigned short *lin = malloc(1 * sizeof(unsigned short));

    unsigned short *col = malloc(1 * sizeof(unsigned short));

    unsigned char *directie = malloc(1 * sizeof(char));

    unsigned char *cod = malloc(4 * sizeof(unsigned char));

    unsigned int *viteza = malloc(1 * sizeof(unsigned int));

    char *info_tmp = info;

    int i = 0, j = 0, k = 0, ok = 0;

    #define A 13
    #define A1 2
    #define A2 4
    #define A3 5
    #define A4 9

    for (i = 0; i < T + 1; i++) {
        ok = 0;

        for (j = 0; j < nr_avioane; j++) {
            memcpy(lin, info_tmp + j * A, 1 * sizeof(unsigned short));

            memcpy(col, info_tmp + A1 + A * j, 1 * sizeof(unsigned short));

            memcpy(directie, info_tmp + A2 + A * j, 1 * sizeof(unsigned char));

            memcpy(cod, info_tmp + A3 + A * j, 4 * sizeof(unsigned char));

            memcpy(viteza, info_tmp + A4 + A * j, 1 * sizeof(unsigned int));

            for (k = 0; k < nr_pct_coord; k++) {
                if (cod[0] == '1') {
                    if (*directie == 'N') {
                        if (X[k] > *lin - 1 - *viteza * i && X[k] < *lin + 4 - *viteza * i && Y[k] == *col) {
                            ok++;
                            break;
                        } else {
                            if (X[k] == *lin + 1 - *viteza * i && Y[k] > *col - 3 && Y[k] < *col + 3) {
                                ok++;
                                break;
                            } else {
                                if (X[k] == *lin + 3 - *viteza * i && Y[k] > *col - 2 && Y[k] < *col + 2) {
                                    ok++;
                                    break;
                                }
                            }
                        }
                    }

                    if (*directie == 'S') {
                        if (X[k] < *lin + 1 + *viteza * i && X[k] > *lin - 4 + *viteza * i && Y[k] == *col) {
                            ok++;
                            break;
                        } else {
                            if (X[k] == *lin - 1 + *viteza * i && Y[k] > *col - 3 && Y[k] < *col + 3) {
                                ok++;
                                break;
                            } else {
                                if (X[k] == *lin - 3 + *viteza * i && Y[k] > *col - 2 && Y[k] < *col + 2) {
                                    ok++;
                                    break;
                                }
                            }
                        }
                    }

                    if (*directie == 'E') {
                        if (X[k] == *lin && Y[k] > *col - 4 + *viteza * i && Y[k] < *col + 1 + *viteza * i) {
                            ok++;
                            break;
                        } else {
                            if (Y[k] == *col - 1 + *viteza * i && X[k] > *lin - 3 && X[k] < *lin + 3) {
                                ok++;
                                break;
                            } else {
                                if (Y[k] == *col - 3 + *viteza * i && X[k] > *lin - 2 && X[k] < *lin + 2) {
                                    ok++;
                                    break;
                                }
                            }
                        }
                    }

                    if (*directie == 'W') {
                        if (X[k] == *lin && Y[k] < *col + 4 - *viteza * i && Y[k] > *col - 1 - *viteza * i) {
                            ok++;
                            break;
                        } else {
                            if (Y[k] == *col + 1 - *viteza * i && X[k] > *lin - 3 && X[k] < *lin + 3) {
                                ok++;
                                break;
                            } else {
                                if (Y[k] == *col + 3 - *viteza * i && X[k] > *lin - 2 && X[k] < *lin + 2) {
                                    ok++;
                                    break;
                                }
                            }
                        }
                    }
                }

                if (cod[0] == '2') {
                    if (*directie == 'N') {
                        if (X[k] > *lin - 1 - *viteza * i && X[k] < *lin + A3 - *viteza * i && Y[k] == *col) {
                            ok++;
                            break;
                        } else {
                            if (X[k] == *lin + 1 - *viteza * i && Y[k] > *col - 2 && Y[k] < *col + 2) {
                                ok++;
                                break;
                            } else {
                                if (X[k] == *lin + 2 - *viteza * i && Y[k] > *col - 4 && Y[k] < *col + 4) {
                                    ok++;
                                    break;
                                } else {
                                    if (X[k] == *lin + 4 - *viteza * i && Y[k] > *col - 3 && Y[k] < *col +3) {
                                        ok++;
                                        break;
                                    }
                                }
                            }
                        }
                    }

                    if (*directie == 'S') {
                        if (X[k] > *lin + 1 + *viteza * i && X[k] > *lin - A3 + *viteza * i && Y[k] == *col) {
                            ok++;
                            break;
                        } else {
                            if (X[k] == *lin - 1 + *viteza * i && Y[k] > *col - 2 && Y[k] < *col + 2) {
                                ok++;
                                break;
                            } else {
                                if (X[k] == *lin - 2 + *viteza * i && Y[k] > *col - 4 && Y[k] < *col + 4) {
                                    ok++;
                                    break;
                                } else {
                                    if (X[k] == *lin - 4 + *viteza * i && Y[k] > *col - 3 && Y[k] < *col +3) {
                                        ok++;
                                        break;
                                    }
                                }
                            }
                        }
                    }

                    if (*directie == 'E') {
                        if (X[k] == *lin && Y[k] > *col - A3 + *viteza * i && Y[k] < *col + 1 + *viteza * i) {
                            ok++;
                            break;
                        } else {
                            if (X[k] > *lin - 2 && X[k] < *lin + 2 && Y[k] == *col - 1 + *viteza * i) {
                                ok++;
                                break;
                            } else {
                                if (X[k] > *lin - 4 && X[k] < *lin + 4 && Y[k] ==  *col - 2 + *viteza * i) {
                                    ok++;
                                    break;
                                } else {
                                    if (X[k] > *lin - 3 && X[k] < *lin + 3 && Y[k] == *col - 4 + *viteza * i) {
                                        ok++;
                                        break;
                                    }
                                }
                            }
                        }
                    }

                    if (*directie == 'W') {
                        if (X[k] == *lin && Y[k] < *col + A3 - *viteza * i && Y[k] > *col - 1 - *viteza * i) {
                            ok++;
                            break;
                        } else {
                            if (X[k] > *lin - 2 && X[k] < *lin + 2 && Y[k] == *col + 1 - *viteza * i) {
                                ok++;
                                break;
                            } else {
                                if (X[k] > *lin - 4 && X[k] < *lin + 4 && Y[k] ==  *col + 2 - *viteza * i) {
                                    ok++;
                                    break;
                                } else {
                                    if (X[k] > *lin - 3 && X[k] < *lin + 3 && Y[k] == *col + 4 - *viteza * i) {
                                        ok++;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d: %d\n", i, ok);
    }
}
