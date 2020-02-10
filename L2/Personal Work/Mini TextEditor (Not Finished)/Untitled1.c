#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
typedef struct texte {
	char *chaine;
	int longueur;
	int capacite;
} texte;

texte creer() {
	texte t;
	t.longueur = 0;
	t.capacite = 16;
	t.chaine = calloc(t.capacite, sizeof(char));
	return t;
}

void liberer(texte *t) { free(t->chaine); }

int taille(texte t) { return t.longueur; }

int capacite(texte t) { return t.capacite; }

char caractere(texte t, int pos) { return t.chaine[pos]; }

void modifierCapacite(texte *t, int minimum) {
	if (t->capacite <= minimum) {
		char *z;
		z = calloc(minimum + 1, sizeof(char));
		if (t->chaine != NULL) strcpy(z, t->chaine);
		free(t->chaine);
		if (t->chaine != NULL) t->chaine = z;
		t->capacite = minimum + 1;
	}
}

void ajouterCaractere(texte *t, char caractere) {
	if ((t->capacite) <= (t->longueur) + 1) {
		modifierCapacite(t, t->capacite);
	}
	*(t->chaine + t->longueur) = caractere;
	(t->longueur)++;
	*(t->chaine + t->longueur) = '\0';
}

void ajouterChaine(texte *t, char *str) {
	int i;
	for (i = 0; i < strlen(str); i++) ajouterCaractere(t, str[i]);
}

int position(texte t, char *str) {
	char *s = strstr(t.chaine, str);
	if (s == NULL) return -1;
	return t.longueur - strlen(s);
}
int dernierePosition(texte t, char *str) {
	int i, l = strlen(str);
	char rts[l];
	for (i = 0; i < l; i++) rts[i] = str[l - i - 1];
	rts[l] = '\0';
	strrev(t.chaine);
	i = position(t, rts);
	strrev(t.chaine);
	if (i == -1) return -1;
	return strlen(t.chaine) - l - i;
}

void insereChaine(texte *t, char *str, int debut) {
	char *s;
	char *f;
	int i;
	if (debut > (t->longueur)) {
		ajouterChaine(t, str);
	} else {
		if (debut < 0) debut = 0;
		s = calloc(debut, sizeof(char));
		f = calloc(t->longueur - debut, sizeof(char));
		for (i = 0; i < debut; i++) s[i] = *(t->chaine + i);
		int j = 0;
		for (i = debut; i < t->longueur; i++) {
			f[j] = *(t->chaine + i);
			j++;
		}
		s[debut] = '\0';
		f[t->longueur - debut] = '\0';
		t->longueur = 0;
		ajouterChaine(t, s);
		ajouterChaine(t, str);
		ajouterChaine(t, f);
	}
}

void modifierCapacite2(texte *t, int minimum) {
	if (t->capacite <= minimum) {
		char *z;
		z = calloc(minimum * 2, sizeof(char));
		if (t->chaine != NULL) strcpy(z, t->chaine);
		liberer(t);
		if (t->chaine != NULL) t->chaine = z;
		t->capacite = minimum * 2;
	}
}

//  Les Listes
typedef struct Element Element;
typedef struct Element {
	texte info;
	Element *suivant;
} Liste;
Liste *initialisation() {
	Liste *liste = malloc(sizeof(*liste));
	Element *element = malloc(sizeof(*element));
	element->info = creer();
	element->suivant = NULL;
	return liste;
}
void insertion(Liste *liste, texte nouv) {
	/* Création du nouvel élément */
	Element *nouveau = malloc(sizeof(*nouveau));

	nouveau->info = nouv;
	nouveau->suivant = NULL;
	/* Insertion de l'élément a la fin de la liste */
	liste->suivant = nouveau;
}
// Les Piles
typedef struct {
	texte tab[N];
	int sommet;
} Pile;
Pile initpile() {
	Pile p;
	p.sommet = -1;
	return p;
}
int PileVide(Pile p) { return (p.sommet == -1); }
int PilePleine(Pile p) { return (p.sommet == N - 1); }
int Empiler(Pile *p, texte x) {
	if (PilePleine(*p)) return 0;
	p->tab[++(p->sommet)] = x;
	return 1;
}
void depiler(Pile *p, texte *x) {
	if (!PileVide(*p)) *x = p->tab[p->sommet--];
}

// Les Files
typedef struct {
	texte T[N];
	int queue, tete;
} file;
file initfile() {
	file F;
	F.queue = -1;
	F.tete = -1;
	return F;
}
int filevide(file f) { return f.tete == 0; }
void enfiler(file *F, texte x) {
	(*F).queue++;
	(*F).T[(*F).queue] = x;
	if (filevide(*F)) (*F).tete++;
}

