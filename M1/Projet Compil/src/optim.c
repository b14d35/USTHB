#include "../Headers/optim.h"
#include "../Headers/pile2.h"
#include "../Headers/TS.h"
#include "../Headers/quad.h"
#include <stdio.h>
// Rendre value à 0
void viderVars(){
	int i=0, j; 
	ELT* p;
	for (i=0;i<TAILLE;i++){
		if (TS[i]!=NULL){
			p=TS[i]; 
			while(p!=NULL){
				p->value = 0;
				p=p->svt;
			}
		}
	}
}

// Les variables utilisés dans un certain Quad
void usedVars(int x, char* y){
	int i;
	if(strcmp(q[x].op1, y) != 0 && isNumber(x, 1) == 0){
		int z = 0;
		if(q[x].op1[0] != 't'){
			z = getValeur(q[x].op1);
			insererValeur(q[x].op1, 1);
		}
		if(z == 0){
			for(i=x-1; i>-1; i--){
				if(strcmp(q[x].op1, q[i].res) == 0){
					usedVars(i, y);
					break;
				}
			}
			
		}
	}
	if(strcmp(q[x].op2, y) != 0 && strcmp(q[x].op2, "") != 0 && isNumber(x, 2) == 0){
		int z = 0;
		if(q[x].op2[0] != 't'){
			z = getValeur(q[x].op2);
			insererValeur(q[x].op2, 1); 
		}
		if(z == 0){
			for(i=x-1; i>-1; i--){
				if(strcmp(q[x].op2, q[i].res) == 0){
					usedVars(i, y);
					break;
				}
			}
		}
	}
}

// Si le resultat d'une variable utilisé dans un Quad a été changé
int hasChanged(int x){
	if(q[x].opr[0] != 'B' && q[x].res[0] != 't'){
		return getValeur(q[x].res);
	}
	return 0;
}

// Si une position dans le Quad est un nombre
int isNumber(int i, int y){
	if(y == 1){
		if((q[i].op1[0]>='0' && q[i].op1[0]<='9') || q[i].op1[0] == '-'){
			return 1;
		}
	}else if(y == 2){
		if((q[i].op2[0]>='0' && q[i].op2[0]<='9') || q[i].op2[0] == '-'){
			return 1;
		}
	}else if(y == 3){
		if((q[i].res[0]>='0' && q[i].res[0]<='9') || q[i].res[0] == '-'){
			return 1;
		}
	}
	return 0;
}

// Régler les numéros des Jump dans les Quad après suppression d'un Quad
void jump(int num){
	int i, j;
	for(i=num; i<QC; i++){
		q[i].opr = strdup(q[i+1].opr);
		q[i].op1 = strdup(q[i+1].op1);
		q[i].op2 = strdup(q[i+1].op2);
		q[i].res = strdup(q[i+1].res);
		for(j=0; j<4; j++){
			q[i].col[j] = q[i+1].col[j];
		}
	}
	QC--;
	for(i=0; i<=num; i++){
		if(q[i].opr[0] == 'B'){
			int x = atoi(q[i].op1);
			if(x>num){
				x--;
				char buff[10];
				sprintf(buff, "%02d", x);
				q[i].op1 = strdup(buff);
			}
		}
	}
	for(i=num+1; i<QC; i++){
		if(q[i].opr[0] == 'B'){
			int x = atoi(q[i].op1) - 1;
			char buff[10];
			sprintf(buff, "%02d", x);
			q[i].op1 = strdup(buff);
		}
	}
}

// Les temporaires non utilisés dans les Quad
void useless(){
	int i, j;
	for(i=0; i<QC-1; i++){
		if(q[i].res[0] == 't'){
			for(j=i+1; j<QC; j++){
				if(strcmp(q[i].res, q[j].op1) == 0 || strcmp(q[i].res, q[j].op2) == 0 || strcmp(q[i].res, q[j].res) == 0){
					break;
				}
			}
			if(j == QC){
				jump(i);
				modif = 1;
			}
		}
	}
}

