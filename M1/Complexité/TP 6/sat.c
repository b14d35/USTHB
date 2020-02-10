#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afficher(int n, int m, int Mat[n][m]) {
	int i, j;
	for (int i = 0; i < n; i++) {
		printf("(");
		for (j = 0; j < m; j++) {
			if (Mat[i][j] == 0)
				printf("non[%d]", j);
			else
				printf("[%d]", j);
			if (j != m - 1) printf(" or ");
		}
		printf(")");
		if (i != n - 1) printf(" and ");
	}
	printf("\n");
}
// Version 1 - on envoi la matrice et une valear
// Complexit� au pire cas : O(nm)
int version1(int n, int m, int Mat[n][m], int *T) {
	int i, j;
	for (i = 0; i < n; i++) {
		j = 0;
		while ((Mat[i][j] != T[j]) && j < m) j++;
		if (j == m) return 0;
	}
	return 1;
}

void incremente(int *T, int m) {
	int i = m - 1;
	while (i >= 0) {
		if (T[i] == 0) {
			T[i] = 1;
			break;
		} else {
			T[i] = 0;
			i--;
		}
	}
}
// Version 2 - on dit si le probl�me est satisfaisable
// Complexit� au pire cas : O(mn�)
int version2(int n, int m, int Mat[n][m]) {
	int *T;
	long i, pos = pow(2, m);
	// Cas tr�s speciale
	if (n < pos) return 1;
	T = (int *)malloc(m * sizeof(int));
	for (i = 0; i < m; i++) T[i] = 0;
	for (i = 0; i < pos; i++) {
		int x = version1(n, m, Mat, T);
		if (x == 1)
			return 1;
		else
			incremente(T, m);
	}
	// Pas de solution
	return 0;
}
// Version 2 - on dit si le probl�me est satisfaisable en affichant toutes les
// solutions Complexit� au pire cas : O(mn�)
int version3(int n, int m, int Mat[n][m]) {
	long pos = pow(2, m);
	int *T;
	long i;
	int nb_s = 0;
	T = (int *)malloc(m * sizeof(int));
	for (i = 0; i < m; i++) T[i] = 0;
	for (i = 0; i < pos; i++) {
		int x = version1(n, m, Mat, T);
		if (x == 1) {
			for (int j = 0; j < m; j++) printf("%d ", T[j]);
			printf("\n");
			nb_s++;
		}
		incremente(T, m);
	}
	if (nb_s > 0) return 1;
	return 0;
}
int main() {
	int N = 6;
	int M = 3;
	int i;
	int Mat[6][3] = {{1, 1, 1}, {0, 1, 1}, {1, 0, 1},
					 {0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
	afficher(N, M, Mat);
	int x = version2(N, M, Mat);
	if (x == 0) {
		printf("Probleme non satisfaisable\n");
	} else {
		printf("Probleme satisfaisable\n");
	}
}
