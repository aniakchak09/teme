#include <stdio.h>

int main() {
    #define BITS 32
    #define SEVEN 7
    unsigned int instructiune = 0, positie_bit = 0;
    unsigned int bit = 0, bit1 = 0, bit2 = 0, numar_biti = 0;
    unsigned int i = 0, N = 1, pow2 = 1, dim = 1, primul_1 = 0;

    scanf("%u", &instructiune);

    for (i = BITS - 3; i < BITS; i++) {
        bit = 1 & (instructiune >> i);
        N = N + pow2 * bit;

        pow2 = pow2 * 2;
    }

    printf("%u ", N);

    for (i = BITS - 4; i > BITS - 4 - N * 2; i = i - 2) {
        bit1 = (instructiune >> i) & 1;
        bit2 = (instructiune >> i - 1) & 1;

        if (bit1 == 0 && bit2 == 0)
            printf("+");

        if (bit1 == 0 && bit2 == 1)
            printf("-");

        if (bit1 == 1 && bit2 == 0)
            printf("*");

        if (bit1 == 1 && bit2 == 1)
            printf("/");

        printf(" ");
    }

    pow2 = 1;

    for (i = BITS - SEVEN - N * 2; i < BITS - 3 - N * 2; i++) {
        bit = 1 & (instructiune >> i);
        dim = dim + pow2 * bit;

        pow2 = pow2 * 2;
    }

    printf("%d\n", dim);
}
