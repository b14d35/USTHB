#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct auteur {
	char nom[20], prenom[20];
} auteur;
typedef struct livre {
	int code;
	auteur aut;
	char titre[30];
	int nbl;
} livre;
typedef struct membre {
	int mat;
	char nom[20], prenom[20];
	int emp[200];
	int empl[3];
} membre;
// Le livre est-il disponible?
int livreDisponible(int x) {
	FILE *L;
	livre temp;
	L = fopen("FMembres.dat", "r");
	fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
		   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre, &temp.nbl);
	while (!feof(L) && temp.code <= x) {
		if (temp.code == x) {
			fclose(L);
			return 1;
		}
		fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
			   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre,
			   &temp.nbl);
	}
	fclose(L);
	return 0;
}
// Ajouter une copie au fichier livre
void ajoutCopie(int x) {
	FILE *L, *T;
	livre temp;
	L = fopen("Flivres.txt", "r");
	T = fopen("Ltemp.txt", "w");
	fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
		   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre, &temp.nbl);
	while (!feof(L) && temp.code < x) {
		fprintf(T, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d\n",
				temp.code, temp.aut.nom, temp.aut.prenom, temp.titre, temp.nbl);
		fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
			   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre,
			   &temp.nbl);
	}
	if (temp.code == x) {
		temp.nbl++;
		printf("La copie a ete ajoute avec succes\n");
	} else {
		printf("Le livre n'existe pas\n");
	}
	fprintf(T, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d\n",
			temp.code, temp.aut.nom, temp.aut.prenom, temp.titre, temp.nbl);
	fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
		   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre, &temp.nbl);
	while (!feof(L)) {
		fprintf(T, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d\n",
				temp.code, temp.aut.nom, temp.aut.prenom, temp.titre, temp.nbl);
		fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
			   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre,
			   &temp.nbl);
	}
	fclose(T);
	fclose(L);
	remove("FLivres.txt");
	rename("Ltemp.dat", "FLivres.txt");
}
// Supprimer une copie au fichier livre
void suppCopie(int x) {
	FILE *L, *T;
	livre temp;
	L = fopen("Flivres.txt", "r");
	T = fopen("Ltemp.txt", "w");
	fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
		   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre, &temp.nbl);
	while (!feof(L) && temp.code < x) {
		fprintf(T, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d\n",
				temp.code, temp.aut.nom, temp.aut.prenom, temp.titre, temp.nbl);
		fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
			   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre,
			   &temp.nbl);
	}
	if (temp.code == x) {
		temp.nbl--;
		printf("La copie a ete ajoute avec succes\n");
	} else {
		printf("Le livre n'existe pas\n");
	}
	fprintf(T, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d\n",
			temp.code, temp.aut.nom, temp.aut.prenom, temp.titre, temp.nbl);
	fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
		   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre, &temp.nbl);
	while (!feof(L)) {
		fprintf(T, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d\n",
				temp.code, temp.aut.nom, temp.aut.prenom, temp.titre, temp.nbl);
		fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
			   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre,
			   &temp.nbl);
	}
	fclose(T);
	fclose(L);
	remove("FLivres.txt");
	rename("Ltemp.dat", "FLivres.txt");
}
// Emprunter le livre x pour l'étudiant m
void emprunterLivre(int m, int x) {
	FILE *M, *T;
	membre s;
	int i;
	if (livreDisponible(x) == 1) {
		M = fopen("FMembres.dat", "rb");
		T = fopen("Mtemp.dat", "wb");
		fread(&s, sizeof(membre), 1, M);
		while (s.mat < m && !feof(M)) {
			fwrite(&s, sizeof(membre), 1, T);
			fread(&s, sizeof(membre), 1, M);
		}
		if (s.mat == m) {
			if (s.empl[0] == x || s.empl[1] == x || s.empl[2] == x)
				printf("Ce livre est deja emprunte par cet etudiant\n");
			else if (s.empl[0] == 0 || s.empl[1] == 0 || s.empl[2] == 0) {
				for (i = 0; i < 200; i++) {
					if (s.emp[i] == 0 || s.emp[i] == x) {
						if (s.emp[i] == x) {
							printf(
								"Le livre ne peut etre emprunte qu'une seule "
								"fois\n");
						} else {
							s.emp[i] = x;
							suppCopie(x);
							for (i = 0; i < 3; i++) {
								if (s.empl[i] == 0) {
									s.empl[i] = x;
									break;
								}
							}
							break;
						}
					}
				}
			} else {
				printf("Cet etudiant ne peux plus emprunter de livre");
			}
		} else {
			printf("L'etudiant portant le matricule %d n'existe pas\n", m);
		}
		fprintf(T, "\n", s);
		fread(&s, sizeof(membre), 1, M);
		while (!feof(M)) {
			fwrite(&s, sizeof(membre), 1, T);
			fread(&s, sizeof(membre), 1, M);
		}
		fclose(M);
		fclose(T);
		remove("FMembres.Dat");
		rename("Mtemp.dat", "FMembres.Dat");
	} else {
		printf("Livre non disponible\n");
	}
}
// Rendre un Livre
void rendreLivre(int m, int x) {
	FILE *M, *T;
	membre s;
	int i;
	if (livreDisponible(x) == 1) {
		M = fopen("FMembres.dat", "rb");
		T = fopen("Mtemp.dat", "wb");
		fread(&s, sizeof(membre), 1, M);
		while (s.mat < m && !feof(M)) {
			fwrite(&s, sizeof(membre), 1, T);
			fread(&s, sizeof(membre), 1, M);
		}
		if (s.mat == m) {
			if (s.empl[0] == x || s.empl[1] == x || s.empl[2] == x) {
				for (i = 0; i < 3; i++) {
					if (s.empl[i] == x) {
						s.empl[i] = 0;
						ajoutCopie(x);
						printf("Le livre a ete rendu avec succes\n");
						break;
					}
				}
			} else {
				printf("Ce livre n'est pas emprunte par cet etudiant\n");
			}
		}
		fprintf(T, "\n", s);
		fread(&s, sizeof(membre), 1, M);
		while (!feof(M)) {
			fwrite(&s, sizeof(membre), 1, T);
			fread(&s, sizeof(membre), 1, M);
		}
		fclose(M);
		fclose(T);
		remove("FMembres.Dat");
		rename("Mtemp.dat", "FMembres.Dat");
	} else {
		printf("Livre non disponible\n");
	}
}
// Les livres empruntés par l'étudiant
void livresEmp(int m) {
	FILE *M, *L;
	membre s;
	livre temp;
	M = fopen("FMembres.dat", "rb");
	fread(&s, sizeof(membre), 1, M);
	while (s.mat < m && !feof(M)) {
		fread(&s, sizeof(membre), 1, M);
	}
	if (s.mat == m) {
		L = fopen("Flivres.txt", "r");
		fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
			   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre,
			   &temp.nbl);
		while (!feof(L)) {
			if (temp.code == s.empl[0] || temp.code == s.empl[1] ||
				temp.code == s.empl[3]) {
				printf(
					"Code:%d - Nom Auteur:%s - Prenom Auteur:%s - Titre:%s\n",
					temp.code, temp.aut.nom, temp.aut.prenom, temp.titre);
			}
			fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
				   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre,
				   &temp.nbl);
		}
		fclose(L);
	} else {
		printf("Cet etudiant n'existe pas\n");
	}
}
// Ajoute un étudiant à membres
void ajoutEtud(membre x) {
	FILE *M, *T;
	membre s;
	int i = 0;
	livre temp;
	M = fopen("FMembres.dat", "rb");
	T = fopen("Mtemp.dat", "wb");
	fread(&s, sizeof(membre), 1, M);
	while (s.mat < x.mat && !feof(M)) {
		i++;
		fwrite(&s, sizeof(membre), 1, T);
		fread(&s, sizeof(membre), 1, M);
	}
	if (i == 0) {
		fwrite(&x, sizeof(membre), 1, T);
	} else {
		if (s.mat == x.mat) {
			printf("Cet etudiant existe deja\n");
		} else {
			fwrite(&x, sizeof(membre), 1, T);
			printf("L'etudiant a ete ajoute avec succes");
		}
		fwrite(&s, sizeof(membre), 1, T);
		fread(&s, sizeof(membre), 1, M);
		while (!feof(M)) {
			printf("7");
			fwrite(&s, sizeof(membre), 1, T);
			fread(&s, sizeof(membre), 1, M);
		}
	}
	fclose(M);
	fclose(T);
	remove("FMembres.Dat");
	rename("Mtemp.dat", "FMembres.Dat");
}
// Supprimer un étudiant de membres
void suppEtud(int m) {
	FILE *M, *T;
	membre s;
	int i;
	M = fopen("FMembres.dat", "rb");
	T = fopen("Mtemp.dat", "wb");
	fread(&s, sizeof(membre), 1, M);
	while (s.mat < m && !feof(M)) {
		fwrite(&s, sizeof(membre), 1, T);
		fread(&s, sizeof(membre), 1, M);
	}
	if (s.mat == m) {
		for (i = 0; i < 3; i++) {
			if (s.empl[i] != 0) ajoutCopie(s.empl[i]);
		}
		printf("L'etudiant a ete supprime avec succes\n");
	} else {
		printf("L'etudiant n'existe pas\n");
		fprintf(T, "\n", s);
	}
	fread(&s, sizeof(membre), 1, M);
	while (!feof(M)) {
		fwrite(&s, sizeof(membre), 1, T);
		fread(&s, sizeof(membre), 1, M);
	}
	fclose(M);
	fclose(T);
	remove("FMembres.Dat");
	rename("Mtemp.dat", "FMembres.Dat");
}
// Ajouter un livre
void ajoutLivre(livre x) {
	FILE *L, *T;
	livre temp;
	int i = 0;
	L = fopen("Flivres.txt", "r");
	rewind(L);
	fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
		   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre, &temp.nbl);
	while (!feof(L)) {
		i++;
		fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
			   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre,
			   &temp.nbl);
	}
	fclose(L);
	if (i == 0) {
		L = fopen("Flivres.txt", "a");
		fprintf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d\n",
				x.code, x.aut.nom, x.aut.prenom, x.titre, x.nbl);
		printf("Le livre a ete ajotee avec succes\n");
		fclose(L);
	} else if (i < 200) {
		L = fopen("Flivres.txt", "r");
		T = fopen("Ltemp.txt", "w");
		fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
			   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre,
			   &temp.nbl);
		while (!feof(L) && temp.code < x.code) {
			fprintf(
				T, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d\n",
				temp.code, temp.aut.nom, temp.aut.prenom, temp.titre, temp.nbl);
			fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
				   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre,
				   &temp.nbl);
		}
		if (temp.code == x.code) {
			printf("Le livre existe deja\n");
		} else {
			fprintf(T,
					"Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d\n",
					x.code, x.aut.nom, x.aut.prenom, x.titre, x.nbl);
			printf("Le livre a ete ajotee avec succes\n");
			if (!feof(L)) {
				fprintf(
					T,
					"Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d\n",
					temp.code, temp.aut.nom, temp.aut.prenom, temp.titre,
					temp.nbl);
				fscanf(
					L,
					"Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
					&temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre,
					&temp.nbl);
				while (!feof(L)) {
					fprintf(T,
							"Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - "
							"NbExmp:%d\n",
							temp.code, temp.aut.nom, temp.aut.prenom,
							temp.titre, temp.nbl);
					fscanf(L,
						   "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - "
						   "NbExmp:%d",
						   &temp.code, &temp.aut.nom, &temp.aut.prenom,
						   &temp.titre, &temp.nbl);
				}
			}
		}
		fclose(T);
		fclose(L);
		remove("FLivres.txt");
		rename("Ltemp.txt", "FLivres.txt");
	} else {
		printf("Le nombre max de livres a ete atteint\n");
	}
}
// Affichage des livres 4 à la fois puis continuer ou pas
void afficheLivres() {
	FILE *L;
	livre temp;
	int i;
	char x;
	L = fopen("Flivres.txt", "r");
	i = 0;
	x = 1;
	fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
		   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre, &temp.nbl);
	while (!feof(L) && x == '1') {
		i++;
		printf(
			"Code:%d - Nom Auteur:%s - Prenom Auteur:%s - Titre:%s - "
			"NbExmp:%d\n",
			temp.code, temp.aut.nom, temp.aut.prenom, temp.titre, temp.nbl);
		fscanf(L, "Code:%d - NomAut:%s - PrenAut:%s - Titre:%s - NbExmp:%d",
			   &temp.code, &temp.aut.nom, &temp.aut.prenom, &temp.titre,
			   &temp.nbl);
		if (i % 4 == 0) {
			printf("Continuer (1-OUI) :\t");
			scanf("%c", &x);
		}
	}
	fclose(L);
}
// Affichage des membres 4 à la fois puis continuer ou pas
void afficheMembres() {
	FILE *M;
	membre s;
	int i;
	char x;
	M = fopen("FMembres.dat", "rb");
	i = 0;
	x = '1';
	fread(&s, sizeof(membre), 1, M);
	while (!feof(M) && x == '1') {
		i++;
		printf("Nom:%s - Prenom:%s - Matricule:%d", s.nom, s.prenom, s.mat);
		fread(&s, sizeof(membre), 1, M);
		if (i % 4 == 0) {
			printf("Continuer (1-OUI) :\t");
			scanf("%c", &x);
		}
	}
	fclose(M);
}
main() {
	FILE *M, *L;
	livre l;
	membre s;
	char choix;
	int i, c, x, y;
	M = fopen("FMembres.dat", "ab");
	close(M);
	L = fopen("FLivres.txt", "a");
	close(L);
// Menu qui appel toutes les fonctions ou sort du programme
menu:
	system("cls");
	printf("\t\tMenu Principale\n\n");
	printf("\t1-Affichage\n");
	printf("\t2-Gerer les memebres\n");
	printf("\t3-Gerer les livres\n");
	printf("\t4-Gerer les Emprunts\n");
	printf("\t5-Quitter\n");
	printf("\n\nVotre Choix : \t");
	scanf("%c", &choix);
	switch (choix) {
		case '1':
		menu1:
			system("cls");
			printf("\t\tAffichage\n\n");
			printf("\t1-Afficher les livres\n");
			printf("\t2-Afficher les membres\n");
			printf("\t3-Afficher les livres empruntes par un etudiant\n");
			printf("\t4-Menu Principale\n");
			printf("\t5-Quitter\n");
			printf("\n\nVotre Choix : \t");
			scanf("%c", &choix);
			switch (choix) {
				case '1':
					system("cls");
					afficheLivres();
					system("pause");
					break;
				case '2':
					system("cls");
					afficheMembres();
					system("pause");
					break;
				case '3':
					system("cls");
					printf("Donnez la matricule de l'etudiant :\t");
					do {
						scanf("%d", &x);
					} while (x < 1);
					livresEmp(x);
					system("pause");
					break;
				case '4':
					goto menu;
					break;
				case '5':
					return 0;
					break;
			}
			goto menu1;
			break;
		case '2':
		menu2:
			system("cls");
			printf("\t\tGerer les memebres\n\n");
			printf("\t1-Ajout d'un etudiant\n");
			printf("\t2-Supprimer un etudiant\n");
			printf("\t3-Menu Principale\n");
			printf("\t4-Quitter\n");
			printf("\n\nVotre Choix : \t");
			scanf("%c", &choix);
			switch (choix) {
				case '1':
					system("cls");
					printf("Donnez le nom de l'etudiant:\t");
					scanf("%s", &s.nom);
					printf("Donnez le prenom de l'etudiant:\t");
					scanf("%s", &s.prenom);
					printf("Donnez le matricule de l'etudiant:\t");
					do {
						scanf("%d", &s.mat);
					} while (s.mat < 1);
					for (i = 0; i < 3; i++) {
						s.empl[i] = 0;
					}
					for (i = 0; i < 200; i++) {
						s.emp[i] = 0;
					}
					ajoutEtud(s);
					system("pause");
					break;
				case '2':
					system("cls");
					printf("Donnez le matricule de l'etudiant:\t");
					do {
						scanf("%d", &x);
					} while (x < 1);
					suppEtud(x);
					system("pause");
					break;
				case '3':
					goto menu;
					break;
				case '4':
					return 0;
					break;
			}
			goto menu2;
			break;
		case '3':
		menu3:
			system("cls");
			printf("\t\tGérer les livres\n\n");
			printf("\t1-Supprimer une copie d'un livre\n");
			printf("\t2-Ajouter une copie d'un livre\n");
			printf("\t3-Ajouter un livre\n");
			printf("\t4-Menu Principale\n");
			printf("\t5-Quitter\n");
			printf("\n\nVotre Choix : \t");
			scanf("%c", &choix);
			switch (choix) {
				case '1':
					system("cls");
					printf("Donnez le code du livre:\t");
					do {
						scanf("%d", &x);
					} while (x < 1);
					suppCopie(x);
					system("pause");
					break;
				case '2':
					system("cls");
					printf("Donnez le code du livre:\t");
					do {
						scanf("%d", &x);
					} while (x < 1);
					ajoutCopie(x);
					system("pause");
					break;
				case '3':
					system("cls");
					printf("Donnez le litre du livre:\t");
					scanf("%s", &l.titre);
					printf("Donnez le nom d'auteur du livre:\t");
					scanf("%s", &l.aut.nom);
					printf("Donnez le prenom d'auteur du livre:\t");
					scanf("%s", &l.aut.prenom);
					printf("Donnez le code du livre:\t");
					do {
						scanf("%d", &l.code);
					} while (l.code < 1);
					printf("Donnez le nombre de copies du livre:\t");
					do {
						scanf("%d", &l.nbl);
					} while (l.nbl < 0);
					ajoutLivre(l);
					system("pause");
					break;
				case '4':
					goto menu;
					break;
				case '5':
					return 0;
					break;
			}
			goto menu3;
			break;
		case '4':
		menu4:
			system("cls");
			printf("\t\tGérer les Emprunts\n\n");
			printf("\t1-Disponibilite d'un livre\n");
			printf("\t2-Emprunter un livre\n");
			printf("\t3-Rendre un livre\n");
			printf("\t4-Menu Principale\n");
			printf("\t5-Quitter\n");
			printf("\n\nVotre Choix : \t");
			scanf("%c", &choix);
			switch (choix) {
				case '1':
					system("cls");
					printf("Donnez le code du livre:\t");
					do {
						scanf("%d", &x);
					} while (x < 1);
					if (livreDisponible(x) == 1)
						printf("Le livre est disponible\n");
					else
						printf("Le livre n'est pas disponible\n");
					system("pause");
					break;
				case '2':
					system("cls");
					printf("Donnez le code du livre a emprunter:\t");
					do {
						scanf("%d", &x);
					} while (x < 1);
					printf(
						"Donnez le matricule de l'etudiant qui empreinte le "
						"livre:\t");
					do {
						scanf("%d", &y);
					} while (y < 1);
					emprunterLivre(y, x);
					system("pause");
					break;
				case '3':
					system("cls");
					printf("Donnez le code du livre a rendre:\t");
					do {
						scanf("%d", &x);
					} while (x < 1);
					printf(
						"Donnez le matricule de l'etudiant qui rend le "
						"livre:\t");
					do {
						scanf("%d", &y);
					} while (y < 1);
					rendreLivre(y, x);
					system("pause");
					break;
				case '4':
					goto menu;
					break;
				case '5':
					return 0;
					break;
			}
			goto menu4;
			break;
		case '5':
			return 0;
	}
	goto menu;
}
