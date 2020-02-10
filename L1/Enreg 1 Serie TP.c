#include <stdio.h>
#include <string.h>
typedef struct {
	int NumBat;
	char cite[30], commune[30], wilaya[20];
} Adresse;
typedef struct {
	char Nom[20], Prenom[20];
	float Moy, Note[10];
	int Nb;
	Adresse adr;
} Etudiant;
void Tindouf(Etudiant A[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (strcmpi(A[i].adr.wilaya, "Tindouf") == 0) {
			printf("%f\n", A[i].Moy);
		}
	}
}

int main() {
	int i, j, s, N;
	Etudiant x;
	printf("Donnez le nombre d'etudiants\n");
	do {
		scanf("%d", &N);
	} while (N < 1);
	Etudiant T[N];
	for (i = 0; i < N; i++) {
		printf("Donnez le Nom de l'etudiant %d\n", i + 1);
		scanf("%s", T[i].Nom);
		printf("Donnez le Prenom de l'etudiant %d\n", i + 1);
		scanf("%s", T[i].Prenom);
		printf("Donnez le nombre de notes de l'etudiant %d\n", i + 1);
		do {
			scanf("%d", &T[i].Nb);
		} while (T[i].Nb < 1 || T[i].Nb > 10);
		s = 0;
		printf("Remplissage des notes\n");
		for (j = 0; j < T[i].Nb; j++) {
			do {
				scanf("%f", &T[i].Note[j]);
			} while (T[i].Note[j] < 0 || T[i].Note[j] > 20);
			s = s + T[i].Note[j];
		}
		T[i].Moy = s / T[i].Nb;
		printf("Le num du batiment\n");
		scanf("%d", &T[i].adr.NumBat);
		printf("Le nom de la cite\n");
		scanf("%s", T[i].adr.cite);
		printf("Le nom de la commune\n");
		scanf("%s", T[i].adr.commune);
		printf("Le nom de la wilaya\n");
		scanf("%s", T[i].adr.wilaya);
	}
	printf("Les etudiants admis sont:\n");
	while (i >= 0) {
		if (T[i].Moy >= 10) {
			printf("%s %s\n", T[i].Nom, T[i].Prenom);
			i--;
		} else {
			i--;
		}
	}
	for (i = 0; i < N - 1; i++) {
		for (j = i + 1; j < N; j++) {
			if (T[i].Moy < T[j].Moy) {
				x = T[i];
				T[i] = T[j];
				T[j] = x;
			}
		}
	}
	if (N >= 3) {
		printf("Les trois majorants sont:\n");
		printf("%s %s\n", T[0].Nom, T[0].Prenom);
		printf("%s %s\n", T[1].Nom, T[1].Prenom);
		printf("%s %s\n", T[2].Nom, T[2].Prenom);
	} else {
		for (i = 0; i < N; i++) {
			printf("Les trois premiers sont:\n");
			printf("%s %s\n", T[i].Nom, T[i].Prenom);
		}
	}
	printf("La moyenne des etudiants habitant a Tindouf\n");
	Tindouf(T, N);
	printf(
		"Les etudiants habitants dans la meme commune que l'etudiant ayant la "
		"plus basse moyenne\n");
	for (i = 0; i < N - 1; i++) {
		if (strcmpi(T[i].adr.commune, T[N - 1].adr.commune) == 0) {
			printf("%s %s\n", T[i].Nom, T[i].Prenom);
		}
	}
}
