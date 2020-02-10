%{
#include "synt.tab.h"
#include "Fonctions.h"
#include "Errors.h"
int nbligne=1;
int nbcolone=1;
extern YYSTYPE yylval;
void commentaire(char x[]){
	int i;
	for(i=0;i<strlen(x);i++){
		if(x[i]=='\n'){nbcolone=1;nbligne++;}
		else nbcolone++;
	}
}
%}

idf [a-zA-Z][a-zA-Z0-9_]*
integer [-+]?[0-9]+
real [-+]?[0-9]+"."[0-9]+
string \".*\"
comp <|>|<=|>=|=|!=
%%
[Aa][Ll][Gg][Oo][Rr][Ii][Tt][Hh][Mm][Ee] {nbcolone+=yyleng;return mc_algo;}
[Vv][Aa][Rr] {nbcolone+=yyleng;return mc_var;}
[Dd][Ee][Bb][Uu][Tt] {nbcolone+=yyleng;return mc_deb;}
[Ff][Ii][Nn] {nbcolone+=yyleng;return mc_fin;}
[Pp][Oo][Uu][Rr] {nbcolone+=yyleng;return mc_pour;}
[Jj][Uu][Ss][Qq][Uu][Ee] {nbcolone+=yyleng;return mc_jusque;}
[Ff][Aa][Ii][Rr][Ee] {nbcolone+=yyleng;return mc_faire;}
[Ff][Aa][Ii][Tt] {nbcolone+=yyleng;return mc_fait;}
[Ss][Ii] {nbcolone+=yyleng;return mc_si;}
; {nbcolone++;return pvg;}
: {nbcolone++;return mc_dp;}
"<--" {nbcolone+=3;return mc_aff;}
\( {nbcolone++;return mc_po;}
\) {nbcolone++;return mc_pf;}
\[ {nbcolone++;return mc_co;}
\] {nbcolone++;return mc_cf;}
\| {nbcolone++;return mc_bar;}

\+ {nbcolone++;return '+';}
\- {nbcolone++;return '-';}
\/ {nbcolone++;return '/';}
\* {nbcolone++;return '*';}

"//"(.)* nbcolone+=yyleng;
"/*"[^*/]*"*/" {commentaire(yytext);}
entier {nbcolone+=yyleng;yylval.str=strdup(yytext);return mc_entier;}
reel {nbcolone+=yyleng;yylval.str=strdup(yytext);return mc_reel;}
chaine {nbcolone+=yyleng;yylval.str=strdup(yytext);return mc_chaine;}

{idf}  {nbcolone+=yyleng;if (yyleng>12){ErrorLongueurIdf(yytext);}
		yylval.str=strdup(yytext);return idf;}
{real} {nbcolone+=yyleng;yylval.flo=atoi(yytext);return real;}
{integer} {nbcolone+=yyleng;if(atoi(yytext)<=32657 && atoi(yytext)>=-32658)yylval.num=atoi(yytext);
			else ErrorDepassementTaille();
			return integer;}
{string} {nbcolone+=yyleng;yylval.str=strdup(yytext);return string;}
{comp} {nbcolone+=yyleng;return comp;}
[ ] {nbcolone++;}
[\t] {nbcolone+=4;}
\n {nbligne++;nbcolone=1;}
. printf("erreur lexicale ligne %d colonne %d\n \n",nbligne,nbcolone);
%%
int yyerror(char *msg){
	textattr(12);
	printf("Erreur Ligne:%d - colonne:%d : %s encountred\n",nbligne,nbcolone,msg);
	textattr(15);
}

int yywrap(){
	return 1;
}
