#include <stdio.h>

int main() {
    #define BITS 32
    #define DIM 16
    #define SEVEN 7

    unsigned int i = 0, j = 0, k = 0, l = 0;
    unsigned int instructiune = 0, positie_bit = 0;
    unsigned int bit = 0, bit1 = 0, bit2 = 0;
    unsigned int N = 1, pow2 = 1, dim = 1;
    unsigned int numar_operanzi = 0;

    scanf("%u", &instructiune);

    for (i = BITS - 3; i < BITS; i++) {
        bit = 1 & (instructiune >> i);
        N = N + pow2 * bit;

        pow2 = pow2 * 2;
    }

    char op[N];

    for (i = BITS - 4; i > BITS - 4 - N * 2; i = i - 2) {
        bit1 = (instructiune >> i) & 1;
        bit2 = (instructiune >> i - 1) & 1;

        if (bit1 == 0 && bit2 == 0)
            op[j] = '+';

        if (bit1 == 0 && bit2 == 1)
            op[j] = '-';

        if (bit1 == 1 && bit2 == 0)
            op[j] = '*';


        if (bit1 == 1 && bit2 == 1)
            op[j] = '/';

        j++;
    }

    pow2 = 1;

    for (i = BITS - SEVEN - N * 2; i < BITS - 3 - N * 2; i++) {
        bit = 1 & (instructiune >> i);
        dim = dim + pow2 * bit;

        pow2 = pow2 * 2;
    }

    numar_operanzi = ((N + 1) * dim) / DIM;

    if (((N + 1) * dim) % DIM != 0)
        numar_operanzi++;

    unsigned short operand_brut[numar_operanzi], operand[N + 1], aux = 0;

    for (i = 0; i < numar_operanzi; i++) {
        scanf("%hd", &operand_brut[i]);

        for (k = DIM / dim; k > 0; k--) {
            pow2 = 1;

            operand[l] = 0;
            aux = 0;

            for (j = (k - 1) * dim; j < k * dim; j++) {
                bit = 1 & (operand_brut[i] >> j);
                aux = aux + pow2 * bit;

                pow2 = pow2 * 2;
            }

            if (l == k - 1 && aux == 0) {
            continue; } else {
                operand[l] = aux;
                l++;
                }
        }
    }

    unsigned int suma = operand[0];

    for (i = 0; i < N; i++) {
        if (op[i] == '+')
            suma = suma + operand[i + 1];

        if (op[i] == '-')
            suma = suma - operand[i + 1];

        if (op[i] == '*')
            suma = suma * operand[i + 1];

        if (op[i] == '/')
            suma = suma / operand[i + 1];
    }

    printf("%d\n", suma);
}
