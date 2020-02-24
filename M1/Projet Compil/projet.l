%{
#include <string.h>
#include "projet.tab.h"
#include "Headers/indentation.h"
#include "Headers/MyAtoi.h"
extern YYSTYPE yylval;
int ligne=1, colonne=1;
const int IND = 4;
int level = 0;
int end = 0, fake = 0;
%}
digit [0-9]
alpha [a-zA-Z]
entier {digit}+|"(""-"{digit}+")"
idf [A-Z][0-9a-z]*
%%

^[ \t]*\n {ligne++;}

^[ \t]* {
			int taille = indent_depth(yytext);
			int i, times;
			colonne += taille;
			int value = what_ind(taille);
			switch(value){
				case -1: yyerror("Erreur In/Dedentation");
					break;
				case 1: level = taille;
						return(INDENT);
						break;
				case -2: 
					times = (level - taille) / IND;
					for(i=0;i<times;i++){
						unput('$');
						fake++;
					}
					break;
			}
	}

^[a-zA-Z]+ {
	if(level == 0) REJECT;
	int i,times;
	char *yycopy = strdup( yytext );
	for ( i = yyleng - 1; i >= 0; --i ){
		unput( yycopy[i] );
	}
	free( yycopy );
	times = level / IND;
	for(i=0;i<times;i++){
		unput('$');
		fake++;
	}
}	

<<EOF>> {
	int i, times;
	times = level / IND;
	if(times == 0){
		yyterminate();
	}else{
		unput('@');
		end = 1;
	}
	for(i=0;i<times;i++){
		unput('$');
		fake++;
	}
}		

"@"	{if(end==1)yyterminate();REJECT;}
"$" {if(fake>0){fake--; level-=IND; return(DEDENT);} REJECT;}	
"int" {colonne+=yyleng; yylval.str=strdup(yytext); return(XINT);}
{entier} {colonne+=yyleng; if(MyAtoi(yytext)<=32767 && MyAtoi(yytext)>=-32768)yylval.num=MyAtoi(yytext);
			else ErrorDepassementTaille(); return(ENTIER);}
{idf} {colonne+=yyleng; yylval.str=strdup(yytext);if(yyleng>8){yyerror("IDF Trop Long");} return(IDF);}

"(" {colonne++; yylval.str=strdup(yytext); return (PO);}
")" {colonne++; yylval.str=strdup(yytext); return (PF);}
":" {colonne++; yylval.str=strdup(yytext); return (DP);}
"," {colonne++; yylval.str=strdup(yytext); return (VIRG);}

"-" {colonne++; yylval.str=strdup(yytext); return '-';}
"+" {colonne++; yylval.str=strdup(yytext); return '+';}
"*" {colonne++; yylval.str=strdup(yytext); return '*';}
"/" {colonne++; yylval.str=strdup(yytext); return '/';}
"=" {colonne++; yylval.str=strdup(yytext); return '=';}

if {colonne+=yyleng; yylval.str=strdup(yytext); return(IF);}
elif {colonne+=yyleng; yylval.str=strdup(yytext); return(ELIF);}
else {colonne+=yyleng; yylval.str=strdup(yytext); return(ELSE);}

for {colonne+=yyleng; yylval.str=strdup(yytext); return(FOR);}
range {colonne+=yyleng; yylval.str=strdup(yytext); return(RANGE);}
in {colonne+=yyleng; yylval.str=strdup(yytext); return(INN);}
while {colonne+=yyleng; yylval.str=strdup(yytext); return(WHILE);}

">" {colonne++; yylval.str=strdup(yytext); return(GT);}
">=" {colonne++; yylval.str=strdup(yytext); return(GE);}
"==" {colonne++; yylval.str=strdup(yytext); return(EQ);}
"!=" {colonne++; yylval.str=strdup(yytext);return(NE);}
"<=" {colonne++; yylval.str=strdup(yytext);return(LE);}
"<" {colonne++; yylval.str=strdup(yytext);return(LT);}

#.* {colonne+=yyleng; yylval.str=strdup(yytext);}
^[ \t]*#.*\n {ligne++; yylval.str=strdup(yytext);}
[\n] {colonne=1; ligne++; yylval.str=strdup(yytext);return SAUT;}
[\t] {colonne+=IND; yylval.str=strdup(yytext);}
" " {colonne++; yylval.str=strdup(yytext);}

. {yyerror("Erreur lexicale entite");}
%%
int yywrap () {return 1;}
