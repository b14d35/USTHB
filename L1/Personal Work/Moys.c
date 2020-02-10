#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char N[30],P[30];
    float moy1,moy2,moyf;
} student;
int main() {
    FILE *M,*ADM,*AJR,*ADMD;
    student x;
    int a,i,j;
    M=fopen("Moyennes.txt","r");
    ADM=fopen("Admis.txt","w");
    AJR=fopen("Ajournees.txt","w");
    a=0;
    while (!feof(M)) {
        fscanf(M,"%s %s %f %f",&x.N,&x.P,&x.moy1,&x.moy2);
        x.moyf=(x.moy1+x.moy2)/2;
        if (x.moyf>=10) {
            fprintf(ADM,"%s %s %f\n",x.N,x.P,x.moyf);
            a++;
        }
        else {
            fprintf(AJR,"%s %s %f\n",x.N,x.P,x.moyf);
        }
    }
    fclose(M);
    fclose(ADM);
    fclose(AJR);
    student T[a];
    i=0;
    x.moy1=0;
    x.moy2=0;
    ADM=fopen("Admis.txt","r");
    while (!feof(ADM)) {
        fscanf(ADM,"%s %s %f",&x.N,&x.P,&x.moyf);
        T[i]=x;
        i++;
    }
    fclose(ADM);
    for (i=0;i<a-1;i++) {
        for (j=i+1;j<a;j++) {
            if (T[i].moyf<T[j].moyf) {
                x=T[i];
                T[i]=T[j];
                T[j]=x;
            }
        }
    }
    ADMD=fopen("Admis Triees.txt","w");
    for (i=0;i<a;i++) {
        fprintf(ADMD,"%s %s %f\n",T[i].N,T[i].P,T[i].moyf);
    }
    fclose(ADMD);
}
