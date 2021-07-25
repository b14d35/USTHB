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
int num_quad = 0;
char buff[10];
char buff2[10];
pile *JUMPS = NULL;
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

%token <num>ENTIER <flo>NUMERIC <str>CHARACTER <str>LOGICAL <str>IDF COMMENT
%token <str>XINT <str>XNUM <str>XCHAR
%token <str>IF <str>ELSE <str>ELIF <str>IFELSE
%token <str>FOR <str>INN <str>WHILE
%token DP VIRG SAUT INC DEC
%token INDENT DEDENT

%type<str> usage comparateur
%type<NT> exp values aff_suite
%type<num> exp_cond elif_stmt else_stmt

%left LE GE EQ NE LT GT
%left '+' '-'
%left '*' '/'
%left '%'
%left PO PF
%left CO CF
%left AO AF
%left AND OR
%union {char* nom;}
%start entree_seule
%%

entree_seule: simple_stmt entree_seule
			| if_stmt entree_seule
			| for_stmt entree_seule
			| while_stmt entree_seule
			|
			;

for_stmt: FOR PO IDF {ErrorNonDeclaree($3);} INN ENTIER DP ENTIER {RangeEronne($6, $8);} PF SAUT {sprintf(buff, "%d", $6); Quad("=", strdup(buff), "", $3); sprintf(buff2, "%d", $8);Quad("BG", "", $3, strdup(buff2)); JUMPS = push(JUMPS);} suite {sprintf(buff2, "t%02d", temp++); Quad("+", $3, "1", strdup(buff2)); Quad("=", strdup(buff2), "", $3); Maj(JUMPS->adrCond, QC + 1); JUMPS = pop(JUMPS); sprintf(buff, "%02d", num_quad); Quad("BR", strdup(buff), "", "");};

while_stmt: WHILE exp_cond {JUMPS = push(JUMPS);} SAUT suite {Maj(JUMPS->adrCond, QC + 1); JUMPS = pop(JUMPS); sprintf(buff, "%02d", num_quad); Quad("BR", strdup(buff), "", "");};
			
if_stmt: IF exp_cond {JUMPS = push(JUMPS);} SAUT suite elif_stmt {if ($6 == 1) {Maj(JUMPS->adrCond, QC); JUMPS = pop(JUMPS);} if ($6 == 3) {Maj(JUMPS->adrCond, QC); JUMPS = pop(JUMPS);}};

elif_stmt: {Maj(JUMPS->adrCond, QC + 1); JUMPS = pop(JUMPS); Quad("BR", "", "", ""); JUMPS = push(JUMPS);} ELIF exp_cond {JUMPS = push(JUMPS);} SAUT suite else_stmt {if ($7 == 1) $$ = 4; else $$ = 3; if($$ == 4) Maj(JUMPS->adrCond, QC); else Maj(JUMPS->adrCond, QC); JUMPS = pop(JUMPS);}
		| else_stmt {if ($1 == 1) $$ = 2; else $$ = 1;}
		;
		 
else_stmt: {Maj(JUMPS->adrCond, QC + 1); JUMPS = pop(JUMPS); Quad("BR", "", "", ""); JUMPS = push(JUMPS);} ELSE SAUT suite {Maj(JUMPS->adrCond, QC); JUMPS = pop(JUMPS); if($$ == 1){Maj(JUMPS->adrCond, QC + 1); JUMPS = pop(JUMPS);} $$ = 1;}
		| {$$ = 0;}
		;
		
suite: AO SAUT entree_seule AF SAUT;
			
simple_stmt: increment_stmt SAUT
			| decrement_stmt SAUT
			| declaration_stmt SAUT
			| affectation_stmt SAUT
			;
			
affectation_stmt: aff_suite exp {Quad("=", $2.id, "", $1.id);}
				| aff_suite IFELSE PO exp_cond {JUMPS = push(JUMPS);} VIRG exp 
				{ErrorNonDeclaree($1.id); Quad("=", $7.id, "", $1.id);Maj(JUMPS->adrCond, QC + 1); JUMPS = pop(JUMPS); Quad("BR", "", "", ""); JUMPS = push(JUMPS);} 
				VIRG exp PF {Quad("=", $10.id, "", $1.id); Maj(JUMPS->adrCond, QC); JUMPS = pop(JUMPS);}
				;
