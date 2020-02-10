#include "conio21/conio.c"
#include <windows.h>
#include <stdio.h>
#include <string.h>
typedef struct{
	char NomEntite[20];
	char CodeEntite[20];
	char TypeEntite[20];
	int Taille;
} TypeTS;
TypeTS ts[100];
int CpTabSym=0;
int recherche(char entite[]){
	int i=0;
	while(i<CpTabSym){
		if (strcmp(entite,ts[i].NomEntite)==0 && strcmp(ts[i].CodeEntite,"Nom Algo")!=0) return i;
		i++;
	}
	return -1;
}

void inserer(char entite[]){
	if ( recherche(entite)==-1){
		strcpy(ts[CpTabSym].NomEntite,entite);
		CpTabSym++;
	}
}
void insererCode(char entite[], char code[]){
	int x=recherche(entite);
	if(x!=-1){
		if(strcmp(ts[x].CodeEntite,"")==0) strcpy(ts[x].CodeEntite,code);
	}
}
void insererType(char entite[], char type[]){
	int x=recherche(entite);
	if(x!=-1){
		if(strcmp(ts[x].TypeEntite,"")==0) strcpy(ts[x].TypeEntite,type);
	}
}
void insererType2(char type[]){
	int i;
	for(i=1;i<CpTabSym;i++){
		if(strcmp(ts[i].TypeEntite,"a")==0) strcpy(ts[i].TypeEntite,type);
	}
}
void insererTaille(char entite[], int taille){
	int x=recherche(entite);
	if(x!=-1){
		if(strcmp(ts[x].TypeEntite,"a")==0) ts[x].Taille=taille;
	}
}
int ColCode(TypeTS x){
	if(strcmp(x.CodeEntite,"Nom Algo")==0) return 11;
	else if(strcmp(x.CodeEntite,"Variable")==0) return 10;
	else if(strcmp(x.CodeEntite,"Tableau")==0) return 9;
	else return 12;
}
int ColType(TypeTS x){
	if(strcmp(x.TypeEntite,"Entier")==0) return 110;
	else if(strcmp(x.TypeEntite,"Chaine")==0) return 90;
	else if(strcmp(x.TypeEntite,"Reel")==0) return 70;
	else return 120;
}
int ColTaille(TypeTS x){
	if(strcmp(x.CodeEntite,"Tableau")==0){
		if(x.Taille<1) return 12;
		else return 6;
	}
	else return 120;
}
void afficher (){
    textattr(3);
	printf("\n\t/****************Table des symboles***************/\n");
	printf("\t____________________________________________________\n");
	printf("\t| NomEntite |  CodeEntite  |  TypeEntite   | Taille |\n");
	printf("\t|___________|______________|_______________|________|\n");
	int i=0;
	int cl=0;
	while(i<CpTabSym){
	    textattr(3);
        printf("\t|");
		cl=ColCode(ts[i]);
		textattr(cl);
		printf("%10s",ts[i].NomEntite);
        textattr(3);
        printf(" |");
		if(strcmp(ts[i].CodeEntite,"")==0)textattr(120);
		else textattr(cl);
        printf("%12s",ts[i].CodeEntite);
        textattr(3);
        printf("  |");
		cl=ColType(ts[i]);
		textattr(cl);
        printf("%12s",ts[i].TypeEntite);
        textattr(3);
        printf("   |");
		cl=ColTaille(ts[i]);
		textattr(cl);
		if(strcmp(ts[i].CodeEntite,"Tableau")==0) printf("%7d",ts[i].Taille);
		else printf("       ");
        textattr(3);
        printf(" |\n");
		i++;
	}
	textattr(3);
	printf("\t|___________|______________|_______________|________|\n");
	textattr(15);
}
int doubleDeclaration (char entite[]){
	int posEntite=recherche(entite);
	if(posEntite==-1) return 0;
	return 1;
}
int nonDeclare (char entite[]){
	int posEntite=recherche(entite);
	if(posEntite==-1) return 1;
	return 0;
}

char SvType[20][20];
int types=0;
void init(){
	for(types=0;types<20;types++)strcpy(SvType[types],"");
	types=0;
}
void ajouter(char entite[]){
	if(strcmp(entite,"Chaine")==0||strcmp(entite,"Entier")==0||strcmp(entite,"Reel")==0)strcpy(SvType[types],entite);
	else{
		int t=recherche(entite);
		if(t!=-1)strcpy(SvType[types],ts[t].TypeEntite);
		else strcpy(SvType[types],"");
	}
	types++;
}
int nonCompatible(){
	int i;
	if(types==1) return 0;
	for(i=0;i<types-1;i++)if(strcmp(SvType[i],SvType[i+1])!=0)return 1;
	return 0;
}
int tailleTableauDepasse(char entite[], int t){
	int r=recherche(entite);
	if(r!=-1){if(ts[r].Taille<t) return 1;}
	else return 0;
}
