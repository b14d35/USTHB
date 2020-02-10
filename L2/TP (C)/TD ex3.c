#include <stdio.h>
#include <stdlib.h>
void remplir(int *e, int N) {
	int i, x;
	printf("Remplissage des valeurs:\n");
	for (i = 0; i < N; i++) {
		scanf("%d", &x);
		if (x >= 0 && x <= N) {
			e[x] = 1;
		}
	}
}
void afficherEnsemble(int *e, int N) {
	int i;
	for (i = 0; i <= N; i++) {
		printf("%d|", e[i]);
	}
	printf("\n");
}
int appartient(int *e, int x, int N) {
	if (x >= 0 && x <= N && e[x] == x) {
		return 1;
	} else {
		return 0;
	}
}
void ajouter(int *e, int x, int N) { e[x] = 1; }
int *uni(int *e1, int *e2, int N) {
	int i, *e;
	e = calloc(N, sizeof(int));
	for (i = 0; i <= N; i++) {
		if (e1[i] == 1 || e2[i] == 1) {
			e[i] = 1;
		}
	}
	return e;
}
int *inter(int *e1, int *e2, int N) {
	int i, *e;
	e = calloc(N, sizeof(int));
	for (i = 0; i <= N; i++) {
		if (e1[i] == 1 && e2[i] == 1) {
			e[i] = 1;
		}
	}
	return e;
}
int *diffirence(int *e1, int *e2, int N) {
	int i, *e;
	e = calloc(N, sizeof(int));
	for (i = 0; i <= N; i++) {
		if (e1[i] == 1 && e2[i] == 0) {
			e[i] == 1;
		}
	}
	return e;
}
int *DifSym(int *A, int *B, int N) {
	int i, *e;
	e = calloc(N, sizeof(int));
	e = diffirence(uni(A, B, N), inter(A, B, N), N);
	return e;
}
main() {
	int N, M, *e1, *e2, *e;
	printf("Taille du tableau 1:\t");
	scanf("%d", &N);
	e1 = calloc(N, sizeof(int));
	remplir(e1, N);
	printf("Ens 1 : \n");
	afficherEnsemble(e1, N);
}
