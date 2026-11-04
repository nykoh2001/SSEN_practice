#if 0

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    scanf("%d", &N);

    if (N % 2 == 0 || N > 100) {
        printf("INPUT ERROR");
        return 0;
    }

    int offset = 0;
    int k = (N + 1) / 2;
    const int middle = k - 1;

    char result[101][101];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 2 * (i + 1) - 1; j++) {
            result[middle - i + j][middle - i] = (char)('A' + (offset++) % 26);
        }
    }

    int count;
    for (int i = 0; i < N; i++) {
        count = i < k ? i + 1 : 2 * k - i - 1;
        for (int j = 0; j < count; j++) {
            printf("%c ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}


#endif
