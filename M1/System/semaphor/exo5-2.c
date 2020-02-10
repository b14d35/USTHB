#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define N 10
#define M 30
int T[N] = {0,0,0,0,0,0,0,0,0,0};

void affiche(){
	for(int k=0;k<10;k++) printf("%d ",T[k]);
	printf("\n");
}


sem_t vide,plein,P,C;
int i=0,j=0;

void* producteur(void *k){
	sem_wait(&P);
	sem_wait(&vide);
	T[i++] = rand()%100+1;
	i%=10;
	affiche();
	sem_post(&plein);
	sem_post(&P);
}

void* consommateur(void *k){
	sem_wait(&C);
	sem_wait(&plein);
	T[j++] = 0;
	j%=10;
	affiche();
	sem_post(&vide);
	sem_post(&C);
}

int main(){
	srand(time(NULL));
	sem_init(&vide,0,N);
	sem_init(&plein,0,0);
	sem_init(&P,0,1);
	sem_init(&C,0,1);
	pthread_t TH[M];
	affiche();
	//for(int x=0;x<15;x++)pthread_create(&TH[x],0,producteur,NULL);
	//for(int x=15;x<M;x++)pthread_create(&TH[x],0,consommateur,NULL);
	for(int x=0;x<M;x++){
		switch(rand()%2){
			case 0:
				pthread_create(&TH[x],0,producteur,NULL);
				break;
			case 1:
				pthread_create(&TH[x],0,consommateur,NULL);
				break;
		}
	}
	for(int x=0;x<M;x++)pthread_join(TH[x],NULL);
	return 0;
}
