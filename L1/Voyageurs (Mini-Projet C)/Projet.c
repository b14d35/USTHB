#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct voyageur {
	int x;
	int mat;
	char tel[15];
	char nom[20];
	char prenom[20];
	char adresse[100];
};
struct temps {
	int h, m, s;
};
struct trajet {
	int matricule, distance, prix;
	char wilactu[20];
	char wilaarr[20];
	char moy[30];
	struct temps heur_dpart;
	struct temps heur_darriver;
};
struct trajet traj;
struct voyageur voy;
/// Fonction qui permet d'ajouter un trajet
void ajout(FILE *f, FILE *s) {
	int t;
	s = fopen("inf.txt", "r");
	fscanf(s, "NbMat:%d NbTraj:%d", &voy.mat, &traj.matricule);
	fclose(s);
	s = fopen("inf.txt", "w");
	fprintf(s, "NbMat:%d NbTraj:%d", voy.mat, traj.matricule + 1);
	fclose(s);
	f = fopen("trajet.txt", "a");
	printf("donner le wilya actuel :\t");
	scanf("%s", &traj.wilactu);
	printf("donner la destination  :\t");
	scanf("%s", &traj.wilaarr);
	printf("donner l'heure de depart: \t");
	scanf("%d", &traj.heur_dpart.h);
	scanf("%d", &traj.heur_dpart.m);
	scanf("%d", &traj.heur_dpart.s);
	printf("donner l'heure d'arrive :\t");
	scanf("%d", &traj.heur_darriver.h);
	scanf("%d", &traj.heur_darriver.m);
	scanf("%d", &traj.heur_darriver.s);
	printf("donner la distance: \t");
	scanf("%d", &traj.distance);
	printf("donner le moyen : \n");
	printf("1-Bus :\t\t");
	printf("2-Train :\t");
	printf("3-TGV :\n");
	do {
		printf("Votre choix :\n");
		scanf("%d", &t);
	} while (t < 1 || t > 3);
	switch (t) {
		case 1:
			strcpy(traj.moy, "BUS");
			break;
		case 2:
			strcpy(traj.moy, "TRAIN");
			break;
		case 3:
			strcpy(traj.moy, "TGV");
			break;
	}
	printf("avec le prix de :\t");
	scanf("%d", &traj.prix);
	fprintf(f,
			"TRAJET:%d de distance %d par %s de  %d:%d:%d  a %d:%d:%d  de %s "
			"vers: %s de prix:%d  \n",
			traj.matricule, traj.distance, traj.moy, traj.heur_dpart.h,
			traj.heur_dpart.m, traj.heur_dpart.s, traj.heur_darriver.h,
			traj.heur_darriver.m, traj.heur_darriver.s, traj.wilactu,
			traj.wilaarr, traj.prix);
	printf("\n");
	fclose(f);
}
/// Une fonction qui permet de supprimer un trajet
void sup(FILE *f, int x) {
	FILE *fei;
	f = fopen("trajet.txt", "r");
	fei = fopen("co-trajet.txt", "w");
	do {
		fscanf(f,
			   "TRAJET:%d de distance %d par %s de  %d:%d:%d  a %d:%d:%d  de "
			   "%s vers: %s de prix:%d ",
			   &traj.matricule, &traj.distance, &traj.moy, &traj.heur_dpart.h,
			   &traj.heur_dpart.m, &traj.heur_dpart.s, &traj.heur_darriver.h,
			   &traj.heur_darriver.m, &traj.heur_darriver.s, &traj.wilactu,
			   &traj.wilaarr, &traj.prix);
		if (x != traj.matricule) {
			fprintf(fei,
					"TRAJET:%d de distance %d par %s de  %d:%d:%d  a %d:%d:%d  "
					"de %s vers: %s de prix:%d \n",
					traj.matricule, traj.distance, traj.moy, traj.heur_dpart.h,
					traj.heur_dpart.m, traj.heur_dpart.s, traj.heur_darriver.h,
					traj.heur_darriver.m, traj.heur_darriver.s, traj.wilactu,
					traj.wilaarr, traj.prix);
		}
	} while (!feof(f));
	fclose(f);
	fclose(fei);
	remove("trajet.txt");
	rename("co-trajet.txt", "trajet.txt");
	printf("\n");
}
/// Fonction qui permet de modifier un trajet
void modif(FILE *f, int x) {
	FILE *fei;
	int t;
	f = fopen("trajet.txt", "r");
	fei = fopen("co-trajet.txt", "w");
	do {
		fscanf(f,
			   "TRAJET:%d de distance %d par %s de  %d:%d:%d  a %d:%d:%d  de "
			   "%s vers: %s de prix:%d ",
			   &traj.matricule, &traj.distance, &traj.moy, &traj.heur_dpart.h,
			   &traj.heur_dpart.m, &traj.heur_dpart.s, &traj.heur_darriver.h,
			   &traj.heur_darriver.m, &traj.heur_darriver.s, &traj.wilactu,
			   &traj.wilaarr, &traj.prix);
		if (x == traj.matricule) {
			printf("give a new price :\t");
			scanf("%d", &traj.prix);
			printf("give a new distance:\t");
			scanf("%d", &traj.distance);
			printf("give a new time for leaving:\t");
			scanf("%d", &traj.heur_dpart.h);
			scanf("%d", &traj.heur_dpart.m);
			scanf("%d", &traj.heur_dpart.s);
			printf("give a new time for :\t");
			scanf("%d", &traj.heur_darriver.h);
			scanf("%d", &traj.heur_darriver.m);
			scanf("%d", &traj.heur_darriver.s);
			printf("donner la ville actuel:\t");
			scanf("%s", &traj.wilactu);
			printf("donner l'arret :\t");
			scanf("%s", &traj.wilaarr);
			printf("donner le moyen : \n");
			printf("1-Bus :\t\t");
			printf("2-Train :\t");
			printf("3-TGV :\n");
			do {
				printf("Votre choix :\n");
				scanf("%d", &t);
			} while (t < 1 || t > 3);
			switch (t) {
				case 1:
					strcpy(traj.moy, "BUS");
					break;
				case 2:
					strcpy(traj.moy, "TRAIN");
					break;
				case 3:
					strcpy(traj.moy, "TGV");
					break;
			}
		}
		fprintf(fei,
				"TRAJET:%d de distance %d par %s de  %d:%d:%d  a %d:%d:%d  de "
				"%s vers: %s de prix:%d  \n",
				traj.matricule, traj.distance, traj.moy, traj.heur_dpart.h,
				traj.heur_dpart.m, traj.heur_dpart.s, traj.heur_darriver.h,
				traj.heur_darriver.m, traj.heur_darriver.s, traj.wilactu,
				traj.wilaarr, traj.prix);
	} while (!feof(f));
	fclose(f);
	fclose(fei);
	remove("trajet.txt");
	rename("co-trajet.txt", "trajet.txt");
	printf("\n");
}
/// Fonction qui permet de d'afficher tout les trajets (complets + libres)
void affi(FILE *f) {
	f = fopen("trajet.txt", "r");
	printf("la list des trajets est :\n");
	do {
		fscanf(f,
			   "TRAJET:%d de distance %d par %s de  %d:%d:%d  a %d:%d:%d  de "
			   "%s vers: %s de prix:%d  ",
			   &traj.matricule, &traj.distance, &traj.moy, &traj.heur_dpart.h,
			   &traj.heur_dpart.m, &traj.heur_dpart.s, &traj.heur_darriver.h,
			   &traj.heur_darriver.m, &traj.heur_darriver.s, &traj.wilactu,
			   &traj.wilaarr, &traj.prix);
		printf(
			"TRAJET:%d de distance %d par %s de  %d:%d:%d  a %d:%d:%d  de %s "
			"vers: %s de prix:%d  \n",
			traj.matricule, traj.distance, traj.moy, traj.heur_dpart.h,
			traj.heur_dpart.m, traj.heur_dpart.s, traj.heur_darriver.h,
			traj.heur_darriver.m, traj.heur_darriver.s, traj.wilactu,
			traj.wilaarr, traj.prix);
	} while (!feof(f));
	printf("\n");
	fclose(f);
}
/// Fonction qui permet de verifier si une place est libre
int libre(FILE *g, int x) {
	int i, t;
	t = 0;
	i = 0;
	g = fopen("reservation.txt", "r");
	do {
		fscanf(g, "Matricule:%d Trajet:%d \n", &voy.mat, &voy.x);
		if (traj.matricule == voy.x) {
			i++;
		}
	} while (!feof(g));
	fclose(g);
	if (strcmpi(traj.moy, "BUS") == 0 && i < 56 ||
		strcmpi(traj.moy, "TRAIN") == 0 && i < 201 ||
		strcmpi(traj.moy, "TGV") == 0 && i < 151) {
		t = 1;
	}
	printf("\n");
	return t;
}
/// Fonction qui permet d'afficher les trajets avec des places libres
void des(FILE *f, FILE *g) {
	int i;
	f = fopen("trajet.txt", "r");
	do {
		i = 0;
		fscanf(f,
			   "TRAJET:%d de distance %d par %s de  %d:%d:%d  a %d:%d:%d  de "
			   "%s vers: %s de prix:%d  ",
			   &traj.matricule, &traj.distance, &traj.moy, &traj.heur_dpart.h,
			   &traj.heur_dpart.m, &traj.heur_dpart.s, &traj.heur_darriver.h,
			   &traj.heur_darriver.m, &traj.heur_darriver.s, &traj.wilactu,
			   &traj.wilaarr, &traj.prix);
		if (libre(g, traj.matricule) == 1) {
			printf(
				"TRAJET:%d de distance %d par %s de  %d:%d:%d  a %d:%d:%d  de "
				"%s vers: %s de prix:%d  \n",
				traj.matricule, traj.distance, traj.moy, traj.heur_dpart.h,
				traj.heur_dpart.m, traj.heur_dpart.s, traj.heur_darriver.h,
				traj.heur_darriver.m, traj.heur_darriver.s, traj.wilactu,
				traj.wilaarr, traj.prix);
		}
	} while (!feof(f));
	fclose(f);
	printf("\n");
}
/// Fonction qui permet de reserver une place
void reserver(FILE *g, FILE *h, FILE *s, int x) {
	s = fopen("inf.txt", "r");
	fscanf(s, "NbMat:%d NbTraj:%d", &voy.mat, &traj.matricule);
	fclose(s);
	s = fopen("inf.txt", "w");
	fprintf(s, "NbMat:%d NbTraj:%d", voy.mat + 1, traj.matricule);
	fclose(s);
	g = fopen("reservation.txt", "a");
	h = fopen("voyageur.txt", "a");
	printf("Donnez votre nom :\t");
	scanf("%s", &voy.nom);
	printf("Donnez votre prenom :\t");
	scanf("%s", &voy.prenom);
	printf("Donnez le tel :\t");
	scanf("%s", &voy.tel);
	printf("Donnez l'addresse: \t");
	scanf("%s", &voy.adresse);
	fprintf(h, "Matricule:%d Trajet:%d Tel:%s Nom:%s Prenom:%s Addr:%s \n",
			voy.mat, x, voy.tel, voy.nom, voy.prenom, voy.adresse);
	fprintf(g, "Matricule:%d Trajet:%d \n", voy.mat, x);
	fclose(h);
	fclose(g);
	printf("\n");
}
/// Fonction qui permet de modifier une reservation (changer son trajet)
void modifr(FILE *h, FILE *g, int x, int y) {
	FILE *hi;
	FILE *gi;
	h = fopen("voyageur.txt", "r");
	hi = fopen("voyageur-tmp.txt", "w");
	do {
		fscanf(h, "Matricule:%d Trajet:%d Tel:%s Nom:%s Prenom:%s Addr:%s \n",
			   &voy.mat, &voy.x, &voy.tel, &voy.nom, &voy.prenom, &voy.adresse);
		if (voy.mat == y) {
			voy.x = x;
		}
		fprintf(hi, "Matricule:%d Trajet:%d Tel:%s Nom:%s Prenom:%s Addr:%s \n",
				voy.mat, voy.x, voy.tel, voy.nom, voy.prenom, voy.adresse);
	} while (!feof(h));
	fclose(h);
	fclose(hi);
	remove("voyageur.txt");
	rename("voyageur-tmp.txt", "voyageur.txt");
	g = fopen("reservation.txt", "r");
	gi = fopen("res-tmp.txt", "w");
	do {
		fscanf(g, "Matricule:%d Trajet:%d \n", &voy.mat, &voy.x);
		if (voy.mat == y) {
			voy.x = x;
		}
		fprintf(gi, "Matricule:%d Trajet:%d \n", voy.mat, voy.x);
	} while (!feof(g));
	fclose(h);
	fclose(hi);
	remove("reservation.txt");
	rename("res-tmp.txt", "reservation.txt");
	printf("\n");
}
/// Fonction qui permet de supprimer sa reservation
void supr(FILE *g, FILE *h, int y) {
	FILE *G, *H;
	h = fopen("voyageur.txt", "r");
	H = fopen("v-tmp.txt", "w");
	do {
		fscanf(h, "Matricule:%d Trajet:%d Tel:%s Nom:%s Prenom:%s Addr:%s \n",
			   &voy.mat, &voy.x, &voy.tel, &voy.nom, &voy.prenom, &voy.adresse);
		if (voy.mat != y) {
			fprintf(H,
					"Matricule:%d Trajet:%d Tel:%s Nom:%s Prenom:%s Addr:%s \n",
					voy.mat, voy.x, voy.tel, voy.nom, voy.prenom, voy.adresse);
		}
	} while (!feof(h));
	fclose(h);
	fclose(H);
	remove("voyageur.txt");
	rename("v-tmp.txt", "voyageur.txt");
	g = fopen("reservation.txt", "r");
	G = fopen("r-tmp.txt", "w");
	do {
		fscanf(g, "Matricule:%d Trajet:%d \n", &voy.mat, &voy.x);
		if (voy.mat != y) {
			fprintf(G, "Matricule:%d Trajet:%d \n", voy.mat, voy.x);
		}
	} while (!feof(g));
	fclose(g);
	fclose(G);
	remove("reservation.txt");
	rename("r-tmp.txt", "reservation.txt");
	printf("\n");
}
/// Fonction qui permet de supprimer les reservations d'un trajet (si le trajet
/// n'existe plus on doit supprimer les reservations)
void supc(FILE *g, FILE *h, int x) {
	FILE *G, *H;
	h = fopen("voyageur.txt", "r");
	H = fopen("v-tmp.txt", "w");
	do {
		fscanf(h, "Matricule:%d Trajet:%d Tel:%s Nom:%s Prenom:%s Addr:%s \n",
			   &voy.mat, &voy.x, &voy.tel, &voy.nom, &voy.prenom, &voy.adresse);
		if (voy.x != x) {
			fprintf(H,
					"Matricule:%d Trajet:%d Tel:%s Nom:%s Prenom:%s Addr:%s \n",
					voy.mat, voy.x, voy.tel, voy.nom, voy.prenom, voy.adresse);
		}
	} while (!feof(h));
	fclose(h);
	fclose(H);
	remove("voyageur.txt");
	rename("v-tmp.txt", "voyageur.txt");
	g = fopen("reservation.txt", "r");
	G = fopen("r-tmp.txt", "w");
	do {
		fscanf(g, "Matricule:%d Trajet:%d \n", &voy.mat, &voy.x);
		if (voy.x != x) {
			fprintf(G, "Matricule:%d Trajet:%d \n", voy.mat, voy.x);
		}
	} while (!feof(g));
	fclose(g);
	fclose(G);
	remove("reservation.txt");
	rename("r-tmp.txt", "reservation.txt");
	printf("\n");
}
/// Determine s'il une matricule existe dans les reservations ou non
int exister(FILE *g, int x) {
	int y;
	g = fopen("reservation.txt", "r");
	y = 0;
	do {
		fscanf(g, "Matricule:%d Trajet:%d \n", &voy.mat, &voy.x);
		if (x == voy.mat) {
			y = 1;
		}
	} while (!feof(g) && y == 0);
	fclose(g);
	return y;
}
/// Determine si un trajet existe ou pas
int existe(FILE *f, int x) {
	int y;
	f = fopen("trajet.txt", "r");
	y = 0;
	do {
		fscanf(f,
			   "TRAJET:%d de distance %d par %s de  %d:%d:%d  a %d:%d:%d  de "
			   "%s vers: %s de prix:%d  \n",
			   &traj.matricule, &traj.distance, &traj.moy, &traj.heur_dpart.h,
			   &traj.heur_dpart.m, &traj.heur_dpart.s, &traj.heur_darriver.h,
			   &traj.heur_darriver.m, &traj.heur_darriver.s, &traj.wilactu,
			   &traj.wilaarr, &traj.prix);
		if (x == traj.matricule) {
			y = 1;
		}
	} while (!feof(f) && y == 0);
	fclose(f);
	return y;
}
main() {
	FILE *f, *g, *h, *s;
	int t, x, y;
	/// Fichier s me permet de generer et sauvegarder la position de mon code de
	/// trajet et la matricule des voyageurs
	s = fopen("inf.txt", "a");
	rewind(s);
	if (feof(s)) {
		fclose(s);
		s = fopen("inf.txt", "w");
		fprintf(s, "NbMat:%d NbTraj:%d", 0, 0);
	}
	/// Si les fichiers n'existent pas ils seront crees
	fclose(s);
	f = fopen("trajet.txt", "a");
	fclose(f);
	g = fopen("reservation.txt", "a");
	fclose(g);
	h = fopen("voyageur.txt", "a");
	fclose(h);
g:
	printf(
		"\n***************\t Bonjour "
		"monsieur/madame******************************\n");
	printf("\t1-Etes vous un gerant ?\n");
	printf("\t2-Etes vous un utilisateur ?\n");
	printf("\t3-Quitter\n");
	do {
		printf("donner le choix:\t");
		scanf("%d", &t);
	} while (t < 1 || t > 3);
	printf("\n");
	switch (t) {
		case 1:
		h:
			printf("\n******** MENU Administrateur********\n");
			printf("\t1-Ajouter un trajet\n");
			printf("\t2-Supprimer un trajet\n");
			printf("\t3-Modifier un trajet \n");
			printf("\t4-Afficher les trajets\n");
			printf("\t5-Menu Principal\n");
			printf("\t6-Quitter\n");
			do {
				printf("votre choix:\t");
				scanf("%d", &t);
			} while (t < 1 || t > 6);
			switch (t) {
				case 1:
					ajout(f, s);
					system("pause");
					/// On fait un appel simple a la foncion d'ajout de trajet
					break;
				case 2:
					printf("donnez le code de trajet :\t");
					scanf("%d", &x);
					if (existe(f, x) == 1) {
						sup(f, x);
					} else {
						printf("Ce trajet n'existe pas\n\n");
					}
					if (exister(g, x) == 1) {
						supc(g, h, x);
					}
					/// On lit le code du trajet qu'on veut supprimer
					/// On verifie qu'il existe bien avec la fonction existe
					/// S'il existe on le supprime sinon on affiche que le
					/// trajet n'existe pas On verifie aussi s'il y a des
					/// reservations avec ce trajet on les annule toutes
					system("pause");
					break;
				case 3:
					printf("donnez le code de trajet :\t");
					scanf("%d", &x);
					if (existe(f, x) == 1) {
						modif(f, x);
					} else {
						printf("Ce trajet n'existe pas\n\n");
					}
					system("pause");
					/// On lit le code du trajet S'il existe on le modifie sinon
					/// on affiche qu'il n'existe pas
					break;
				case 4:
					affi(f);
					/// On fait un appel simple a la fonction qui affiche tout
					/// les trajets
					system("pause");
					break;
				case 5:
					goto g;
					break;
				case 6:
					return 0;
			}
			goto h;
			break;
		case 2:
		i:
			printf("\n******** MENU Utilisateur********\n");
			printf("\t1-Voire la disponibilite des places dans un trajet\n");
			printf("\t2-Reserver une place\n");
			printf("\t3-Modifier une reservation\n");
			printf("\t4-Annuler une reservation\n");
			printf("\t5-Menu Principal\n");
			printf("\t6-Quitter\n");
			do {
				printf("votre choix:\t");
				scanf("%d", &t);
			} while (t < 1 || t > 6);
			switch (t) {
				case 1:
					des(f, g);
					system("pause");
					/// On fait appel a la fonction qui affiche les trajets avec
					/// des places vides
					break;
				case 2:
					printf("donnez le code de trajet :\t");
					scanf("%d", &x);
					if (existe(f, x) == 1) {
						if (libre(g, x) == 1) {
							reserver(g, h, s, x);
						} else {
							printf("Ce voyage est complet\n");
						}
					} else {
						printf("Ce trajet n'existe pas\n\n");
					}
					system("pause");
					/// On cherche si le code du trajet existe puis on lui
					/// reserve Puis on verifie s'il est disponible, ensuite on
					/// voit si il y a des places ou non
					break;
				case 3:
					printf("donnez votre matricule :\t");
					scanf("%d", &y);
					if (exister(g, y) == 1) {
						printf("donnez le nouveau code :\t");
						scanf("%d", &x);
						if (existe(f, x) == 1) {
							if (libre(g, x) == 1) {
								modifr(h, g, y, x);
							} else {
								printf("Ce trajet est complet\n\n");
							}
						} else {
							printf("Ce trajet n'existe pas\n\n");
						}
					} else {
						printf("Cette matricule n'existe pas\n\n");
					}
					system("pause");
					/// On cherche d'abord si le voyageur existe, puis il rentre
					/// le nouveau trajet pour le modifier
					break;
				case 4:
					printf("donnez votre matricule :\t");
					scanf("%d", &y);
					if (exister(g, y) == 1) {
						supr(g, h, y);
					} else {
						printf("Cette matricule n'existe pas\n\n");
					}
					system("pause");
					/// On recherche si le passager existe a partir de sa
					/// matricule puis on le supprime
					break;
				case 5:
					printf("\n");
					goto g;
					break;
				case 6:
					return 0;
			}
			goto i;
			break;
		case 3:
			return 0;
	}
}
