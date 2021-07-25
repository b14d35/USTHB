#include "../Headers/TS.h"
#include "../conio21/conio.c"
void init(){ 
	int i;
	for (i=0;i<TAILLE;i++){
		TS[i]=NULL;
	}
}

int Fhach(char* e){
	int i=0, count=0; 
	while(e[i]!='\0'){
		count+=e[i]*i*(10*(i+1));
		i++;
	} 
	return (count%TAILLE);
} 

int recherche(char * el, ELT** adr){
	ELT* p;
	int index = Fhach(el);
	p=TS[index];
	*adr =p;
	if (p==NULL){
		return 0;
	}
	if (!strcmp(p->IDF,el)){
		return 1;
	}
	p=p->svt;
	while (p!=NULL && strcmp(p->IDF,el)){
		p=p->svt;
	}
	*adr =p;
	if (p==NULL){
		return 0;
	}
	return 1;
}

void insererValeur(char* idf, int value){
	ELT * adr; 
	recherche(idf,&adr); 
	adr->value = value;
}

int getValeur(char* idf){
	ELT * adr; 
	recherche(idf,&adr); 
	return adr->value;
}


void inserer(char* el,int type, int nature, int value){ 
	ELT* p; 
	ELT* adr;
	int index= Fhach(el);
	p= malloc(sizeof(ELT));
	p->IDF=el; 
	p->type=type;
	p->nature=nature;
	p->value=value;
	if (TS[index]==NULL){
		p->svt=NULL; 
		TS[index]=p;
	}
	else{
		p->svt=TS[index]; 
		TS[index]=p;
	}
}

void afficherTS(){
	int i=0; ELT* p;
	textattr(3);
	printf("\n\t    /*************Table des Symboles************/\n");
	printf("\t     __________________________________________\n");
	printf("\t    |    IDF    |     Type     |    Nature     |\n");
	printf("\t    |___________|______________|_______________|\n");
	for (i=0;i<TAILLE;i++){
		if (TS[i]!=NULL){
			p=TS[i]; 
			while(p!=NULL){
				textattr(3);
				printf("\t    |");
				textattr(15);
				printf("%10s",p->IDF);
				textattr(3);
				printf(" |");
				textattr((p->type)+8);
				printf("    Entier   ");
				textattr(3);
				printf(" |");
				textattr((p->nature)+11);
				printf("   Variable   ");
				textattr(3);
				printf(" |\n");
				p=p->svt;
			}
		}
	}
	textattr(3);
	printf("\t    |___________|______________|_______________|\n");
	printf("\n\t    /*************Fin Table Symboles************/\n");
	textattr(15);
}
