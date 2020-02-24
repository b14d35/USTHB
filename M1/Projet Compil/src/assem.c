#include "../Headers/assem.h"
#include "../Headers/TS.h"
#include "../Headers/quad.h"
#include <stdio.h>
void codeAssem(){
	int jumps[QC+1];
	FILE *f = fopen("code.asm", "w");
	fputs("TITLE code.asm: Exemple mini-python\n", f);
	fputs("Pile segment stack\n", f);
	fprintf(f, "\tDW %d dup(?)\n", nbr_temps+3);
	fputs("Pile ends\n", f);
	fputs("DATA segment\n", f);
	int i=0; ELT* p;
	for (i=0;i<TAILLE;i++){
		if (TS[i]!=NULL){
			p=TS[i]; 
			while(p!=NULL){
				fprintf(f, "\t%s DW ?\n",p->IDF);
				p=p->svt;
			}
		}
	}
	fputs("DATA ends\n", f);
	fputs("CODE segment\n", f);
	fputs("\tMAIN:\n", f);
	fputs("\t\tASSUME CS:CODE, DS:DATA, SS:Pile\n", f);
	fputs("\t\tMOV AX, data\n", f);
	fputs("\t\tMOV DS, AX\n", f);
	fputs("\t\tMOV AX, Pile\n", f);
	fputs("\t\tMOV SS, AX\n", f);
	for(i=0; i<QC; i++){
		jumps[i] = 0;
	}
	for(i=0; i<QC; i++){
		char c = q[i].opr[0];
		if(c == 'B'){
			int x = atoi(q[i].op1);
			jumps[x] = 1;
		}
	}
	for(i=0; i<QC; i++){
		if(jumps[i] == 1){
			fprintf(f, "\tetiq%02d:\n", i);
		}
		char c = q[i].opr[0];
		fprintf(f, "\t\t;Quad(%s, %s, %s, %s)\n", q[i].opr, q[i].op1, q[i].op2, q[i].res);
		switch(c){
			// Les operations vers une variable
			case '+':
			case '-':
			case '/':
			case '*':
				if(q[i].op1[0] == 't'){
					int x = num_temp(i, 1);
					fprintf(f, "\t\tMOV SP, %d\n", (x-1)*2);
					if(strcmp(q[i].op2, "") == 0){
						fprintf(f, "\t\tPOP BX\n");
					}else{
						fprintf(f, "\t\tPOP AX\n");
					}
				}else{
					if(strcmp(q[i].op2, "") != 0){
						fprintf(f, "\t\tMOV AX, %s\n", q[i].op1);
					}
				}
				int cas = 0;
				if(q[i].op2[0] == 't'){
					int x = num_temp(i, 2);
					fprintf(f, "\t\tMOV SP, %d\n", (x-1)*2);
					fprintf(f, "\t\tPOP BX\n");
					cas = 2;
				}
				if(c == '/' || c == '*'){
					if(isNumber(i, 2) == 1){
						fprintf(f, "\t\tMOV BX, %s\n", q[i].op2);
						cas = 2;
					}
				}
				if(cas == 2){
					switch(c){
						case '+':
							fprintf(f, "\t\tADD AX, BX\n");
							break;
						case '-':
							fprintf(f, "\t\tSUB AX, BX\n");
							break;
						case '*':
							fprintf(f, "\t\tMUL BX\n");
							break;
						case '/':
							fprintf(f, "\t\tDIV BX\n");
							break;
					}
				}else{
					switch(c){
						case '+':
							fprintf(f, "\t\tADD AX, %s\n", q[i].op2);
							break;
						case '-':
							if(strcmp(q[i].op2, "") == 0){
								fprintf(f, "\t\tMOV AX, 0\n");
								if(q[i].op1[0] == 't'){
									fprintf(f, "\t\tSUB AX, BX\n");
								}else{
									fprintf(f, "\t\tSUB AX, %s\n", q[i].op1);
								}
							}else{
								fprintf(f, "\t\tSUB AX, %s\n", q[i].op2);
							}
							break;
						case '*':
							fprintf(f, "\t\tMUL %s\n", q[i].op2);
							break;
						case '/':
							fprintf(f, "\t\tDIV %s\n", q[i].op2);
							break;
					}
				}
				int x = num_temp(i, 3);
				fprintf(f, "\t\tMOV SP, %d\n", x*2);
				fprintf(f, "\t\tPUSH AX\n");
				break;
			case '=':
				if(isNumber(i, 1) == 1){
					cas = 1;
				}else if(q[i].op1[0] == 't'){
					int x = num_temp(i, 1);
					fprintf(f, "\t\tMOV SP, %d\n", (x-1)*2);
					fprintf(f, "\t\tPOP AX\n");
					cas = 0;
				}else{
					fprintf(f, "\t\tMOV AX, %s\n", q[i].op1);
					cas = 0;
				}
				if(cas == 1){
					if(q[i].res[0] != 't'){
						fprintf(f, "\t\tMOV %s, %s\n", q[i].res, q[i].op1);
					}else{
						int x = num_temp(i, 3);
						fprintf(f, "\t\tMOV SP, %d\n", x*2);
						fprintf(f, "\t\tPUSH AX\n");
					}
				}else{
					if(q[i].res[0] != 't'){
						fprintf(f, "\t\tMOV %s, AX\n", q[i].res);
					}else{
						int x = num_temp(i, 3);
						fprintf(f, "\t\tMOV SP, %d\n", x*2);
						fprintf(f, "\t\tPUSH AX\n");
					}
				}
				break;
			case 'B':
				if(q[i].opr[1] == 'R'){
					fprintf(f, "\t\t  JMP etiq%s\n", q[i].op1);
				}else{
					int cas = 0;
					int temp1 = 0, temp2;
					if(q[i].op2[0] == 't'){
						temp1 = 1;
					}
					if(q[i].res[0] == 't'){
						temp2 = 1;
					}
					if(isNumber(i, 2) == 1){
						fprintf(f, "\t\tMOV CX, %s\n", q[i].op2);
						cas = 1;
					}
					if(cas == 0){
						if(isNumber(i, 3) == 0){
							fprintf(f, "\t\tMOV CX, %s\n", q[i].res);
							cas = 2;
						}
					}
					switch(cas){
						case 0:
							if(temp1 == 1 && temp2 == 1){
								int x = num_temp(i, 2);
								fprintf(f, "\t\tMOV SP, %d\n", (x-1)*2);
								fprintf(f, "\t\tPOP CX\n");
								int y = num_temp(i, 3);
								fprintf(f, "\t\tMOV SP, %d\n", (y-1)*2);
								fprintf(f, "\t\tPOP BX\n");
								fprintf(f, "\t\tCMP CX, BX\n");
							}else if(temp1 == 1){
								int x = num_temp(i, 2);
								fprintf(f, "\t\tMOV SP, %d\n", (x-1)*2);
								fprintf(f, "\t\tPOP CX\n");
								fprintf(f, "\t\tCMP CX, %s\n", q[i].res);
							}else if(temp2 == 1){
								int x = num_temp(i, 3);
								fprintf(f, "\t\tMOV SP, %d\n", (x-1)*2);
								fprintf(f, "\t\tPOP CX\n");
								fprintf(f, "\t\tCMP %s, CX\n", q[i].op1);
							}else{
								fprintf(f, "\t\tCMP %s, %s\n", q[i].op2, q[i].res);
							}
							break;
						case 1:
							if(temp2 == 1){
								int x = num_temp(i, 3);
								fprintf(f, "\t\tMOV SP, %d\n", (x-1)*2);
								fprintf(f, "\t\tPOP BX\n");
								fprintf(f, "\t\tCMP CX, BX\n");
							}else{
								fprintf(f, "\t\tCMP CX, %s\n", q[i].res);
							}
							break;
						case 2:
							fprintf(f, "\t\tCMP %s, CX\n", q[i].op2);
							break;
					}
					char *temp = strdup(q[i].opr);
					temp[0] = 'J';
					fprintf(f, "\t\t%s etiq%s\n", temp, q[i].op1);
				}
				break;
		}
	}
	if(jumps[QC] == 1){
		fprintf(f, "\tetiq%02d:\n", QC);
	}
	fputs("\t\tENDS\n", f);
	fputs("\tEND MAIN\n", f);
	fclose(f);
}
