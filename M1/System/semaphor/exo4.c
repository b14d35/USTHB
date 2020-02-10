#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
int nb_tour = 10;
int NB[3] = {0,0,0};
sem_t S1,S2,A;
int v1,v2;

void* joueur1(void *k){
	while(nb_tour>0){
		v1 = rand()%3;
		sem_post(&S1);
		sem_post(&A);
	}
}

void* joueur2(void *k){
	while(nb_tour>0){
                v2 = rand()%3;
                sem_post(&S2);
		sem_post(&A);
	}
}

void* arbitre(void *k){
	while(nb_tour>0){
		sem_wait(&S1);
		sem_wait(&S2);
		nb_tour--;
		switch(v1){
			case 0:
				if(v2 == 0) NB[2]++;
				else if(v2 == 1) NB[0]++;
				else NB[1]++;
				break;
			case 1:
				if(v2 == 1) NB[2]++;
				else if(v2 == 0) NB[0]++;
				else NB[1]++;
				break;
			case 2:
				if(v2 == 2) NB[2]++;
				else if(v2 == 1) NB[0]++;
				else NB[1]++;
				break;
		}
		sem_post(&S1);
		sem_post(&S2);
	}
}

int main(){
	int i;
	srand(time(NULL));
	sem_init(&S1,0,1);
	sem_init(&S2,0,1);
	sem_init(&A,0,0);
	pthread_t TH[3];
	pthread_create(&TH[0],0,joueur1,NULL);
	pthread_create(&TH[1],0,joueur2,NULL);
	pthread_create(&TH[2],0,arbitre,NULL);
	for(i=0;i<3;i++) pthread_join(TH[i],NULL);
	printf("Joueur 1 gagne : %d\n",NB[0]);
	printf("Joueur 2 gagne : %d\n",NB[1]);
	printf("Partie Null : %d\n",NB[2]);
	return 0;
}
