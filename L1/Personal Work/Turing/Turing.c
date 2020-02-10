#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char ei, vi, vs, es;
} inst;
void affichage(inst T[], int N) {
	int i;
	for (i = 0; i < N; i++) {
		printf("%d:q%c %c %c q%c\n", i + 1, T[i].ei, T[i].vi, T[i].vs, T[i].es);
	}
}
int main() {
	int N, P, i, x, y, z, t, k;
	char choice;
	char A[300], B[300];
	printf("\t\t\tSection 07 Groupe 04 Promo 2015\n\n\n");
g:
	do {
		printf("Donnez le nombre d'instructions : \t");
		scanf("%d", &N);
	} while (N < 1);
	inst T[300];
	printf("Donnez les instructions : \n");
	for (i = 0; i < N; i++) {
		printf("Instruction %d :\n", i + 1);
		printf("Etat initial : \tq");
		do {
			scanf("%c", &T[i].ei);
		} while (T[i].ei == '\n');
		printf("valeur initial : \t");
		do {
			scanf("%c", &T[i].vi);
		} while (T[i].vi == '\n' || (T[i].vi != '0' && T[i].vi != '1' &&
									 T[i].vi != '*' && T[i].vi != '#'));
		printf("Valeur suivante : \t");
		do {
			scanf("%c", &T[i].vs);
			if (T[i].vs == 'g') {
				T[i].vs = 'G';
			} else if (T[i].vs == 'd') {
				T[i].vs = 'D';
			}
		} while (T[i].vs == '\n' ||
				 (T[i].vs != '0' && T[i].vs != '1' && T[i].vs != '*' &&
				  T[i].vs != 'G' && T[i].vs != 'D' && T[i].vs != '#'));
		printf("Etat suivant : \tq");
		do {
			scanf("%c", &T[i].es);
		} while (T[i].es == '\n');
	}
	affichage(T, N);
	system("pause");
p:
	printf("\n1-Remplissage des instructions\n");
	printf("2-Affichage des intructions\n");
	printf("3-Modifier une instruction\n");
	printf("4-Ajouter une instruction\n");
	printf("5-Supprimer une instruction\n");
	printf("6-Derouler un exemple\n");
	printf("7-Quitter\n");
	printf("Donnez votre choix : \t");
	do {
		scanf("%c", &choice);
	} while (choice == '\n' ||
			 (choice != '1' && choice != '2' && choice != '3' &&
			  choice != '4' && choice != '5' && choice != '6' &&
			  choice != '7'));
	switch (choice) {
		case '1':
			goto g;
			break;
		case '2':
			affichage(T, N);
			system("pause");
			break;
		case '3':
			printf("Donnez la position de l'instruction a changer : \t");
			do {
				scanf("%d", &P);
			} while (P < 1 || P > N);
			printf("Instruction %d :\n", P);
			P--;
			printf("Etat initial : \tq");
			do {
				scanf("%c", &T[P].ei);
			} while (T[P].ei == '\n');
			printf("valeur initial : \t");
			do {
				scanf("%c", &T[P].vi);
			} while (T[P].vi == '\n' || (T[P].vi != '0' && T[P].vi != '1' &&
										 T[P].vi != '*' && T[P].vi != '#'));
			printf("Valeur suivante : \t");
			do {
				scanf("%c", &T[P].vs);
				if (T[P].vs == 'g') {
					T[P].vs = 'G';
				} else if (T[P].vs == 'd') {
					T[P].vs = 'D';
				}
			} while (T[P].vs == '\n' ||
					 (T[P].vs != '0' && T[P].vs != '1' && T[P].vs != '*' &&
					  T[P].vs != 'G' && T[P].vs != 'D' && T[P].vs != '#'));
			printf("Etat suivant : \tq");
			do {
				scanf("%c", &T[P].es);
			} while (T[P].es == '\n');
			affichage(T, N);
			system("pause");
			break;
		case '4':
			printf("Etat initial : \tq");
			do {
				scanf("%c", &T[N].ei);
			} while (T[N].ei == '\n');
			printf("valeur initial : \t");
			do {
				scanf("%c", &T[N].vi);
			} while (T[N].vi == '\n' || (T[N].vi != '0' && T[N].vi != '1' &&
										 T[N].vi != '*' && T[N].vi != '#'));
			printf("Valeur suivante : \t");
			do {
				scanf("%c", &T[N].vs);
				if (T[N].vs == 'g') {
					T[N].vs = 'G';
				} else if (T[N].vs == 'd') {
					T[N].vs = 'D';
				}
			} while (T[N].vs == '\n' ||
					 (T[N].vs != '0' && T[N].vs != '1' && T[N].vs != '*' &&
					  T[N].vs != 'G' && T[N].vs != 'D' && T[N].vs != '#'));
			printf("Etat suivant : \tq");
			do {
				scanf("%c", &T[N].es);
			} while (T[N].es == '\n');
			N++;
			affichage(T, N);
			system("pause");
			break;
		case '5':
			printf("Donnez la position de l'instruction a supprimer : \t");
			do {
				scanf("%d", &P);
			} while (P < 1 || P > N);
			P--;
			N--;
			for (i = P; i < N; i++) {
				T[i] = T[i + 1];
			}
			affichage(T, N);
			system("pause");
			break;
		case '6':
			for (i = 0; i < 300; i++) {
				B[i] = '0';
			}
			A[100] = '0';
			printf("Donnez le nombre de variable (1,2,3) : \t");
			do {
				scanf("%d", &P);
			} while (P != 1 && P != 2 && P != 3);
			t = 100;
			switch (P) {
				case 3:
					printf("Donnez le nombre : \t");
					do {
						scanf("%d", &x);
					} while (x < 0);
					for (i = 0; i <= x; i++) {
						B[t + i] = '1';
					}
					B[t + x + 1] = '*';
					t = t + x + 2;
				case 2:
					printf("Donnez le nombre : \t");
					do {
						scanf("%d", &y);
					} while (y < 0);
					for (i = 0; i <= y; i++) {
						B[t + i] = '1';
					}
					B[t + y + 1] = '*';
					t = t + y + 2;
				case 1:
					printf("Donnez le nombre : \t");
					do {
						scanf("%d", &z);
					} while (z < 0);
					for (i = 0; i <= z; i++) {
						B[t + i] = '1';
					}
					break;
			}
			for (i = 0; i < 300; i++) {
				printf("%c|", B[i]);
			}
			t = 100;
		s:
			for (i = 0; i < N; i++) {
				if (A[t] == T[i].ei && B[t] == T[i].vi) {
					if (T[i].vs == '0' || T[i].vs == '1' || T[i].vs == '*' ||
						T[i].vs == '#') {
						B[t] = T[i].vs;
						A[t] = T[i].es;
						printf("\n\n");
						for (i = 0; i < 300; i++) {
							printf("%c|", B[i]);
						}
						printf("\n\n");
						system("pause");
						goto s;
					} else {
						if (T[i].vs == 'G') {
							t--;
							A[t] = T[i].es;
							printf("\n\n");
							for (k = 0; k < 300; k++) {
								printf("%c|", B[k]);
							}
							printf("\n\n");
							system("pause");
							goto s;
						} else if (T[i].vs == 'D') {
							t++;
							A[t] = T[i].es;
							printf("\n\n");
							for (k = 0; k < 300; k++) {
								printf("%c|", B[k]);
							}
							printf("\n\n");
							system("pause");
							goto s;
						}
					}
				}
			}
			printf("\n\n");
			for (i = 0; i < 300; i++) {
				printf("%c|", B[i]);
			}
			printf("\n\n");
			x = 0;
			for (i = 0; i < 300; i++) {
				if (B[i] == '1') {
					x++;
				} else if (B[i] == '*') {
					if (x > 0) {
						printf("%d * ", x - 1);
						x = 0;
					} else {
						printf(" * ");
					}
				} else if (x > 0 && B[i] == '0') {
					printf("%d\n\n", x - 1);
					break;
				}
			}
			for (i = 0; i < 300; i++) {
				if (B[i] == '1') {
					if (i != t) {
						printf(
							"Attention le curseur n'est pas sur le premier "
							"1\n\n");
					}
					break;
				}
			}
			system("pause");
			break;
		case '7':
			return 0;
			break;
	}
	goto p;
}
