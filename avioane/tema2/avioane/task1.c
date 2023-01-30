#include "./utils.h"

void SolveTask1(void *info, int nr_avioane) {
    int i = 0, j = 0;

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

    for (i = 0; i < nr_avioane; i++) {
    memcpy(x, info_tmp + i * A, 1 * sizeof(unsigned short));

    memcpy(y, info_tmp + A1 + A * i, 1 * sizeof(unsigned short));

    memcpy(directie, info_tmp + A2 + A * i, 1 * sizeof(unsigned char));

    memcpy(cod, info_tmp + A3 + A * i, 4 * sizeof(unsigned char));

    memcpy(viteza, info_tmp + A4 + A * i, 1 * sizeof(unsigned int));

    printf("(%hd, %hd)\n", x[0],  y[0]);

    printf("%c\n", directie[0]);

    for (j = 0; j < 4; j++) {
        printf("%c", cod[j]);
    }

    printf("\n");

    printf("%d\n", viteza[0]);
    printf(" \n");
    }
}
