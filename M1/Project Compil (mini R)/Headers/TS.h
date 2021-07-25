#define TAILLE 100
typedef struct elt{
	char* IDF;
	int type;
	int nature;
	int value;
	struct elt* svt;
}ELT;
ELT* TS[TAILLE];
void init();
int Fhach(char* e);
int recherche(char * el, ELT** adr);
void insererValeur(char* idf, int value);
int getValeur(char* idf);
void inserer(char* el,int type, int nature, int value);
void afficherTS();
