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

        rez = n[0];

        for (i = 0; i < N-1; i++) {
        if (op[i] == '+')
            rez = rez + n[i + 1];

        if (op[i] == '-')
            rez = rez - n[i + 1];

        if (op[i] == '*')
            rez = rez * n[i + 1];

        if (op[i] == '/') {
                if (n[i + 1 != 0])
                    rez = rez / n[i + 1];
                else
                    printf("error");
            }
        }
        printf("%f\n", rez);
    }