// Réduction de multiplication et division et suite de -(exp) Quand exp est une constante
void mult_reduc(){
	int i;
	for(i=0; i<QC; i++){
		char op = q[i].opr[0];
		if(op == '*'){
			int x = atoi(q[i].op1);
			int y = atoi(q[i].op2);
			if(x == 1 && y == 1){
				q[i].opr = "=";
				q[i].op2 = "";
				getColor(i);
				modif = 1;
			}else if(y == 1){
				q[i].opr = "=";
				q[i].op2 = "";
				getColor(i);
				modif = 1;
			}else if(x == 1){
				q[i].opr = "=";
				q[i].op1 = strdup(q[i].op2);
				q[i].op2 = "";
				getColor(i);
				modif = 1;
			}else if(x == 2){
				q[i].opr = "+";
				q[i].op1 = strdup(q[i].op2);
				getColor(i);
				modif = 1;
			}else if(y == 2){
				q[i].opr = "+";
				q[i].op2 = strdup(q[i].op1);
				getColor(i);
				modif = 1;
			}
		}else if(op == '/'){
			int x = atoi(q[i].op2);
			if(x == 1){
				q[i].opr = "=";
				q[i].op2 = "";
				getColor(i);
				modif = 1;
			}
		}else if(op == '-'){
			if(strcmp(q[i].op2, "") == 0 && isNumber(i, 1)){
				int val = atoi(q[i].op1);
				val *= -1;
				q[i].opr = "=";
				char buff[10];
				sprintf(buff, "%d", val);
				q[i].op1 = strdup(buff);
				getColor(i);
				modif = 1;
			}
		}
	}
}

// t01 = (t02|cst|IDF) ==> remplacer tous les apparences de t01 avec (t02|cst|IDF)
void copie(){
	int i, j;
	for(i=0; i<QC-1; i++){
		char c = q[i].opr[0];
		if(c == '=' && q[i].res[0] == 't'){
			usedVars(i, q[i].res);
			for(j=i+1; j<QC; j++){
				if(hasChanged(j) == 1){
					break;
				}
				char op = q[j].opr[0];
				if(op != 'B'){
					if(strcmp(q[j].op1, q[i].res) == 0){
						q[j].op1 = strdup(q[i].op1);
						modif = 1;
					}
					if(strcmp(q[j].op2, q[i].res) == 0){
						q[j].op2 = strdup(q[i].op1);
						modif = 1;
					}
					getColor(j);
				}
			}
			viderVars();
		}
	}
}

// t01 = A * B; t02 = A * B; ==> t01 = A * B; t02 = t01;
void expression(){
	int i, j;
	for(i=0; i<QC-1; i++){
		usedVars(i, q[i].res);
		char c = q[i].opr[0];
		if(c != '=' && c != 'B'){
			pile2 *quads = NULL;
			int changed = 0;
			for(j=i+1; j<QC; j++){
				if(changed == 1){
					changed = 0;
					if(empty2(quads) != 1){
						j = peek2(quads);
						quads = pop2(quads);
					}
				}
				char op = q[j].opr[0];
				if(op == 'B'){
					if(strcmp(q[j].opr, "BR") == 0){
						changed = 1;
						continue;
					}else{
						quads = push2(quads, atoi(q[j].op1));
						continue;
					}
					
				}
				else if(hasChanged(j) == 1){
					changed = 1;
					continue;
				}
				if(c == op){
					switch(c){
						case '+':
						case '*':
							if(strcmp(q[i].op1, q[j].op1)==0 && strcmp(q[i].op2, q[j].op2)==0 || strcmp(q[i].op1, q[j].op2)==0 && strcmp(q[i].op2, q[j].op1)==0){
								q[j].opr = "=";
								q[j].op1 = strdup(q[i].res);
								q[j].op2 = "";
								getColor(j);
								modif = 1;
							}
							break;
						case '/':
						case '-':
							if(strcmp(q[i].op1, q[j].op1)==0 && strcmp(q[i].op2, q[j].op2)==0){
								q[j].opr = "=";
								q[j].op1 = strdup(q[i].res);
								q[j].op2 = "";
								getColor(j);
								modif = 1;
							}
							break;
					}
				}
				if(strcmp(q[i].res, q[j].res) == 0){
					break;
				}
			}
		}
		viderVars();
	}
}

// Nombre de constante dans un Quad
int constante(int ind){
	int cmp = 0;
	cmp += isNumber(ind, 1) + isNumber(ind, 2);
	return cmp;
}

