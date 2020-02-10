#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#define N 10

int A[N][N],B[N][N],C[N][N];
int M = N/2;
void* add_matrice_haut_droite(void *t){
	int i,j;
	for(i=0;i<M;i++){
		for(j=M;j<N;j++) C[i][j] = A[i][j]+B[i][j];
	}
	printf("Fin de calcul Haut Droit\n");
}

void* add_matrice_haut_gauche(void *t){
	int i,j;
	for(i=0;i<M;i++){
		for(j=0;j<M;j++) C[i][j] = A[i][j]+B[i][j];
	}
	printf("Fin de calcul Haut Gauche\n");
}

void* add_matrice_bas_droite(void *t){
	int i,j;
	for(i=M;i<N;i++){
		for(j=M;j<N;j++) C[i][j] = A[i][j]+B[i][j];
	}
	printf("Fin de calcul Bas Droit\n");
}

void* add_matrice_bas_gauche(void *t){
	int i,j;
	for(i=M;i<N;i++){
		for(j=0;j<M;j++) C[i][j] = A[i][j]+B[i][j];
	}
	printf("Fin de calcul Bas Gauche\n");
}

int main(){
	int i,j;
	printf("%d %d\n",M,N);
	pthread_t th[4];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			A[i][j] = 1;
			B[i][j] = i * N + j;
			C[i][j] = 0;
		}
	}
	pthread_create(&th[0],0,add_matrice_haut_droite,NULL);
	pthread_create(&th[1],0,add_matrice_haut_gauche,NULL);
	pthread_create(&th[2],0,add_matrice_bas_droite,NULL);
	pthread_create(&th[3],0,add_matrice_bas_gauche,NULL);
	for(i=0;i<4;i++)pthread_join(th[i],NULL);
	printf("Matrice 1\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	printf("Matrice 2\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",B[i][j]);
		}
		printf("\n");
	}
	printf("Matrice 3\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			int x = i * N + j + 1;
			if(C[i][j] != x){
				perror("Erreur de calcul\n");
				exit(-1);
			}
		}
	}
	return 0;
}
