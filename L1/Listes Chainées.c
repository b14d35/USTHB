#include<stdio.h>
#include<stdlib.h>
#include<string.h>
///Il reste les cas spéciaux dans les listes comme au premier ou a la fin
typedef struct n {
    int val;
    struct n *next;
} Noeud;
int taille(Noeud *tete) {
    int x=0;
    while (tete!=NULL) {
        x++;
        tete=tete->next;
    }
    return x;
}
Noeud* position(Noeud *tete,int x) {
    while (tete!=NULL && x>1) {
        tete=tete->next;
        x--;
    }
}
Noeud* inserer(Noeud *tete,int x,int pos) {
    Noeud *P,*Q;
    P=malloc(sizeof(Noeud));
    if (pos-1==0) {
        P->val=x;
        P->next=tete->next;
        tete=P;
    }
    else {
        Q=malloc(sizeof(Noeud));
        P=position(tete,pos-1);
        Q->val=x;
        Q->next=P->next;
        P->next=Q;
    }
}
Noeud* supp(Noeud *tete,int x) {
    Noeud *P,*Q;
    P=malloc(sizeof(Noeud));
    Q=malloc(sizeof(Noeud));
    P=position(tete,x-1);
    Q=position(tete,x);
    P->next=Q->next;
    free(Q);
}
int main() {
    int n,i;
    Noeud *tete,*P,*Q;
    printf("Donnez la taille de votre chaine : \t");
    do {
        scanf("%d",&n);
    } while (n<1);

    tete=malloc(sizeof(Noeud));
    Q=malloc(sizeof(Noeud));
    printf("Donnez la valeur : \t");
    scanf("%d",&tete->val);
    tete->next=NULL;
    Q=tete;
    for (i=2;i<=n;i++) {
        P=malloc(sizeof(Noeud));
        Q->next=P;
        printf("Donnez la valeur : \t");
        scanf("%d",&P->val);
        Q=P;
        Q->next=NULL;
    }
    P=tete;
    printf("%d\t",P->val);
    P=P->next;
    while (P!=NULL) {
        printf("%d\t",P->val);
        P=P->next;
    }
}
