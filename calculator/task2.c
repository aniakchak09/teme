#include <stdio.h>

int main() {
        int N = 0, i = 0;

        scanf("%d", &N);

        float rez = 0, n[N];
        char op[N - 1];

        for (i = 0; i < N; i++) {
            scanf("%f", &n[i]);
        }

        scanf("%s", op);

        for (i = 0; i < N-1; i++) {
            if (op[i] == '*' || op[i] == '/') {
                    if (op[i] == '*') {
                            n[i+1] = n[i] * n[i+1];
                            n[i] = 0;
                            if (i > 1)
                                op[i] = op[i-1];
                            else
                                op[i] = '+';
                        } else {
                                    n[i+1] = n[i] / n[i+1];
                                    n[i] = 0;
                                    if (i > 1)
                                        op[i] = op[i-1];
                                    else
                                        op[i] = '+';
                                }
            }
        }
            rez = n[0];

            for (i = 0; i < N-1; i++) {
                if (op[i] == '+')
                    rez = rez + n[i + 1];
                else
                    rez = rez - n[i + 1];
            }

        printf("%f\n", rez);
    }