// Simplification algébrique t01 = J + 1; t02 = t01 - 1; ==> t02 = J;
void propa(){
	int i, j;
	for(i=0; i<QC-1; i++){
		usedVars(i, q[i].res);
		char d = q[i].opr[0];
		if((d == '+' || d == '-') && constante(i)>0){
			pile2 *quads = NULL;
			int changed = 0;
			for(j=i+1; j<QC; j++){
				if(changed == 1){
					changed = 0;
					if(empty2(quads) != 1){
						j = peek2(quads);
						quads = pop2(quads);
					}
				}
				char c = q[j].opr[0];
				if(c == 'B'){
					if(strcmp(q[j].opr, "BR") == 0){
						changed = 1;
						continue;
					}else{
						quads = push2(quads, atoi(q[j].op1));
						continue;
					}
				}
				else if(hasChanged(j) == 1){
					changed = 1;
					continue;
				}
				if(hasChanged(j) == 1){
					changed = 1;
					continue;
				}
				if((c == '+' || c == '-') && constante(j) == 1){
					if(strcmp(q[i].res, q[j].op1) == 0 ){
						int val = atoi(q[j].op2);
						if(c == '-'){
							val *= -1;
						}
						int done = 0;
						if(isNumber(i, 1) == 1){
							int val2 = atoi(q[i].op1);
							if(val + val2 == 0){
								if(q[i].opr[0] == '+'){
									q[j].opr = "=";
								}else{
									q[j].opr = "-";
								}
								q[j].op1 = strdup(q[i].op2);
								q[j].op2 = "";
								getColor(j);
								done = 1;
								modif = 1;
							}
						}
						if(done == 0 && isNumber(i, 2) == 1){
							int val2 = atoi(q[i].op2);
							if(d == '-'){
								val2 *= -1;
							}
							if(val + val2 == 0){
								q[j].opr = "=";
								q[j].op1 = strdup(q[i].op1);
								q[j].op2 = "";
								getColor(j);
								modif = 1;
							}
						}
					}else if(strcmp(q[i].res, q[j].op2) == 0){
						int val = atoi(q[j].op1);
						int done = 0;
						if(isNumber(i, 1) == 1){
							int val2 = atoi(q[i].op1);
							if(c == '-'){
								val2 *= -1;
							}
							if(val + val2 == 0){
								if(d == c){
									q[j].opr = "=";
								}else{
									q[j].opr = "-";
								}
								q[j].op1 = strdup(q[i].op2);
								q[j].op2 = "";
								getColor(j);
								done = 1;
								modif = 1;
							}
						}
						if(done == 0 && isNumber(i, 2) == 1){
							int val2 = atoi(q[i].op2);
							if(d != c){
								val2 *= -1;
							}
							if(val + val2 == 0){
								if(c == '+'){
									q[j].opr = "=";
								}else{
									q[j].opr = "-";
								}
								q[j].op1 = strdup(q[i].op1);
								q[j].op2 = "";
								getColor(j);
								modif = 1;
							}
						}
					}
				}
			}
			if(q[i+1].opr[0] == '=' && strcmp(q[i].res, q[i+1].op1) == 0){
				pile2 *quads = NULL;
				int changed = 0;
				for(j=i+2; j<QC; j++){
					if(changed == 1){
						changed = 0;
						if(empty2(quads) != 1){
							j = peek2(quads);
							quads = pop2(quads);
						}
					}
					char c = q[j].opr[0];
					if(hasChanged(j) == 1){
						changed = 1;
						continue;
					}
					if(c == 'B'){
						if(strcmp(q[j].opr, "BR") == 0){
							changed = 1;
							continue;
						}else{
							quads = push2(quads, atoi(q[j].op1));
							continue;
						}
					}
					else if(hasChanged(j) == 1){
						changed = 1;
						continue;
					}
					if(hasChanged(j) == 1){
						changed = 1;
						continue;
					}
					if((c == '+' || c == '-') && constante(j) == 1){
						if(strcmp(q[i+1].res, q[j].op1) == 0 ){
							int val = atoi(q[j].op2);
							if(c == '-'){
								val *= -1;
							}
							int done = 0;
							if(isNumber(i, 1) == 1){
								int val2 = atoi(q[i].op1);
								if(val + val2 == 0){
									if(q[i].opr[0] == '+'){
										q[j].opr = "=";
									}else{
										q[j].opr = "-";
									}
									q[j].op1 = strdup(q[i].op2);
									q[j].op2 = "";
									getColor(j);
									done = 1;
									modif = 1;
								}
							}
							if(done == 0 && isNumber(i, 2) == 1){
								int val2 = atoi(q[i].op2);
								if(d == '-'){
									val2 *= -1;
								}
								if(val + val2 == 0){
									q[j].opr = "=";
									q[j].op1 = strdup(q[i].op1);
									q[j].op2 = "";
									getColor(j);
									modif = 1;
								}
							}
						}else if(strcmp(q[i+1].res, q[j].op2) == 0){
							int val = atoi(q[j].op1);
							int done = 0;
							if(isNumber(i, 1) == 0){
								int val2 = atoi(q[i].op1);
								if(c == '-'){
									val2 *= -1;
								}
								if(val + val2 == 0){
									if(d == c){
										q[j].opr = "=";
									}else{
										q[j].opr = "-";
									}
									q[j].op1 = strdup(q[i].op2);
									q[j].op2 = "";
									getColor(j);
									done = 1;
									modif = 1;
								}
							}
							if(done == 0 && isNumber(i, 2) == 1){
								int val2 = atoi(q[i].op2);
								if(d != c){
									val2 *= -1;
								}
								if(val + val2 == 0){
									if(c == '+'){
										q[j].opr = "=";
									}else{
										q[j].opr = "-";
									}
									q[j].op1 = strdup(q[i].op1);
									q[j].op2 = "";
									getColor(j);
									modif = 1;
								}
							}
						}
					}
				}
			}
		}
		viderVars();
	}
}