// Fin des Structures

main() {
	char c;
	int SC;
structure:
	system("cls");
	printf("\tChoisir la structure a implementer:\n");
	printf("1-Les Liste Lineaires\n");
	printf("2-Les Piles\n");
	printf("3-Les Files\n");
	printf("4-Quitter\n");
	printf("\tVotre Choix:\t");
	scanf(" %c", &c);
	switch (c) {
		case '1':
			printf("Listes Lineaires Choisees\n");
			system("pause");
			SC = 1;
			break;
		case '2':
			printf("Piles Choisees\n");
			system("pause");
			SC = 2;
			break;
		case '3':
			printf("Files Choisees\n");
			system("pause");
			SC = 3;
			break;
		case '4':
			break;
		default:
			goto structure;
	}
	if (c != '4') {
		file f = initfile();
		Pile p = initpile();
		Liste *l = initialisation();
		texte t = creer();
		char Car;
		char *Ch;
		int debut;
	choix:
		system("cls");
		printf("1-Ajouter Caractere\n");
		printf("2-Ajouter Chaine\n");
		printf("3-Inserer une Chaine a une position donnee\n");
		printf("4-Afficher la premiere occurence d'une chaine donnee\n");
		printf("5-Afficher la derniere occurence d'une chaine donnee\n");
		printf("6-Menu Principale\n");
		printf("7-Quitter\n");
		printf("\tVotre Choix:\t");
		scanf(" %c", &c);
		switch (c) {
			case '1':
				system("cls");
				printf("Ecrire le caractere a inserer:\t");
				scanf(" %c", &Car);
				if (SC == 1) {
					insertion(l, t);
				} else if (SC == 2) {
					Empiler(&p, t);
				} else if (SC == 3) {
					enfiler(&f, t);
				}
				ajouterCaractere(&t, Car);
				printf("La chaine : \t %s \n\n", t.chaine);
				system("pause");
				goto choix;
				break;
			case '2':
				system("cls");
				printf("Ecrire la chaine a ajouter : \t");
				scanf("%s", &Ch);
				if (SC == 1) {
					insertion(l, t);
				} else if (SC == 2) {
					Empiler(&p, t);
				} else if (SC == 3) {
					enfiler(&f, t);
				}
				ajouterChaine(&t, &Ch);
				printf("La chaine : \t %s \n\n", t.chaine);
				system("pause");
				goto choix;
				break;
			case '3':
				system("cls");
				printf("Ecrire la chaine a ajouter : \t");
				scanf("%s", &Ch);
				printf("Entrer la position ou l'inserer : \t");
				scanf("%d", &debut);
				if (SC == 1) {
					insertion(l, t);
				} else if (SC == 2) {
					Empiler(&p, t);
				} else if (SC == 3) {
					enfiler(&f, t);
				}
				insereChaine(&t, &Ch, debut);
				printf("La chaine : \t %s \n\n", t.chaine);
				system("pause");
				goto choix;
				break;
			case '4':
				system("cls");
				printf(
					"Ecrire la chaine dont on veut la position de la 1ere "
					"occurence : \t");
				scanf("%s", &Ch);
				if (SC == 1) {
					insertion(l, t);
				} else if (SC == 2) {
					Empiler(&p, t);
				} else if (SC == 3) {
					enfiler(&f, t);
				}
				if (position(t, &Ch) != -1)
					printf(
						"La Premiere occurence de %s debute dans chaine[%d]\n",
						&Ch, position(t, &Ch));
				else
					printf("La chaine %s n'existe pas\n", &Ch);
				system("pause");
				goto choix;
				break;
			case '5':
				system("cls");
				printf(
					"Ecrire la chaine dont on veut la derniere de la 1ere "
					"occurence : \t");
				scanf("%s", &Ch);
				if (SC == 1) {
					insertion(l, t);
				} else if (SC == 2) {
					Empiler(&p, t);
				} else if (SC == 3) {
					enfiler(&f, t);
				}
				if (dernierePosition(t, &Ch) != -1)
					printf(
						"La Derniere occurence de %s debute dans chaine[%d]\n",
						&Ch, dernierePosition(t, &Ch));
				else
					printf("La chaine %s n'existe pas\n", &Ch);
				system("pause");
				goto choix;
				break;
			case '6':
				goto structure;
				break;
			case '7':
				break;
			case 'z':
				if (SC == 2) {
					depiler(&p, &t);
					system("pause");
				}
			default:
				goto choix;
				break;
		}
	}
	return 0;
}
