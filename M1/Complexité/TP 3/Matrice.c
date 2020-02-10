#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1500
int main() {
	long i, j, k;
	int all;
	long **A, **B, **C;
	long N[8] = {100, 300, 500, 700, 900, 1100, 1300, 1500};
	double t[8];
	clock_t t1, t2;
	A = (long **)malloc(MAX * sizeof(long *));
	B = (long **)malloc(MAX * sizeof(long *));
	C = (long **)malloc(MAX * sizeof(long *));
	for (i = 0; i < MAX; i++) {
		A[i] = (long *)malloc(MAX * sizeof(long));
		B[i] = (long *)malloc(MAX * sizeof(long));
		C[i] = (long *)malloc(MAX * sizeof(long));
	}
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			A[i][j] = i + 1;
			B[i][j] = j + 1;
			C[i][j] = 0;
		}
	}
	for (all = 0; all < 8; all++) {
		t1 = clock();
		for (i = 0; i < N[all]; i++) {
			for (j = 0; j < N[all]; j++) {
				C[i][j] = 0;
				for (k = 0; k < N[all]; k++) {
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		t2 = clock();
		t[all] = (double)(t2 - t1) / CLOCKS_PER_SEC;
	}
	for (all = 0; all < 8; all++) {
		printf("Temps d'execution : %f\n", t[all]);
	}
}
