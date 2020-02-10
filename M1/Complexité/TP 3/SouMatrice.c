#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MILLI_S 1000.0
#include <sys/time.h>
#include <windows.h>
#define MAX 3000

void sousMat1(long **A, long **B, long n, long m, long x, long y) {
	long i, j, k, l;
	for (i = 0; i < n - x + 1; i++) {
		for (j = 0; j < m - y + 1; j++) {
			if (A[i][j] == B[0][0]) {
				for (k = 0; k < x; k++) {
					for (l = 0; l < y; l++) {
						if (A[i + k][j + l] != B[k][l]) break;
					}
					if (l != y) break;
				}
				if (k == x) {
					printf("Sous Matrice Trouvee %ld %ld\n", i, j);
					return;
				}
			}
		}
	}
	printf("Non trouvee\n");
	return;
}

void sousMat2(long **A, long **B, long n, long m, long x, long y) {
	long i, j, k, l;
	long start, end, half;
	for (i = 0; i < n - x + 1; i++) {
		start = 0;
		end = m - y;
		j = -1;
		while (start < end) {
			half = (start + end) / 2;
			if (A[i][half] == B[0][0]) {
				j = half;
				break;
			} else if (A[i][half] < B[0][0])
				start = half + 1;
			else
				end = half - 1;
		}
		if (A[i][start] == B[0][0]) j = start;
		if (A[i][end] == B[0][0]) j = end;
		if (j != -1) {
			for (k = 0; k < x; k++) {
				for (l = 0; l < y; l++) {
					if (A[i + k][j + l] != B[k][l]) break;
				}
				if (l != y) break;
			}
			if (k == x) {
				printf("Sous Matrice Trouvee %ld %ld\n", i, j);
				return;
			}
		}
	}
	printf("Non trouvee\n");
	return;
}

int main() {
	LARGE_INTEGER deb, fin, freq;
	double tempExec, tempExecEnSeconds;
	long i, j, k;
	long **A, **B, **C, **D;
	long N[16] = {1600, 1800, 2000, 2200, 2400, 2600, 2800, 3000,
				  3000, 3000, 3000, 3000, 3000, 3000, 3000, 3000};
	long M[16] = {1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300,
				  1400, 1600, 1800, 2000, 2200, 2400, 2600, 2800};
	double t[16], tt[16];
	clock_t t1, t2;
	A = (long **)malloc(MAX * sizeof(long *));
	B = (long **)malloc(MAX * sizeof(long *));
	C = (long **)malloc(MAX * sizeof(long *));
	D = (long **)malloc(MAX * sizeof(long *));
	for (i = 0; i < MAX; i++) {
		A[i] = (long *)malloc(MAX * sizeof(long));
		B[i] = (long *)malloc(MAX * sizeof(long));
		C[i] = (long *)malloc(MAX * sizeof(long));
		D[i] = (long *)malloc(MAX * sizeof(long));
	}
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			A[i][j] = ((i + j) % 5) + 1;
		}
	}
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			C[i][j] = j - 10;
		}
	}
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			B[i][j] = ((i + j) % 5) + 1;
		}
	}
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			D[i][j] = 0;
		}
	}
	for (i = 0; i < 16; i++) {
		long temp1 = A[M[i]][M[i]];
		long temp2 = B[M[i]][M[i]];
		long temp3 = A[M[i]][M[i]];
		long temp4 = B[M[i]][M[i]];
		A[M[i]][M[i]] = 0;
		B[M[i]][M[i]] = 0;
		C[M[i]][M[i]] = 0;
		D[M[i]][M[i]] = 0;
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&deb);
		sousMat1(C, D, N[i], N[i], M[i], M[i]);
		QueryPerformanceCounter(&fin);
		tempExec = MILLI_S * (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		tempExecEnSeconds = (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		t[i] = tempExec;
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&deb);
		sousMat2(C, D, N[i], N[i], M[i], M[i]);
		QueryPerformanceCounter(&fin);
		tempExec = MILLI_S * (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		tempExecEnSeconds = (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		tt[i] = tempExec;
		printf("%lf\t%lf\n", t[i], tt[i]);
		A[M[i]][M[i]] = temp1;
		B[M[i]][M[i]] = temp2;
		C[M[i]][M[i]] = temp3;
		D[M[i]][M[i]] = temp4;
	}
}
