#include "../Headers/Errors.h"
#include "../Headers/TS.h"

// Les erreurs ont été annulée dans le projet

int ErrorDoubleDeclaration(char *idf) {
	int index;
	ELT *adr;
	int b = recherche(idf, &adr);
	/*if(b == 1){
		textattr(14);
		printf("Erreur Symantique Ligne:%d Colone:%d Double Declaration de
	%s\n",ligne,colonne,idf); textattr(15);
	}*/
	return b;
}

void ErrorNonDeclaree(char *idf) {
	int index;
	ELT *adr;
	int b = recherche(idf, &adr);
	if (b != 1) {
		/*textattr(2);
		printf("Erreur Symantique Ligne:%d Colone:%d Non Declaration de
		%s\n",ligne,colonne-strlen(idf),idf); textattr(15);*/
		inserer(idf, 1, 1, 0);
	}
}

void ErrorDepassementTaille() {
	textattr(9);
	printf("Erreur Lexical Ligne:%d Ligne:%d Capacite Depassee \n", ligne,
		   colonne);
	textattr(15);
}

void RangeEronne(int a, int b) {
	if (a > b) {
		textattr(6);
		printf("Erreur Symantique Ligne:%d Colone:%d Range Erronee\n", ligne,
			   colonne);
		textattr(15);
	}
}

void ErrorDivisionParZero() {
	textattr(13);
	printf(
		"Erreur Symantique Ligne:%d Colonne:%d Devision par zero impossible\n",
		ligne, colonne);
	textattr(15);
}