// Si une variable est utilisé une seule fois après sa déclaration, on la remplace avec son temporaire
void propag_exp(){
	int i=0, j; 
	ELT* p;
	for (i=0;i<TAILLE;i++){
		if (TS[i]!=NULL){
			p=TS[i]; 
			while(p!=NULL){
				int count=0, equalQuad = -1, otherQuad = -1;
				for(j=0; j<QC; j++){
					if(q[j].opr[0] == '=' && strcmp(q[j].res, p->IDF) == 0){
						if(strcmp(q[j].op1, p->IDF) == 0){
							count++;
						}
						count++;
						if(otherQuad != -1){
							break;
						}
						if(equalQuad == -1){
							equalQuad = j;
						}else{
							break;
						}
					}else if(q[j].opr[0] == 'B'){
						if(strcmp(q[j].op1, p->IDF) == 0){
							count++;
							if(otherQuad == -1){
								otherQuad = j;
							}else{
								break;
							}
						}else if(strcmp(q[j].op2, p->IDF) == 0){
							count++;
							if(otherQuad == -1){
								otherQuad = j;
							}else{
								break;
							}
						}
					}else{
						if(strcmp(q[j].op1, p->IDF) == 0){
							count++;
							if(otherQuad == -1){
								otherQuad = j;
							}else{
								break;
							}
						}else if(strcmp(q[j].op2, p->IDF) == 0){
							count++;
							if(otherQuad == -1){
								otherQuad = j;
							}else{
								break;
							}
						}
					}
					if(count>2){
						break;
					}
				}
				if(j == QC && count == 2 && otherQuad != -1 && equalQuad != -1){
					if(strcmp(q[otherQuad].op1, p->IDF) == 0){
						q[otherQuad].op1 = strdup(q[equalQuad].op1);
					}else{
						q[otherQuad].op2 = strdup(q[equalQuad].op1);
					}
					getColor(otherQuad);
					modif = 1;
				}
				p=p->svt;
			}
		}
	}
}

// Extraction du numéro du temporaire
int num_temp(int i, int y){
	char temp[10];
	if(y == 1){
		strcpy(temp, q[i].op1 + 1);
	}else if(y == 2){
		strcpy(temp, q[i].op2 + 1);
	}else if(y == 3){
		strcpy(temp, q[i].res + 1);
	}
	return atoi(temp);
}

// Changer les nums des temps pour optimiser la pile
void temps(){
	int nbr = 0, i, j, var=0;
	for(i=0; i<QC; i++){
		if(q[i].res[0] == 't'){
			int x = num_temp(i, 3);
			if(x>nbr){
				nbr = x;
			}
		}
	}
	int tmp[nbr];
	for(i=0; i<nbr; i++){
		tmp[i] = 0;
	}
	for(i=0; i<QC; i++){
		if(q[i].res[0] == 't'){
			tmp[num_temp(i, 3) - 1] = 1;
		}
	}
	int fin = nbr - 1;
	for(i=0; i<fin; i++){
		if(tmp[i] == 0){
			nbr_temps--;
			while(tmp[fin] != 1){
				fin--;
			}
			if(fin<=i){
				break;
			}
			tmp[fin] = 0;
			for(j=0; j<QC; j++){
				char replace[5];
				char toreplace[5];
				sprintf(replace, "t%02d", i+1);
				sprintf(toreplace, "t%02d", fin+1);
				if(strcmp(q[j].op1, toreplace) == 0){
					q[j].op1 = strdup(replace);
				}
				if(strcmp(q[j].op2, toreplace) == 0){
					q[j].op2 = strdup(replace);
				}
				if(strcmp(q[j].res, toreplace) == 0){
					q[j].res = strdup(replace);
				}
			}
			fin--;
		}
	}
	while(tmp[nbr-1] == 0){
		nbr--;
	}
	nbr_temps = nbr;
}

void optimisation(){
	while(modif){
		modif = 0;
		propag_exp();
		expression();
		copie();
		propa();
		mult_reduc();
		useless();
	}
	temps();
}
