#include <stdio.h>
main() {
	FILE *F, *T;
	int x, y, n, i, z, choice;
amezwaru:
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
			F = fopen("fEntier.txt", "r");
			do {
				fscanf(F, "%d", &y);
				printf("%d\n", y);
			} while (!feof(F));
			fclose(F);
			system("PAUSE");
			goto amezwaru;
			break;
		case 2:
			F = fopen("fEntier.txt", "r");
			printf("\nEnter the number to search:\t");
			scanf("%d", &x);
			n = 0;
			do {
				fscanf(F, "%d", &y);
				if (x == y) {
					printf("The number %d exists\n", x);
					n = 1;
				}
			} while (!feof(F) && n == 0);
			if (n == 0) {
				printf("The number %d does not exists\n", x);
			}
			fclose(F);
			system("PAUSE");
			goto amezwaru;
			break;
		case 3:
			printf("\nGive the number of numbers to delete:\t");
			do {
				scanf("%d", &n);
			} while (n < 1);
			for (i = 1; i <= n; i++) {
				printf("Give the %d number to delete:\t", i);
				scanf("%d", &x);
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
			}
			system("PAUSE");
			goto amezwaru;
			break;
		case 4:
			printf("\nGive the number to replace:\t");
			scanf("%d", &x);
			F = fopen("fEntier.txt", "r");
			n = 0;
			do {
				fscanf(F, "%d", &y);
				if (x == y) {
					n = 1;
				}
			} while (!feof(F) && n == 0);
			fclose(F);
			if (n == 0) {
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
			system("PAUSE");
			goto amezwaru;
			break;
		case 5:
			goto angaru;
			break;
	}
angaru:
	system("PAUSE");
}
