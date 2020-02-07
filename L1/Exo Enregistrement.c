/*(1) Proposer une structure d''enregistrement pour representer un point A(x,y) avec des coordonnees cartisiennes.
            (Abssisse,ordonee)
(2) Donnez le programme qui permet de lire les coorrdonnees de 2 points A et B.
(3) Ecrire une fonction qui permet de calculer la distance Euclidienne.
            D=|Xa - Xb| + |Ya - Yb|*/
#include<stdio.h>
#include<math.h>
typedef struct {
  float x,y;
} point;
float Distance(point A,point B) {
    return fabs(A.x-B.x) + fabs(A.y-B.y);
}
int main() {
    point A,B;
    float d;
    printf("Donnez les coordonnees du point A\n");
    printf("Donnez l'abssisse\n");
    scanf("%f",&A.x);
    printf("Donnez l'ordonnee\n");
    scanf("%f",&A.y);
    printf("Donnez les coordonnees du point B\n");
    printf("Donnez l'abssisse\n");
    scanf("%f",&B.x);
    printf("Donnez l'ordonnee\n");
    scanf("%f",&B.y);
    printf("Les coordonnees sont:\n");
    printf("A=%f,%f\n",A.x,A.y);
    printf("B=%f,%f\n",B.x,B.y);
    d=Distance(A,B);
    printf("La distance = %f",d);
}
