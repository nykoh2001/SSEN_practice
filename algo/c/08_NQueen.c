/* 전진성님 코드 */

#if 0

#define MAX_N 15
int N;
int col[MAX_N];
int diag_r[MAX_N * 2];
int diag_l[MAX_N * 2];

void mask(int r, int c) {
    col[c] = 1;
    diag_r[r + c] = 1;
    diag_l[N + r - c] = 1;
}

void unmask(int r, int c) {
    col[c] = 0;
    diag_r[r + c] = 0;
    diag_l[N + r - c] = 0;
}

int check(int r, int c) {
    if (col[c] || diag_r[r + c] || diag_l[N + r - c]) return 1;
    return 0;
}

int n_queen(int r) {
    if (r > N) {
        return 1;
    }

    int cnt = 0;
    for (int c = 1; c <= N; c++) {
        if (check(r, c)) continue;
        mask(r, c);
        cnt += n_queen(r + 1);
        unmask(r, c);
    }

    return cnt;
}


int main(void) {
    scanf("%d", &N);
    printf("%d\n", n_queen(1));

    return 0;
}

#endif
