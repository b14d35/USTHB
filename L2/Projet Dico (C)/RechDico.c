#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "conio21/conio.c"
// Donne le nombre de mots existant dans le DICO
long taille(char *name) {
	long i = 0;
	FILE *dico;
	char temp[250];
	dico = fopen(name, "r");
	while (!feof(dico)) {
		fgets(temp, 250, dico);
		i = i + 1;
	}
	fclose(dico);
	return i;
}
// Retourne la position du char qui suit la ligne de la moiti� de begin et end
long half(char *name, long begin, long end) {
	FILE *dico;
	char temp[250];
	long t = (begin + end) / 2;
	dico = fopen(name, "r");
	fseek(dico, t, SEEK_SET);
	fgets(temp, 250, dico);
	return t + strlen(temp);
}
// Retourne la position d'un mot s'il existe, sinon retourne -1
long exists(char *word, char *name) {
	FILE *dico;
	long begin, end, mil, i;
	char desc[250], mot[30];
	dico = fopen(name, "r");
	begin = 0;
	fseek(dico, 0, SEEK_END);
	end = ftell(dico);
	do {
		mil = half(name, begin, end);
		fseek(dico, mil, SEEK_SET);
		fscanf(dico, "%s", mot);
		fgets(desc, 250, dico);
		if (strcmpi(word, mot) > 0) {
			begin = mil;
		} else if (strcmpi(word, mot) < 0) {
			end = mil;
		} else {
			return mil;
		}
	} while (begin <= end && half(name, begin, end) != end);
	if (half(name, begin, end) == end) {
	ici:
		fseek(dico, begin, SEEK_SET);
		fscanf(dico, "%s", mot);
		fgets(desc, 250, dico);
		if (strcmpi(word, mot) == 0) {
			return begin;
		}
		begin = begin + strlen(mot) + strlen(desc);
		if (begin <= end) goto ici;
	}
	fclose(dico);
	return -1;
}

void findw(char *word, char *name) {
	FILE *dico;
	char mot[250], desc[250];
	if (exists(word, name) == -1) {
		printf("%s ", word);
		delay("n'existe pas\n", 1);
	} else {
		dico = fopen(name, "r");
		fseek(dico, exists(word, name), SEEK_SET);
		fscanf(dico, "%s", mot);
		fgets(desc, 250, dico);
		strcat(mot, desc);
		delay(mot, 1);
		fclose(dico);
	}
}

void fpell(char *name, int i) {
	FILE *file, *dico;
	int c = 0;
	char m[30];
	file = fopen("Session.txt", "r");
	system("cls");
	textattr(3);
	cadre_aff(80, 10, 52, 5);
	textattr(11);
	gotoxy(55, 6);
	delay("Rouge = N'existe pas | Vert = Existe \n", 1);
	fscanf(file, "%s\n", m);
	while (!feof(file)) {
		c++;
		gotoxy(55, 6 + c);
		if (exists(m, name) == -1) {
			textattr(12);
			printf("%s\n", m);
		} else if (i == 1) {
			textattr(10);
			findw(m, name);
		} else {
			textattr(10);
			printf("%s\n", m);
		}
		fscanf(file, "%s\n", m);
	}
	fclose(file);
	remove("Session.txt");
}

