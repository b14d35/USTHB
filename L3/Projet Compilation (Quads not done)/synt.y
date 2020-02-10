%{
char suavType [20];
extern int nbligne;
extern int nbcolone;
%}

%union {
int num;
float flo;
char* str;
}
%token mc_algo <str>idf mc_deb mc_var mc_fin pvg <str>mc_reel <str>mc_entier <str>mc_chaine mc_dp mc_bar
%token  <flo>real <num>integer <str>string comp mc_po mc_pf mc_co mc_cf
%token mc_aff mc_pour mc_jusque mc_faire mc_fait mc_si

%start project
%%
project: entete PART_DEC mc_deb INST mc_fin{printf("\t\tProgramme Syntaxiquement Correct\n");}
;
entete: mc_algo idf {inserer($2);insererCode($2,"Nom Algo");}
;
PART_DEC : mc_var DEC |
;
DEC: VARIABLES mc_dp TYPE pvg DEC | VARIABLES mc_dp TYPE pvg
;
TYPE: mc_entier {insererType2("Entier");}| mc_reel {insererType2("Reel");}| mc_chaine {insererType2("Chaine");}
;
VARIABLES: idf {if(doubleDeclaration($1)){ErrorDoubleDeclaration($1);}
		inserer($1);insererCode($1,"Variable");insererType($1,"a");}
			|VARIABLES mc_bar idf {if(doubleDeclaration($3)){ErrorDoubleDeclaration($3);}
		inserer($3);insererCode($3,"Variable");insererType($3,"a");}
			| idf mc_co integer mc_cf{if(doubleDeclaration($1)){ErrorDoubleDeclaration($1);}
		inserer($1);insererCode($1,"Tableau");insererType($1,"a");insererTaille($1,$3);}
		    | VARIABLES mc_bar idf mc_co integer mc_cf{if(doubleDeclaration($3)){ErrorDoubleDeclaration($3);}
		inserer($3);insererCode($3,"Tableau");insererType($3,"a");insererTaille($3,$5);}
;
INST: INST AFFECTATION {if(nonCompatible())ErrorNonCompatibilite();}
		| INST BOUCLE | INST CONDITION |
;
AFFECTATION: idf {init();ajouter($1);if(nonDeclare($1))ErrorNonDeclaree($1);}
				mc_aff  OP_AR pvg
				| idf mc_co integer {init();ajouter($1);if(nonDeclare($1))ErrorNonDeclaree($1);}
				{if(tailleTableauDepasse($1,$3))ErrorTailleDepassee();}
				mc_cf mc_aff OP_AR pvg
			
;
OP_AR: CONST | OP_AR '*' CONST 
			 | OP_AR '+' CONST
			 | OP_AR '-' CONST 
			 | OP_AR real | OP_AR integer
			 | OP_AR '/' real {if($3==0.0)ErrorDivisionParZero();}
			 | OP_AR '/' idf {if(nonDeclare($3)) ErrorNonDeclaree($3);}
			 | OP_AR '/' integer {if($3==0)ErrorDivisionParZero()}
;
CONST : real {ajouter("Reel");}
 | integer {ajouter("Entier");}
 | string {ajouter("Chaine");} 
 | idf mc_co integer mc_cf {if(nonDeclare($1))ErrorNonDeclaree($1);if(tailleTableauDepasse($1,$3))ErrorTailleDepassee();}
 | idf {ajouter($1);if(nonDeclare($1))ErrorNonDeclaree($1);}
;
BOUCLE: mc_pour idf {init();ajouter($2);if(nonDeclare($2))ErrorNonDeclaree($2);}
		mc_aff OP_AR mc_jusque VAL mc_faire INST mc_fait
		
;
VAL: integer | idf {if(nonDeclare($1))ErrorNonDeclaree($1);}
;
CONDITION: mc_faire INST mc_si mc_po idf {init();ajouter($5);if(nonDeclare($5))ErrorNonDeclaree($5);}
		comp CONST mc_pf 	
;
%%
main(){
yyparse();
afficher();
}
