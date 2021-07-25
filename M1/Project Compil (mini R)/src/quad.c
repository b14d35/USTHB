#include "../Headers/quad.h"

void getColor(int i){
	switch(q[i].opr[0]){
		case '+':
		case '-':
		case '*':
		case '/':
			q[i].col[0] = 10;
			break;
		case '=':
			q[i].col[0] = 11;
			break;
		default:
			q[i].col[0] = 12;
			break;
	}
	switch(q[i].col[0]){
		case 10:
		case 11:
			if(q[i].op1[0] == 't'){
				q[i].col[1] = 8;
			}else if((q[i].op1[0]>='0' && q[i].op1[0]<='9') || q[i].op1[0] == '-'){
				q[i].col[1] = 13;
			}else{
				q[i].col[1] = 9;
			}
			break;
		case 12:
			q[i].col[1] = 14;
			break;
		default:
			q[i].col[1] = 15;
			break;
	}
	if(q[i].op2[0] == 't'){
		q[i].col[2] = 8;
	}else if((q[i].op2[0]>='0' && q[i].op2[0]<='9') || q[i].op2[0] == '-'){
		q[i].col[2] = 13;
	}else{
		q[i].col[2] = 9;
	}
	switch(q[i].col[0]){
		case 10:
			q[i].col[3] = 8;
			break;
		case 11:
			if(q[i].res[0] == 't'){
				q[i].col[3] = 8;
			}else{
				q[i].col[3] = 9;
			}
			break;
		case 12:
			if((q[i].res[0]>='0' && q[i].res[0]<='9') || q[i].res[0] == '-'){
				q[i].col[3] = 13;
			}else{
				q[i].col[3] = 9;
			}
			break;
		default:
			q[i].col[3] = 15;
			break;
	}
}

void Quad(char* opr, char* op1, char* op2, char* res){
	q[QC].opr = opr;
	q[QC].op1 = op1;
	q[QC].op2 = op2;
	q[QC].res = res;
	getColor(QC);
	QC++;
}


void afficherQuad(int x){
	int i;
	textattr(6);
	if(x == 1){
		printf("\n\t   /***************Les Quadruplets**************/\n");
	}else{
		printf("\n\t   /**********Les Quadruplets Optimises*********/\n");
	}
	printf("\t    ____________________________________________\n");
	printf("\t   | ID |   OPR   |   OP1   |   OP2   |   RES   |\n");
	printf("\t   |____|_________|_________|_________|_________|\n");
	for (i=0;i<QC;i++){
		textattr(6);
		printf("\t   | ");
		textattr(14);
		printf("%02d", i);
		textattr(6);
		printf(" |");
		textattr(q[i].col[0]);
		printf("  %5s  ", q[i].opr);
		textattr(6);
		printf("|");
		textattr(q[i].col[1]);
		printf("  %5s  ", q[i].op1);
		textattr(6);
		printf("|");
		textattr(q[i].col[2]);
		printf("  %5s  ", q[i].op2);
		textattr(6);
		printf("|");
		textattr(q[i].col[3]);
		printf("  %5s  ", q[i].res);
		textattr(6);
		printf("|\n");
	}
	printf("\t   |____|_________|_________|_________|_________|\n");
	textattr(15);
}

void Maj(int nQc, int jmp){
	char buff[10];
	sprintf(buff, "%02d", jmp);
	q[nQc].op1 = strdup(buff);
}
