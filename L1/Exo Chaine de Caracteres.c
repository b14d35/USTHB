#include<stdio.h>
#include<string.h>
int main() {
    char T[7][9],A[9];
    int i,j,b,c=0;
    printf("Faites entrer les jours de semaines\n");
    for (i=0;i<7;i++) {
        do{
			printf("\t");
			gets(T[i]);
			b=1;
				if (strcmpi(T[i],"SAMEDI")==0 || strcmpi(T[i],"DIMANCHE")==0 || strcmpi(T[i],"LUNDI")==0 || strcmpi(T[i],"MARDI")==0
					|| strcmpi(T[i],"MERCREDI")==0 || strcmpi(T[i],"JEUDI")==0 || strcmpi(T[i],"VENDREDI")==0) {
					b=0;
					c++;
				}
			if (b==1) {
				printf("\nCe n'est pas un jour\n");
			}
			j=0;
            while(b==0 && j<c) {
                if (strcmpi(T[i],T[j])==0 && i!=j) {
					printf("\nVous avez deja entree ce jour\n");
					b=1;
					c--;
                }
                else {
                    j++;
                }
            }
        }while(b==1);
    }
    for (i=0;i<7;i++) {
        for (j=i+1;j<7;j++) {
           if(strcmp(T[i],T[j])>0) {
               strcpy(A,T[i]);
               strcpy(T[i],T[j]);
               strcpy(T[j],A);
           }
        }
    }
    printf("\nLes jours selon l'ordre alphabetique\n");
    for (i=0;i<7;i++) {
        puts(T[i]);
    }
}
