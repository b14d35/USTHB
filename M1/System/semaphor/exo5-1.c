#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define N 10
#define M 20
int T[N] = {0,0,0,0,0,0,0,0,0,0};

void affiche(){
	for(int k=0;k<10;k++) printf("%d ",T[k]);
	printf("\n");
}


sem_t vide,plein;
int i=0,j=0;

void* producteur(void *k){
	int x=0;
	while(x<M){
		sem_wait(&vide);
		T[i++] = rand()%100+1;
		i%=10;
		printf("\n");
		affiche();
		
		sem_post(&plein);
		x++;
	}
}

void* consommateur(void *k){
	int x=0;
	while(x<M){
		sem_wait(&plein);
		T[j++] = 0;
		j%=10;
		printf("\n");
		affiche();
		
		sem_post(&vide);
		x++;
	}
}

int main(){
	srand(time(NULL));
	sem_init(&vide,0,N);
	sem_init(&plein,0,0);
	pthread_t TH[2];
	affiche();
	pthread_create(&TH[0],0,producteur,NULL);
	pthread_create(&TH[1],0,consommateur,NULL);
	pthread_join(TH[0],NULL);
	pthread_join(TH[1],NULL);
	return 0;
}