void entete() {
	int i;
	gotoxy(75, 1);
	delay("Projet De Programmation En Lanquage C", 1);
	gotoxy(86, 3);
	delay("\tDICTIONNAIRE\n", 1);
	for (i = 1; i <= 189; i++) printf("_");
	printf("\n");
}
void dessine_menu(int x, int y) {
	gotoxy(x, y);
	printf(
		"%c%c%c%c%c   %c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c     %c%c%c%c   "
		"%c%c%c   %c%c%c",
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(x, y + 1);
	Sleep(100);
	printf(
		"%c%c%c%c%c%c %c%c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c    %c%c%c%c "
		"  %c%c%c   %c%c%c",
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(x, y + 2);
	Sleep(100);
	printf(
		"%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c        %c%c%c%c%c%c   %c%c%c%c   "
		"%c%c%c   %c%c%c",
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219, 219, 219, 219);
	gotoxy(x, y + 3);
	Sleep(100);
	printf(
		"%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c  "
		"%c%c%c%c   %c%c%c   %c%c%c",
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(x, y + 3);
	Sleep(100);
	printf(
		"%c%c%c  %c%c%c  %c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c %c%c%c%c "
		"  %c%c%c   %c%c%c",
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(x, y + 4);
	Sleep(100);
	printf(
		"%c%c%c   %c   %c%c%c   %c%c%c        %c%c%c%c  %c%c%c%c%c%c%c   "
		"%c%c%c   %c%c%c",
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219);
	gotoxy(x, y + 5);
	Sleep(100);
	printf(
		"%c%c%c       %c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c    %c%c%c%c%c   "
		"%c%c%c%c%c%c%c%c%c",
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(x, y + 6);
	Sleep(100);
	printf(
		"%c%c%c       %c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c     %c%c%c%c    "
		"%c%c%c%c%c%c%c ",
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
		219, 219, 219, 219, 219, 219, 219, 219);
}
void pied_de_page()

{
	int i;
	gotoxy(1, 35);
	for (i = 1; i <= 189; i++) printf("_");
	gotoxy(89, 37);
	delay("REALISE PAR:", 1);
	gotoxy(75, 39);
	textattr(10);
	delay("		b14d35		", 1);
	gotoxy(82, 41);
	textattr(11);
	delay("SECTION B   |   GROUPE 3", 1);
	gotoxy(89, 43);
	textattr(12);
	delay("ANNEE UNIVERSITAIRE : 2016/2017\n", 1);
	textattr(15);
	for (i = 1; i <= 189; i++) printf("_");
}

void cadre_aff(int l, int L, int x, int y) {
	int i;
	gotoxy(x, y);
	printf("%c", 201);
	gotoxy(x, y + L);
	printf("%c", 200);
	gotoxy(x + l, y);
	printf("%c", 187);
	gotoxy(x + l, y + L);
	printf("%c", 188);
	for (i = 1; i <= l - 1; i++) {
		gotoxy(x + i, y);
		printf("%c", 205);
		gotoxy(x + i, y + L);
		printf("%c", 205);
	}
	for (i = 1; i <= L - 1; i++) {
		gotoxy(x, y + i);
		printf("%c", 186);
		gotoxy(x + l, y + i);
		printf("%c", 186);
	}
}

int menu() {
	char *t[] = {
		"1-  CHOISIR UN AUTRE DICO                                             "
		"        ",
		"2-  EXISTENCE D'UN MOT                                                "
		"        ",
		"3-  AFFICHER UN MOT AVEC SA DEFINITION                                "
		"        ",
		"4-  CHERCHER PLUSIEURS MOTS                                           "
		"        ",
		"5-  CHERCHER PLUSIEURS MOTS AVEC LES DEFINITIONS                      "
		"        ",
		"6-  NOMBRE DE MOTS DANS CE DICO                                       "
		"        "};

	int n = 6;
	int i, j, quite = 1, quite2, y = 20, x = 55, choix;
	char c1, c2, c3, c4;
debut:
	entete();
	pied_de_page();
	textattr(15);
	dessine_menu(68, 8);
	textattr(255);
	for (i = 1; i <= strlen(t[0]) + 6; i++) {
		for (j = 1; j <= n + 4; j++) {
			gotoxy(x - 4 + i, y - 3 + j);
			printf("%c", 219);
		}
	}
	printf("\n");
	textcolor(15);

	for (i = 0; i < n; i++) {
		if (i == 0)
			textbackground(12);
		else
			textbackground(0);
		gotoxy(x, y + i);
		delay(t[i], 1);
	}
	i = 0;
	while (quite) {
		c1 = getch();
		if (c1 == 13 || c1 == 27) {
			if (c1 == 27) {
				quite2 = 1;
				choix = 1;
				gotoxy(1, y);
				textattr(0);
				system("cls");
				textattr(204);
				for (i = 1; i <= 46; i++) {
					for (j = 1; j <= 5; j++) {
						gotoxy(x + 13 + i, y - 3 + j);
						printf("%c", 219);
						Sleep(1);
					}
				}
				textattr(207);
				gotoxy(x + 15, y);
				delay("ETES VOUS SURE DE VOULOIR QUITTER ?!  (Y", 1);
				printf("%c", 92);
				delay("N) ", 1);
				gotoxy(109, y);
				textattr(143);
				printf("O");
				while (quite2) {
					c3 = getch();
					if (c3 == 13)
						quite2 = 0;
					else if (c3 == -32) {
						c4 = getch();
						if (c4 == 77 && choix == 1) {
							gotoxy(111, y);
							textattr(143);
							printf("N");
							gotoxy(109, y);
							textattr(207);
							printf("O");
							choix--;
						}
						if (c4 == 75 && choix == 0) {
							gotoxy(109, y);
							textattr(143);
							printf("O");
							gotoxy(111, y);
							textattr(207);
							printf("N");
							choix++;
						}
					}
				}

				textattr(15);
				if (choix == 1) {
					i = -1;
					quite = 0;
				} else
					goto debut;
			} else
				quite = 0;
		}

		else if (c1 == -32) {
			c2 = getch();
			if (c2 == 72) {
				if (i > 0) {
					gotoxy(x, i - 1 + y);
					textbackground(12);
					printf("%s\n", t[i - 1]);
					textbackground(0);
					gotoxy(x, i + y);
					printf("%s\n", t[i]);
					i--;
				} else {
					gotoxy(x, y + n - 1);
					textbackground(12);
					printf("%s\n", t[n - 1]);
					gotoxy(x, y);
					textbackground(0);
					printf("%s\n", t[0]);
					i = n - 1;
				}
			} else if (c2 == 80) {
				if (i < n - 1) {
					gotoxy(x, y + i + 1);
					textbackground(12);
					printf("%s\n", t[i + 1]);
					textbackground(0);
					gotoxy(x, y + i);
					printf("%s\n", t[i]);
					i++;
				} else {
					gotoxy(x, y);
					textbackground(12);
					printf("%s\n", t[0]);
					gotoxy(x, y + i);
					textbackground(0);
					printf("%s\n", t[i]);
					i = 0;
				}
			}
		}
	}
	if (i >= 0 && i <= 4) {
		textcolor(9);
		textbackground(10);
		gotoxy(x, y + i);
		delay(t[i], 1);
	}
	return i + 1;
}
int main() {
	int quite = 0, choix, c;
	char dic[20], mot[30], desc[250];
	FILE *t = NULL, *p = NULL;
	strcpy(dic, "MyDico.txt");
	system("mode con LINES=55 COLS=189");
	textattr(15);
	while (!quite) {
		choix = menu();
		textattr(0);
		system("cls");
		switch (choix) {
			case 1:
				textattr(3);
				cadre_aff(80, 10, 52, 5);
				textattr(11);
				gotoxy(55, 6);
				delay("Donnez le nom de votre dico:\t", 1);
				textattr(15);
				scanf("%s", dic);
				t = fopen(dic, "r");
				gotoxy(55, 8);
				if (t == NULL) {
					textattr(12);
					delay("Le nom du fichier n'existe pas\n", 1);
					exit(-1);
				} else {
					textattr(10);
					delay("Le Dico est charge avec sucees\n", 1);
				}
				textattr(15);
				gotoxy(70, 18);
				system("pause");
				break;
			case 2:
				textattr(3);
				cadre_aff(80, 10, 52, 5);
				textattr(11);
				gotoxy(55, 6);
				delay("Donnez votre mot:\t", 1);
				textattr(15);
				scanf("%s", mot);
				gotoxy(55, 8);
				if (exists(mot, dic) == -1) {
					textattr(12);
					delay("Ce mot n'existe pas n'existe pas\n", 1);
				} else {
					textattr(10);
					delay("Ce mot existe\n", 1);
				}
				textattr(15);
				gotoxy(70, 18);
				system("pause");
				break;
			case 3:
				textattr(3);
				cadre_aff(80, 10, 52, 5);
				textattr(11);
				gotoxy(55, 6);
				delay("Donnez votre mot:\t", 1);
				textattr(15);
				scanf("%s", mot);
				gotoxy(55, 8);
				if (exists(mot, dic) != -1) {
					textattr(10);
				} else {
					textattr(12);
				}
				findw(mot, dic);
				textattr(15);
				gotoxy(70, 18);
				system("pause");
				break;
			case 4:
			case 5:
				textattr(3);
				cadre_aff(80, 10, 52, 5);
				textattr(11);
				gotoxy(55, 6);
				delay("Remplissez le fichier (0 pour quitter)\n", 1);
				textattr(15);
				p = fopen("Session.txt", "w");
				c = 0;
				strcpy(mot, "1");
				while (strcmp(mot, "0") != 0) {
					gotoxy(55, 7 + c);
					scanf("%s", mot);
					fprintf(p, "%s\n", mot);
					c++;
				}
				fclose(p);
				fpell(dic, choix - 4);
				textattr(15);
				gotoxy(70, 18);
				system("pause");
				break;
			case 6:
				textattr(3);
				cadre_aff(80, 10, 52, 5);
				textattr(13);
				gotoxy(80, 10);
				delay("Nombre de mots est de : ", 1);
				printf("%d\n", taille(dic));
				textattr(15);
				gotoxy(70, 18);
				system("pause");
				break;
			case 0:
				quite = 1;
				textattr(12);
				cadre_aff(50, 5, 65, 17);
				gotoxy(72, 19);
				textattr(14);
				delay("MERCI POUR L'USAGE DU PROGRAMME", 1);
				gotoxy(70, 24);
				textattr(15);
				system("pause");
				break;
		}
		textattr(15);
		system("cls");
	}
	return 0;
}
