%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/TS.h"
#include "Headers/Errors.h"
#include "Headers/quad.h"
#include "Headers/pile.h"
#include "Headers/optim.h"
#include "Headers/assem.h"
int yylex();
int yyerror(char *);
extern FILE* yyin;
extern int ligne, colonne;
int QC = 0, modif = 1;
int temp = 1;
int nbr_if = 0;
int ins_what = 0;
char buff[10];
pile *IFS = NULL;
pile *ELIFS = NULL;
%}
%union {
	int num;
	float flo;
	char* str;
	struct {
		int res;
		char* id;
	} NT;
}

%token <num>ENTIER <str>IDF COMMENT
%token <str>XINT
%token <str>IF <str>ELIF <str>ELSE
%token <str>FOR RANGE INN WHILE
%token DP VIRG SAUT
%token INDENT DEDENT

%type<str> usage comparateur
%type<NT> exp values
%type<num> exp_cond

%left LE GE EQ NE LT GT
%left '+' '-'
%left '*' '/'
%left PO PF
%union {char* nom;}
%start entree_seule
%%

entree_seule: stmt_simple entree_seule
			| if_stmt {nbr_if--;} entree_seule
			|
			;
	
stmt_simple: declaration_stmt SAUT
		   | affectation_stmt SAUT
		   ;
		   
declaration_stmt: XINT liste;

liste: usage
	| usage '=' exp {Quad("=", $3.id, "", $1);}
	| usage VIRG liste
	| usage '=' exp VIRG {Quad("=", $3.id, "", $1);} liste
	;

usage: IDF  {if(ErrorDoubleDeclaration($1) != 1)inserer($1, 1, 1, 0);}
	;

affectation_stmt: IDF '=' exp {ErrorNonDeclaree($1); Quad("=", $3.id, "", $1);}
				;

if_stmt: {nbr_if++; ins_what=1;} IF PO exp_cond PF DP SAUT suite {ins_what=2;} elif_stmt;

elif_stmt: {
			Maj(IFS->adrCond, QC + 1);
			IFS = pop(IFS);
			Quad("BR", "", "", "");
			IFS = push(IFS);
		} ELIF PO exp_cond PF DP SAUT suite else_stmt
		| else_stmt
		;
		 
else_stmt: {
			if(peek(ELIFS) == nbr_if){
				Maj(ELIFS->adrCond, QC + 1);
				ELIFS = pop(ELIFS);
				Quad("BR", "", "", "");
				ELIFS = push(ELIFS);
			}else{
				Maj(IFS->adrCond, QC + 1);
				IFS = pop(IFS);
				Quad("BR", "", "", "");
				IFS = push(IFS);
			}
		} ELSE DP SAUT suite {
			if(peek(ELIFS) == nbr_if){
				Maj(ELIFS->adrCond, QC);
				ELIFS = pop(ELIFS);
			}
			Maj(IFS->adrCond, QC);
			IFS = pop(IFS);
		}
		| {
			if(peek(ELIFS) == nbr_if){
				Maj(ELIFS->adrCond, QC);
				ELIFS = pop(ELIFS);
			}
			Maj(IFS->adrCond, QC);
			IFS = pop(IFS);
		}
		;

suite: INDENT entree_seule DEDENT;
	
exp: IDF {ErrorNonDeclaree($1); $$.res = getValeur($1); sprintf(buff, "%s", $1); $$.id = strdup(buff);}
	| ENTIER {$$.res = $1; sprintf(buff, "%d", $1); $$.id = strdup(buff);}
	| PO exp PF {$$.res = $2.res; sprintf(buff, "%s", $2.id); $$.id = strdup(buff);}
	| '-' exp {$$.res = $2.res * -1; sprintf(buff, "t%02d", temp++); $$.id = strdup(buff); Quad("-", $2.id, "", $$.id);}
	| exp '+' exp {$$.res = $1.res + $3.res; sprintf(buff, "t%02d", temp++); $$.id = strdup(buff); Quad("+", $1.id, $3.id, $$.id);}
	| exp '-' exp {$$.res = $1.res - $3.res; sprintf(buff, "t%02d", temp++); $$.id = strdup(buff); Quad("-", $1.id, $3.id, $$.id);}
	| exp '*' exp {$$.res = $1.res * $3.res; sprintf(buff, "t%02d", temp++); $$.id = strdup(buff); Quad("*", $1.id, $3.id, $$.id);}
	| exp '/' exp {;sprintf(buff, "t%02d", temp++); $$.id = strdup(buff); Quad("/", $1.id, $3.id, $$.id);}
	;

exp_cond: values comparateur values {
				Quad($2, "", $1.id, $3.id);
				if(ins_what==1){
					IFS = push(IFS);
				}else{
					ELIFS = push(ELIFS);
				}
				
				if(strcmp($2, "BG")){
					$$ = ($1.res <= $3.res)? 1 : 0 ;
				}else if(strcmp($2, "BL")){
					$$ = ($1.res >= $3.res)? 1 : 0 ;
				}else if(strcmp($2, "BNE")){
					$$ = ($1.res == $3.res)? 1 : 0 ;
				}else if(strcmp($2, "BE")){
					$$ = ($1.res <! $3.res)? 1 : 0 ;
				}else if(strcmp($2, "BGE")){
					$$ = ($1.res < $3.res)? 1 : 0 ;
				}else if(strcmp($2, "BLE")){
					$$ = ($1.res > $3.res)? 1 : 0 ;
				}
			}
		;

values: IDF {ErrorNonDeclaree($1); $$.res = getValeur($1); sprintf(buff, "%s", $1); $$.id = strdup(buff);}
		| ENTIER {$$.res = $1; sprintf(buff, "%d", $1); $$.id = strdup(buff);}
		;

comparateur: LE {$$ = "BG";}
			| GE {$$ = "BL";}
			| EQ {$$ = "BNE";}
			| NE {$$ = "BE";}
			| LT {$$ = "BGE";}
			| GT {$$ = "BLE";}
			;

%%
int yyerror(char* msg){
	textattr(12);
	printf("%s L=%d C=%d\n", msg, ligne, colonne);
	textattr(15);
	exit(0);
}
int main(){
	textattr(15);
	printf("\n");
	init();
	printf("\n");
	yyin = fopen("in.txt","r");
	if(yyparse()==0){
		textattr(5);
		printf("\n\t\t***********************************\n");
		printf("\t\t********Parsing Successfull********\t\t\n");
		printf("\t\t***********************************\n");
		textattr(15);
	}
	afficherTS();
	afficherQuad(1);
	optimisation();
	afficherQuad(0);
	codeAssem();
	fclose(yyin);
}
