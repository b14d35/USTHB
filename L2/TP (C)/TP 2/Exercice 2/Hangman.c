#include <stdio.h>
#include <string.h>
void rempl(char c[], int n, char *c1) {
	int i;
	for (i = 0; i < n; i++) {
		c1[i] = '-';
	}
}
void maj(char *c, int n) {
	int i;
	for (i = 0; i < n; i++) {
		c[i] = toupper(c[i]);
	}
}
void alpha(char *c) {
	int i;
	for (i = 0; i < 26; i++) {
		c[i] = 'A' + i;
	}
}
void aff(int e, char *c, char *c1) {
	int i;
	printf("Try left:\t%d\n", e);
	printf("Alphabet:\t");
	for (i = 0; i < 26; i++) {
		printf("%c", c[i]);
	}
	printf("\nMot:\t%s\n", c1);
}
void init(char *A, char *B, char *C) {
	int i;
	for (i = 0; i < 26; i++) {
		A[i] = 0;
		B[i] = 0;
		C[i] = 0;
	}
	for (i = 26; i < 30; i++) {
		B[i] = 0;
		C[i] = 0;
	}
}
void menu() {
	printf("\n1-Save a game\n");
	printf("2-Load saved game\n\n");
}
main() {
	char A[26], Mot[30], Motc[30], ch;
	int i, e, c, t;
	FILE *F;
AG:
	init(A, Mot, Motc);
	alpha(A);
	printf("Give a word:\t");
	scanf("%s", Mot);
	t = strlen(Mot);
	maj(Mot, t);
	rempl(Mot, t, Motc);
	e = 10;
	for (i = 0; i < 20; i++) {
		printf("\n\n\n");
	}
DG:
	menu();
	aff(e, A, Motc);
LE:
	printf("\nChoose a letter:\t");
	do {
		scanf("%c", &ch);
		ch = toupper(ch);
		if (ch == '1' || ch == '2') {
			switch (ch) {
				case '1':
					F = fopen("Saved.txt", "w");
					fprintf(F, "%d\n", e);
					fprintf(F, "%s\n", Mot);
					fprintf(F, "%s\n", Motc);
					for (i = 0; i < 26; i++) {
						fprintf(F, "%c", A[i]);
					}
					fprintf(F, "\n");
					fclose(F);
					printf("\n\tGame saved sucessfullt\n");
					break;
				case '2':
					init(A, Mot, Motc);
					F = fopen("Saved.txt", "r");
					fscanf(F, "%d\n", &e);
					fscanf(F, "%s\n", Mot);
					fscanf(F, "%s\n", Motc);
					for (i = 0; i < 26; i++) {
						fscanf(F, "%c", &A[i]);
					}
					fclose(F);
					printf("\n\tGame loaded sucessfullt\n");
					aff(e, A, Motc);
					break;
			}
		}
	} while (ch < 'A' || ch > 'Z');
	if (A[ch - 'A'] == '-') {
		printf("Already used");
		goto LE;
	}
	A[ch - 'A'] = '-';
	c = 0;
	for (i = 0; i < t; i++) {
		if (Mot[i] == ch) {
			Motc[i] = ch;
			c = 1;
		}
	}
	if (c == 0) {
		e--;
	}
	if (strcmpi(Mot, Motc) == 0) {
		printf("CONGRATULATIONS The word was : %s\n", Mot);
	} else {
		if (e > 0) {
			goto DG;
		} else {
			printf("GAME OVER The word was : %s\n", Mot);
		}
	}
	printf("\n\tPlay again\n1-Oui\t2-Non\n\tChoix:\t");
	do {
		scanf("%c", &ch);
	} while (ch != '1' && ch != '2');
	if (ch == '1') {
		goto AG;
	}
}