aff_suite: IDF '=' {ErrorNonDeclaree($1); sprintf(buff, "%s", $1); $$.id = strdup(buff);}
		;
			
increment_stmt: IDF INC ENTIER {ErrorNonDeclaree($1); sprintf(buff, "%d", $3); sprintf(buff2, "t%02d", temp++); Quad("+", $1, strdup(buff), strdup(buff2)); Quad("=", strdup(buff2), "", $1);};

decrement_stmt: IDF DEC ENTIER {ErrorNonDeclaree($1); sprintf(buff, "%d", $3); sprintf(buff2, "t%02d", temp++); Quad("+", $1, strdup(buff), strdup(buff2)); Quad("=", strdup(buff2), "", $1);};

declaration_stmt: types liste;
				;

types: XINT;

liste: liste2
	| usage '=' exp {Quad("=", $3.id, "", $1);}
	;
	
liste2: usage | usage VIRG liste2;

usage: IDF  {if(ErrorDoubleDeclaration($1) != 1)inserer($1, 1, 1, 0);}
	;

comparateur: LE {$$ = "BG";}
			| GE {$$ = "BL";}
			| EQ {$$ = "BNE";}
			| NE {$$ = "BE";}
			| LT {$$ = "BGE";}
			| GT {$$ = "BLE";}
			;

exp: IDF {ErrorNonDeclaree($1); $$.res = getValeur($1); sprintf(buff, "%s", $1); $$.id = strdup(buff);}
	| ENTIER {$$.res = $1; sprintf(buff, "%d", $1); $$.id = strdup(buff);}
	| PO exp PF {$$.res = $2.res; sprintf(buff, "%s", $2.id); $$.id = strdup(buff);}
	| '-' exp {$$.res = $2.res * -1; sprintf(buff, "t%02d", temp++); $$.id = strdup(buff); Quad("-", $2.id, "", $$.id);}
	| exp '+' exp {$$.res = $1.res + $3.res; sprintf(buff, "t%02d", temp++); $$.id = strdup(buff); Quad("+", $1.id, $3.id, $$.id);}
	| exp '-' exp {$$.res = $1.res - $3.res; sprintf(buff, "t%02d", temp++); $$.id = strdup(buff); Quad("-", $1.id, $3.id, $$.id);}
	| exp '*' exp {$$.res = $1.res * $3.res; sprintf(buff, "t%02d", temp++); $$.id = strdup(buff); Quad("*", $1.id, $3.id, $$.id);}
	| exp '/' exp {;sprintf(buff, "t%02d", temp++); $$.id = strdup(buff); Quad("/", $1.id, $3.id, $$.id);}
	;

values: IDF {ErrorNonDeclaree($1); $$.res = getValeur($1); sprintf(buff, "%s", $1); $$.id = strdup(buff);}
		| ENTIER {$$.res = $1; sprintf(buff, "%d", $1); $$.id = strdup(buff);}
		;

exp_cond: PO values comparateur values PF {
				Quad($3, "", $2.id, $4.id);
				
				if(strcmp($3, "BG")){
					$$ = ($2.res <= $4.res)? 1 : 0 ;
				}else if(strcmp($3, "BL")){
					$$ = ($2.res >= $4.res)? 1 : 0 ;
				}else if(strcmp($3, "BNE")){
					$$ = ($2.res == $4.res)? 1 : 0 ;
				}else if(strcmp($3, "BE")){
					$$ = ($2.res <! $4.res)? 1 : 0 ;
				}else if(strcmp($3, "BGE")){
					$$ = ($2.res < $4.res)? 1 : 0 ;
				}else if(strcmp($3, "BLE")){
					$$ = ($2.res > $4.res)? 1 : 0 ;
				}
			}
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
