#include <stdio.h>

int main() {
        int N = 0, i = 0, c = 0, c1 = 0, i1 = 1;

        scanf("%d", &N);

        float rez = 0, n[N], n1[N], n2[N];
        char op[N - 1], op1[N-1], op2[N-1];

        for (i = 0; i < N; i++) {
            scanf("%f", &n[i]);
        }

        scanf("%s", op);

        for (i = 0; i < N-1; i++) {
            if (op[i] == '*') {
                n[i+1] = n[i] * n[i+1];
            }

            if (op[i] == '/') {
                n[i+1] = n[i] / n[i+1];
            }
        }

        for (i = 0; i < N-1; i++) {
            if (op[i] != '*' && op[i] != '/') {
                n1[i1] = n[i];
                op1[i1] = op[i];
                i1++;
            }
        }

        n1[i1+1] = n[N-1];

        for (i = 0; i < i1-1; i++) {
            printf("%f\n", n1[i]);
        }

        // for (i = 0; i < N-1-c; i++) {
        //     if (op1[i] == '#') {
        //             n1[i+1] = (n1[i] + n1[i+1])*(n1[i] + n1[i+1]);
        //             n1[i] = 0;
        //             c1++;
        //     }
        // }
        // n2[0] = n1[0];
        // i1 = 1;

        // for (i = 1; i < N-c; i++) {
        //     if (n1[i] != 0) {
        //         n2[i1] = n1[i];
        //         op2[i1-1] = op1[i-1];
        //         i1++;
        //     }
        // }

        // for (i = 0; i < N-c; i++) {
        //     if (op2[i] == '+') {
        //         // printf("%f %f\n", n2[i], n2[i+1]);
        //         n2[i+1] = n2[i] + n2[i + 1];
        //     }
        //     if (op2[i] == '-') {
        //         n2[i+1] = n2[i] - n2[i + 1];
        //     }
        //     }
        // for (i = 0; i < N-c-c1; i++) {
        //     printf("%f\n", n2[i]);
        // }
        // rez = n2[N-c-c1-1];
        // printf("%f\n", rez);
    }
