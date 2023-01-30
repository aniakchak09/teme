#include "./utils.h"
/*
sortare crescator dupa tip
    pentru tipuri egale, descrescator dupa Codul Aeroportului
        pentru coduri egale, crescator dupa viteza
*/

int comp(const void *m, const void *n) {
    unsigned short *x = malloc(1 * sizeof(unsigned short));

    unsigned short *y = malloc(1 * sizeof(unsigned short));

    unsigned char *directie = malloc(1 * sizeof(char));

    unsigned char *cod = malloc(4 * sizeof(unsigned char));

    unsigned int *viteza = malloc(1 * sizeof(unsigned int));

    char *ma = m, *na = n;

    #define B 5
    #define B1 6
    #define B2 7
    #define B3 8
    #define B4 9

    if (*(ma + B) != *(na + B))
        return (*(ma + B) - *(na + B));

    if (*(ma + B1) != *(na + B1))
        return (*(na + B1) - *(ma + B1));

    if (*(ma + B2) != *(na + B2))
        return (*(na + B2) - *(ma + B2));

    if (*(ma + B3) != *(na + B3))
        return (*(na + B3) - *(ma + B3));

    if (*(ma + B4) != *(na + B4))
        return (*(ma + B4) - *(na + B4));

    return 0;
}

void SolveTask3(void *info, int nr_avioane) {
    #define A 13
    #define A1 2
    #define A2 4
    #define A3 5
    #define A4 9

    int i = 0, j = 0;

    unsigned short *x = malloc(1 * sizeof(unsigned short));

    unsigned short *y = malloc(1 * sizeof(unsigned short));

    unsigned char *directie = malloc(1 * sizeof(char));

    unsigned char *cod = malloc(4 * sizeof(unsigned char));

    unsigned int *viteza = malloc(1 * sizeof(unsigned int));

    char *info_tmp = info;

    qsort(info_tmp, nr_avioane, A * sizeof(char), comp);

    for (i = 0; i < nr_avioane; i++) {
    memcpy(x, info_tmp + i * A, 1 * sizeof(unsigned short));

    memcpy(y, info_tmp + A1 + A * i, 1 * sizeof(unsigned short));

    memcpy(directie, info_tmp + A2 + A * i, 1 * sizeof(unsigned char));

    memcpy(cod, info_tmp + A3 + A * i, 4 * sizeof(unsigned char));

    memcpy(viteza, info_tmp + A4 + A * i, 1 * sizeof(unsigned int));

    printf("(%hd, %hd)\n", *x, *y);

    printf("%c\n", *directie);

    for (j = 0; j < 4; j++) {
        printf("%c", cod[j]);
    }

    printf("\n");

    printf("%d\n", *viteza);
    printf(" \n");
    }
}
