#include <stdio.h>
int main() {
	FILE *FA, *FB, *FC;
	int i, j, k, N, M;
	float t, x;
	char X[20], Y[20], Z[20];
	printf("Name of the file 1\n");
	gets(X);
	strcat(X, ".txt");
	printf("Name of the file 2\n");
	gets(Y);
	strcat(Y, ".txt");

	// gets(Z);

	do {
		printf("Taille file 1\n");
		scanf("%d", &N);
	} while (N < 1);

	printf("Remplissage file 1\n");
	FA = fopen(X, "w");
	scanf("%f", &t);
	fprintf(FA, "%f\n", t);
	x = t;
	for (i = 1; i < N; i++) {
		do {
			scanf("%f", &t);
		} while (t < x);
		fprintf(FA, "%f\n", t);
	}
	fclose(FA);

	do {
		printf("Taille file 2\n");
		scanf("%d", &M);
	} while (M < 1);

	printf("Remplissage file 2\n");
	FB = fopen(Y, "w");
	scanf("%f", &t);
	fprintf(FB, "%f\n", t);
	x = t;
	for (i = 1; i < M; i++) {
		do {
			scanf("%f", &t);
		} while (t < x);
		fprintf(FB, "%f\n", t);
	}
	fclose(FB);
	float TABA[N];
	FA = fopen(X, "r");
	fscanf(FA, "%f", &t);
	i = 0;
	while (!feof(FA)) {
		TABA[i] = t;
		i++;
		fscanf(FA, "%f", &t);
	}
	fclose(FA);
	float TABB[M];
	FB = fopen(Y, "r");
	fscanf(FB, "%f", &t);
	i = 0;
	while (!feof(FB)) {
		TABB[i] = t;
		i++;
		fscanf(FB, "%f", &t);
	}
	fclose(FB);
	float TABC[N + M];
	i = 0;
	j = 0;
	k = 0;
	while (k <= N + M) {
		if (TABA[i] < TABB[j]) {
			TABC[k] = TABA[i];
			i++;
			k++;
			if (i == N) {
				for (i = j; i < M; i++) {
					TABC[k] = TABB[i];
					k++;
				}
			}
		} else {
			TABC[k] = TABB[j];
			j++;
			k++;
			if (j == M) {
				for (j = i; j < N; j++) {
					TABC[k] = TABA[j];
					k++;
				}
			}
		}
	}
	printf("Name of the file 3\n");
	scanf("%s", Z);
	strcat(Z, ".txt");
	FC = fopen(Z, "w");
	for (i = 0; i < N + M; i++) {
		fprintf(FC, "%f\n", TABC[i]);
	}
	fclose(FC);
}
