#include <stdio.h>
void afficher(FILE *F) {
	int y;
	F = fopen("fEntier.txt", "r");
	do {
		fscanf(F, "%d", &y);
		printf("%d\n", y);
	} while (!feof(F));
	fclose(F);
}
int rechercher(FILE *F, int x) {
	int n, y;
	n = 0;
	F = fopen("fEntier.txt", "r");
	do {
		fscanf(F, "%d", &y);
		if (x == y) {
			n = 1;
		}
	} while (!feof(F) && n == 0);
	fclose(F);
	return n;
}
FILE *supprimer(int *n, int x, FILE *F) {
	int y, z;
	FILE *T;
	F = fopen("fEntier.txt", "r");
	T = fopen("temp.txt", "w");
	z = 0;
	do {
		fscanf(F, "%d", &y);
		if (y != x && z == 0) {
			fprintf(T, "%d", y);
			z = 1;
		} else if (y != x && z == 1) {
			fprintf(T, "\n%d", y);
		}
	} while (!feof(F));
	fclose(T);
	fclose(F);
	remove("fEntier.txt");
	rename("temp.txt", "fEntier.txt");
	(*n)--;
}
FILE *remplacer(FILE *F, int x) {
	int y, z;
	FILE *T;
	if (rechercher(F, x) == 0) {
		F = fopen("fEntier.txt", "a");
		fprintf(F, "\n%d", x);
		fclose(F);
	} else {
		F = fopen("fEntier.txt", "r");
		T = fopen("temp.txt", "w");
		z = 0;
		do {
			fscanf(F, "%d", &y);
			if (z == 0) {
				if (y == x) {
					fprintf(T, "%d", y * y);
				} else {
					fprintf(T, "%d", y);
				}
				z = 1;
			} else {
				if (y == x) {
					fprintf(T, "\n%d", y * y);
				} else {
					fprintf(T, "\n%d", y);
				}
			}
		} while (!feof(F));
		fclose(T);
		fclose(F);
		remove("fEntier.txt");
		rename("temp.txt", "fEntier.txt");
	}
}
main() {
	int choice, x, n, i;
	FILE *F;
top:
	printf("\nChoose what you want to do:\n");
	printf("\t1-Show content\n");
	printf("\t2-Search for a number\n");
	printf("\t3-Delete a group of numbers\n");
	printf("\t4-Replace a number\n");
	printf("\t5-Quit\n");
	printf("Your choice:\t");
	do {
		scanf("%d", &choice);
	} while (choice < 1 || choice > 5);
	switch (choice) {
		case 1:
			afficher(F);
			system("PAUSE");
			goto top;
			break;
		case 2:
			printf("\nEnter the number to search:\t");
			scanf("%d", &x);
			if (rechercher(F, x) == 1) {
				printf("The number %d exists\n", x);
			} else {
				printf("The number %d does not exists\n", x);
			}
			system("PAUSE");
			goto top;
			break;
		case 3:
			printf("\nGive the number of numbers to delete:\t");
			do {
				scanf("%d", &n);
			} while (n < 1);
			i = 0;
		bcl:
			i++;
			printf("Give the %d number to delete:\t", i);
			scanf("%d", &x);
			supprimer(&n, x, F);
			if (n > 0) {
				goto bcl;
			}
			system("PAUSE");
			goto top;
			break;
		case 4:
			printf("\nGive the number to replace:\t");
			scanf("%d", &x);
			remplacer(F, x);
			system("PAUSE");
			goto top;
			break;
		case 5:
			goto ends;
			break;
	}
ends:
	system("PAUSE");
}
