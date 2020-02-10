#include <stdio.h>
#include <string.h>
int main() {
	FILE *F;
	int i, j;
	float b;
	char X[21];
	F = fopen("Mots.txt", "w");
	b = 1;
	i = 1;
	do {
		gets(X);
		i++;
		if (strcmp(X, "*") != 0) {
			fprintf(F, "%s\n", X);
		} else {
			b = 0;
		}
	} while (b == 1 && i <= 50);
	fclose(F);
	i = 0;
	b = 0;
	F = fopen("Mots.txt", "r");
	fscanf(F, "%s", &X);
	while (!feof(F)) {
		b = b + strlen(X);
		i++;
		fscanf(F, "%s", &X);
	}
	printf("Nombre d'elements : %d\n", i);
	printf("Longueur moyenne : %f\n", b / i);
	fclose(F);
	char T[i][21];
	F = fopen("Mots.txt", "r");
	fscanf(F, "%s", &X);
	i = 0;
	while (!feof(F)) {
		strcpy(T[i], X);
		i++;
		fscanf(F, "%s", &X);
	}
	fclose(F);
	FILE *G;
	G = fopen("Mots10.txt", "w");
	for (j = 0; j < i; j++) {
		if (strlen(T[j]) >= 10) {
			strcpy(X, T[j]);
			fprintf(G, "%s\n", X);
		}
	}
}
