#include "day6_lib.h"

void print_2D(int (*p)[3][4]) {
	int r = SIZE(*p);
	int c = SIZE(**p);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%5d ", (*p)[i][j]);

		printf("\n");
	}
}

void exchange0(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void exchange1(int** ap, int** bp) {
	int temp = **ap;
	**ap = **bp;
	**bp = temp;
}

void exchange2(int*** app, int*** bpp) {
	int temp = ***app;
	***app = ***bpp;
	***bpp = temp;
}

void exchange3(int** ap, int** bp) {
	int* temp = *ap;
	*ap = *bp;
	*bp = temp;
}

void exchange4(int*** app, int*** bpp) {
	int* temp = **app;
	**app = **bpp;
	**bpp = temp;
}

void exchange5(int*** app, int*** bpp) {
	int** temp = *app;
	*app = *bpp;
	*bpp = temp;
}
